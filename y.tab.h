/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ARGS = 258,                    /* ARGS  */
    TRUE_ = 259,                   /* TRUE_  */
    FALSE_ = 260,                  /* FALSE_  */
    MAIN = 261,                    /* MAIN  */
    VOID = 262,                    /* VOID  */
    NULL_ = 263,                   /* NULL_  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    FOR = 266,                     /* FOR  */
    WHILE = 267,                   /* WHILE  */
    DO = 268,                      /* DO  */
    FUNC = 269,                    /* FUNC  */
    RETURN = 270,                  /* RETURN  */
    INT = 271,                     /* INT  */
    INT_P = 272,                   /* INT_P  */
    CHAR = 273,                    /* CHAR  */
    CHAR_P = 274,                  /* CHAR_P  */
    REAL = 275,                    /* REAL  */
    REAL_P = 276,                  /* REAL_P  */
    BOOL = 277,                    /* BOOL  */
    VAR = 278,                     /* VAR  */
    STRING = 279,                  /* STRING  */
    EQEQ = 280,                    /* EQEQ  */
    SMALL_EQ = 281,                /* SMALL_EQ  */
    BIG_EQ = 282,                  /* BIG_EQ  */
    NOT_EQ = 283,                  /* NOT_EQ  */
    OR = 284,                      /* OR  */
    AND = 285,                     /* AND  */
    COMMENT = 286,                 /* COMMENT  */
    ID = 287,                      /* ID  */
    DIGITS_VALUE = 288,            /* DIGITS_VALUE  */
    HEX_VALUE = 289,               /* HEX_VALUE  */
    REAL_VALUE = 290,              /* REAL_VALUE  */
    STRING_VALUE = 291,            /* STRING_VALUE  */
    CHAR_VALUE = 292,              /* CHAR_VALUE  */
    non_else = 293                 /* non_else  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ARGS 258
#define TRUE_ 259
#define FALSE_ 260
#define MAIN 261
#define VOID 262
#define NULL_ 263
#define IF 264
#define ELSE 265
#define FOR 266
#define WHILE 267
#define DO 268
#define FUNC 269
#define RETURN 270
#define INT 271
#define INT_P 272
#define CHAR 273
#define CHAR_P 274
#define REAL 275
#define REAL_P 276
#define BOOL 277
#define VAR 278
#define STRING 279
#define EQEQ 280
#define SMALL_EQ 281
#define BIG_EQ 282
#define NOT_EQ 283
#define OR 284
#define AND 285
#define COMMENT 286
#define ID 287
#define DIGITS_VALUE 288
#define HEX_VALUE 289
#define REAL_VALUE 290
#define STRING_VALUE 291
#define CHAR_VALUE 292
#define non_else 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
