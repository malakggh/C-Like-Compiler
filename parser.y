%{
    // Authors:
    //         ***REMOVED*** ***REMOVED***,
    //         ***REMOVED*** ***REMOVED***,
    //         ***REMOVED*** ***REMOVED***
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "helper.c"
    int yyerror(char* e);
    int yylex();
    struct node* head;
//     struct ScopeStack* stack = NULL;
    struct ScopeStack* test_stack = NULL;
    struct Scope* global_scope = NULL;
%}

%token ARGS TRUE_ FALSE_ VOID NULL_ IF ELSE FOR WHILE DO FUNC RETURN INT INT_P CHAR CHAR_P REAL REAL_P BOOL VAR STRING EQEQ SMALL_EQ BIG_EQ NOT_EQ OR AND COMMENT ID DIGITS_VALUE HEX_VALUE REAL_VALUE STRING_VALUE CHAR_VALUE


%left OR
%left AND
%left EQEQ NOT_EQ '<' '>' SMALL_EQ BIG_EQ  
%left '+' '-'
%left '*' '/'
%left ';' ','
%right '!' '&' '=' 
%nonassoc non_else
%nonassoc ELSE

%%
/* "#"" -- mean ignore me but don't shift
   ""   -- mean ignore me and shift    
 */
program:
        code_global {head = $1;}
        ;

code_global:
        func_or_prod code_global {
                $$ = mknode("#global_scope",(struct node*[]){$1,$2,NULL});
        }
        | {$$=mknode1("#");}
        ;

code:
        func_or_prod code {$$ = mknode("#non_global_scope",(struct node*[]){$1,$2,NULL});}
        | {$$=mknode1("#");}
        ;

func_or_prod: 
//      1    2   3  4           5   6  7     8  9     10        11 
        FUNC ID '(' parameters ')' ':' type '{' block return_st '}'
        {
            struct node* parTemp = mknode("",(struct node*[]){$4,NULL});
            struct node* blockTemp = mknode("",(struct node*[]){$9,$10,NULL});
            struct node* temp = mknode("",(struct node*[]){
                mknode1($2->token),nl(),
                mknode1("(ARGS"),nl(), parTemp, mknode1(")"),nl(),
                mknode1("(RET "), mknode1($7->token), mknode1(")"),nl(),
                mknode1("(BODY"),nl(), blockTemp, mknode1(")"),nl(),
                NULL});
            
            $$ = mknode("",(struct node*[]){mknode1("(FUNC"),nl(),temp,mknode1(")"),nl(),NULL});

            struct Scope* currentScope = newScope();
            struct VarArr* parametersArr = newVarArr();
            getFunctionVarArr_Scanner(parTemp, parametersArr);
            struct Function* newFunc = newFunction($2->token, $7->type, parametersArr);
            appendFunctionArr(currentScope->funcsArr, newFunc);
            $$->scope = currentScope;
            $$->pointer = currentScope;

            // check 1 + 2 (if main exists once and if it's void and has no args)
            mainCheck(currentScope);

            // check 9 (function can not return string)
            if ($7->type == STRING_T){
                printf("Error: function can not return string\n");
                exit(0);
            }

            struct Scope* block_scope = newScope();
            block_scope->varArr = deepCopyVarArr(newFunc->varArr);
            block_scope->returnType = newFunc->returnType;
            // extract the vars from the block
            addVarArrToScope($9->scope->varArr, block_scope);
            addFunctionArrToScope($9->scope->funcsArr, block_scope);
            block_scope->useScope = $9->scope->useScope;
            addVarArrToScope($10->use_scope->varArr, block_scope->useScope);
            addFunctionArrToScope($10->use_scope->funcsArr, block_scope->useScope);
            //pushScope(stack, block_scope);    
            blockTemp->pointer = block_scope;
            checkDuplicateVarOrFuncInScope(block_scope);

            // printScopeStack(stack);

        }
//      1    2    3  4           5   6  7     8  9     10
        |FUNC ID '(' parameters ')' ':' VOID '{' block '}'
        {
            node* parTemp = mknode("",(struct node*[]){$4,NULL});
            node* blockTemp = mknode("",(struct node*[]){$9,NULL});
            node* temp = mknode("",(struct node*[]){
                mknode1($2->token),nl(),
                mknode1("(ARGS"),nl(), parTemp, mknode1(")"),nl(),
                mknode1("(RET "), mknode1("VOID"), mknode1(")"),nl(),
                mknode1("(BODY"),nl(), blockTemp, mknode1(")"),nl(),
                NULL});
            
            $$ = mknode("",(struct node*[]){mknode1("(FUNC"),nl(),temp,mknode1(")"),nl(),NULL});


            struct Scope* currentScope = newScope();
            struct VarArr* parametersArr = newVarArr();
            getFunctionVarArr_Scanner(parTemp, parametersArr);
            struct Function* newFunc = newFunction($2->token, VOID_T, parametersArr);
            appendFunctionArr(currentScope->funcsArr, newFunc);
            $$->scope = currentScope;
            $$->pointer = currentScope;

            // check 1 + 2 (if main exists once and if it's void and has no args)
            mainCheck(currentScope);

            struct Scope* block_scope = newScope();
            block_scope->varArr = deepCopyVarArr(newFunc->varArr);
            block_scope->returnType = newFunc->returnType;
            // extract the vars from the block
            addVarArrToScope($9->scope->varArr, block_scope);
            addFunctionArrToScope($9->scope->funcsArr, block_scope);
            block_scope->useScope = $9->scope->useScope;
            //pushScope(stack, block_scope);    
            blockTemp->pointer = block_scope;
            checkDuplicateVarOrFuncInScope(block_scope);
        }
        ;


return_st:
        RETURN exp ';' {
            $$ = mknode("#ret_st",(struct node*[]){mknode1("(RET "),$2,mknode1(")"),nl(),NULL});
            $$->use_scope = newScope();
            addVarArrToScope($2->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($2->use_scope->funcsArr, $$->use_scope);
        }
        ;

type:
        INT {node* t = mknode1("INT"); t->type = INT_T; $$ = t;}
        |REAL {node* t = mknode1("REAL"); t->type = REAL_T; $$ = t;}
        |CHAR {node* t = mknode1("CHAR"); t->type = CHAR_T; $$ = t;}
        |BOOL {node* t = mknode1("BOOL"); t->type = BOOL_T; $$ = t;}
        |INT_P {node* t = mknode1("INT_P"); t->type = INT_P_T; $$ = t;}
        |REAL_P {node* t = mknode1("REAL_P"); t->type = REAL_P_T; $$ = t;}
        |CHAR_P {node* t = mknode1("CHAR_P"); t->type = CHAR_P_T; $$ = t;}
        |STRING {node* t = mknode1("STRING"); t->type = STRING_T; $$ = t;}
        ;


parameters:
        ARGS args_var {$$ = mknode("#",(struct node*[]){mknode1("("),$2,nl(),NULL});}
        |ARGS args_var ';' parameters {$$ = mknode("#",(struct node*[]){mknode1("("),$2,nl(),$4,NULL});}
        | {
                $$ = mknode("#",(struct node*[]){mknode1("NONE"),nl(),NULL});
          }
        ;

args_var:
        ID ':' type {$$ = mknode("#",(struct node*[]){$1,mknode1(","),$3,mknode1(")"),NULL});$$->type = $3->type;$1->type = $3->type; }
        |ID ',' args_var {$$ = mknode("#",(struct node*[]){$1,mknode1(","),$3,NULL});$$->type = $3->type;$1->type = $3->type; }
        ;

block: comment_st code vars statements{
            $$ = mknode("#",(struct node*[]){$2,$3,$4,NULL});

            $$->scope = newScope();
            add_vars_to_scope($3, $$->scope);
            add_functions_to_scope($2, $$->scope);

            $$->use_scope = newScope();
            add_statements_to_scope($4, $$->use_scope);
            $$->scope->useScope = $$->use_scope;
        }
        ;

comment_st:
        COMMENT comment_st {$$ = mknode1("#comment");}
        | {$$=mknode1("#");}
        ;

statements:
        statement statements {$$ = mknode("#statements",(struct node*[]){$1,$2,NULL});}
        | {$$=mknode1("#");}
        ;

vars: 
        var_st vars {$$ = mknode("#vars",(struct node*[]){$1,$2,NULL});}
        | {$$=mknode1("#");}
        ;

statement:
        if_st {
            $$ = mknode("#",(struct node*[]){$1,NULL});
            $$->use_scope = $1->use_scope;
        }
        |do_st {
            $$ = mknode("#",(struct node*[]){$1,NULL});
            $$->use_scope = $1->use_scope;
        }
        |while_st {
            $$ = mknode("#",(struct node*[]){$1,NULL});
            $$->use_scope = $1->use_scope;
        }
        |for_st {
            $$ = mknode("#",(struct node*[]){$1,NULL});
            $$->use_scope = $1->use_scope;
        }
        |assignment_st ';' {
            $$ = mknode("#",(struct node*[]){$1,NULL});
            $$->use_scope = $1->use_scope;
        }
        |func_call ';' {
            $$ = mknode("#func_call_stmt",(struct node*[]){$1,nl(),NULL});
            $$->use_scope = $1->use_scope;
        }
        |new_block{
            $$ = mknode("#new_block",(struct node*[]){mknode1("(BLOCK"),nl(),
            mknode("",(struct node*[]){$1,NULL})
            ,mknode1(")"),nl(),NULL});
            $$->scope = $1->scope;
        }
        |COMMENT {$$ = mknode1("#");printf("comment...\n");}
        ;

statement_block:
        statement {
            $$ = mknode("#statement_block",(struct node*[]){$1,NULL});
            // printf("statement_block\n");
            // printtree_REAL($1,0);
            // do the same for the printing tree semantic
            if (!(strcmp($1->token,"#new_block")==0)){
                $$->scope = newScope();
                $$->use_scope = $1->use_scope;

                $$->scope->useScope = $$->use_scope;
                
                //pushScope(stack, block_scope);    
                $1->pointer = $$->scope;
                checkDuplicateVarOrFuncInScope($$->scope);

            }
        }
        |return_st {
            $$ = mknode("#statement_block",(struct node*[]){$1,NULL});
            $$->scope = newScope();
            $$->use_scope = $1->use_scope;

            $$->scope->useScope = $$->use_scope;
            
            //pushScope(stack, block_scope);    
            $1->pointer = $$->scope;
            checkDuplicateVarOrFuncInScope($$->scope);
        }

new_block: 
        '{' vars statements return_st'}'{
            $$ = mknode("#",(struct node*[]){$2,$3,$4,NULL});

            $$->scope = newScope();
            add_vars_to_scope($2, $$->scope);

            $$->use_scope = newScope();
            add_statements_to_scope($3, $$->use_scope);
            addVarArrToScope($4->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($4->use_scope->funcsArr, $$->use_scope);
            $$->scope->useScope = $$->use_scope;

            //pushScope(stack, block_scope);    
            $$->pointer = $$->scope;
            checkDuplicateVarOrFuncInScope($$->scope);
        }
        |'{' vars statements'}'{
            $$ = mknode("#",(struct node*[]){$2,$3,NULL});

            $$->scope = newScope();
            add_vars_to_scope($2, $$->scope);

            $$->use_scope = newScope();
            add_statements_to_scope($3, $$->use_scope);
            $$->scope->useScope = $$->use_scope;
            
            //pushScope(stack, block_scope);    
            $$->pointer = $$->scope;
            checkDuplicateVarOrFuncInScope($$->scope);
        }
        ;

if_st:
        IF '(' exp ')' statement_block %prec non_else {
                struct node* temp = mknode("",(struct node*[]){$3,$5,NULL});
                $$ = mknode("#",(struct node*[]){mknode1("(IF"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                $$->use_scope = newScope();
                addVarArrToScope($3->use_scope->varArr, $$->use_scope);
                addFunctionArrToScope($3->use_scope->funcsArr, $$->use_scope);
                }
        |IF '(' exp ')' statement_block ELSE statement_block {
                struct node* temp = mknode("",(struct node*[]){$3,$5,$7,NULL});
                $$ = mknode("#",(struct node*[]){mknode1("(IF-ELSE"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                $$->use_scope = newScope();
                addVarArrToScope($3->use_scope->varArr, $$->use_scope);
                addFunctionArrToScope($3->use_scope->funcsArr, $$->use_scope);
                }
        ;

do_st:
        DO statement_block WHILE '(' exp ')' ';' {
            struct node* whileDoConds = mknode("",(struct node*[]){
                    mknode1("(DO-WHILE-INIT"),nl(),
                    mknode("",(struct node*[]){$5,NULL}),nl(),
                    mknode1(")"),
                    NULL});
            struct node* whileDoBlock = mknode("",(struct node*[]){
                    mknode1("(DO-WHILE-BLOCK"),nl(),
                    mknode("",(struct node*[]){$2,NULL}),
                    mknode1(")"),
                    NULL});
            $$ = mknode("#",(struct node*[]){
                    mknode1("(DO-WHILE"),
                    nl(),whileDoConds,
                    nl(),whileDoBlock,
                    nl(),mknode1(")"),
                    nl()
                    ,NULL});
            $$->use_scope = newScope();
            addVarArrToScope($5->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($5->use_scope->funcsArr, $$->use_scope);
        }
        ;

while_st:
        // 1   2   3   4        5
        WHILE '(' exp ')' statement_block {
            struct node* whileConds = mknode("",(struct node*[]){
                    mknode1("(WHILE-INIT"),nl(),
                    mknode("",(struct node*[]){$3,NULL}),
                    mknode1(")"),
                    NULL});
            struct node* whileBlock = mknode("",(struct node*[]){
                    mknode1("(WHILE-BLOCK"),nl(),
                    mknode("",(struct node*[]){$5,NULL}),
                    mknode1(")"),
                    NULL});
            $$ = mknode("#",(struct node*[]){
                    mknode1("(WHILE"),
                    nl(),whileConds,
                    nl(),whileBlock,
                    nl(),mknode1(")"),
                    nl()
                    ,NULL});
            $$->use_scope = newScope();
            addVarArrToScope($3->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($3->use_scope->funcsArr, $$->use_scope);
        }
        ;

for_st:
        FOR '(' assignment_st ';' exp ';' assignment_st ')' statement_block {
            struct node* forConds = mknode("",(struct node*[]){
                    mknode1("(FOR-INIT"),nl(),
                    mknode("",(struct node*[]){$3,NULL}),
                    mknode("",(struct node*[]){$5,NULL}),nl(),
                    mknode("",(struct node*[]){$7,NULL}),
                    mknode1(")"),
                    NULL});
            struct node* forBlock = mknode("",(struct node*[]){
                    mknode1("(FOR-BLOCK"),nl(),
                    mknode("",(struct node*[]){$9,NULL}),nl(),
                    mknode1(")"),
                    NULL});
            $$ = mknode("#",(struct node*[]){
                    mknode1("(FOR"),
                    nl(),forConds,
                    nl(),forBlock,
                    nl(),mknode1(")"),
                    nl()
                    ,NULL});
            $$->use_scope = newScope();
            addVarArrToScope($3->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($3->use_scope->funcsArr, $$->use_scope);
            
            addVarArrToScope($5->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($5->use_scope->funcsArr, $$->use_scope);
            
            addVarArrToScope($7->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($7->use_scope->funcsArr, $$->use_scope);
        }
        ;
        /* void addVarArrToScope(VarArr* varArr, Scope* scope); */


assignment_st:
        lhs '=' exp {
            struct node* expTemp = mknode("",(struct node*[]){$3,NULL});
            $$ = mknode("#assignment_st",(struct node*[]){mknode1("(="),$1,nl(),expTemp,mknode1(")"),nl(),NULL});
            $$->use_scope = newScope();
            addVarArrToScope($1->use_scope->varArr, $$->use_scope);
            addVarArrToScope($3->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($3->use_scope->funcsArr, $$->use_scope);
        }
        ;

lhs:
        ID {
            $$ = mknode1($1->token);
            $$->use_scope = newScope();
            appendVarArr($$->use_scope->varArr, newVar_($1->token));
        }
        |ID '[' exp ']' {
            $$ = mknode("#stringAtIndex",(struct node*[]){mknode1($1->token),mknode1("["),$3,mknode1("]"),NULL});
            $$->use_scope = newScope();
            appendVarArr($$->use_scope->varArr, newVar_($1->token));
        }
        |'*' ID {
            $$ = mknode("#derefId",(struct node*[]){mknode1("*"),mknode1($2->token),NULL});
            $$->use_scope = newScope();
            appendVarArr($$->use_scope->varArr, newVar_($2->token));
        }
        ;

value:
    STRING_VALUE {$$ = mknode1($1->token); $$->type = STRING_T;}
    | CHAR_VALUE {$$ = mknode1($1->token); $$->type = CHAR_T;}
    | TRUE_ {$$ = mknode1("TRUE"); $$->type = BOOL_T;}
    | FALSE_ {$$ = mknode1("FALSE"); $$->type = BOOL_T;}
    | NULL_ {$$ = mknode1("NULL"); $$->type = NULL_T;}
    | HEX_VALUE {$$ = mknode1($1->token); $$->type = INT_T;}
    | DIGITS_VALUE {$$ = mknode1($1->token); $$->type = INT_T;}
    | REAL_VALUE {$$ = mknode1($1->token); $$->type = REAL_T;}
    ;

var_st:
        VAR var_list ';' {
            $$ = mknode("#",(struct node*[]){mknode1("(VAR ")
            ,nl()
            ,mknode("",(struct node*[]){$2,NULL})
            ,nl()
            ,mknode1(")"),nl(),NULL});
            $$->scope = newScope();
            get_var_list($2,$$->scope->varArr);
            
        }
        |STRING var_string_list ';' {
            $$ = mknode("#",(struct node*[]){mknode1("(VAR_STRING ")
            ,nl()
            ,mknode("",(struct node*[]){$2,NULL})
            ,nl()
            ,mknode1(")"),nl(),NULL});
            $$->scope = newScope();
            get_var_string_list($2,$$->scope->varArr);
        }
        ;

var_list:
        var_op ':' type {$$ = mknode("#",(struct node*[]){$1,nl(),mknode1("Type: "),$3,NULL});$$->type = $3->type;$1->type = $3->type;}
        |var_op ',' var_list {$$ = mknode("#",(struct node*[]){$1,nl(),$3,NULL});$$->type = $3->type;$1->type = $3->type; }
        ;

var_op:
        ID {$$ = mknode1($1->token);}
        |assignment_st {$$ = mknode("#ass_in_var",(struct node*[]){$1,NULL});}
        ;

var_string_list:
        var_string_opt {$$ = mknode("#",(struct node*[]){$1,nl(),NULL});}
        |var_string_opt ',' var_string_list {$$ = mknode("#",(struct node*[]){$1,nl(),$3,NULL});}
        ;

var_string_opt:
        ID '[' exp ']' {$$ = mknode("#var_string_opt",(struct node*[]){mknode1($1->token),mknode1("["),$3,mknode1("]"),NULL});}
        |assignment_st {$$ = mknode("#ass_in_str",(struct node*[]){$1,NULL});}
        ;

func_call:
        ID '(' exp_list ')' {
            $$ = mknode("#",(struct node*[]){mknode1("function call "),mknode1($1->token),mknode1("("),$3,mknode1(")"),NULL});
            $$->use_scope = newScope();
            add_args_to_scope($3, $$->use_scope);
            appendFunctionArr($$->use_scope->funcsArr, newFunction($1->token,NONE_T,newVarArr()));
        }
        ;

exp_list: 
        exp {$$ = mknode("#exp_list",(struct node*[]){$1,NULL});}
        | exp ',' exp_list {$$ = mknode("#exp_list",(struct node*[]){$1,mknode1(","),$3,NULL});}
        | {$$=mknode1("#");}
        ;
    /* void addVarArrToScope(VarArr* varArr, Scope* scope); */

exp:		
          exp '+' exp {$$ = expNode("( +",$1,$3); $$->exp_node = mkExpNode("+",$1,$3);$$->exp_node->var = freshVar();}//			
        | exp '-' exp {$$ = expNode("( -",$1,$3); $$->exp_node = mkExpNode("-",$1,$3);$$->exp_node->var = freshVar();}//				
        | exp '*' exp {$$ = expNode("( *",$1,$3); $$->exp_node = mkExpNode("*",$1,$3);$$->exp_node->var = freshVar();}//
        | exp '/' exp {$$ = expNode("( /",$1,$3); $$->exp_node = mkExpNode("/",$1,$3);$$->exp_node->var = freshVar();}//		
        | exp EQEQ exp {$$ = expNode("( ==",$1,$3); $$->exp_node = mkExpNode("==",$1,$3);$$->exp_node->var = freshVar();}//
        | exp NOT_EQ exp {$$ = expNode("( !=",$1,$3); $$->exp_node = mkExpNode("!=",$1,$3);$$->exp_node->var = freshVar();}//
        | exp '<' exp {$$ = expNode("( <",$1,$3); $$->exp_node = mkExpNode("<",$1,$3);$$->exp_node->var = freshVar();}//
        | exp SMALL_EQ exp {$$ = expNode("( <=",$1,$3); $$->exp_node = mkExpNode("<=",$1,$3);$$->exp_node->var = freshVar();}//
        | exp '>' exp {$$ = expNode("( >",$1,$3); $$->exp_node = mkExpNode(">",$1,$3);$$->exp_node->var = freshVar();}//
        | exp BIG_EQ exp {$$ = expNode("( >=",$1,$3); $$->exp_node = mkExpNode(">=",$1,$3);$$->exp_node->var = freshVar();}//
        | exp OR exp {$$ = expNode("( ||",$1,$3); $$->exp_node = mkExpNode("||",$1,$3);$$->exp_node->var = freshVar();}//	
        | exp AND exp {$$ = expNode("( &&",$1,$3); $$->exp_node = mkExpNode("&&",$1,$3);$$->exp_node->var = freshVar();}//		
        | '!' exp {//
            $$ = mknode("#",(struct node*[]){mknode1("!"),nl(),$2,NULL});
            $$->use_scope = newScope();
            addVarArrToScope($2->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($2->use_scope->funcsArr, $$->use_scope);
            $$->exp_node = mkExpNode("!",$2,NULL);
            $$->exp_node->var = freshVar();
        } 								
        | ID {
            $$ = mknode1($1->token);
            $$->use_scope = newScope();
            appendVarArr($$->use_scope->varArr, newVar_($1->token));
            $$->exp_node = mkExpNode($1->token,NULL,NULL);
            $$->exp_node->leaf_type = ID_LEAF;
        }											
        | func_call {
            $$ = mknode("#func_call_as_exp",(struct node*[]){$1,NULL});
            $$->use_scope = newScope();
            addVarArrToScope($1->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($1->use_scope->funcsArr, $$->use_scope);
            $$->exp_node = mkExpNode($1->children[1]->token,NULL,NULL);
            $$->exp_node->leaf_type = FUNC_CALL;
            $$->exp_node->var = freshVar();
        }	  							
        | '|' ID '|' {
            $$ = mknode("#",(struct node*[]){mknode1("lenOf("),mknode1($2->token),mknode1(")"),NULL});
            $$->use_scope = newScope();
            appendVarArr($$->use_scope->varArr, newVar_($2->token));
            $$->exp_node = mkExpNode($2->token,NULL,NULL);
            $$->exp_node->leaf_type = LEN_OF_STR;
        }	 									
        | '(' exp ')' {$$ = $2;}														
        | '&' ID {
            $$ = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1($2->token),mknode1(")"),NULL});
            $$->use_scope = newScope();
            appendVarArr($$->use_scope->varArr, newVar_($2->token));   
            $$->exp_node = mkExpNode($2->token,NULL,NULL);
            $$->exp_node->leaf_type = ADDRESS_OF; 
            $$->exp_node->var = freshVar();
            $$->exp_node->code = plusStr($$->exp_node->var,plusStr(" = &", $2->token));
        }	  											
        | '&' ID '[' exp ']' {
            $$ = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1($2->token),mknode1("["),$4,mknode1("]"),NULL});
            $$->use_scope = newScope();
            appendVarArr($$->use_scope->varArr, newVar_($2->token));
            addVarArrToScope($4->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($4->use_scope->funcsArr, $$->use_scope);

            struct node* idNode = mknode1($2->token);
            idNode->exp_node = mkExpNode($2->token,NULL,NULL);
            idNode->exp_node->leaf_type = ID_LEAF;

            $$->exp_node = mkExpNode("addressOfChar",idNode,$4);
            $$->exp_node->var = freshVar();

        }
        | ID '[' exp ']'{
            $$ = mknode("#",(struct node*[]){mknode1($1->token),mknode1("["),$3,mknode1("]"),NULL});
            $$->use_scope = newScope();
            appendVarArr($$->use_scope->varArr, newVar_($1->token));
            addVarArrToScope($3->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($3->use_scope->funcsArr, $$->use_scope);

            struct node* idNode = mknode1($1->token);
            idNode->exp_node = mkExpNode($1->token,NULL,NULL);
            idNode->exp_node->leaf_type = ID_LEAF;

            $$->exp_node = mkExpNode("charAt",idNode,$3);
            $$->exp_node->var = freshVar();
        }
        | '*' exp {
            $$ = mknode("#",(struct node*[]){mknode1("dereference("),$2,mknode1(")"),NULL});
            $$->use_scope = newScope();
            addVarArrToScope($2->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($2->use_scope->funcsArr, $$->use_scope);
            $$->exp_node = mkExpNode("dereference",$2,NULL);
            $$->exp_node->var = freshVar();
        }
        | value {
            $$ = mknode("#",(struct node*[]){$1,NULL});
            $$->use_scope = newScope();
            $$->exp_node = mkExpNode($1->token,NULL,NULL);
            $$->exp_node->leaf_type = VALUE;
            $$->exp_node->result = $1->type;
            $$->exp_node->var = $1->token;
        }
        | '-' exp {
            $$ = mknode("#",(struct node*[]){mknode1("-"),$2,NULL});
            $$->use_scope = newScope();
            addVarArrToScope($2->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($2->use_scope->funcsArr, $$->use_scope);
            $$->exp_node = mkExpNode("unary-",$2,NULL);
            $$->exp_node->var = freshVar();
        }
        | '+' exp {
            $$ = mknode("#",(struct node*[]){mknode1("+"),$2,NULL});
            $$->use_scope = newScope();
            addVarArrToScope($2->use_scope->varArr, $$->use_scope);
            addFunctionArrToScope($2->use_scope->funcsArr, $$->use_scope);
            $$->exp_node = mkExpNode("unary+",$2,NULL);
            $$->exp_node->var = freshVar();
        }
        ;

 
%%

#include "lex.yy.c"
int main(){
    /* stack = newScopeStack(); */
    global_scope = newScope();
    test_stack = newScopeStack();
    pushScope(test_stack, global_scope);
    yyparse();
    struct node* temp = mknode("",(struct node*[]){mknode1("(CODE"),nl(),head,mknode1(")"),nl(),NULL});
    semantic(temp,test_stack,global_scope);
    printf("printing tree\n");
    printtree(temp,0);
    printf("done printing tree\n");
}

int yyerror(char* e){
    int yydebug = 1;
    fflush(stdout);
    fprintf(stderr,"Error %s at Line %d\n",e,yylineno);
    fprintf(stderr,"%s Rejected\n",yytext);
    return 0;
}