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
    struct ScopeStack* stack = NULL;
    struct Scope* global_scope = NULL;
    void addVarArrToScope(VarArr* varArr, Scope* scope);
    void addFunctionArrToScope(FunctionArr* funcArr, Scope* scope);
    void reverseStack(ScopeStack* stack);
%}


%token ARGS TRUE_ FALSE_ MAIN VOID NULL_ IF ELSE FOR WHILE DO FUNC RETURN INT INT_P CHAR CHAR_P REAL REAL_P BOOL VAR STRING EQEQ SMALL_EQ BIG_EQ NOT_EQ OR AND COMMENT ID DIGITS_VALUE HEX_VALUE REAL_VALUE STRING_VALUE CHAR_VALUE

%left '+' '-'
%left '*' '/'
%left EQEQ NOT_EQ '<' '>' SMALL_EQ BIG_EQ  
%left OR AND
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
        func_or_prod {
                // since we don't support global variables the only thing that we can get from the child function is
                // the function name, arguments and return type
                addFunctionArrToScope($1->scope->funcsArr, global_scope);
                reverseStack(stack);
                printScope(global_scope,9999);
                printScopeStack(stack);
                printtree($1,0);
                // free the stack
                stack->len = 0;
        } code_global {
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
            
            struct node* func = mknode("",(struct node*[]){mknode1("(FUNC"),nl(),temp,mknode1(")"),nl(),NULL});
            $$ = func;


            struct Scope* currentScope = newScope();
            struct VarArr* parametersArr = newVarArr();
            getFunctionVarArr_Scanner(parTemp, parametersArr);
            struct Function* newFunc = newFunction($2->token, $7->type, parametersArr);
            appendFunctionArr(currentScope->funcsArr, newFunc);
            $$->scope = currentScope;

            struct Scope* block_scope = newScope();
            block_scope->varArr = deepCopyVarArr(newFunc->varArr);
            block_scope->returnType = newFunc->returnType;
            // extract the vars from the block
            addVarArrToScope($9->scope->varArr, block_scope);
            addFunctionArrToScope($9->scope->funcsArr, block_scope);
            pushScope(stack, block_scope);    

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
        }
        ;


return_st:
        RETURN exp ';' {$$ = mknode("#",(struct node*[]){mknode1("(RET "),$2,mknode1(")"),nl(),NULL});}
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
            Scope* currentScope = newScope();
            add_vars_to_scope($3, currentScope);
            add_functions_to_scope($2, currentScope);
            $$->scope = currentScope;
        }
        ;

comment_st:
        COMMENT {$$ = mknode1("#comment");} comment_st
        | {$$=mknode1("#");}
        ;

statements:
        statement statements {$$ = mknode("#stmts",(struct node*[]){$1,$2,NULL});}
        | {$$=mknode1("#");}
        ;

vars: 
        var_st vars {$$ = mknode("#vars",(struct node*[]){$1,$2,NULL});}
        | {$$=mknode1("#");}
        ;

statement:
        if_st {$$ = mknode("#",(struct node*[]){$1,NULL});}
        |do_st {$$ = mknode("#",(struct node*[]){$1,NULL});}
        |while_st {$$ = mknode("#",(struct node*[]){$1,NULL});}
        |for_st {$$ = mknode("#",(struct node*[]){$1,NULL});}
        |assignment_st ';' {$$ = mknode("#",(struct node*[]){$1,NULL});}
        |func_call ';' {$$ = mknode("#",(struct node*[]){$1,nl(),NULL});}
        |COMMENT {$$ = mknode1("#");printf("comment...\n");}
        |new_block{
                $$ = mknode("#",(struct node*[]){mknode1("(BLOCK"),nl(),
                mknode("",(struct node*[]){$1,NULL})
                ,mknode1(")"),nl(),NULL});
                $$->scope = $1->scope;
        }
        ;

statement_block:
        statement {$$ = mknode("#",(struct node*[]){$1,NULL});}
        |return_st {$$ = mknode("#",(struct node*[]){$1,NULL});}

new_block: 
        '{' vars statements return_st'}'{
			$$ = mknode("#",(struct node*[]){$2,$3,$4,NULL});
            $$->scope = newScope();
            add_vars_to_scope($2, $$->scope);
            pushScope(stack,$$->scope);
        }
        |'{' vars statements'}'{
            $$ = mknode("#",(struct node*[]){$2,$3,NULL});
            $$->scope = newScope();
            add_vars_to_scope($2, $$->scope);
            pushScope(stack,$$->scope);
        }
        ;

if_st:
        IF '(' exp ')' statement_block %prec non_else {
                struct node* temp = mknode("",(struct node*[]){$3,$5,NULL});
                $$ = mknode("#",(struct node*[]){mknode1("(IF"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                }
        |IF '(' exp ')' statement_block ELSE statement_block {
                struct node* temp = mknode("",(struct node*[]){$3,$5,$7,NULL});
                $$ = mknode("#",(struct node*[]){mknode1("(IF-ELSE"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
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
        }
        ;

assignment_st:
        lhs '=' exp {
                struct node* expTemp = mknode("",(struct node*[]){$3,NULL});
                $$ = mknode("#",(struct node*[]){mknode1("(="),$1,nl(),expTemp,mknode1(")"),nl(),NULL});
                }
        ;

lhs:
        ID {$$ = mknode1($1->token);}
        |ID '[' exp ']' {$$ = mknode("#",(struct node*[]){mknode1($1->token),mknode1("["),$3,mknode1("]"),NULL});}
        |'*' ID {$$ = mknode("#",(struct node*[]){mknode1("*"),mknode1($2->token),NULL});}
        ;

value:
    STRING_VALUE {$$ = mknode1($1->token);}
    | CHAR_VALUE {$$ = mknode1($1->token);}
    | TRUE_ {$$ = mknode1("TRUE");}
    | FALSE_ {$$ = mknode1("FALSE");}
    | NULL_ {$$ = mknode1("NULL");}
    | HEX_VALUE {$$ = mknode1($1->token);}
    | DIGITS_VALUE {$$ = mknode1($1->token);}
    | REAL_VALUE {$$ = mknode1($1->token);}
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
        ID '[' exp ']' {$$ = mknode("#",(struct node*[]){mknode1($1->token),mknode1("["),$3,mknode1("]"),NULL});}
        |assignment_st {$$ = mknode("#ass_in_str",(struct node*[]){$1,NULL});}
        ;

func_call:
        ID '(' exp_list ')' {$$ = mknode("#",(struct node*[]){mknode1("function call "),mknode1($1->token),mknode1("("),$3,mknode1(")"),NULL});}
        ;

exp_list: 
        exp {$$ = mknode("#",(struct node*[]){$1,NULL});}
        | exp ',' exp_list {$$ = mknode("#",(struct node*[]){$1,mknode1(","),$3,NULL});}
        | {$$=mknode1("#");}
        ;

exp:		
          exp '+' exp {$$ = expNode("( +",$1,$3);}    			
        | exp '-' exp {$$ = expNode("( -",$1,$3);}      				
        | exp '*' exp {$$ = expNode("( *",$1,$3);}							
        | exp '/' exp {$$ = expNode("( /",$1,$3);}													
        | exp EQEQ exp {$$ = expNode("( ==",$1,$3);}							
        | exp NOT_EQ exp {$$ = expNode("( !=",$1,$3);}							
        | exp '<' exp {$$ = expNode("( <",$1,$3);}									
        | exp SMALL_EQ exp {$$ = expNode("( <=",$1,$3);}								
        | exp '>' exp {$$ = expNode("( >",$1,$3);}								
        | exp BIG_EQ exp {$$ = expNode("( >=",$1,$3);}					
        | exp OR exp {$$ = expNode("( ||",$1,$3);}				
        | exp AND exp {$$ = expNode("( &&",$1,$3);}												
        | '!' exp {$$ = mknode("#",(struct node*[]){mknode1("!"),nl(),$2,NULL});} 								
        | ID {$$ = mknode1($1->token);}											
        | func_call {$$ = mknode("#",(struct node*[]){$1,NULL});}	  							
        | '|' ID '|' {$$ = mknode("#",(struct node*[]){mknode1("lenOf("),mknode1($2->token),mknode1(")"),NULL});}	 									
        | '(' exp ')' {$$ = $2;}//mknode("#",(struct node*[]){mknode1("("),$2,mknode1(")"),NULL});}																
        | '&' ID {$$ = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1($2->token),mknode1(")"),NULL});}	  											
        | '&' ID '[' exp ']' {$$ = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1($2->token),mknode1("["),$4,mknode1("]"),NULL});}
        | '*' ID {$$ = mknode("#",(struct node*[]){mknode1("dereference("),mknode1($2->token),mknode1(")"),NULL});}
        |value {$$ = mknode("#",(struct node*[]){$1,NULL});}
        | '-' exp {$$ = mknode("#",(struct node*[]){mknode1("-"),$2,NULL});}
        | '+' exp {$$ = mknode("#",(struct node*[]){mknode1("+"),$2,NULL});}
        ;

 
%%

#include "lex.yy.c"
int main(){
        stack = newScopeStack();
        global_scope = newScope();
        yyparse();
        struct node* temp = mknode("",(struct node*[]){mknode1("(CODE"),nl(),head,mknode1(")"),nl(),NULL});
        printf("printing tree\n");
        printtree(temp,0);
        printf("done printing tree\n");
        /* semanticsCheck(temp); */
}

int yyerror(char* e){
        int yydebug = 1;
        fflush(stdout);
        fprintf(stderr,"Error %s at Line %d\n",e,yylineno);
        fprintf(stderr,"%s Rejected\n",yytext);
        return 0;
}