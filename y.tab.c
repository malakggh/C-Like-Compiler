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
//     struct ScopeStack* stack = NULL;
    struct ScopeStack* test_stack = NULL;
    struct Scope* global_scope = NULL;

#line 88 "y.tab.c"

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
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_NULL_ = 7,                      /* NULL_  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_DO = 12,                        /* DO  */
  YYSYMBOL_FUNC = 13,                      /* FUNC  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_INT_P = 16,                     /* INT_P  */
  YYSYMBOL_CHAR = 17,                      /* CHAR  */
  YYSYMBOL_CHAR_P = 18,                    /* CHAR_P  */
  YYSYMBOL_REAL = 19,                      /* REAL  */
  YYSYMBOL_REAL_P = 20,                    /* REAL_P  */
  YYSYMBOL_BOOL = 21,                      /* BOOL  */
  YYSYMBOL_VAR = 22,                       /* VAR  */
  YYSYMBOL_STRING = 23,                    /* STRING  */
  YYSYMBOL_EQEQ = 24,                      /* EQEQ  */
  YYSYMBOL_SMALL_EQ = 25,                  /* SMALL_EQ  */
  YYSYMBOL_BIG_EQ = 26,                    /* BIG_EQ  */
  YYSYMBOL_NOT_EQ = 27,                    /* NOT_EQ  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_COMMENT = 30,                   /* COMMENT  */
  YYSYMBOL_ID = 31,                        /* ID  */
  YYSYMBOL_DIGITS_VALUE = 32,              /* DIGITS_VALUE  */
  YYSYMBOL_HEX_VALUE = 33,                 /* HEX_VALUE  */
  YYSYMBOL_REAL_VALUE = 34,                /* REAL_VALUE  */
  YYSYMBOL_STRING_VALUE = 35,              /* STRING_VALUE  */
  YYSYMBOL_CHAR_VALUE = 36,                /* CHAR_VALUE  */
  YYSYMBOL_37_ = 37,                       /* '<'  */
  YYSYMBOL_38_ = 38,                       /* '>'  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '!'  */
  YYSYMBOL_46_ = 46,                       /* '&'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_non_else = 48,                  /* non_else  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ':'  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* '['  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_56_ = 56,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_code_global = 59,               /* code_global  */
  YYSYMBOL_code = 60,                      /* code  */
  YYSYMBOL_func_or_prod = 61,              /* func_or_prod  */
  YYSYMBOL_return_st = 62,                 /* return_st  */
  YYSYMBOL_type = 63,                      /* type  */
  YYSYMBOL_parameters = 64,                /* parameters  */
  YYSYMBOL_args_var = 65,                  /* args_var  */
  YYSYMBOL_block = 66,                     /* block  */
  YYSYMBOL_comment_st = 67,                /* comment_st  */
  YYSYMBOL_statements = 68,                /* statements  */
  YYSYMBOL_vars = 69,                      /* vars  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_statement_block = 71,           /* statement_block  */
  YYSYMBOL_new_block = 72,                 /* new_block  */
  YYSYMBOL_if_st = 73,                     /* if_st  */
  YYSYMBOL_do_st = 74,                     /* do_st  */
  YYSYMBOL_while_st = 75,                  /* while_st  */
  YYSYMBOL_for_st = 76,                    /* for_st  */
  YYSYMBOL_assignment_st = 77,             /* assignment_st  */
  YYSYMBOL_lhs = 78,                       /* lhs  */
  YYSYMBOL_value = 79,                     /* value  */
  YYSYMBOL_var_st = 80,                    /* var_st  */
  YYSYMBOL_var_list = 81,                  /* var_list  */
  YYSYMBOL_var_op = 82,                    /* var_op  */
  YYSYMBOL_var_string_list = 83,           /* var_string_list  */
  YYSYMBOL_var_string_opt = 84,            /* var_string_opt  */
  YYSYMBOL_func_call = 85,                 /* func_call  */
  YYSYMBOL_exp_list = 86,                  /* exp_list  */
  YYSYMBOL_exp = 87                        /* exp  */
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
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
       2,     2,     2,    45,     2,     2,     2,     2,    46,     2,
      49,    50,    41,    39,    44,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    43,
      37,    47,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    56,    53,     2,     2,     2,     2,
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
      35,    36,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    36,    36,    40,    43,    47,    48,    53,   100,   140,
     149,   150,   151,   152,   153,   154,   155,   156,   161,   162,
     163,   169,   170,   173,   187,   188,   192,   193,   197,   198,
     202,   206,   210,   214,   218,   222,   226,   232,   236,   253,
     266,   282,   299,   306,   316,   342,   367,   402,   413,   418,
     423,   431,   432,   433,   434,   435,   436,   437,   438,   442,
     452,   464,   465,   469,   470,   474,   475,   479,   480,   484,
     493,   494,   495,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   519,   526,   534,   541,
     542,   549,   563,   576,   583,   590,   597
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
  "FALSE_", "VOID", "NULL_", "IF", "ELSE", "FOR", "WHILE", "DO", "FUNC",
  "RETURN", "INT", "INT_P", "CHAR", "CHAR_P", "REAL", "REAL_P", "BOOL",
  "VAR", "STRING", "EQEQ", "SMALL_EQ", "BIG_EQ", "NOT_EQ", "OR", "AND",
  "COMMENT", "ID", "DIGITS_VALUE", "HEX_VALUE", "REAL_VALUE",
  "STRING_VALUE", "CHAR_VALUE", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "';'", "','", "'!'", "'&'", "'='", "non_else", "'('", "')'", "':'",
  "'{'", "'}'", "'['", "']'", "'|'", "$accept", "program", "code_global",
  "code", "func_or_prod", "return_st", "type", "parameters", "args_var",
  "block", "comment_st", "statements", "vars", "statement",
  "statement_block", "new_block", "if_st", "do_st", "while_st", "for_st",
  "assignment_st", "lhs", "value", "var_st", "var_list", "var_op",
  "var_string_list", "var_string_opt", "func_call", "exp_list", "exp", YY_NULLPTR
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

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,     7,    45,  -158,    22,    -7,  -158,  -158,    48,    25,
       8,   -25,    23,    30,    25,   346,    48,    88,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,    32,
      36,    60,    60,    60,    39,    22,    82,  -158,  -158,    42,
      22,   116,    61,    -4,    -2,    87,    42,  -158,  -158,  -158,
    -158,     1,  -158,  -158,  -158,  -158,  -158,   116,   116,   116,
     116,    81,   116,    84,  -158,  -158,   281,  -158,   -36,    85,
    -158,    66,    76,   -20,    68,  -158,    83,    80,    86,    92,
      93,     2,  -158,     3,    42,  -158,    87,  -158,  -158,  -158,
    -158,  -158,    90,    91,  -158,   116,   116,    59,    59,  -158,
    -158,    71,   206,    74,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,  -158,   116,  -158,   116,
    -158,    -4,   346,   116,  -158,    -2,   116,    -1,   116,  -158,
    -158,   120,    87,  -158,  -158,  -158,    95,   260,   142,   116,
    -158,  -158,    21,    21,    21,    21,   314,   333,    21,    21,
      59,    59,  -158,  -158,   149,   308,  -158,  -158,   174,  -158,
     213,    89,    94,   233,   104,    -5,  -158,   116,  -158,   181,
    -158,   107,     2,   116,     2,   116,  -158,   105,  -158,  -158,
     150,   288,  -158,   240,  -158,     2,    -1,   117,  -158,   113,
    -158,     2,  -158
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     1,     3,    20,     0,
       0,     0,    18,     0,     0,     0,    20,     0,    22,    10,
      14,    12,    16,    11,    15,    13,    17,    21,    19,     0,
       0,    25,    25,    25,     0,     6,     0,    24,     8,    29,
       6,     0,     0,     0,     0,    27,    29,     5,    53,    54,
      55,    86,    57,    56,    58,    51,    52,     0,     0,     0,
       0,     0,     0,     0,    94,    87,     0,     7,    63,     0,
      64,     0,     0,     0,    48,    68,     0,    65,     0,     0,
       0,     0,    37,    48,    29,    23,    27,    36,    30,    31,
      32,    33,     0,     0,    28,    72,     0,    96,    95,    93,
      85,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,    50,     0,
      59,     0,     0,     0,    60,     0,     0,     0,     0,    39,
      38,     0,    27,    26,    34,    35,     0,    70,     0,     0,
      89,    88,    77,    80,    82,    78,    83,    84,    79,    81,
      73,    74,    75,    76,     0,    47,    62,    61,     0,    66,
       0,    48,     0,     0,     0,     0,    69,    72,    92,     0,
      49,    67,     0,     0,     0,     0,    41,     0,    71,    91,
      42,     0,    45,     0,    40,     0,     0,     0,    43,     0,
      44,     0,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,   160,   145,     9,   -33,   -12,   176,   179,   162,
     163,   -79,   -38,   -39,  -157,  -158,  -158,  -158,  -158,  -158,
     -42,  -158,  -158,  -158,    96,  -158,    70,  -158,   -45,    57,
     -37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    39,     4,   129,    27,    10,    12,    34,
      35,    85,    45,   130,   131,    87,    88,    89,    90,    91,
      92,    71,    64,    46,    72,    73,    76,    77,    65,   136,
     137
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    70,    75,    42,    66,    30,    86,   133,    94,    41,
      78,   -48,    79,    80,    81,   180,    41,   182,   117,    14,
      97,    98,    99,   100,   121,   102,    15,    68,   188,    74,
     161,   122,    82,    83,   192,     1,    93,    69,     5,    69,
      69,    93,     8,    69,    40,     6,   132,    86,   176,    40,
      95,     9,    95,   165,    84,    96,    11,   117,    13,   138,
     112,   113,   114,   115,    43,    44,    16,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    70,
     154,    17,   155,    75,    31,   162,   158,    93,    32,   160,
      33,   163,    38,    86,    29,    78,    41,    79,    80,    81,
     114,   115,   169,    19,    20,    21,    22,    23,    24,    25,
     157,    26,   101,   119,    67,   103,   118,    82,    83,   120,
      48,    49,   123,    50,   125,   139,   124,    93,    69,    93,
     141,   164,   177,   134,   135,   126,   181,   173,   183,    84,
      93,   127,   128,   117,   189,   166,    93,    51,    52,    53,
      54,    55,    56,   175,   -49,    57,    58,    59,   184,   185,
     190,    60,    61,   191,     7,    62,   104,   105,   106,   107,
     108,   109,    63,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    47,   110,   111,   112,   113,
     114,   115,    28,    18,    36,   159,    37,   168,   104,   105,
     106,   107,   108,   109,   170,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   156,   110,   111,
     112,   113,   114,   115,   178,     0,     0,     0,     0,   171,
     104,   105,   106,   107,   108,   109,   179,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     110,   111,   112,   113,   114,   115,   140,   104,   105,   106,
     107,   108,   109,   172,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   110,   111,   112,
     113,   114,   115,   174,   104,   105,   106,   107,   108,   109,
     187,     0,     0,     0,     0,     0,     0,   110,   111,   112,
     113,   114,   115,     0,   167,   104,   105,   106,   107,   108,
     109,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   110,   111,   112,   113,   114,
     115,   186,   104,   105,   106,   107,   108,   109,   104,   105,
     106,   107,     0,   109,     0,   110,   111,   112,   113,   114,
     115,   110,   111,   112,   113,   114,   115,   104,   105,   106,
     107,    19,    20,    21,    22,    23,    24,    25,     0,    26,
     110,   111,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
      45,    43,    44,    36,    41,    17,    45,    86,    46,    14,
       8,    47,    10,    11,    12,   172,    14,   174,    54,    44,
      57,    58,    59,    60,    44,    62,    51,    31,   185,    31,
      31,    51,    30,    31,   191,    13,    81,    41,    31,    41,
      41,    86,    49,    41,    35,     0,    84,    86,    53,    40,
      49,     3,    49,   132,    52,    54,    31,    54,    50,    96,
      39,    40,    41,    42,    22,    23,    43,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   121,
     117,    51,   119,   125,    52,   127,   123,   132,    52,   126,
      30,   128,    53,   132,     6,     8,    14,    10,    11,    12,
      41,    42,   139,    15,    16,    17,    18,    19,    20,    21,
     122,    23,    31,    47,    53,    31,    31,    30,    31,    43,
       4,     5,    54,     7,    44,    54,    43,   172,    41,   174,
      56,    11,   165,    43,    43,    49,   173,    43,   175,    52,
     185,    49,    49,    54,   186,    50,   191,    31,    32,    33,
      34,    35,    36,    49,    47,    39,    40,    41,    53,     9,
      43,    45,    46,    50,     4,    49,    24,    25,    26,    27,
      28,    29,    56,    24,    25,    26,    27,    28,    29,    37,
      38,    39,    40,    41,    42,    40,    37,    38,    39,    40,
      41,    42,    16,    14,    32,   125,    33,    55,    24,    25,
      26,    27,    28,    29,    55,    24,    25,    26,    27,    28,
      29,    37,    38,    39,    40,    41,    42,   121,    37,    38,
      39,    40,    41,    42,   167,    -1,    -1,    -1,    -1,    55,
      24,    25,    26,    27,    28,    29,    55,    24,    25,    26,
      27,    28,    29,    37,    38,    39,    40,    41,    42,    -1,
      37,    38,    39,    40,    41,    42,    50,    24,    25,    26,
      27,    28,    29,    50,    24,    25,    26,    27,    28,    29,
      37,    38,    39,    40,    41,    42,    -1,    37,    38,    39,
      40,    41,    42,    50,    24,    25,    26,    27,    28,    29,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    -1,    44,    24,    25,    26,    27,    28,
      29,    -1,    24,    25,    26,    27,    28,    29,    37,    38,
      39,    40,    41,    42,    43,    37,    38,    39,    40,    41,
      42,    43,    24,    25,    26,    27,    28,    29,    24,    25,
      26,    27,    -1,    29,    -1,    37,    38,    39,    40,    41,
      42,    37,    38,    39,    40,    41,    42,    24,    25,    26,
      27,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      37,    38,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    58,    59,    61,    31,     0,    59,    49,     3,
      64,    31,    65,    50,    44,    51,    43,    51,    65,    15,
      16,    17,    18,    19,    20,    21,    23,    63,    64,     6,
      63,    52,    52,    30,    66,    67,    66,    67,    53,    60,
      61,    14,    62,    22,    23,    69,    80,    60,     4,     5,
       7,    31,    32,    33,    34,    35,    36,    39,    40,    41,
      45,    46,    49,    56,    79,    85,    87,    53,    31,    41,
      77,    78,    81,    82,    31,    77,    83,    84,     8,    10,
      11,    12,    30,    31,    52,    68,    70,    72,    73,    74,
      75,    76,    77,    85,    69,    49,    54,    87,    87,    87,
      87,    31,    87,    31,    24,    25,    26,    27,    28,    29,
      37,    38,    39,    40,    41,    42,    43,    54,    31,    47,
      43,    44,    51,    54,    43,    44,    49,    49,    49,    62,
      70,    71,    69,    68,    43,    43,    86,    87,    87,    54,
      50,    56,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    81,    63,    87,    83,
      87,    31,    77,    87,    11,    68,    50,    44,    55,    87,
      55,    55,    50,    43,    50,    49,    53,    62,    86,    55,
      71,    87,    71,    87,    53,     9,    43,    50,    71,    77,
      43,    50,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      64,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    76,    77,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     0,    11,    10,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       0,     3,     3,     4,     2,     0,     2,     0,     2,     0,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       5,     4,     5,     7,     7,     5,     9,     3,     1,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     1,     1,     1,     3,     4,     1,     4,
       1,     3,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     3,     3,
       2,     5,     4,     2,     1,     2,     2
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
#line 36 "parser.y"
                    {head = yyvsp[0];}
#line 1441 "y.tab.c"
    break;

  case 3: /* code_global: func_or_prod code_global  */
#line 40 "parser.y"
                                 {
                yyval = mknode("#global_scope",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});
        }
#line 1449 "y.tab.c"
    break;

  case 4: /* code_global: %empty  */
#line 43 "parser.y"
          {yyval=mknode1("#");}
#line 1455 "y.tab.c"
    break;

  case 5: /* code: func_or_prod code  */
#line 47 "parser.y"
                          {yyval = mknode("#non_global_scope",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});}
#line 1461 "y.tab.c"
    break;

  case 6: /* code: %empty  */
#line 48 "parser.y"
          {yyval=mknode1("#");}
#line 1467 "y.tab.c"
    break;

  case 7: /* func_or_prod: FUNC ID '(' parameters ')' ':' type '{' block return_st '}'  */
#line 54 "parser.y"
        {
            struct node* parTemp = mknode("",(struct node*[]){yyvsp[-7],NULL});
            struct node* blockTemp = mknode("",(struct node*[]){yyvsp[-2],yyvsp[-1],NULL});
            struct node* temp = mknode("",(struct node*[]){
                mknode1(yyvsp[-9]->token),nl(),
                mknode1("(ARGS"),nl(), parTemp, mknode1(")"),nl(),
                mknode1("(RET "), mknode1(yyvsp[-4]->token), mknode1(")"),nl(),
                mknode1("(BODY"),nl(), blockTemp, mknode1(")"),nl(),
                NULL});
            
            yyval = mknode("",(struct node*[]){mknode1("(FUNC"),nl(),temp,mknode1(")"),nl(),NULL});

            struct Scope* currentScope = newScope();
            struct VarArr* parametersArr = newVarArr();
            getFunctionVarArr_Scanner(parTemp, parametersArr);
            struct Function* newFunc = newFunction(yyvsp[-9]->token, yyvsp[-4]->type, parametersArr);
            appendFunctionArr(currentScope->funcsArr, newFunc);
            yyval->scope = currentScope;
            yyval->pointer = currentScope;

            // check 1 + 2 (if main exists once and if it's void and has no args)
            mainCheck(currentScope);

            // check 9 (function can not return string)
            if (yyvsp[-4]->type == STRING_T){
                printf("Error: function can not return string\n");
                exit(0);
            }

            struct Scope* block_scope = newScope();
            block_scope->varArr = deepCopyVarArr(newFunc->varArr);
            block_scope->returnType = newFunc->returnType;
            // extract the vars from the block
            addVarArrToScope(yyvsp[-2]->scope->varArr, block_scope);
            addFunctionArrToScope(yyvsp[-2]->scope->funcsArr, block_scope);
            block_scope->useScope = yyvsp[-2]->scope->useScope;
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, block_scope->useScope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, block_scope->useScope);
            //pushScope(stack, block_scope);    
            blockTemp->pointer = block_scope;
            checkDuplicateVarOrFuncInScope(block_scope);

            // printScopeStack(stack);

        }
#line 1517 "y.tab.c"
    break;

  case 8: /* func_or_prod: FUNC ID '(' parameters ')' ':' VOID '{' block '}'  */
#line 101 "parser.y"
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


            struct Scope* currentScope = newScope();
            struct VarArr* parametersArr = newVarArr();
            getFunctionVarArr_Scanner(parTemp, parametersArr);
            struct Function* newFunc = newFunction(yyvsp[-8]->token, VOID_T, parametersArr);
            appendFunctionArr(currentScope->funcsArr, newFunc);
            yyval->scope = currentScope;
            yyval->pointer = currentScope;

            // check 1 + 2 (if main exists once and if it's void and has no args)
            mainCheck(currentScope);

            struct Scope* block_scope = newScope();
            block_scope->varArr = deepCopyVarArr(newFunc->varArr);
            block_scope->returnType = newFunc->returnType;
            // extract the vars from the block
            addVarArrToScope(yyvsp[-1]->scope->varArr, block_scope);
            addFunctionArrToScope(yyvsp[-1]->scope->funcsArr, block_scope);
            block_scope->useScope = yyvsp[-1]->scope->useScope;
            //pushScope(stack, block_scope);    
            blockTemp->pointer = block_scope;
            checkDuplicateVarOrFuncInScope(block_scope);
        }
#line 1557 "y.tab.c"
    break;

  case 9: /* return_st: RETURN exp ';'  */
#line 140 "parser.y"
                       {
            yyval = mknode("#ret_st",(struct node*[]){mknode1("(RET "),yyvsp[-1],mknode1(")"),nl(),NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, yyval->use_scope);
        }
#line 1568 "y.tab.c"
    break;

  case 10: /* type: INT  */
#line 149 "parser.y"
            {node* t = mknode1("INT"); t->type = INT_T; yyval = t;}
#line 1574 "y.tab.c"
    break;

  case 11: /* type: REAL  */
#line 150 "parser.y"
              {node* t = mknode1("REAL"); t->type = REAL_T; yyval = t;}
#line 1580 "y.tab.c"
    break;

  case 12: /* type: CHAR  */
#line 151 "parser.y"
              {node* t = mknode1("CHAR"); t->type = CHAR_T; yyval = t;}
#line 1586 "y.tab.c"
    break;

  case 13: /* type: BOOL  */
#line 152 "parser.y"
              {node* t = mknode1("BOOL"); t->type = BOOL_T; yyval = t;}
#line 1592 "y.tab.c"
    break;

  case 14: /* type: INT_P  */
#line 153 "parser.y"
               {node* t = mknode1("INT_P"); t->type = INT_P_T; yyval = t;}
#line 1598 "y.tab.c"
    break;

  case 15: /* type: REAL_P  */
#line 154 "parser.y"
                {node* t = mknode1("REAL_P"); t->type = REAL_P_T; yyval = t;}
#line 1604 "y.tab.c"
    break;

  case 16: /* type: CHAR_P  */
#line 155 "parser.y"
                {node* t = mknode1("CHAR_P"); t->type = CHAR_P_T; yyval = t;}
#line 1610 "y.tab.c"
    break;

  case 17: /* type: STRING  */
#line 156 "parser.y"
                {node* t = mknode1("STRING"); t->type = STRING_T; yyval = t;}
#line 1616 "y.tab.c"
    break;

  case 18: /* parameters: ARGS args_var  */
#line 161 "parser.y"
                      {yyval = mknode("#",(struct node*[]){mknode1("("),yyvsp[0],nl(),NULL});}
#line 1622 "y.tab.c"
    break;

  case 19: /* parameters: ARGS args_var ';' parameters  */
#line 162 "parser.y"
                                      {yyval = mknode("#",(struct node*[]){mknode1("("),yyvsp[-2],nl(),yyvsp[0],NULL});}
#line 1628 "y.tab.c"
    break;

  case 20: /* parameters: %empty  */
#line 163 "parser.y"
          {
                yyval = mknode("#",(struct node*[]){mknode1("NONE"),nl(),NULL});
          }
#line 1636 "y.tab.c"
    break;

  case 21: /* args_var: ID ':' type  */
#line 169 "parser.y"
                    {yyval = mknode("#",(struct node*[]){yyvsp[-2],mknode1(","),yyvsp[0],mknode1(")"),NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type; }
#line 1642 "y.tab.c"
    break;

  case 22: /* args_var: ID ',' args_var  */
#line 170 "parser.y"
                         {yyval = mknode("#",(struct node*[]){yyvsp[-2],mknode1(","),yyvsp[0],NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type; }
#line 1648 "y.tab.c"
    break;

  case 23: /* block: comment_st code vars statements  */
#line 173 "parser.y"
                                      {
            yyval = mknode("#",(struct node*[]){yyvsp[-2],yyvsp[-1],yyvsp[0],NULL});

            yyval->scope = newScope();
            add_vars_to_scope(yyvsp[-1], yyval->scope);
            add_functions_to_scope(yyvsp[-2], yyval->scope);

            yyval->use_scope = newScope();
            add_statements_to_scope(yyvsp[0], yyval->use_scope);
            yyval->scope->useScope = yyval->use_scope;
        }
#line 1664 "y.tab.c"
    break;

  case 24: /* comment_st: COMMENT comment_st  */
#line 187 "parser.y"
                           {yyval = mknode1("#comment");}
#line 1670 "y.tab.c"
    break;

  case 25: /* comment_st: %empty  */
#line 188 "parser.y"
          {yyval=mknode1("#");}
#line 1676 "y.tab.c"
    break;

  case 26: /* statements: statement statements  */
#line 192 "parser.y"
                             {yyval = mknode("#statements",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});}
#line 1682 "y.tab.c"
    break;

  case 27: /* statements: %empty  */
#line 193 "parser.y"
          {yyval=mknode1("#");}
#line 1688 "y.tab.c"
    break;

  case 28: /* vars: var_st vars  */
#line 197 "parser.y"
                    {yyval = mknode("#vars",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});}
#line 1694 "y.tab.c"
    break;

  case 29: /* vars: %empty  */
#line 198 "parser.y"
          {yyval=mknode1("#");}
#line 1700 "y.tab.c"
    break;

  case 30: /* statement: if_st  */
#line 202 "parser.y"
              {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = yyvsp[0]->use_scope;
        }
#line 1709 "y.tab.c"
    break;

  case 31: /* statement: do_st  */
#line 206 "parser.y"
               {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = yyvsp[0]->use_scope;
        }
#line 1718 "y.tab.c"
    break;

  case 32: /* statement: while_st  */
#line 210 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = yyvsp[0]->use_scope;
        }
#line 1727 "y.tab.c"
    break;

  case 33: /* statement: for_st  */
#line 214 "parser.y"
                {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = yyvsp[0]->use_scope;
        }
#line 1736 "y.tab.c"
    break;

  case 34: /* statement: assignment_st ';'  */
#line 218 "parser.y"
                           {
            yyval = mknode("#",(struct node*[]){yyvsp[-1],NULL});
            yyval->use_scope = yyvsp[-1]->use_scope;
        }
#line 1745 "y.tab.c"
    break;

  case 35: /* statement: func_call ';'  */
#line 222 "parser.y"
                       {
            yyval = mknode("#func_call_stmt",(struct node*[]){yyvsp[-1],nl(),NULL});
            yyval->use_scope = yyvsp[-1]->use_scope;
        }
#line 1754 "y.tab.c"
    break;

  case 36: /* statement: new_block  */
#line 226 "parser.y"
                  {
            yyval = mknode("#new_block",(struct node*[]){mknode1("(BLOCK"),nl(),
            mknode("",(struct node*[]){yyvsp[0],NULL})
            ,mknode1(")"),nl(),NULL});
            yyval->scope = yyvsp[0]->scope;
        }
#line 1765 "y.tab.c"
    break;

  case 37: /* statement: COMMENT  */
#line 232 "parser.y"
                 {yyval = mknode1("#");printf("comment...\n");}
#line 1771 "y.tab.c"
    break;

  case 38: /* statement_block: statement  */
#line 236 "parser.y"
                  {
            yyval = mknode("#statement_block",(struct node*[]){yyvsp[0],NULL});
            // printf("statement_block\n");
            // printtree_REAL($1,0);
            // do the same for the printing tree semantic
            if (!(strcmp(yyvsp[0]->token,"#new_block")==0)){
                yyval->scope = newScope();
                yyval->use_scope = yyvsp[0]->use_scope;

                yyval->scope->useScope = yyval->use_scope;
                
                //pushScope(stack, block_scope);    
                yyvsp[0]->pointer = yyval->scope;
                checkDuplicateVarOrFuncInScope(yyval->scope);

            }
        }
#line 1793 "y.tab.c"
    break;

  case 39: /* statement_block: return_st  */
#line 253 "parser.y"
                   {
            yyval = mknode("#statement_block",(struct node*[]){yyvsp[0],NULL});
            yyval->scope = newScope();
            yyval->use_scope = yyvsp[0]->use_scope;

            yyval->scope->useScope = yyval->use_scope;
            
            //pushScope(stack, block_scope);    
            yyvsp[0]->pointer = yyval->scope;
            checkDuplicateVarOrFuncInScope(yyval->scope);
        }
#line 1809 "y.tab.c"
    break;

  case 40: /* new_block: '{' vars statements return_st '}'  */
#line 266 "parser.y"
                                        {
            yyval = mknode("#",(struct node*[]){yyvsp[-3],yyvsp[-2],yyvsp[-1],NULL});

            yyval->scope = newScope();
            add_vars_to_scope(yyvsp[-3], yyval->scope);

            yyval->use_scope = newScope();
            add_statements_to_scope(yyvsp[-2], yyval->use_scope);
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, yyval->use_scope);
            yyval->scope->useScope = yyval->use_scope;

            //pushScope(stack, block_scope);    
            yyval->pointer = yyval->scope;
            checkDuplicateVarOrFuncInScope(yyval->scope);
        }
#line 1830 "y.tab.c"
    break;

  case 41: /* new_block: '{' vars statements '}'  */
#line 282 "parser.y"
                               {
            yyval = mknode("#",(struct node*[]){yyvsp[-2],yyvsp[-1],NULL});

            yyval->scope = newScope();
            add_vars_to_scope(yyvsp[-2], yyval->scope);

            yyval->use_scope = newScope();
            add_statements_to_scope(yyvsp[-1], yyval->use_scope);
            yyval->scope->useScope = yyval->use_scope;
            
            //pushScope(stack, block_scope);    
            yyval->pointer = yyval->scope;
            checkDuplicateVarOrFuncInScope(yyval->scope);
        }
#line 1849 "y.tab.c"
    break;

  case 42: /* if_st: IF '(' exp ')' statement_block  */
#line 299 "parser.y"
                                                      {
                struct node* temp = mknode("",(struct node*[]){yyvsp[-2],yyvsp[0],NULL});
                yyval = mknode("#",(struct node*[]){mknode1("(IF"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                yyval->use_scope = newScope();
                addVarArrToScope(yyvsp[-2]->use_scope->varArr, yyval->use_scope);
                addFunctionArrToScope(yyvsp[-2]->use_scope->funcsArr, yyval->use_scope);
                }
#line 1861 "y.tab.c"
    break;

  case 43: /* if_st: IF '(' exp ')' statement_block ELSE statement_block  */
#line 306 "parser.y"
                                                             {
                struct node* temp = mknode("",(struct node*[]){yyvsp[-4],yyvsp[-2],yyvsp[0],NULL});
                yyval = mknode("#",(struct node*[]){mknode1("(IF-ELSE"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                yyval->use_scope = newScope();
                addVarArrToScope(yyvsp[-4]->use_scope->varArr, yyval->use_scope);
                addFunctionArrToScope(yyvsp[-4]->use_scope->funcsArr, yyval->use_scope);
                }
#line 1873 "y.tab.c"
    break;

  case 44: /* do_st: DO statement_block WHILE '(' exp ')' ';'  */
#line 316 "parser.y"
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
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[-2]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-2]->use_scope->funcsArr, yyval->use_scope);
        }
#line 1900 "y.tab.c"
    break;

  case 45: /* while_st: WHILE '(' exp ')' statement_block  */
#line 342 "parser.y"
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
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[-2]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-2]->use_scope->funcsArr, yyval->use_scope);
        }
#line 1927 "y.tab.c"
    break;

  case 46: /* for_st: FOR '(' assignment_st ';' exp ';' assignment_st ')' statement_block  */
#line 367 "parser.y"
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
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[-6]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-6]->use_scope->funcsArr, yyval->use_scope);
            
            addVarArrToScope(yyvsp[-4]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-4]->use_scope->funcsArr, yyval->use_scope);
            
            addVarArrToScope(yyvsp[-2]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-2]->use_scope->funcsArr, yyval->use_scope);
        }
#line 1962 "y.tab.c"
    break;

  case 47: /* assignment_st: lhs '=' exp  */
#line 402 "parser.y"
                    {
            struct node* expTemp = mknode("",(struct node*[]){yyvsp[0],NULL});
            yyval = mknode("#assignment_st",(struct node*[]){mknode1("(="),yyvsp[-2],nl(),expTemp,mknode1(")"),nl(),NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[-2]->use_scope->varArr, yyval->use_scope);
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 1975 "y.tab.c"
    break;

  case 48: /* lhs: ID  */
#line 413 "parser.y"
           {
            yyval = mknode1(yyvsp[0]->token);
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 1985 "y.tab.c"
    break;

  case 49: /* lhs: ID '[' exp ']'  */
#line 418 "parser.y"
                        {
            yyval = mknode("#stringAtIndex",(struct node*[]){mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-3]->token));
        }
#line 1995 "y.tab.c"
    break;

  case 50: /* lhs: '*' ID  */
#line 423 "parser.y"
                {
            yyval = mknode("#derefId",(struct node*[]){mknode1("*"),mknode1(yyvsp[0]->token),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 2005 "y.tab.c"
    break;

  case 51: /* value: STRING_VALUE  */
#line 431 "parser.y"
                 {yyval = mknode1(yyvsp[0]->token); yyval->type = STRING_T;}
#line 2011 "y.tab.c"
    break;

  case 52: /* value: CHAR_VALUE  */
#line 432 "parser.y"
                 {yyval = mknode1(yyvsp[0]->token); yyval->type = CHAR_T;}
#line 2017 "y.tab.c"
    break;

  case 53: /* value: TRUE_  */
#line 433 "parser.y"
            {yyval = mknode1("TRUE"); yyval->type = BOOL_T;}
#line 2023 "y.tab.c"
    break;

  case 54: /* value: FALSE_  */
#line 434 "parser.y"
             {yyval = mknode1("FALSE"); yyval->type = BOOL_T;}
#line 2029 "y.tab.c"
    break;

  case 55: /* value: NULL_  */
#line 435 "parser.y"
            {yyval = mknode1("NULL"); yyval->type = NULL_T;}
#line 2035 "y.tab.c"
    break;

  case 56: /* value: HEX_VALUE  */
#line 436 "parser.y"
                {yyval = mknode1(yyvsp[0]->token); yyval->type = INT_T;}
#line 2041 "y.tab.c"
    break;

  case 57: /* value: DIGITS_VALUE  */
#line 437 "parser.y"
                   {yyval = mknode1(yyvsp[0]->token); yyval->type = INT_T;}
#line 2047 "y.tab.c"
    break;

  case 58: /* value: REAL_VALUE  */
#line 438 "parser.y"
                 {yyval = mknode1(yyvsp[0]->token); yyval->type = REAL_T;}
#line 2053 "y.tab.c"
    break;

  case 59: /* var_st: VAR var_list ';'  */
#line 442 "parser.y"
                         {
            yyval = mknode("#",(struct node*[]){mknode1("(VAR ")
            ,nl()
            ,mknode("",(struct node*[]){yyvsp[-1],NULL})
            ,nl()
            ,mknode1(")"),nl(),NULL});
            yyval->scope = newScope();
            get_var_list(yyvsp[-1],yyval->scope->varArr);
            
        }
#line 2068 "y.tab.c"
    break;

  case 60: /* var_st: STRING var_string_list ';'  */
#line 452 "parser.y"
                                    {
            yyval = mknode("#",(struct node*[]){mknode1("(VAR_STRING ")
            ,nl()
            ,mknode("",(struct node*[]){yyvsp[-1],NULL})
            ,nl()
            ,mknode1(")"),nl(),NULL});
            yyval->scope = newScope();
            get_var_string_list(yyvsp[-1],yyval->scope->varArr);
        }
#line 2082 "y.tab.c"
    break;

  case 61: /* var_list: var_op ':' type  */
#line 464 "parser.y"
                        {yyval = mknode("#",(struct node*[]){yyvsp[-2],nl(),mknode1("Type: "),yyvsp[0],NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type;}
#line 2088 "y.tab.c"
    break;

  case 62: /* var_list: var_op ',' var_list  */
#line 465 "parser.y"
                             {yyval = mknode("#",(struct node*[]){yyvsp[-2],nl(),yyvsp[0],NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type; }
#line 2094 "y.tab.c"
    break;

  case 63: /* var_op: ID  */
#line 469 "parser.y"
           {yyval = mknode1(yyvsp[0]->token);}
#line 2100 "y.tab.c"
    break;

  case 64: /* var_op: assignment_st  */
#line 470 "parser.y"
                       {yyval = mknode("#ass_in_var",(struct node*[]){yyvsp[0],NULL});}
#line 2106 "y.tab.c"
    break;

  case 65: /* var_string_list: var_string_opt  */
#line 474 "parser.y"
                       {yyval = mknode("#",(struct node*[]){yyvsp[0],nl(),NULL});}
#line 2112 "y.tab.c"
    break;

  case 66: /* var_string_list: var_string_opt ',' var_string_list  */
#line 475 "parser.y"
                                            {yyval = mknode("#",(struct node*[]){yyvsp[-2],nl(),yyvsp[0],NULL});}
#line 2118 "y.tab.c"
    break;

  case 67: /* var_string_opt: ID '[' exp ']'  */
#line 479 "parser.y"
                       {yyval = mknode("#var_string_opt",(struct node*[]){mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});}
#line 2124 "y.tab.c"
    break;

  case 68: /* var_string_opt: assignment_st  */
#line 480 "parser.y"
                       {yyval = mknode("#ass_in_str",(struct node*[]){yyvsp[0],NULL});}
#line 2130 "y.tab.c"
    break;

  case 69: /* func_call: ID '(' exp_list ')'  */
#line 484 "parser.y"
                            {
            yyval = mknode("#",(struct node*[]){mknode1("function call "),mknode1(yyvsp[-3]->token),mknode1("("),yyvsp[-1],mknode1(")"),NULL});
            yyval->use_scope = newScope();
            add_args_to_scope(yyvsp[-1], yyval->use_scope);
            appendFunctionArr(yyval->use_scope->funcsArr, newFunction(yyvsp[-3]->token,NONE_T,newVarArr()));
        }
#line 2141 "y.tab.c"
    break;

  case 70: /* exp_list: exp  */
#line 493 "parser.y"
            {yyval = mknode("#exp_list",(struct node*[]){yyvsp[0],NULL});}
#line 2147 "y.tab.c"
    break;

  case 71: /* exp_list: exp ',' exp_list  */
#line 494 "parser.y"
                           {yyval = mknode("#exp_list",(struct node*[]){yyvsp[-2],mknode1(","),yyvsp[0],NULL});}
#line 2153 "y.tab.c"
    break;

  case 72: /* exp_list: %empty  */
#line 495 "parser.y"
          {yyval=mknode1("#");}
#line 2159 "y.tab.c"
    break;

  case 73: /* exp: exp '+' exp  */
#line 500 "parser.y"
                      {yyval = expNode("( +",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("+",yyvsp[-2],yyvsp[0]);}
#line 2165 "y.tab.c"
    break;

  case 74: /* exp: exp '-' exp  */
#line 501 "parser.y"
                      {yyval = expNode("( -",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("-",yyvsp[-2],yyvsp[0]);}
#line 2171 "y.tab.c"
    break;

  case 75: /* exp: exp '*' exp  */
#line 502 "parser.y"
                      {yyval = expNode("( *",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("*",yyvsp[-2],yyvsp[0]);}
#line 2177 "y.tab.c"
    break;

  case 76: /* exp: exp '/' exp  */
#line 503 "parser.y"
                      {yyval = expNode("( /",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("/",yyvsp[-2],yyvsp[0]);}
#line 2183 "y.tab.c"
    break;

  case 77: /* exp: exp EQEQ exp  */
#line 504 "parser.y"
                       {yyval = expNode("( ==",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("==",yyvsp[-2],yyvsp[0]);}
#line 2189 "y.tab.c"
    break;

  case 78: /* exp: exp NOT_EQ exp  */
#line 505 "parser.y"
                         {yyval = expNode("( !=",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("!=",yyvsp[-2],yyvsp[0]);}
#line 2195 "y.tab.c"
    break;

  case 79: /* exp: exp '<' exp  */
#line 506 "parser.y"
                      {yyval = expNode("( <",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("<",yyvsp[-2],yyvsp[0]);}
#line 2201 "y.tab.c"
    break;

  case 80: /* exp: exp SMALL_EQ exp  */
#line 507 "parser.y"
                           {yyval = expNode("( <=",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("<=",yyvsp[-2],yyvsp[0]);}
#line 2207 "y.tab.c"
    break;

  case 81: /* exp: exp '>' exp  */
#line 508 "parser.y"
                      {yyval = expNode("( >",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode(">",yyvsp[-2],yyvsp[0]);}
#line 2213 "y.tab.c"
    break;

  case 82: /* exp: exp BIG_EQ exp  */
#line 509 "parser.y"
                         {yyval = expNode("( >=",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode(">=",yyvsp[-2],yyvsp[0]);}
#line 2219 "y.tab.c"
    break;

  case 83: /* exp: exp OR exp  */
#line 510 "parser.y"
                     {yyval = expNode("( ||",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("||",yyvsp[-2],yyvsp[0]);}
#line 2225 "y.tab.c"
    break;

  case 84: /* exp: exp AND exp  */
#line 511 "parser.y"
                      {yyval = expNode("( &&",yyvsp[-2],yyvsp[0]); yyval->exp_node = mkExpNode("&&",yyvsp[-2],yyvsp[0]);}
#line 2231 "y.tab.c"
    break;

  case 85: /* exp: '!' exp  */
#line 512 "parser.y"
                  {//
            yyval = mknode("#",(struct node*[]){mknode1("!"),nl(),yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
            yyval->exp_node = mkExpNode("!",yyvsp[0],NULL);
        }
#line 2243 "y.tab.c"
    break;

  case 86: /* exp: ID  */
#line 519 "parser.y"
             {
            yyval = mknode1(yyvsp[0]->token);
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
            yyval->exp_node = mkExpNode(yyvsp[0]->token,NULL,NULL);
            yyval->exp_node->leaf_type = ID_LEAF;
        }
#line 2255 "y.tab.c"
    break;

  case 87: /* exp: func_call  */
#line 526 "parser.y"
                    {
            yyval = mknode("#func_call_as_exp",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
            yyval->exp_node = mkExpNode(yyvsp[0]->children[1]->token,NULL,NULL);
            yyval->exp_node->leaf_type = FUNC_CALL;
        }
#line 2268 "y.tab.c"
    break;

  case 88: /* exp: '|' ID '|'  */
#line 534 "parser.y"
                     {
            yyval = mknode("#",(struct node*[]){mknode1("lenOf("),mknode1(yyvsp[-1]->token),mknode1(")"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-1]->token));
            yyval->exp_node = mkExpNode(yyvsp[-1]->token,NULL,NULL);
            yyval->exp_node->leaf_type = LEN_OF_STR;
        }
#line 2280 "y.tab.c"
    break;

  case 89: /* exp: '(' exp ')'  */
#line 541 "parser.y"
                      {yyval = yyvsp[-1];}
#line 2286 "y.tab.c"
    break;

  case 90: /* exp: '&' ID  */
#line 542 "parser.y"
                 {
            yyval = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1(yyvsp[0]->token),mknode1(")"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));   
            yyval->exp_node = mkExpNode(yyvsp[0]->token,NULL,NULL);
            yyval->exp_node->leaf_type = ADDRESS_OF; 
        }
#line 2298 "y.tab.c"
    break;

  case 91: /* exp: '&' ID '[' exp ']'  */
#line 549 "parser.y"
                             {
            yyval = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-3]->token));
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, yyval->use_scope);

            struct node* idNode = mknode1(yyvsp[-3]->token);
            idNode->exp_node = mkExpNode(yyvsp[-3]->token,NULL,NULL);
            idNode->exp_node->leaf_type = ID_LEAF;

            yyval->exp_node = mkExpNode("addressOfChar",idNode,yyvsp[-1]);

        }
#line 2317 "y.tab.c"
    break;

  case 92: /* exp: ID '[' exp ']'  */
#line 563 "parser.y"
                        {
            yyval = mknode("#",(struct node*[]){mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-3]->token));
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, yyval->use_scope);

            struct node* idNode = mknode1(yyvsp[-3]->token);
            idNode->exp_node = mkExpNode(yyvsp[-3]->token,NULL,NULL);
            idNode->exp_node->leaf_type = ID_LEAF;

            yyval->exp_node = mkExpNode("charAt",idNode,yyvsp[-1]);
        }
#line 2335 "y.tab.c"
    break;

  case 93: /* exp: '*' exp  */
#line 576 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){mknode1("dereference("),yyvsp[0],mknode1(")"),NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
            yyval->exp_node = mkExpNode("dereference",yyvsp[0],NULL);
        }
#line 2347 "y.tab.c"
    break;

  case 94: /* exp: value  */
#line 583 "parser.y"
                {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = newScope();
            yyval->exp_node = mkExpNode(yyvsp[0]->token,NULL,NULL);
            yyval->exp_node->leaf_type = VALUE;
            yyval->exp_node->result = yyvsp[0]->type;
        }
#line 2359 "y.tab.c"
    break;

  case 95: /* exp: '-' exp  */
#line 590 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){mknode1("-"),yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
            yyval->exp_node = mkExpNode("unary-",yyvsp[0],NULL);
        }
#line 2371 "y.tab.c"
    break;

  case 96: /* exp: '+' exp  */
#line 597 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){mknode1("+"),yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
            yyval->exp_node = mkExpNode("unary+",yyvsp[0],NULL);
        }
#line 2383 "y.tab.c"
    break;


#line 2387 "y.tab.c"

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

#line 607 "parser.y"


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
