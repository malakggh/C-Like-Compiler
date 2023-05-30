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
    VOID = 261,                    /* VOID  */
    NULL_ = 262,                   /* NULL_  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    FOR = 265,                     /* FOR  */
    WHILE = 266,                   /* WHILE  */
    DO = 267,                      /* DO  */
    FUNC = 268,                    /* FUNC  */
    RETURN = 269,                  /* RETURN  */
    INT = 270,                     /* INT  */
    INT_P = 271,                   /* INT_P  */
    CHAR = 272,                    /* CHAR  */
    CHAR_P = 273,                  /* CHAR_P  */
    REAL = 274,                    /* REAL  */
    REAL_P = 275,                  /* REAL_P  */
    BOOL = 276,                    /* BOOL  */
    VAR = 277,                     /* VAR  */
    STRING = 278,                  /* STRING  */
    EQEQ = 279,                    /* EQEQ  */
    SMALL_EQ = 280,                /* SMALL_EQ  */
    BIG_EQ = 281,                  /* BIG_EQ  */
    NOT_EQ = 282,                  /* NOT_EQ  */
    OR = 283,                      /* OR  */
    AND = 284,                     /* AND  */
    COMMENT = 285,                 /* COMMENT  */
    ID = 286,                      /* ID  */
    DIGITS_VALUE = 287,            /* DIGITS_VALUE  */
    HEX_VALUE = 288,               /* HEX_VALUE  */
    REAL_VALUE = 289,              /* REAL_VALUE  */
    STRING_VALUE = 290,            /* STRING_VALUE  */
    CHAR_VALUE = 291,              /* CHAR_VALUE  */
    non_else = 292                 /* non_else  */
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
#define VOID 261
#define NULL_ 262
#define IF 263
#define ELSE 264
#define FOR 265
#define WHILE 266
#define DO 267
#define FUNC 268
#define RETURN 269
#define INT 270
#define INT_P 271
#define CHAR 272
#define CHAR_P 273
#define REAL 274
#define REAL_P 275
#define BOOL 276
#define VAR 277
#define STRING 278
#define EQEQ 279
#define SMALL_EQ 280
#define BIG_EQ 281
#define NOT_EQ 282
#define OR 283
#define AND 284
#define COMMENT 285
#define ID 286
#define DIGITS_VALUE 287
#define HEX_VALUE 288
#define REAL_VALUE 289
#define STRING_VALUE 290
#define CHAR_VALUE 291
#define non_else 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
