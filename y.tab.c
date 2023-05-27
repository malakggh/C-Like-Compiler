/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 87 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ARGS = 3,                       /* ARGS  */
  YYSYMBOL_TRUE_ = 4,                      /* TRUE_  */
  YYSYMBOL_FALSE_ = 5,                     /* FALSE_  */
  YYSYMBOL_MAIN = 6,                       /* MAIN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_NULL_ = 8,                      /* NULL_  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_DO = 13,                        /* DO  */
  YYSYMBOL_FUNC = 14,                      /* FUNC  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_INT_P = 17,                     /* INT_P  */
  YYSYMBOL_CHAR = 18,                      /* CHAR  */
  YYSYMBOL_CHAR_P = 19,                    /* CHAR_P  */
  YYSYMBOL_REAL = 20,                      /* REAL  */
  YYSYMBOL_REAL_P = 21,                    /* REAL_P  */
  YYSYMBOL_BOOL = 22,                      /* BOOL  */
  YYSYMBOL_VAR = 23,                       /* VAR  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_EQEQ = 25,                      /* EQEQ  */
  YYSYMBOL_SMALL_EQ = 26,                  /* SMALL_EQ  */
  YYSYMBOL_BIG_EQ = 27,                    /* BIG_EQ  */
  YYSYMBOL_NOT_EQ = 28,                    /* NOT_EQ  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_COMMENT = 31,                   /* COMMENT  */
  YYSYMBOL_ID = 32,                        /* ID  */
  YYSYMBOL_DIGITS_VALUE = 33,              /* DIGITS_VALUE  */
  YYSYMBOL_HEX_VALUE = 34,                 /* HEX_VALUE  */
  YYSYMBOL_REAL_VALUE = 35,                /* REAL_VALUE  */
  YYSYMBOL_STRING_VALUE = 36,              /* STRING_VALUE  */
  YYSYMBOL_CHAR_VALUE = 37,                /* CHAR_VALUE  */
  YYSYMBOL_38_ = 38,                       /* '+'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '>'  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '!'  */
  YYSYMBOL_47_ = 47,                       /* '&'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_non_else = 49,                  /* non_else  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_code_global = 60,               /* code_global  */
  YYSYMBOL_61_1 = 61,                      /* @1  */
  YYSYMBOL_code = 62,                      /* code  */
  YYSYMBOL_func_or_prod = 63,              /* func_or_prod  */
  YYSYMBOL_return_st = 64,                 /* return_st  */
  YYSYMBOL_type = 65,                      /* type  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_args_var = 67,                  /* args_var  */
  YYSYMBOL_block = 68,                     /* block  */
  YYSYMBOL_comment_st = 69,                /* comment_st  */
  YYSYMBOL_70_2 = 70,                      /* @2  */
  YYSYMBOL_statements = 71,                /* statements  */
  YYSYMBOL_vars = 72,                      /* vars  */
  YYSYMBOL_statement = 73,                 /* statement  */
  YYSYMBOL_statement_block = 74,           /* statement_block  */
  YYSYMBOL_new_block = 75,                 /* new_block  */
  YYSYMBOL_if_st = 76,                     /* if_st  */
  YYSYMBOL_do_st = 77,                     /* do_st  */
  YYSYMBOL_while_st = 78,                  /* while_st  */
  YYSYMBOL_for_st = 79,                    /* for_st  */
  YYSYMBOL_assignment_st = 80,             /* assignment_st  */
  YYSYMBOL_lhs = 81,                       /* lhs  */
  YYSYMBOL_value = 82,                     /* value  */
  YYSYMBOL_var_st = 83,                    /* var_st  */
  YYSYMBOL_var_list = 84,                  /* var_list  */
  YYSYMBOL_var_op = 85,                    /* var_op  */
  YYSYMBOL_var_string_list = 86,           /* var_string_list  */
  YYSYMBOL_var_string_opt = 87,            /* var_string_opt  */
  YYSYMBOL_func_call = 88,                 /* func_call  */
  YYSYMBOL_exp_list = 89,                  /* exp_list  */
  YYSYMBOL_exp = 90                        /* exp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,     2,    47,     2,
      50,    51,    40,    38,    45,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    44,
      42,    48,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    57,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    34,    34,    38,    38,    57,    61,    62,    67,   102,
     119,   123,   124,   125,   126,   127,   128,   129,   130,   135,
     136,   137,   143,   144,   147,   157,   157,   158,   162,   163,
     167,   168,   172,   173,   174,   175,   176,   177,   178,   179,
     188,   189,   192,   200,   212,   216,   223,   246,   268,   292,
     305,   310,   315,   323,   324,   325,   326,   327,   328,   329,
     330,   334,   344,   356,   357,   361,   362,   366,   367,   371,
     372,   376,   389,   390,   391,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   413,   418,
     424,   429,   430,   435,   442,   447,   451,   457
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ARGS", "TRUE_",
  "FALSE_", "MAIN", "VOID", "NULL_", "IF", "ELSE", "FOR", "WHILE", "DO",
  "FUNC", "RETURN", "INT", "INT_P", "CHAR", "CHAR_P", "REAL", "REAL_P",
  "BOOL", "VAR", "STRING", "EQEQ", "SMALL_EQ", "BIG_EQ", "NOT_EQ", "OR",
  "AND", "COMMENT", "ID", "DIGITS_VALUE", "HEX_VALUE", "REAL_VALUE",
  "STRING_VALUE", "CHAR_VALUE", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'",
  "';'", "','", "'!'", "'&'", "'='", "non_else", "'('", "')'", "':'",
  "'{'", "'}'", "'['", "']'", "'|'", "$accept", "program", "code_global",
  "@1", "code", "func_or_prod", "return_st", "type", "parameters",
  "args_var", "block", "comment_st", "@2", "statements", "vars",
  "statement", "statement_block", "new_block", "if_st", "do_st",
  "while_st", "for_st", "assignment_st", "lhs", "value", "var_st",
  "var_list", "var_op", "var_string_list", "var_string_opt", "func_call",
  "exp_list", "exp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-158)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,     6,    42,  -158,  -158,    -6,  -158,     5,    45,  -158,
      19,    10,   -28,    21,    28,    19,    85,    45,    38,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
      30,    34,    58,    58,  -158,    37,     5,    78,    58,  -158,
      40,     5,   112,    60,  -158,   -14,   -10,   144,    40,  -158,
    -158,  -158,  -158,    65,  -158,  -158,  -158,  -158,  -158,   112,
     112,    90,   112,    91,   112,    93,  -158,  -158,   295,  -158,
     -20,    95,  -158,    73,    84,    -2,    74,  -158,    86,    94,
      81,    88,    92,     0,  -158,   -16,    40,  -158,   144,  -158,
    -158,  -158,  -158,  -158,    96,   110,  -158,   112,   328,   328,
    -158,  -158,    79,   198,   103,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,  -158,   112,  -158,
     112,  -158,   -14,    85,   112,  -158,   -10,   112,    -3,   112,
    -158,  -158,   124,   144,  -158,  -158,  -158,   113,   274,   112,
    -158,  -158,    89,    89,    89,    89,  -158,  -158,   328,   328,
      69,    69,    89,    89,   152,   322,  -158,  -158,   173,  -158,
     217,   106,   119,   236,   115,    -5,  -158,   112,   192,  -158,
     118,     0,   112,     0,   112,  -158,   114,  -158,  -158,   157,
     302,  -158,   255,  -158,     0,    -3,   126,  -158,   120,  -158,
       0,  -158
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     2,     3,     0,     1,     5,    21,     4,
       0,     0,     0,    19,     0,     0,     0,    21,     0,    23,
      11,    15,    13,    17,    12,    16,    14,    18,    22,    20,
       0,     0,    27,    27,    25,     0,     7,     0,    27,     9,
      31,     7,     0,     0,    26,     0,     0,    29,    31,     6,
      55,    56,    57,    88,    59,    58,    60,    53,    54,     0,
       0,     0,     0,     0,     0,     0,    95,    89,     0,     8,
      65,     0,    66,     0,     0,     0,    50,    70,     0,    67,
       0,     0,     0,     0,    38,    50,    31,    24,    29,    39,
      32,    33,    34,    35,     0,     0,    30,    74,    97,    96,
      94,    87,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,    52,
       0,    61,     0,     0,     0,    62,     0,     0,     0,     0,
      41,    40,     0,    29,    28,    36,    37,     0,    72,     0,
      91,    90,    79,    82,    84,    80,    85,    86,    75,    76,
      77,    78,    81,    83,     0,    49,    64,    63,     0,    68,
       0,    50,     0,     0,     0,     0,    71,    74,     0,    51,
      69,     0,     0,     0,     0,    43,     0,    73,    93,    44,
       0,    47,     0,    42,     0,     0,     0,    45,     0,    46,
       0,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,   165,  -158,   132,    72,   -33,   -13,   166,   159,
     153,   147,  -158,   -81,   -40,   -41,  -157,  -158,  -158,  -158,
    -158,  -158,   -44,  -158,  -158,  -158,    66,  -158,    61,  -158,
     -47,    22,   -39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,    40,     4,   130,    28,    11,    13,
      35,    36,    38,    87,    47,   131,   132,    89,    90,    91,
      92,    93,    94,    73,    66,    48,    74,    75,    78,    79,
      67,   137,   138
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    72,    77,    68,    43,    31,    88,   134,    96,    80,
      42,    81,    82,    83,   179,    42,   181,    15,    70,     1,
      98,    99,    76,   101,    16,   103,    71,   187,   -50,   161,
      71,    84,    85,   191,    97,   118,    95,    71,     5,   118,
      71,    95,     6,   122,     8,    30,   133,    88,    10,   175,
     123,    12,   165,    86,    20,    21,    22,    23,    24,    25,
      26,    14,    27,    45,    46,    17,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    72,   154,
      18,   155,    77,    32,   162,   158,    95,    33,   160,    34,
     163,    39,    88,    42,   105,   106,   107,   108,   109,   110,
     168,    20,    21,    22,    23,    24,    25,    26,    41,    27,
     157,   115,   116,    41,    69,    97,    50,    51,   109,   110,
      52,   120,   100,   102,    95,   104,    95,   119,   121,   124,
     125,   127,   176,   180,   139,   182,   164,    95,   128,   126,
     135,   188,   129,    95,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    80,   136,    81,    82,    83,    62,    63,
     141,   118,    64,   172,   166,   174,   -51,   184,   183,    65,
     189,   190,     9,    49,    19,    84,    85,   105,   106,   107,
     108,   109,   110,    29,    71,    44,    37,   159,   156,   177,
     111,   112,   113,   114,   115,   116,     0,    86,   105,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   169,     0,
       0,   111,   112,   113,   114,   115,   116,   105,   106,   107,
     108,   109,   110,   105,   106,   107,   108,   109,   110,   170,
     111,   112,   113,   114,   115,   116,   111,   112,   113,   114,
     115,   116,   105,   106,   107,   108,   109,   110,   178,   140,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   105,   106,   107,   108,   109,   110,     0,   171,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     105,   106,   107,   108,   109,   110,     0,   173,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   105,
     106,   107,   108,   109,   110,     0,   186,     0,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,     0,   167,
     105,   106,   107,   108,   109,   110,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     111,   112,   113,   114,   115,   116,   185,   105,   106,   107,
     108,   109,   110,   105,   106,   107,   108,   109,   110,     0,
     111,   112,   113,   114,   115,   116,     0,     0,   113,   114,
     115,   116
};

static const yytype_int16 yycheck[] =
{
      47,    45,    46,    42,    37,    18,    47,    88,    48,     9,
      15,    11,    12,    13,   171,    15,   173,    45,    32,    14,
      59,    60,    32,    62,    52,    64,    40,   184,    48,    32,
      40,    31,    32,   190,    50,    55,    83,    40,    32,    55,
      40,    88,     0,    45,    50,     7,    86,    88,     3,    54,
      52,    32,   133,    53,    16,    17,    18,    19,    20,    21,
      22,    51,    24,    23,    24,    44,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   122,   118,
      52,   120,   126,    53,   128,   124,   133,    53,   127,    31,
     129,    54,   133,    15,    25,    26,    27,    28,    29,    30,
     139,    16,    17,    18,    19,    20,    21,    22,    36,    24,
     123,    42,    43,    41,    54,    50,     4,     5,    29,    30,
       8,    48,    32,    32,   171,    32,   173,    32,    44,    55,
      44,    50,   165,   172,    55,   174,    12,   184,    50,    45,
      44,   185,    50,   190,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     9,    44,    11,    12,    13,    46,    47,
      57,    55,    50,    44,    51,    50,    48,    10,    54,    57,
      44,    51,     7,    41,    15,    31,    32,    25,    26,    27,
      28,    29,    30,    17,    40,    38,    33,   126,   122,   167,
      38,    39,    40,    41,    42,    43,    -1,    53,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    38,    39,    40,    41,    42,    43,    25,    26,    27,
      28,    29,    30,    25,    26,    27,    28,    29,    30,    56,
      38,    39,    40,    41,    42,    43,    38,    39,    40,    41,
      42,    43,    25,    26,    27,    28,    29,    30,    56,    51,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    25,    26,    27,    28,    29,    30,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      25,    26,    27,    28,    29,    30,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    25,
      26,    27,    28,    29,    30,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    -1,    45,
      25,    26,    27,    28,    29,    30,    -1,    25,    26,    27,
      28,    29,    30,    38,    39,    40,    41,    42,    43,    44,
      38,    39,    40,    41,    42,    43,    44,    25,    26,    27,
      28,    29,    30,    25,    26,    27,    28,    29,    30,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    40,    41,
      42,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    59,    60,    63,    32,     0,    61,    50,    60,
       3,    66,    32,    67,    51,    45,    52,    44,    52,    67,
      16,    17,    18,    19,    20,    21,    22,    24,    65,    66,
       7,    65,    53,    53,    31,    68,    69,    68,    70,    54,
      62,    63,    15,    64,    69,    23,    24,    72,    83,    62,
       4,     5,     8,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    46,    47,    50,    57,    82,    88,    90,    54,
      32,    40,    80,    81,    84,    85,    32,    80,    86,    87,
       9,    11,    12,    13,    31,    32,    53,    71,    73,    75,
      76,    77,    78,    79,    80,    88,    72,    50,    90,    90,
      32,    90,    32,    90,    32,    25,    26,    27,    28,    29,
      30,    38,    39,    40,    41,    42,    43,    44,    55,    32,
      48,    44,    45,    52,    55,    44,    45,    50,    50,    50,
      64,    73,    74,    72,    71,    44,    44,    89,    90,    55,
      51,    57,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    84,    65,    90,    86,
      90,    32,    80,    90,    12,    71,    51,    45,    90,    56,
      56,    51,    44,    51,    50,    54,    64,    89,    56,    74,
      90,    74,    90,    54,    10,    44,    51,    74,    80,    44,
      51,    74
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    61,    60,    60,    62,    62,    63,    63,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    66,    67,    67,    68,    70,    69,    69,    71,    71,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    78,    79,    80,
      81,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     3,     0,     2,     0,    11,    10,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     0,     3,     3,     4,     0,     3,     0,     2,     0,
       2,     0,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     5,     4,     5,     7,     7,     5,     9,     3,
       1,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     1,     1,     1,     3,     4,
       1,     4,     1,     3,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       3,     3,     2,     5,     2,     1,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: code_global  */
#line 34 "parser.y"
                    {head = yyvsp[0];}
#line 1446 "y.tab.c"
    break;

  case 3: /* @1: %empty  */
#line 38 "parser.y"
                     {
                // since we don't support global variables the only thing that we can get from the child function is
                // the function name, arguments and return type
                addFunctionArrToScope(yyvsp[0]->scope->funcsArr, global_scope);
                reverseStack(stack);
                
                // nestTheStack(stack);


                printScope(global_scope,9999);
                printScopeStack(stack);
                semantics(yyvsp[0],stack);
                // printtree($1,0);
                // printSemanticOrder($1);
                // free the stack
                stack->len = 0;
        }
#line 1468 "y.tab.c"
    break;

  case 4: /* code_global: func_or_prod @1 code_global  */
#line 54 "parser.y"
                      {
                yyval = mknode("#global_scope",(struct node*[]){yyvsp[-2],yyvsp[-1],NULL});
            }
#line 1476 "y.tab.c"
    break;

  case 5: /* code_global: %empty  */
#line 57 "parser.y"
          {yyval=mknode1("#");}
#line 1482 "y.tab.c"
    break;

  case 6: /* code: func_or_prod code  */
#line 61 "parser.y"
                          {yyval = mknode("#non_global_scope",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});}
#line 1488 "y.tab.c"
    break;

  case 7: /* code: %empty  */
#line 62 "parser.y"
          {yyval=mknode1("#");}
#line 1494 "y.tab.c"
    break;

  case 8: /* func_or_prod: FUNC ID '(' parameters ')' ':' type '{' block return_st '}'  */
#line 68 "parser.y"
        {
            struct node* parTemp = mknode("",(struct node*[]){yyvsp[-7],NULL});
            struct node* blockTemp = mknode("",(struct node*[]){yyvsp[-2],yyvsp[-1],NULL});
            struct node* temp = mknode("",(struct node*[]){
                mknode1(yyvsp[-9]->token),nl(),
                mknode1("(ARGS"),nl(), parTemp, mknode1(")"),nl(),
                mknode1("(RET "), mknode1(yyvsp[-4]->token), mknode1(")"),nl(),
                mknode1("(BODY"),nl(), blockTemp, mknode1(")"),nl(),
                NULL});
            
            struct node* func = mknode("",(struct node*[]){mknode1("(FUNC"),nl(),temp,mknode1(")"),nl(),NULL});
            yyval = func;


            struct Scope* currentScope = newScope();
            struct VarArr* parametersArr = newVarArr();
            getFunctionVarArr_Scanner(parTemp, parametersArr);
            struct Function* newFunc = newFunction(yyvsp[-9]->token, yyvsp[-4]->type, parametersArr);
            appendFunctionArr(currentScope->funcsArr, newFunc);
            yyval->scope = currentScope;

            struct Scope* block_scope = newScope();
            block_scope->varArr = deepCopyVarArr(newFunc->varArr);
            block_scope->returnType = newFunc->returnType;
            // extract the vars from the block
            addVarArrToScope(yyvsp[-2]->scope->varArr, block_scope);
            addFunctionArrToScope(yyvsp[-2]->scope->funcsArr, block_scope);
            block_scope->nestedBlocks = howManyBlockIhaveInside(yyvsp[-2],0);
            block_scope->nestedFuncs = howManyFunctionsIHaveInside(yyvsp[-2],0);
            pushScope(stack, block_scope);    
            // printScopeStack(stack);

        }
#line 1532 "y.tab.c"
    break;

  case 9: /* func_or_prod: FUNC ID '(' parameters ')' ':' VOID '{' block '}'  */
#line 103 "parser.y"
        {
            node* parTemp = mknode("",(struct node*[]){yyvsp[-6],NULL});
            node* blockTemp = mknode("",(struct node*[]){yyvsp[-1],NULL});
            node* temp = mknode("",(struct node*[]){
                mknode1(yyvsp[-8]->token),nl(),
                mknode1("(ARGS"),nl(), parTemp, mknode1(")"),nl(),
                mknode1("(RET "), mknode1("VOID"), mknode1(")"),nl(),
                mknode1("(BODY"),nl(), blockTemp, mknode1(")"),nl(),
                NULL});
            
            yyval = mknode("",(struct node*[]){mknode1("(FUNC"),nl(),temp,mknode1(")"),nl(),NULL});
        }
#line 1549 "y.tab.c"
    break;

  case 10: /* return_st: RETURN exp ';'  */
#line 119 "parser.y"
                       {yyval = mknode("#",(struct node*[]){mknode1("(RET "),yyvsp[-1],mknode1(")"),nl(),NULL});}
#line 1555 "y.tab.c"
    break;

  case 11: /* type: INT  */
#line 123 "parser.y"
            {node* t = mknode1("INT"); t->type = INT_T; yyval = t;}
#line 1561 "y.tab.c"
    break;

  case 12: /* type: REAL  */
#line 124 "parser.y"
              {node* t = mknode1("REAL"); t->type = REAL_T; yyval = t;}
#line 1567 "y.tab.c"
    break;

  case 13: /* type: CHAR  */
#line 125 "parser.y"
              {node* t = mknode1("CHAR"); t->type = CHAR_T; yyval = t;}
#line 1573 "y.tab.c"
    break;

  case 14: /* type: BOOL  */
#line 126 "parser.y"
              {node* t = mknode1("BOOL"); t->type = BOOL_T; yyval = t;}
#line 1579 "y.tab.c"
    break;

  case 15: /* type: INT_P  */
#line 127 "parser.y"
               {node* t = mknode1("INT_P"); t->type = INT_P_T; yyval = t;}
#line 1585 "y.tab.c"
    break;

  case 16: /* type: REAL_P  */
#line 128 "parser.y"
                {node* t = mknode1("REAL_P"); t->type = REAL_P_T; yyval = t;}
#line 1591 "y.tab.c"
    break;

  case 17: /* type: CHAR_P  */
#line 129 "parser.y"
                {node* t = mknode1("CHAR_P"); t->type = CHAR_P_T; yyval = t;}
#line 1597 "y.tab.c"
    break;

  case 18: /* type: STRING  */
#line 130 "parser.y"
                {node* t = mknode1("STRING"); t->type = STRING_T; yyval = t;}
#line 1603 "y.tab.c"
    break;

  case 19: /* parameters: ARGS args_var  */
#line 135 "parser.y"
                      {yyval = mknode("#",(struct node*[]){mknode1("("),yyvsp[0],nl(),NULL});}
#line 1609 "y.tab.c"
    break;

  case 20: /* parameters: ARGS args_var ';' parameters  */
#line 136 "parser.y"
                                      {yyval = mknode("#",(struct node*[]){mknode1("("),yyvsp[-2],nl(),yyvsp[0],NULL});}
#line 1615 "y.tab.c"
    break;

  case 21: /* parameters: %empty  */
#line 137 "parser.y"
          {
                yyval = mknode("#",(struct node*[]){mknode1("NONE"),nl(),NULL});
          }
#line 1623 "y.tab.c"
    break;

  case 22: /* args_var: ID ':' type  */
#line 143 "parser.y"
                    {yyval = mknode("#",(struct node*[]){yyvsp[-2],mknode1(","),yyvsp[0],mknode1(")"),NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type; }
#line 1629 "y.tab.c"
    break;

  case 23: /* args_var: ID ',' args_var  */
#line 144 "parser.y"
                         {yyval = mknode("#",(struct node*[]){yyvsp[-2],mknode1(","),yyvsp[0],NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type; }
#line 1635 "y.tab.c"
    break;

  case 24: /* block: comment_st code vars statements  */
#line 147 "parser.y"
                                      {
            yyval = mknode("#",(struct node*[]){yyvsp[-2],yyvsp[-1],yyvsp[0],NULL});
            Scope* currentScope = newScope();
            add_vars_to_scope(yyvsp[-1], currentScope);
            add_functions_to_scope(yyvsp[-2], currentScope);
            yyval->scope = currentScope;
        }
#line 1647 "y.tab.c"
    break;

  case 25: /* @2: %empty  */
#line 157 "parser.y"
                {yyval = mknode1("#comment");}
#line 1653 "y.tab.c"
    break;

  case 27: /* comment_st: %empty  */
#line 158 "parser.y"
          {yyval=mknode1("#");}
#line 1659 "y.tab.c"
    break;

  case 28: /* statements: statement statements  */
#line 162 "parser.y"
                             {yyval = mknode("#stmts",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});}
#line 1665 "y.tab.c"
    break;

  case 29: /* statements: %empty  */
#line 163 "parser.y"
          {yyval=mknode1("#");}
#line 1671 "y.tab.c"
    break;

  case 30: /* vars: var_st vars  */
#line 167 "parser.y"
                    {yyval = mknode("#vars",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});}
#line 1677 "y.tab.c"
    break;

  case 31: /* vars: %empty  */
#line 168 "parser.y"
          {yyval=mknode1("#");}
#line 1683 "y.tab.c"
    break;

  case 32: /* statement: if_st  */
#line 172 "parser.y"
              {yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});}
#line 1689 "y.tab.c"
    break;

  case 33: /* statement: do_st  */
#line 173 "parser.y"
               {yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});}
#line 1695 "y.tab.c"
    break;

  case 34: /* statement: while_st  */
#line 174 "parser.y"
                  {yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});}
#line 1701 "y.tab.c"
    break;

  case 35: /* statement: for_st  */
#line 175 "parser.y"
                {yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});}
#line 1707 "y.tab.c"
    break;

  case 36: /* statement: assignment_st ';'  */
#line 176 "parser.y"
                           {yyval = mknode("#",(struct node*[]){yyvsp[-1],NULL});}
#line 1713 "y.tab.c"
    break;

  case 37: /* statement: func_call ';'  */
#line 177 "parser.y"
                       {yyval = mknode("#",(struct node*[]){yyvsp[-1],nl(),NULL});}
#line 1719 "y.tab.c"
    break;

  case 38: /* statement: COMMENT  */
#line 178 "parser.y"
                 {yyval = mknode1("#");printf("comment...\n");}
#line 1725 "y.tab.c"
    break;

  case 39: /* statement: new_block  */
#line 179 "parser.y"
                  {
                yyval = mknode("#",(struct node*[]){mknode1("(BLOCK"),nl(),
                mknode("",(struct node*[]){yyvsp[0],NULL})
                ,mknode1(")"),nl(),NULL});
                yyval->scope = yyvsp[0]->scope;
        }
#line 1736 "y.tab.c"
    break;

  case 40: /* statement_block: statement  */
#line 188 "parser.y"
                  {yyval = mknode("#statement_block",(struct node*[]){yyvsp[0],NULL});}
#line 1742 "y.tab.c"
    break;

  case 41: /* statement_block: return_st  */
#line 189 "parser.y"
                   {yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});}
#line 1748 "y.tab.c"
    break;

  case 42: /* new_block: '{' vars statements return_st '}'  */
#line 192 "parser.y"
                                        {
			yyval = mknode("#",(struct node*[]){yyvsp[-3],yyvsp[-2],yyvsp[-1],NULL});
            yyval->scope = newScope();
            add_vars_to_scope(yyvsp[-3], yyval->scope);
            yyval->scope->nestedBlocks = howManyBlockIhaveInside(yyvsp[-2],0);
            pushScope(stack,yyval->scope);
            // printScopeStack(stack);
        }
#line 1761 "y.tab.c"
    break;

  case 43: /* new_block: '{' vars statements '}'  */
#line 200 "parser.y"
                               {
            yyval = mknode("#",(struct node*[]){yyvsp[-2],yyvsp[-1],NULL});
            yyval->scope = newScope();
            add_vars_to_scope(yyvsp[-2], yyval->scope);
            yyval->scope->nestedBlocks = howManyBlockIhaveInside(yyvsp[-1],0);
            pushScope(stack,yyval->scope);
            // printScopeStack(stack);
            // printf("\nblock inside me %d\n",howManyBlockIhaveInside($3,0));
        }
#line 1775 "y.tab.c"
    break;

  case 44: /* if_st: IF '(' exp ')' statement_block  */
#line 212 "parser.y"
                                                      {
                struct node* temp = mknode("",(struct node*[]){yyvsp[-2],yyvsp[0],NULL});
                yyval = mknode("#",(struct node*[]){mknode1("(IF"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                }
#line 1784 "y.tab.c"
    break;

  case 45: /* if_st: IF '(' exp ')' statement_block ELSE statement_block  */
#line 216 "parser.y"
                                                             {
                struct node* temp = mknode("",(struct node*[]){yyvsp[-4],yyvsp[-2],yyvsp[0],NULL});
                yyval = mknode("#",(struct node*[]){mknode1("(IF-ELSE"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                }
#line 1793 "y.tab.c"
    break;

  case 46: /* do_st: DO statement_block WHILE '(' exp ')' ';'  */
#line 223 "parser.y"
                                                 {
                struct node* whileDoConds = mknode("",(struct node*[]){
                        mknode1("(DO-WHILE-INIT"),nl(),
                        mknode("",(struct node*[]){yyvsp[-2],NULL}),nl(),
                        mknode1(")"),
                        NULL});
                struct node* whileDoBlock = mknode("",(struct node*[]){
                        mknode1("(DO-WHILE-BLOCK"),nl(),
                        mknode("",(struct node*[]){yyvsp[-5],NULL}),
                        mknode1(")"),
                        NULL});
                yyval = mknode("#",(struct node*[]){
                        mknode1("(DO-WHILE"),
                        nl(),whileDoConds,
                        nl(),whileDoBlock,
                        nl(),mknode1(")"),
                        nl()
                        ,NULL});
        }
#line 1817 "y.tab.c"
    break;

  case 47: /* while_st: WHILE '(' exp ')' statement_block  */
#line 246 "parser.y"
                                          {
                struct node* whileConds = mknode("",(struct node*[]){
                        mknode1("(WHILE-INIT"),nl(),
                        mknode("",(struct node*[]){yyvsp[-2],NULL}),
                        mknode1(")"),
                        NULL});
                struct node* whileBlock = mknode("",(struct node*[]){
                        mknode1("(WHILE-BLOCK"),nl(),
                        mknode("",(struct node*[]){yyvsp[0],NULL}),
                        mknode1(")"),
                        NULL});
                yyval = mknode("#",(struct node*[]){
                        mknode1("(WHILE"),
                        nl(),whileConds,
                        nl(),whileBlock,
                        nl(),mknode1(")"),
                        nl()
                        ,NULL});
        }
#line 1841 "y.tab.c"
    break;

  case 48: /* for_st: FOR '(' assignment_st ';' exp ';' assignment_st ')' statement_block  */
#line 268 "parser.y"
                                                                            {
                struct node* forConds = mknode("",(struct node*[]){
                        mknode1("(FOR-INIT"),nl(),
                        mknode("",(struct node*[]){yyvsp[-6],NULL}),
                        mknode("",(struct node*[]){yyvsp[-4],NULL}),nl(),
                        mknode("",(struct node*[]){yyvsp[-2],NULL}),
                        mknode1(")"),
                        NULL});
                struct node* forBlock = mknode("",(struct node*[]){
                        mknode1("(FOR-BLOCK"),nl(),
                        mknode("",(struct node*[]){yyvsp[0],NULL}),nl(),
                        mknode1(")"),
                        NULL});
                yyval = mknode("#",(struct node*[]){
                        mknode1("(FOR"),
                        nl(),forConds,
                        nl(),forBlock,
                        nl(),mknode1(")"),
                        nl()
                        ,NULL});
        }
#line 1867 "y.tab.c"
    break;

  case 49: /* assignment_st: lhs '=' exp  */
#line 292 "parser.y"
                    {
            struct node* expTemp = mknode("",(struct node*[]){yyvsp[0],NULL});
            yyval = mknode("#",(struct node*[]){mknode1("(="),yyvsp[-2],nl(),expTemp,mknode1(")"),nl(),NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[-2]->use_scope->varArr, yyval->use_scope);
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
            printf("assignment_st\n");
            printScope(yyval->use_scope,8888);
            }
#line 1882 "y.tab.c"
    break;

  case 50: /* lhs: ID  */
#line 305 "parser.y"
           {
            yyval = mknode1(yyvsp[0]->token);
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 1892 "y.tab.c"
    break;

  case 51: /* lhs: ID '[' exp ']'  */
#line 310 "parser.y"
                        {
            yyval = mknode("#",(struct node*[]){mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-3]->token));
        }
#line 1902 "y.tab.c"
    break;

  case 52: /* lhs: '*' ID  */
#line 315 "parser.y"
                {
            yyval = mknode("#",(struct node*[]){mknode1("*"),mknode1(yyvsp[0]->token),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 1912 "y.tab.c"
    break;

  case 53: /* value: STRING_VALUE  */
#line 323 "parser.y"
                 {yyval = mknode1(yyvsp[0]->token);}
#line 1918 "y.tab.c"
    break;

  case 54: /* value: CHAR_VALUE  */
#line 324 "parser.y"
                 {yyval = mknode1(yyvsp[0]->token);}
#line 1924 "y.tab.c"
    break;

  case 55: /* value: TRUE_  */
#line 325 "parser.y"
            {yyval = mknode1("TRUE");}
#line 1930 "y.tab.c"
    break;

  case 56: /* value: FALSE_  */
#line 326 "parser.y"
             {yyval = mknode1("FALSE");}
#line 1936 "y.tab.c"
    break;

  case 57: /* value: NULL_  */
#line 327 "parser.y"
            {yyval = mknode1("NULL");}
#line 1942 "y.tab.c"
    break;

  case 58: /* value: HEX_VALUE  */
#line 328 "parser.y"
                {yyval = mknode1(yyvsp[0]->token);}
#line 1948 "y.tab.c"
    break;

  case 59: /* value: DIGITS_VALUE  */
#line 329 "parser.y"
                   {yyval = mknode1(yyvsp[0]->token);}
#line 1954 "y.tab.c"
    break;

  case 60: /* value: REAL_VALUE  */
#line 330 "parser.y"
                 {yyval = mknode1(yyvsp[0]->token);}
#line 1960 "y.tab.c"
    break;

  case 61: /* var_st: VAR var_list ';'  */
#line 334 "parser.y"
                         {
            yyval = mknode("#",(struct node*[]){mknode1("(VAR ")
            ,nl()
            ,mknode("",(struct node*[]){yyvsp[-1],NULL})
            ,nl()
            ,mknode1(")"),nl(),NULL});
            yyval->scope = newScope();
            get_var_list(yyvsp[-1],yyval->scope->varArr);
            
        }
#line 1975 "y.tab.c"
    break;

  case 62: /* var_st: STRING var_string_list ';'  */
#line 344 "parser.y"
                                    {
            yyval = mknode("#",(struct node*[]){mknode1("(VAR_STRING ")
            ,nl()
            ,mknode("",(struct node*[]){yyvsp[-1],NULL})
            ,nl()
            ,mknode1(")"),nl(),NULL});
            yyval->scope = newScope();
            get_var_string_list(yyvsp[-1],yyval->scope->varArr);
        }
#line 1989 "y.tab.c"
    break;

  case 63: /* var_list: var_op ':' type  */
#line 356 "parser.y"
                        {yyval = mknode("#",(struct node*[]){yyvsp[-2],nl(),mknode1("Type: "),yyvsp[0],NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type;}
#line 1995 "y.tab.c"
    break;

  case 64: /* var_list: var_op ',' var_list  */
#line 357 "parser.y"
                             {yyval = mknode("#",(struct node*[]){yyvsp[-2],nl(),yyvsp[0],NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type; }
#line 2001 "y.tab.c"
    break;

  case 65: /* var_op: ID  */
#line 361 "parser.y"
           {yyval = mknode1(yyvsp[0]->token);}
#line 2007 "y.tab.c"
    break;

  case 66: /* var_op: assignment_st  */
#line 362 "parser.y"
                       {yyval = mknode("#ass_in_var",(struct node*[]){yyvsp[0],NULL});}
#line 2013 "y.tab.c"
    break;

  case 67: /* var_string_list: var_string_opt  */
#line 366 "parser.y"
                       {yyval = mknode("#",(struct node*[]){yyvsp[0],nl(),NULL});}
#line 2019 "y.tab.c"
    break;

  case 68: /* var_string_list: var_string_opt ',' var_string_list  */
#line 367 "parser.y"
                                            {yyval = mknode("#",(struct node*[]){yyvsp[-2],nl(),yyvsp[0],NULL});}
#line 2025 "y.tab.c"
    break;

  case 69: /* var_string_opt: ID '[' exp ']'  */
#line 371 "parser.y"
                       {yyval = mknode("#",(struct node*[]){mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});}
#line 2031 "y.tab.c"
    break;

  case 70: /* var_string_opt: assignment_st  */
#line 372 "parser.y"
                       {yyval = mknode("#ass_in_str",(struct node*[]){yyvsp[0],NULL});}
#line 2037 "y.tab.c"
    break;

  case 71: /* func_call: ID '(' exp_list ')'  */
#line 376 "parser.y"
                            {
            yyval = mknode("#",(struct node*[]){mknode1("function call "),mknode1(yyvsp[-3]->token),mknode1("("),yyvsp[-1],mknode1(")"),NULL});
            yyval->use_scope = newScope();
            add_args_to_scope(yyvsp[-1], yyval->use_scope);
            appendFunctionArr(yyval->use_scope->funcsArr, newFunction(yyvsp[-3]->token,NONE_T,newVarArr()));
            // printf("func_call\n");
            // printtree_REAL($3,0);
            // printf("\n");
            // printScope($$->use_scope,1010);
        }
#line 2052 "y.tab.c"
    break;

  case 72: /* exp_list: exp  */
#line 389 "parser.y"
            {yyval = mknode("#exp_list",(struct node*[]){yyvsp[0],NULL});}
#line 2058 "y.tab.c"
    break;

  case 73: /* exp_list: exp ',' exp_list  */
#line 390 "parser.y"
                           {yyval = mknode("#exp_list",(struct node*[]){yyvsp[-2],mknode1(","),yyvsp[0],NULL});}
#line 2064 "y.tab.c"
    break;

  case 74: /* exp_list: %empty  */
#line 391 "parser.y"
          {yyval=mknode1("#");}
#line 2070 "y.tab.c"
    break;

  case 75: /* exp: exp '+' exp  */
#line 395 "parser.y"
                      {yyval = expNode("( +",yyvsp[-2],yyvsp[0]);}
#line 2076 "y.tab.c"
    break;

  case 76: /* exp: exp '-' exp  */
#line 396 "parser.y"
                      {yyval = expNode("( -",yyvsp[-2],yyvsp[0]);}
#line 2082 "y.tab.c"
    break;

  case 77: /* exp: exp '*' exp  */
#line 397 "parser.y"
                      {yyval = expNode("( *",yyvsp[-2],yyvsp[0]);}
#line 2088 "y.tab.c"
    break;

  case 78: /* exp: exp '/' exp  */
#line 398 "parser.y"
                      {yyval = expNode("( /",yyvsp[-2],yyvsp[0]);}
#line 2094 "y.tab.c"
    break;

  case 79: /* exp: exp EQEQ exp  */
#line 399 "parser.y"
                       {yyval = expNode("( ==",yyvsp[-2],yyvsp[0]);}
#line 2100 "y.tab.c"
    break;

  case 80: /* exp: exp NOT_EQ exp  */
#line 400 "parser.y"
                         {yyval = expNode("( !=",yyvsp[-2],yyvsp[0]);}
#line 2106 "y.tab.c"
    break;

  case 81: /* exp: exp '<' exp  */
#line 401 "parser.y"
                      {yyval = expNode("( <",yyvsp[-2],yyvsp[0]);}
#line 2112 "y.tab.c"
    break;

  case 82: /* exp: exp SMALL_EQ exp  */
#line 402 "parser.y"
                           {yyval = expNode("( <=",yyvsp[-2],yyvsp[0]);}
#line 2118 "y.tab.c"
    break;

  case 83: /* exp: exp '>' exp  */
#line 403 "parser.y"
                      {yyval = expNode("( >",yyvsp[-2],yyvsp[0]);}
#line 2124 "y.tab.c"
    break;

  case 84: /* exp: exp BIG_EQ exp  */
#line 404 "parser.y"
                         {yyval = expNode("( >=",yyvsp[-2],yyvsp[0]);}
#line 2130 "y.tab.c"
    break;

  case 85: /* exp: exp OR exp  */
#line 405 "parser.y"
                     {yyval = expNode("( ||",yyvsp[-2],yyvsp[0]);}
#line 2136 "y.tab.c"
    break;

  case 86: /* exp: exp AND exp  */
#line 406 "parser.y"
                      {yyval = expNode("( &&",yyvsp[-2],yyvsp[0]);}
#line 2142 "y.tab.c"
    break;

  case 87: /* exp: '!' exp  */
#line 407 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){mknode1("!"),nl(),yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2153 "y.tab.c"
    break;

  case 88: /* exp: ID  */
#line 413 "parser.y"
             {
            yyval = mknode1(yyvsp[0]->token);
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 2163 "y.tab.c"
    break;

  case 89: /* exp: func_call  */
#line 418 "parser.y"
                    {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2174 "y.tab.c"
    break;

  case 90: /* exp: '|' ID '|'  */
#line 424 "parser.y"
                     {
            yyval = mknode("#",(struct node*[]){mknode1("lenOf("),mknode1(yyvsp[-1]->token),mknode1(")"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-1]->token));
        }
#line 2184 "y.tab.c"
    break;

  case 91: /* exp: '(' exp ')'  */
#line 429 "parser.y"
                      {yyval = yyvsp[-1];}
#line 2190 "y.tab.c"
    break;

  case 92: /* exp: '&' ID  */
#line 430 "parser.y"
                 {
            yyval = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1(yyvsp[0]->token),mknode1(")"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));    
        }
#line 2200 "y.tab.c"
    break;

  case 93: /* exp: '&' ID '[' exp ']'  */
#line 435 "parser.y"
                             {
            yyval = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-3]->token));
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2212 "y.tab.c"
    break;

  case 94: /* exp: '*' ID  */
#line 442 "parser.y"
                 {
            yyval = mknode("#",(struct node*[]){mknode1("dereference("),mknode1(yyvsp[0]->token),mknode1(")"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 2222 "y.tab.c"
    break;

  case 95: /* exp: value  */
#line 447 "parser.y"
                {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = newScope();
        }
#line 2231 "y.tab.c"
    break;

  case 96: /* exp: '-' exp  */
#line 451 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){mknode1("-"),yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2242 "y.tab.c"
    break;

  case 97: /* exp: '+' exp  */
#line 457 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){mknode1("+"),yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2253 "y.tab.c"
    break;


#line 2257 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 466 "parser.y"


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
