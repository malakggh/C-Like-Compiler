%{
        #include <stdio.h>
        #include <string.h>
        #include <stdlib.h>
        int yyerror(char* e);
        int yylex();
        typedef struct node {
                char* token;
                struct node** children;
                int child_num;
        } node;
        #define YYSTYPE node* 
        node* mknode(char* token, node** children);
        node* mknode1(char* token);
        node* nl(){return mknode1("\n");};
        node* expNode(char* token,node* first,node* second){
                return mknode("#",(node*[]){
                mknode1(token),nl(),
                mknode("",(node*[]){first,NULL}),nl(),
                mknode("",(node*[]){second,NULL}),nl(),
                mknode1(")"),nl(),NULL});
        }
        struct node* head;
        void printtree(node *tree, int shift);
        char* plusStr(char* str1,char* str2);
        char* shifts(int n);
        int indexOf(char* str, char chr);
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
                        mknode1(plusStr($2->token,"\n")),
                        mknode1("(ARGS\n"), parTemp, mknode1(")\n"),
                        mknode1("(RET "), mknode1($7->token), mknode1(")\n"),
                        mknode1("(BODY\n"), blockTemp, mknode1(")\n"),
                        NULL});
                
                $$ = mknode("",(node*[]){mknode1("(FUNC\n"),temp,mknode1(")\n"),NULL});
        }
//      1    2   3  4           5   6  7     8  9     10
        |FUNC ID '(' parameters ')' ':' VOID '{' block '}'
        {
                struct node* parTemp = mknode("",(node*[]){$4,NULL});
                struct node* blockTemp = mknode("",(node*[]){$9,NULL});
                struct node* temp = mknode("",(node*[]){
                        mknode1(plusStr($2->token,"\n")),
                        mknode1("(ARGS\n"), parTemp, mknode1(")\n"),
                        mknode1("(RET VOID)\n"),
                        mknode1("(BODY\n"), blockTemp, mknode1(")\n"),
                        NULL});
                
                $$ = mknode("",(node*[]){mknode1("(FUNC\n"),temp,mknode1(")\n"),NULL});
        }
        ;


return_st:
        RETURN exp ';' {
                $$ = mknode("#",(node*[]){mknode1("(RET "),$2,mknode1(")"),nl(),NULL});
        }
        ;

type:
        INT {$$ = mknode1("INT");}
        |REAL {$$ = mknode1("REAL");}
        |CHAR {$$ = mknode1("CHAR");}
        |BOOL {$$ = mknode1("BOOL");}
        |INT_P {$$ = mknode1("INT*");}
        |REAL_P {$$ = mknode1("REAL*");}
        |CHAR_P {$$ = mknode1("CHAR*");}
        |STRING {$$ = mknode1("STRING");}
        ;

parameters:
        ARGS args_var {$$ = mknode("#",(node*[]){mknode1("("),$2,nl(),NULL});}
        |ARGS args_var ';' parameters {$$ = mknode("#",(node*[]){mknode1("("),$2,nl(),$4,NULL});}
        | {$$ = mknode("#",(node*[]){mknode1("NONE"),nl(),NULL});}
        ;

args_var:
        ID ':' type {$$ = mknode("#",(node*[]){mknode1($1->token),mknode1(" "),$3,mknode1(")"),NULL});}
        |ID ',' args_var {$$ = mknode("#",(node*[]){mknode1($1->token),mknode1(" "),$3,NULL});}
        ;

block: code vars statements{
                $$ = mknode("#",(node*[]){$1,$2,$3,NULL});
        }
        ;

statements:
        statement statements {$$ = mknode("#",(node*[]){$1,$2,NULL});}
        | {$$=mknode1("#");}
        ;

vars: 
        var_st vars {$$ = mknode("#",(node*[]){$1,$2,NULL});}
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

new_block: 
        '{' vars statements '}'{
                $$ = mknode("#",(node*[]){$2,$3,NULL});
        }
        ;

if_st:
        IF '(' exp ')' statement %prec non_else {
                struct node* temp = mknode("",(node*[]){$3,$5,NULL});
                $$ = mknode("#",(node*[]){mknode1("(IF"),nl(),temp,nl(),mknode1(")\n"),NULL});
                }
        |IF '(' exp ')' statement ELSE statement {
                struct node* temp = mknode("",(node*[]){$3,$5,$7,NULL});
                $$ = mknode("#",(node*[]){mknode1("(IF-ELSE"),nl(),temp,nl(),mknode1(")\n"),NULL});
                }
        ;

do_st:
        DO statement WHILE '(' exp ')' ';' {
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
        WHILE '(' exp ')' statement {
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
        FOR '(' assignment_st ';' exp ';' assignment_st ')' statement {
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
                $$ = mknode("#",(node*[]){mknode1("(="),$1,nl(),expTemp,mknode1(")\n"),NULL});
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
                ,mknode1(")\n"),NULL});}
        |STRING var_string_list ';' {
                $$ = mknode("#",(node*[]){mknode1("(VAR_STRING ")
                ,nl()
                ,mknode("",(node*[]){$2,NULL})
                ,nl()
                ,mknode1(")\n"),NULL});}
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
        | exp ',' exp_list {$$ = mknode("#",(node*[]){$1,mknode1(" "),$3,NULL});}
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
        | '!' exp {$$ = mknode("#",(node*[]){mknode1("!"),$2,NULL});} 								
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

int main(){
        yyparse();
        struct node* temp = mknode("",(node*[]){mknode1("(CODE\n"),head,mknode1(")\n"),NULL});
        printf("printing tree\n");
        printtree(temp,0);
        printf("done printing tree\n");
}

// Funcs

node* mknode(char* token, node** children) {
    char* newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr, token);
    node* newnode = (node*)malloc(sizeof(node));
    newnode->token = newstr;

    int len = 0;
    while(children[len]!=NULL)
        len++;
    newnode->child_num = len;

    node** temp = (node**)malloc(sizeof(node*) * len);
    for(int i=0; i<len; i++){
        temp[i] = children[i];
    }
    newnode->children = temp;

    /* printf("for token: %s, childnum= %d",newnode->token,newnode->child_num); */
    return newnode;
}
node* mknode1(char* token) {
    char* newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr, token);
    node* newnode = (node*)malloc(sizeof(node));
    newnode->token = newstr;
    newnode->children = NULL;
    newnode->child_num = 0;
    return newnode;
}

int hasNewLine = 1;

void printtree(node* tree, int shift) {
    if (tree == NULL) {
        return;
    }
    if (!(tree->token == NULL || strcmp(tree->token,"")==0)){
        if (strcmp(tree->token,"#")!=0)
                printf("%s%s",shifts((shift)*4),tree->token);
    }

    for (int i = 0; i < tree->child_num; i++) {
        if (strcmp(tree->children[i]->token,"#")==0){
                if (hasNewLine == 1)
                        printtree(tree->children[i],shift);//zay el loo7 flatter()
                else
                        printtree(tree->children[i],0);
                continue;
        }
        if (!(tree->children[i]->token == NULL || strcmp(tree->children[i]->token,"")==0)){
                if (indexOf(tree->children[i]->token,'\n')!=-1){
                        if (hasNewLine == 0){
                                hasNewLine = 1;
                                printtree(tree->children[i],0);
                                continue;
                        }else
                                hasNewLine = 1;
                }else{
                        if (hasNewLine == 0)
                                hasNewLine = 0;
                        else{
                                hasNewLine = 0;
                                printtree(tree->children[i],shift+1);
                                continue;
                        }
                }
                        

                if (hasNewLine == 1)
                        printtree(tree->children[i],shift+1);
                else
                        printtree(tree->children[i],0);
        }else{
                if (hasNewLine == 1)
                        printtree(tree->children[i],shift+1);//zay el loo7 flatter()
                else
                        printtree(tree->children[i],0);
        }
    }
}

char* shifts(int n){
        if (n<=0){
                char* temp = malloc(1);
                temp[0]='\0';
                return temp;
        }
        char* temp = malloc(n+1);
        for(int i=0; i<n; i++){
                temp[i] = ' ';
        }
        temp[n]='\0';
        return temp;
}

char* plusStr(char* str1,char* str2){
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        char* result = (char*)malloc(len1 + len2 + 1);
        strcpy(result, str1);
        strcpy(result + len1, str2);
        return result;
}

int indexOf(char* str, char chr) {
    char* result = strchr(str, chr);
    if (result == NULL) {
        return -1;
    } else {
        return result - str;
    }
}

int yyerror(char* e){
        int yydebug = 1;
        fflush(stdout);
        fprintf(stderr,"Error %s at Line %d\n",e,yylineno);
        fprintf(stderr,"%s Rejected\n",yytext);
        return 0;
}