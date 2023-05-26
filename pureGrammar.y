

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
program: code;

code: func_or_prod code|;

func_or_prod: 
        FUNC ID '(' parameters ')' ':' type '{' block return_st '}' 
        |FUNC ID '(' parameters ')' ':' VOID '{' block '}'
        ;

return_st: RETURN exp ';';

type: INT|REAL|CHAR|BOOL|INT_P|REAL_P|CHAR_P|STRING;

parameters:
        ARGS args_var
        |ARGS args_var ';' parameters
        |
        ;

args_var:
        ID ':' type
        |ID ',' args_var
        ;

block: code vars statements;

statements: statement statements;

vars: var_st vars|;

statement: if_st|do_st|while_st|for_st|assignment_st ';'|func_call ';'|COMMENT|new_block;

new_block: '{' vars statements '}';

if_st:
        IF '(' exp ')' statement %prec non_else 
        |IF '(' exp ')' statement ELSE statement 
        ;

do_st:
        DO statement WHILE '(' exp ')' ';'
        ;

while_st:
        WHILE '(' exp ')' statement
        ;

for_st:
        FOR '(' assignment_st ';' exp ';' assignment_st ')' statement
        ;

assignment_st:
        lhs '=' exp 
        ;

lhs:
        ID
        |ID '[' exp ']'
        |'*'
        ;

value:
    STRING_VALUE| CHAR_VALUE| TRUE_| FALSE_| NULL_| HEX_VALUE| DIGITS_VALUE| REAL_VALUE ;

var_st:
        VAR var_list ';'
        |STRING var_string_list ';'
        ;

var_list:
        var_op ':' type
        |var_op ',' var_list
        ;

var_op:
        ID 
        |assignment_st
        ;

var_string_list:
        var_string_opt 
        |var_string_opt ',' var_string_list 
        ;

var_string_opt:
        ID '[' exp ']' 
        |assignment_st 
        ;

func_call: ID '(' exp_list ')';

exp_list: exp | exp ',' exp_list |;

exp:		
          exp '+' exp     			
        | exp '-' exp       				
        | exp '*' exp 							
        | exp '/' exp 													
        | exp EQEQ exp 							
        | exp NOT_EQ exp 							
        | exp '<' exp 									
        | exp SMALL_EQ exp 								
        | exp '>' exp 								
        | exp BIG_EQ exp 					
        | exp OR exp 				
        | exp AND exp 												
        | '!' exp							
        | ID										
        | func_call   							
        | '|' ID '|' 								
        | '(' exp ')'															
        | '&' ID 						
        | '&' ID 
        | '*' ID 
        |value 
        | '-' exp 
        | '+' exp 
        ;

 
%%
