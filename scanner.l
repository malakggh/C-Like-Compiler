%{
// Authors:
// ***REMOVED*** ***REMOVED***,
// ***REMOVED*** ***REMOVED***,
// ***REMOVED*** ***REMOVED***
#include <stdio.h>
int yyerror(char *s);
int print = 0;
%}

%%
"arg->"     { if(print) printf("ARGS\n"); return ARGS; }
"true"      { if(print) printf("TRUE_\n"); return TRUE_; }
"false"     { if(print) printf("FALSE_\n"); return FALSE_; }
"main"      { if(print) printf("MAIN\n"); return MAIN; }
"void"      { if(print) printf("VOID\n"); return VOID; }
"null"      { if(print) printf("NULL_\n"); return NULL_; }
"if"        { if(print) printf("IF\n"); return IF; }
"else"      { if(print) printf("ELSE\n"); return ELSE; }
"for"       { if(print) printf("FOR\n"); return FOR; }
"while"     { if(print) printf("WHILE\n"); return WHILE; }
"do"        { if(print) printf("DO\n"); return DO; }
"function"  { if(print) printf("FUNC\n"); return FUNC; }
"return"    { if(print) printf("RETURN\n"); return RETURN; }
"int"       { if(print) printf("INT\n"); return INT; }
"int*"      { if(print) printf("INT_P\n"); return INT_P; }
"char"      { if(print) printf("CHAR\n"); return CHAR; }
"char*"     { if(print) printf("CHAR_P\n"); return CHAR_P; }
"real"      { if(print) printf("REAL\n"); return REAL; }
"real*"     { if(print) printf("REAL_P\n"); return REAL_P; }
"bool"      { if(print) printf("BOOL\n"); return BOOL; }
"var"       { if(print) printf("VAR\n"); return VAR; }
"string"    { if(print) printf("STRING\n"); return STRING; }
"=="        { if(print) printf("EQEQ\n"); return EQEQ; }
"<="        { if(print) printf("SMALL_EQ\n"); return SMALL_EQ; }
">="        { if(print) printf("BIG_EQ\n"); return BIG_EQ; }
"!="        { if(print) printf("NOT_EQ\n"); return NOT_EQ; }
"||"        { if(print) printf("OR\n"); return OR; }
"&&"        { if(print) printf("AND\n"); return AND; }
"+"         { if(print) printf("+\n"); return yytext[0]; }

"/*"([^*]*|(\*+[^/]))*"*/"  {
    // yylval = mknode1(yytext);
    if(print) printf("COMMENT\n");
    // return COMMENT;
    }

[a-zA-Z][a-zA-Z0-9_]*       {
    yylval = mknode1(yytext);
    if(print) printf("ID(%s)\n",yytext);
    return ID;
    }

[1-9][0-9]*|[0-9]      {
    yylval = mknode1(yytext);
    if(print) printf("DIGITS_VALUE(%s)\n",yytext);
    return DIGITS_VALUE;
    }

0[xX][0-9a-fA-F]+           {
    yylval = mknode1(yytext);
    if(print) printf("HEX_VALUE\n");
    return HEX_VALUE;
    }

[0-9]*"."[0-9]*        {
    yylval = mknode1(yytext);
    if(print) printf("REAL_VALUE\n");
    return REAL_VALUE;
    }

[0-9]*"."?[Ee][+-]?[0-9]+  {
    yylval = mknode1(yytext);
    if(print) printf("REAL_VALUE\n");
    return REAL_VALUE;
    }

\".*\"      {
    int len = 0;
    while(yytext[len]!='\0'){     
        len++;
    }
    int i = 0;
    while(yytext[i]!='\0'){
        if(yytext[i] == '"' && i != 0 && i != len-1)
            return(0);
        i++;
    }
    yylval = mknode1(yytext);
    if(print) printf("STRING_VALUE\n");
    return STRING_VALUE;
}

\'.\'       {
    yylval = mknode1(yytext);
    if(print) printf("CHAR_VALUE\n");
    return CHAR_VALUE;
    }

[\n] {yylineno++;}

[ \t]+ ;

.   {if(print) printf("%c\n",(char)yytext[0]);return yytext[0];}

%%

