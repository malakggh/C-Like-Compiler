%{
        // Authors:
        //         ***REMOVED*** ***REMOVED***,
        //         ***REMOVED*** ***REMOVED***,
        //         ***REMOVED*** ***REMOVED***
        #include <stdio.h>
        #include <string.h>
        #include <stdlib.h>
        int yyerror(char* e);
        int yylex();
        #include "helper.c"
        struct node* head;
        //hi from windows
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
        code {head = $1;}
        ;

code:
        func_or_prod code {
                $$ = mknode("#",(node*[]){$1,$2,NULL});
                }
        | {$$=mknode1("#");}
        ;

func_or_prod: 
//      1    2   3  4           5   6  7     8  9     10        11 
        FUNC ID '(' parameters ')' ':' type '{' block return_st '}'
        {
                struct node* parTemp = mknode("",(node*[]){$4,NULL});
                struct node* blockTemp = mknode("",(node*[]){$9,$10,NULL});
                struct node* temp = mknode("",(node*[]){
                        mknode1($2->token),nl(),
                        mknode1("(ARGS"),nl(), parTemp, mknode1(")"),nl(),
                        mknode1("(RET "), mknode1($7->token), mknode1(")"),nl(),
                        mknode1("(BODY"),nl(), blockTemp, mknode1(")"),nl(),
                        NULL});
                
                struct node* x = mknode("",(node*[]){mknode1("(FUNC"),nl(),temp,mknode1(")"),nl(),NULL});
                $$ = x;
                printtree(x,0);
                printf("---\n");
        }
//      1    2    3  4           5   6  7     8  9     10
        |FUNC ID '(' parameters ')' ':' VOID '{' block '}'
        {
                struct node* parTemp = mknode("",(node*[]){$4,NULL});
                struct node* blockTemp = mknode("",(node*[]){$9,NULL});
                struct node* temp = mknode("",(node*[]){
                        mknode1($2->token),nl(),
                        mknode1("(ARGS"),nl(), parTemp, mknode1(")"),nl(),
                        mknode1("(RET "), mknode1("VOID"), mknode1(")"),nl(),
                        mknode1("(BODY"),nl(), blockTemp, mknode1(")"),nl(),
                        NULL});
                
                $$ = mknode("",(node*[]){mknode1("(FUNC"),nl(),temp,mknode1(")"),nl(),NULL});
        }
        ;


return_st:
        RETURN exp ';' {
                $$ = mknode("#",(node*[]){mknode1("(RET "),$2,mknode1(")"),nl(),NULL});
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
        ARGS args_var {$$ = mknode("#",(node*[]){mknode1("("),$2,nl(),NULL});}
        |ARGS args_var ';' parameters {$$ = mknode("#",(node*[]){mknode1("("),$2,nl(),$4,NULL});}
        | {$$ = mknode("#",(node*[]){mknode1("NONE"),nl(),NULL});}
        ;

args_var:
        ID ':' type {$$ = mknode("#",(node*[]){$1,mknode1(","),$3,mknode1(")"),NULL});$$->type = $3->type;$1->type = $3->type; }
        |ID ',' args_var {$$ = mknode("#",(node*[]){$1,mknode1(","),$3,NULL});$$->type = $3->type;$1->type = $3->type; }
        ;

block: comment_st code vars statements{
                $$ = mknode("#blockCmtCodeVarsStmts",(node*[]){$2,$3,$4,NULL});
        }
        ;

comment_st:
        COMMENT {$$ = mknode1("#comment");} comment_st
        | {$$=mknode1("#");}
        ;

statements:
        statement statements {$$ = mknode("#stmts",(node*[]){$1,$2,NULL});}
        | {$$=mknode1("#");}
        ;

vars: 
        var_st vars {$$ = mknode("#vars",(node*[]){$1,$2,NULL});}
        | {$$=mknode1("#");}
        ;

statement:
        if_st {$$ = mknode("#",(node*[]){$1,NULL});}
        |do_st {$$ = mknode("#",(node*[]){$1,NULL});}
        |while_st {$$ = mknode("#",(node*[]){$1,NULL});}
        |for_st {$$ = mknode("#",(node*[]){$1,NULL});}
        |assignment_st ';' {$$ = mknode("#",(node*[]){$1,NULL});}
        |func_call ';' {$$ = mknode("#",(node*[]){$1,nl(),NULL});}
        |COMMENT {$$ = mknode1("#");printf("comment...\n");}
        |new_block{
                $$ = mknode("#",(node*[]){mknode1("(BLOCK"),nl(),
                mknode("",(node*[]){$1,NULL})
                ,mknode1(")"),nl(),NULL});
                }
        ;

statement_block:
        statement {$$ = mknode("#",(node*[]){$1,NULL});}
        |return_st {$$ = mknode("#",(node*[]){$1,NULL});}

new_block: 
        '{' vars statements return_st'}'{
                $$ = mknode("#",(node*[]){$2,$3,$4,NULL});
                }
        |'{' vars statements'}'{
                $$ = mknode("#",(node*[]){$2,$3,NULL});
                }
        ;

if_st:
        IF '(' exp ')' statement_block %prec non_else {
                struct node* temp = mknode("",(node*[]){$3,$5,NULL});
                $$ = mknode("#",(node*[]){mknode1("(IF"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                }
        |IF '(' exp ')' statement_block ELSE statement_block {
                struct node* temp = mknode("",(node*[]){$3,$5,$7,NULL});
                $$ = mknode("#",(node*[]){mknode1("(IF-ELSE"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                }
        ;

do_st:
        DO statement_block WHILE '(' exp ')' ';' {
                struct node* whileDoConds = mknode("",(node*[]){
                        mknode1("(DO-WHILE-INIT"),nl(),
                        mknode("",(node*[]){$5,NULL}),nl(),
                        mknode1(")"),
                        NULL});
                struct node* whileDoBlock = mknode("",(node*[]){
                        mknode1("(DO-WHILE-BLOCK"),nl(),
                        mknode("",(node*[]){$2,NULL}),
                        mknode1(")"),
                        NULL});
                $$ = mknode("#",(node*[]){
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
                struct node* whileConds = mknode("",(node*[]){
                        mknode1("(WHILE-INIT"),nl(),
                        mknode("",(node*[]){$3,NULL}),
                        mknode1(")"),
                        NULL});
                struct node* whileBlock = mknode("",(node*[]){
                        mknode1("(WHILE-BLOCK"),nl(),
                        mknode("",(node*[]){$5,NULL}),
                        mknode1(")"),
                        NULL});
                $$ = mknode("#",(node*[]){
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
                struct node* forConds = mknode("",(node*[]){
                        mknode1("(FOR-INIT"),nl(),
                        mknode("",(node*[]){$3,NULL}),
                        mknode("",(node*[]){$5,NULL}),nl(),
                        mknode("",(node*[]){$7,NULL}),
                        mknode1(")"),
                        NULL});
                struct node* forBlock = mknode("",(node*[]){
                        mknode1("(FOR-BLOCK"),nl(),
                        mknode("",(node*[]){$9,NULL}),nl(),
                        mknode1(")"),
                        NULL});
                $$ = mknode("#",(node*[]){
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
                struct node* expTemp = mknode("",(node*[]){$3,NULL});
                $$ = mknode("#",(node*[]){mknode1("(="),$1,nl(),expTemp,mknode1(")"),nl(),NULL});
                }
        ;

lhs:
        ID {$$ = mknode1($1->token);}
        |ID '[' exp ']' {$$ = mknode("#",(node*[]){mknode1($1->token),mknode1("["),$3,mknode1("]"),NULL});}
        |'*' ID {$$ = mknode("#",(node*[]){mknode1("*"),mknode1($2->token),NULL});}
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
                $$ = mknode("#",(node*[]){mknode1("(VAR ")
                ,nl()
                ,mknode("",(node*[]){$2,NULL})
                ,nl()
                ,mknode1(")"),nl(),NULL});}
        |STRING var_string_list ';' {
                $$ = mknode("#",(node*[]){mknode1("(VAR_STRING ")
                ,nl()
                ,mknode("",(node*[]){$2,NULL})
                ,nl()
                ,mknode1(")"),nl(),NULL});}
        ;

var_list:
        var_op ':' type {$$ = mknode("#",(node*[]){$1,nl(),mknode1("Type: "),$3,NULL});}
        |var_op ',' var_list {$$ = mknode("#",(node*[]){$1,nl(),$3,NULL});}
        ;

var_op:
        ID {$$ = mknode1($1->token);}
        |assignment_st {$$ = mknode("#",(node*[]){$1,NULL});}
        ;

var_string_list:
        var_string_opt {$$ = mknode("#",(node*[]){$1,nl(),NULL});}
        |var_string_opt ',' var_string_list {$$ = mknode("#",(node*[]){$1,nl(),$3,NULL});}
        ;

var_string_opt:
        ID '[' exp ']' {$$ = mknode("#",(node*[]){mknode1($1->token),mknode1("["),$3,mknode1("]"),NULL});}
        |assignment_st {$$ = mknode("#",(node*[]){$1,NULL});}
        ;

func_call:
        ID '(' exp_list ')' {$$ = mknode("#",(node*[]){mknode1("function call "),mknode1($1->token),mknode1("("),$3,mknode1(")"),NULL});}
        ;

exp_list: 
        exp {$$ = mknode("#",(node*[]){$1,NULL});}
        | exp ',' exp_list {$$ = mknode("#",(node*[]){$1,mknode1(","),$3,NULL});}
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
        | '!' exp {$$ = mknode("#",(node*[]){mknode1("!"),nl(),$2,NULL});} 								
        | ID {$$ = mknode1($1->token);}											
        | func_call {$$ = mknode("#",(node*[]){$1,NULL});}	  							
        | '|' ID '|' {$$ = mknode("#",(node*[]){mknode1("lenOf("),mknode1($2->token),mknode1(")"),NULL});}	 									
        | '(' exp ')' {$$ = $2;}//mknode("#",(node*[]){mknode1("("),$2,mknode1(")"),NULL});}																
        | '&' ID {$$ = mknode("#",(node*[]){mknode1("addressOf("),mknode1($2->token),mknode1(")"),NULL});}	  											
        | '&' ID '[' exp ']' {$$ = mknode("#",(node*[]){mknode1("addressOf("),mknode1($2->token),mknode1("["),$4,mknode1("]"),NULL});}
        | '*' ID {$$ = mknode("#",(node*[]){mknode1("dereference("),mknode1($2->token),mknode1(")"),NULL});}
        |value {$$ = mknode("#",(node*[]){$1,NULL});}
        | '-' exp {$$ = mknode("#",(node*[]){mknode1("-"),$2,NULL});}
        | '+' exp {$$ = mknode("#",(node*[]){mknode1("+"),$2,NULL});}
        ;

 
%%

#include "lex.yy.c"
ScopeStack* stack = newScopeStack();
int main(){
        printf("starting\n");
        yyparse();
        struct node* temp = mknode("",(node*[]){mknode1("(CODE"),nl(),head,mknode1(")"),nl(),NULL});
        printf("printing tree\n");
        /* printtree(temp,0); */
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