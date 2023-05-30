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
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_41_ = 41,                       /* '<'  */
  YYSYMBOL_42_ = 42,                       /* '>'  */
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
  YYSYMBOL_68_1 = 68,                      /* @1  */
  YYSYMBOL_statements = 69,                /* statements  */
  YYSYMBOL_vars = 70,                      /* vars  */
  YYSYMBOL_statement = 71,                 /* statement  */
  YYSYMBOL_statement_block = 72,           /* statement_block  */
  YYSYMBOL_new_block = 73,                 /* new_block  */
  YYSYMBOL_if_st = 74,                     /* if_st  */
  YYSYMBOL_do_st = 75,                     /* do_st  */
  YYSYMBOL_while_st = 76,                  /* while_st  */
  YYSYMBOL_for_st = 77,                    /* for_st  */
  YYSYMBOL_assignment_st = 78,             /* assignment_st  */
  YYSYMBOL_lhs = 79,                       /* lhs  */
  YYSYMBOL_value = 80,                     /* value  */
  YYSYMBOL_var_st = 81,                    /* var_st  */
  YYSYMBOL_var_list = 82,                  /* var_list  */
  YYSYMBOL_var_op = 83,                    /* var_op  */
  YYSYMBOL_var_string_list = 84,           /* var_string_list  */
  YYSYMBOL_var_string_opt = 85,            /* var_string_opt  */
  YYSYMBOL_func_call = 86,                 /* func_call  */
  YYSYMBOL_exp_list = 87,                  /* exp_list  */
  YYSYMBOL_exp = 88                        /* exp  */
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
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

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
      49,    50,    39,    37,    44,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    43,
      41,    47,    42,     2,     2,     2,     2,     2,     2,     2,
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
       0,    35,    35,    39,    42,    46,    47,    52,   101,   143,
     152,   153,   154,   155,   156,   157,   158,   159,   164,   165,
     166,   172,   173,   176,   190,   190,   191,   195,   196,   200,
     201,   205,   209,   213,   217,   221,   225,   229,   235,   239,
     256,   269,   286,   304,   311,   321,   347,   372,   407,   418,
     423,   428,   436,   437,   438,   439,   440,   441,   442,   443,
     447,   457,   469,   470,   474,   475,   479,   480,   484,   485,
     489,   498,   499,   500,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   522,   527,   533,
     538,   539,   544,   551,   556,   560,   566
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
  "STRING_VALUE", "CHAR_VALUE", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'",
  "';'", "','", "'!'", "'&'", "'='", "non_else", "'('", "')'", "':'",
  "'{'", "'}'", "'['", "']'", "'|'", "$accept", "program", "code_global",
  "code", "func_or_prod", "return_st", "type", "parameters", "args_var",
  "block", "comment_st", "@1", "statements", "vars", "statement",
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

#define YYPACT_NINF (-157)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,     7,    42,  -157,     6,    -5,  -157,  -157,    45,    20,
      11,   -27,    22,    29,    20,    86,    45,    39,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,    31,
      35,    59,    59,  -157,    38,     6,    79,    59,  -157,    41,
       6,   113,    61,  -157,   -13,    -9,   145,    41,  -157,  -157,
    -157,  -157,    72,  -157,  -157,  -157,  -157,  -157,   113,   113,
      88,   113,    91,   113,    92,  -157,  -157,   296,  -157,   -19,
      94,  -157,    80,    85,    -1,    75,  -157,    93,    90,    81,
      82,    89,     1,  -157,   -15,    41,  -157,   145,  -157,  -157,
    -157,  -157,  -157,    96,    97,  -157,   113,   329,   329,  -157,
    -157,   100,   199,   104,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,  -157,   113,  -157,   113,
    -157,   -13,    86,   113,  -157,    -9,   113,    -2,   113,  -157,
    -157,   131,   145,  -157,  -157,  -157,   111,   275,   113,  -157,
    -157,    87,    87,    87,    87,  -157,  -157,   329,   329,    70,
      70,    87,    87,   153,   323,  -157,  -157,   174,  -157,   218,
     109,   121,   237,   116,    -4,  -157,   113,   193,  -157,   119,
       1,   113,     1,   113,  -157,   114,  -157,  -157,   159,   303,
    -157,   256,  -157,     1,    -2,   127,  -157,   122,  -157,     1,
    -157
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     1,     3,    20,     0,
       0,     0,    18,     0,     0,     0,    20,     0,    22,    10,
      14,    12,    16,    11,    15,    13,    17,    21,    19,     0,
       0,    26,    26,    24,     0,     6,     0,    26,     8,    30,
       6,     0,     0,    25,     0,     0,    28,    30,     5,    54,
      55,    56,    87,    58,    57,    59,    52,    53,     0,     0,
       0,     0,     0,     0,     0,    94,    88,     0,     7,    64,
       0,    65,     0,     0,     0,    49,    69,     0,    66,     0,
       0,     0,     0,    38,    49,    30,    23,    28,    37,    31,
      32,    33,    34,     0,     0,    29,    73,    96,    95,    93,
      86,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,    51,     0,
      60,     0,     0,     0,    61,     0,     0,     0,     0,    40,
      39,     0,    28,    27,    35,    36,     0,    71,     0,    90,
      89,    78,    81,    83,    79,    84,    85,    74,    75,    76,
      77,    80,    82,     0,    48,    63,    62,     0,    67,     0,
      49,     0,     0,     0,     0,    70,    73,     0,    50,    68,
       0,     0,     0,     0,    42,     0,    72,    92,    43,     0,
      46,     0,    41,     0,     0,     0,    44,     0,    45,     0,
      47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,   167,   133,    73,   -32,   -12,   158,   169,   154,
     148,  -157,   -80,   -39,   -40,  -156,  -157,  -157,  -157,  -157,
    -157,   -43,  -157,  -157,  -157,    66,  -157,    63,  -157,   -46,
      23,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    39,     4,   129,    27,    10,    12,    34,
      35,    37,    86,    46,   130,   131,    88,    89,    90,    91,
      92,    93,    72,    65,    47,    73,    74,    77,    78,    66,
     136,   137
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      94,    71,    76,    67,    42,    30,    87,   133,    95,    79,
      41,    80,    81,    82,   178,    41,   180,    14,    69,     1,
      97,    98,    75,   100,    15,   102,    70,   186,   -49,   160,
      70,    83,    84,   190,    96,   117,    94,    70,     5,   117,
      70,    94,     6,   121,     8,    29,   132,    87,     9,   174,
     122,    11,   164,    85,    19,    20,    21,    22,    23,    24,
      25,    13,    26,    44,    45,    16,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    71,   153,
      17,   154,    76,    31,   161,   157,    94,    32,   159,    33,
     162,    38,    87,    41,   104,   105,   106,   107,   108,   109,
     167,    19,    20,    21,    22,    23,    24,    25,    40,    26,
     156,   114,   115,    40,    68,   108,   109,    49,    50,    99,
      51,    96,   101,   103,    94,   118,    94,   119,   120,   123,
     126,   127,   175,   179,   125,   181,   124,    94,   128,   134,
     135,   187,   163,    94,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    79,   138,    80,    81,    82,    61,    62,
     140,   165,    63,   117,   171,   173,   -50,   182,   183,    64,
     188,     7,   189,    48,    28,    83,    84,   104,   105,   106,
     107,   108,   109,    18,    70,    43,    36,   155,   158,   176,
     110,   111,   112,   113,   114,   115,     0,    85,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,   168,     0,
       0,   110,   111,   112,   113,   114,   115,   104,   105,   106,
     107,   108,   109,   104,   105,   106,   107,   108,   109,   169,
     110,   111,   112,   113,   114,   115,   110,   111,   112,   113,
     114,   115,   104,   105,   106,   107,   108,   109,   177,   139,
       0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   104,   105,   106,   107,   108,   109,     0,   170,     0,
       0,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     104,   105,   106,   107,   108,   109,     0,   172,     0,     0,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   104,
     105,   106,   107,   108,   109,     0,   185,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,     0,   166,
     104,   105,   106,   107,   108,   109,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     110,   111,   112,   113,   114,   115,   184,   104,   105,   106,
     107,   108,   109,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,   115,     0,     0,   112,   113,
     114,   115
};

static const yytype_int16 yycheck[] =
{
      46,    44,    45,    41,    36,    17,    46,    87,    47,     8,
      14,    10,    11,    12,   170,    14,   172,    44,    31,    13,
      58,    59,    31,    61,    51,    63,    39,   183,    47,    31,
      39,    30,    31,   189,    49,    54,    82,    39,    31,    54,
      39,    87,     0,    44,    49,     6,    85,    87,     3,    53,
      51,    31,   132,    52,    15,    16,    17,    18,    19,    20,
      21,    50,    23,    22,    23,    43,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   121,   117,
      51,   119,   125,    52,   127,   123,   132,    52,   126,    30,
     128,    53,   132,    14,    24,    25,    26,    27,    28,    29,
     138,    15,    16,    17,    18,    19,    20,    21,    35,    23,
     122,    41,    42,    40,    53,    28,    29,     4,     5,    31,
       7,    49,    31,    31,   170,    31,   172,    47,    43,    54,
      49,    49,   164,   171,    44,   173,    43,   183,    49,    43,
      43,   184,    11,   189,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     8,    54,    10,    11,    12,    45,    46,
      56,    50,    49,    54,    43,    49,    47,    53,     9,    56,
      43,     4,    50,    40,    16,    30,    31,    24,    25,    26,
      27,    28,    29,    14,    39,    37,    32,   121,   125,   166,
      37,    38,    39,    40,    41,    42,    -1,    52,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    37,    38,    39,    40,    41,    42,    24,    25,    26,
      27,    28,    29,    24,    25,    26,    27,    28,    29,    55,
      37,    38,    39,    40,    41,    42,    37,    38,    39,    40,
      41,    42,    24,    25,    26,    27,    28,    29,    55,    50,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    24,    25,    26,    27,    28,    29,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      24,    25,    26,    27,    28,    29,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    24,
      25,    26,    27,    28,    29,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    -1,    44,
      24,    25,    26,    27,    28,    29,    -1,    24,    25,    26,
      27,    28,    29,    37,    38,    39,    40,    41,    42,    43,
      37,    38,    39,    40,    41,    42,    43,    24,    25,    26,
      27,    28,    29,    24,    25,    26,    27,    28,    29,    -1,
      37,    38,    39,    40,    41,    42,    -1,    -1,    39,    40,
      41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    58,    59,    61,    31,     0,    59,    49,     3,
      64,    31,    65,    50,    44,    51,    43,    51,    65,    15,
      16,    17,    18,    19,    20,    21,    23,    63,    64,     6,
      63,    52,    52,    30,    66,    67,    66,    68,    53,    60,
      61,    14,    62,    67,    22,    23,    70,    81,    60,     4,
       5,     7,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    45,    46,    49,    56,    80,    86,    88,    53,    31,
      39,    78,    79,    82,    83,    31,    78,    84,    85,     8,
      10,    11,    12,    30,    31,    52,    69,    71,    73,    74,
      75,    76,    77,    78,    86,    70,    49,    88,    88,    31,
      88,    31,    88,    31,    24,    25,    26,    27,    28,    29,
      37,    38,    39,    40,    41,    42,    43,    54,    31,    47,
      43,    44,    51,    54,    43,    44,    49,    49,    49,    62,
      71,    72,    70,    69,    43,    43,    87,    88,    54,    50,
      56,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    82,    63,    88,    84,    88,
      31,    78,    88,    11,    69,    50,    44,    88,    55,    55,
      50,    43,    50,    49,    53,    62,    87,    55,    72,    88,
      72,    88,    53,     9,    43,    50,    72,    78,    43,    50,
      72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      64,    65,    65,    66,    68,    67,    67,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    76,    77,    78,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     0,    11,    10,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       0,     3,     3,     4,     0,     3,     0,     2,     0,     2,
       0,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     5,     4,     5,     7,     7,     5,     9,     3,     1,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     1,     1,     3,     4,     1,
       4,     1,     3,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1,     3,
       3,     2,     5,     2,     1,     2,     2
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
#line 35 "parser.y"
                    {head = yyvsp[0];}
#line 1442 "y.tab.c"
    break;

  case 3: /* code_global: func_or_prod code_global  */
#line 39 "parser.y"
                                 {
                yyval = mknode("#global_scope",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});
        }
#line 1450 "y.tab.c"
    break;

  case 4: /* code_global: %empty  */
#line 42 "parser.y"
          {yyval=mknode1("#");}
#line 1456 "y.tab.c"
    break;

  case 5: /* code: func_or_prod code  */
#line 46 "parser.y"
                          {yyval = mknode("#non_global_scope",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});}
#line 1462 "y.tab.c"
    break;

  case 6: /* code: %empty  */
#line 47 "parser.y"
          {yyval=mknode1("#");}
#line 1468 "y.tab.c"
    break;

  case 7: /* func_or_prod: FUNC ID '(' parameters ')' ':' type '{' block return_st '}'  */
#line 53 "parser.y"
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
            block_scope->nestedBlocks = howManyBlockIhaveInside(yyvsp[-2],0);
            block_scope->nestedFuncs = howManyFunctionsIHaveInside(yyvsp[-2],0);
            block_scope->useScope = yyvsp[-2]->scope->useScope;
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, block_scope->useScope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, block_scope->useScope);
            //pushScope(stack, block_scope);    
            blockTemp->pointer = block_scope;
            checkDuplicateVarOrFuncInScope(block_scope);

            // printScopeStack(stack);

        }
#line 1520 "y.tab.c"
    break;

  case 8: /* func_or_prod: FUNC ID '(' parameters ')' ':' VOID '{' block '}'  */
#line 102 "parser.y"
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
            block_scope->nestedBlocks = howManyBlockIhaveInside(yyvsp[-1],0);
            block_scope->nestedFuncs = howManyFunctionsIHaveInside(yyvsp[-1],0);
            block_scope->useScope = yyvsp[-1]->scope->useScope;
            //pushScope(stack, block_scope);    
            blockTemp->pointer = block_scope;
            checkDuplicateVarOrFuncInScope(block_scope);
        }
#line 1562 "y.tab.c"
    break;

  case 9: /* return_st: RETURN exp ';'  */
#line 143 "parser.y"
                       {
            yyval = mknode("#",(struct node*[]){mknode1("(RET "),yyvsp[-1],mknode1(")"),nl(),NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, yyval->use_scope);
        }
#line 1573 "y.tab.c"
    break;

  case 10: /* type: INT  */
#line 152 "parser.y"
            {node* t = mknode1("INT"); t->type = INT_T; yyval = t;}
#line 1579 "y.tab.c"
    break;

  case 11: /* type: REAL  */
#line 153 "parser.y"
              {node* t = mknode1("REAL"); t->type = REAL_T; yyval = t;}
#line 1585 "y.tab.c"
    break;

  case 12: /* type: CHAR  */
#line 154 "parser.y"
              {node* t = mknode1("CHAR"); t->type = CHAR_T; yyval = t;}
#line 1591 "y.tab.c"
    break;

  case 13: /* type: BOOL  */
#line 155 "parser.y"
              {node* t = mknode1("BOOL"); t->type = BOOL_T; yyval = t;}
#line 1597 "y.tab.c"
    break;

  case 14: /* type: INT_P  */
#line 156 "parser.y"
               {node* t = mknode1("INT_P"); t->type = INT_P_T; yyval = t;}
#line 1603 "y.tab.c"
    break;

  case 15: /* type: REAL_P  */
#line 157 "parser.y"
                {node* t = mknode1("REAL_P"); t->type = REAL_P_T; yyval = t;}
#line 1609 "y.tab.c"
    break;

  case 16: /* type: CHAR_P  */
#line 158 "parser.y"
                {node* t = mknode1("CHAR_P"); t->type = CHAR_P_T; yyval = t;}
#line 1615 "y.tab.c"
    break;

  case 17: /* type: STRING  */
#line 159 "parser.y"
                {node* t = mknode1("STRING"); t->type = STRING_T; yyval = t;}
#line 1621 "y.tab.c"
    break;

  case 18: /* parameters: ARGS args_var  */
#line 164 "parser.y"
                      {yyval = mknode("#",(struct node*[]){mknode1("("),yyvsp[0],nl(),NULL});}
#line 1627 "y.tab.c"
    break;

  case 19: /* parameters: ARGS args_var ';' parameters  */
#line 165 "parser.y"
                                      {yyval = mknode("#",(struct node*[]){mknode1("("),yyvsp[-2],nl(),yyvsp[0],NULL});}
#line 1633 "y.tab.c"
    break;

  case 20: /* parameters: %empty  */
#line 166 "parser.y"
          {
                yyval = mknode("#",(struct node*[]){mknode1("NONE"),nl(),NULL});
          }
#line 1641 "y.tab.c"
    break;

  case 21: /* args_var: ID ':' type  */
#line 172 "parser.y"
                    {yyval = mknode("#",(struct node*[]){yyvsp[-2],mknode1(","),yyvsp[0],mknode1(")"),NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type; }
#line 1647 "y.tab.c"
    break;

  case 22: /* args_var: ID ',' args_var  */
#line 173 "parser.y"
                         {yyval = mknode("#",(struct node*[]){yyvsp[-2],mknode1(","),yyvsp[0],NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type; }
#line 1653 "y.tab.c"
    break;

  case 23: /* block: comment_st code vars statements  */
#line 176 "parser.y"
                                      {
            yyval = mknode("#",(struct node*[]){yyvsp[-2],yyvsp[-1],yyvsp[0],NULL});

            yyval->scope = newScope();
            add_vars_to_scope(yyvsp[-1], yyval->scope);
            add_functions_to_scope(yyvsp[-2], yyval->scope);

            yyval->use_scope = newScope();
            add_statements_to_scope(yyvsp[0], yyval->use_scope);
            yyval->scope->useScope = yyval->use_scope;
        }
#line 1669 "y.tab.c"
    break;

  case 24: /* @1: %empty  */
#line 190 "parser.y"
                {yyval = mknode1("#comment");}
#line 1675 "y.tab.c"
    break;

  case 26: /* comment_st: %empty  */
#line 191 "parser.y"
          {yyval=mknode1("#");}
#line 1681 "y.tab.c"
    break;

  case 27: /* statements: statement statements  */
#line 195 "parser.y"
                             {yyval = mknode("#statements",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});}
#line 1687 "y.tab.c"
    break;

  case 28: /* statements: %empty  */
#line 196 "parser.y"
          {yyval=mknode1("#");}
#line 1693 "y.tab.c"
    break;

  case 29: /* vars: var_st vars  */
#line 200 "parser.y"
                    {yyval = mknode("#vars",(struct node*[]){yyvsp[-1],yyvsp[0],NULL});}
#line 1699 "y.tab.c"
    break;

  case 30: /* vars: %empty  */
#line 201 "parser.y"
          {yyval=mknode1("#");}
#line 1705 "y.tab.c"
    break;

  case 31: /* statement: if_st  */
#line 205 "parser.y"
              {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = yyvsp[0]->use_scope;
        }
#line 1714 "y.tab.c"
    break;

  case 32: /* statement: do_st  */
#line 209 "parser.y"
               {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = yyvsp[0]->use_scope;
        }
#line 1723 "y.tab.c"
    break;

  case 33: /* statement: while_st  */
#line 213 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = yyvsp[0]->use_scope;
        }
#line 1732 "y.tab.c"
    break;

  case 34: /* statement: for_st  */
#line 217 "parser.y"
                {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = yyvsp[0]->use_scope;
        }
#line 1741 "y.tab.c"
    break;

  case 35: /* statement: assignment_st ';'  */
#line 221 "parser.y"
                           {
            yyval = mknode("#",(struct node*[]){yyvsp[-1],NULL});
            yyval->use_scope = yyvsp[-1]->use_scope;
        }
#line 1750 "y.tab.c"
    break;

  case 36: /* statement: func_call ';'  */
#line 225 "parser.y"
                       {
            yyval = mknode("#func_call_stmt",(struct node*[]){yyvsp[-1],nl(),NULL});
            yyval->use_scope = yyvsp[-1]->use_scope;
        }
#line 1759 "y.tab.c"
    break;

  case 37: /* statement: new_block  */
#line 229 "parser.y"
                  {
            yyval = mknode("#new_block",(struct node*[]){mknode1("(BLOCK"),nl(),
            mknode("",(struct node*[]){yyvsp[0],NULL})
            ,mknode1(")"),nl(),NULL});
            yyval->scope = yyvsp[0]->scope;
        }
#line 1770 "y.tab.c"
    break;

  case 38: /* statement: COMMENT  */
#line 235 "parser.y"
                 {yyval = mknode1("#");printf("comment...\n");}
#line 1776 "y.tab.c"
    break;

  case 39: /* statement_block: statement  */
#line 239 "parser.y"
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
#line 1798 "y.tab.c"
    break;

  case 40: /* statement_block: return_st  */
#line 256 "parser.y"
                   {
            yyval = mknode("#statement_block",(struct node*[]){yyvsp[0],NULL});
            yyval->scope = newScope();
            yyval->use_scope = yyvsp[0]->use_scope;

            yyval->scope->useScope = yyval->use_scope;
            
            //pushScope(stack, block_scope);    
            yyvsp[0]->pointer = yyval->scope;
            checkDuplicateVarOrFuncInScope(yyval->scope);
        }
#line 1814 "y.tab.c"
    break;

  case 41: /* new_block: '{' vars statements return_st '}'  */
#line 269 "parser.y"
                                        {
            yyval = mknode("#",(struct node*[]){yyvsp[-3],yyvsp[-2],yyvsp[-1],NULL});

            yyval->scope = newScope();
            add_vars_to_scope(yyvsp[-3], yyval->scope);
            yyval->scope->nestedBlocks = howManyBlockIhaveInside(yyvsp[-2],0);

            yyval->use_scope = newScope();
            add_statements_to_scope(yyvsp[-2], yyval->use_scope);
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, yyval->use_scope);
            yyval->scope->useScope = yyval->use_scope;

            //pushScope(stack, block_scope);    
            yyval->pointer = yyval->scope;
            checkDuplicateVarOrFuncInScope(yyval->scope);
        }
#line 1836 "y.tab.c"
    break;

  case 42: /* new_block: '{' vars statements '}'  */
#line 286 "parser.y"
                               {
            yyval = mknode("#",(struct node*[]){yyvsp[-2],yyvsp[-1],NULL});

            yyval->scope = newScope();
            add_vars_to_scope(yyvsp[-2], yyval->scope);
            yyval->scope->nestedBlocks = howManyBlockIhaveInside(yyvsp[-1],0);

            yyval->use_scope = newScope();
            add_statements_to_scope(yyvsp[-1], yyval->use_scope);
            yyval->scope->useScope = yyval->use_scope;
            
            //pushScope(stack, block_scope);    
            yyval->pointer = yyval->scope;
            checkDuplicateVarOrFuncInScope(yyval->scope);
        }
#line 1856 "y.tab.c"
    break;

  case 43: /* if_st: IF '(' exp ')' statement_block  */
#line 304 "parser.y"
                                                      {
                struct node* temp = mknode("",(struct node*[]){yyvsp[-2],yyvsp[0],NULL});
                yyval = mknode("#",(struct node*[]){mknode1("(IF"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                yyval->use_scope = newScope();
                addVarArrToScope(yyvsp[-2]->use_scope->varArr, yyval->use_scope);
                addFunctionArrToScope(yyvsp[-2]->use_scope->funcsArr, yyval->use_scope);
                }
#line 1868 "y.tab.c"
    break;

  case 44: /* if_st: IF '(' exp ')' statement_block ELSE statement_block  */
#line 311 "parser.y"
                                                             {
                struct node* temp = mknode("",(struct node*[]){yyvsp[-4],yyvsp[-2],yyvsp[0],NULL});
                yyval = mknode("#",(struct node*[]){mknode1("(IF-ELSE"),nl(),temp,nl(),mknode1(")"),nl(),NULL});
                yyval->use_scope = newScope();
                addVarArrToScope(yyvsp[-4]->use_scope->varArr, yyval->use_scope);
                addFunctionArrToScope(yyvsp[-4]->use_scope->funcsArr, yyval->use_scope);
                }
#line 1880 "y.tab.c"
    break;

  case 45: /* do_st: DO statement_block WHILE '(' exp ')' ';'  */
#line 321 "parser.y"
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
#line 1907 "y.tab.c"
    break;

  case 46: /* while_st: WHILE '(' exp ')' statement_block  */
#line 347 "parser.y"
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
#line 1934 "y.tab.c"
    break;

  case 47: /* for_st: FOR '(' assignment_st ';' exp ';' assignment_st ')' statement_block  */
#line 372 "parser.y"
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
#line 1969 "y.tab.c"
    break;

  case 48: /* assignment_st: lhs '=' exp  */
#line 407 "parser.y"
                    {
            struct node* expTemp = mknode("",(struct node*[]){yyvsp[0],NULL});
            yyval = mknode("#",(struct node*[]){mknode1("(="),yyvsp[-2],nl(),expTemp,mknode1(")"),nl(),NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[-2]->use_scope->varArr, yyval->use_scope);
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 1982 "y.tab.c"
    break;

  case 49: /* lhs: ID  */
#line 418 "parser.y"
           {
            yyval = mknode1(yyvsp[0]->token);
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 1992 "y.tab.c"
    break;

  case 50: /* lhs: ID '[' exp ']'  */
#line 423 "parser.y"
                        {
            yyval = mknode("#",(struct node*[]){mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-3]->token));
        }
#line 2002 "y.tab.c"
    break;

  case 51: /* lhs: '*' ID  */
#line 428 "parser.y"
                {
            yyval = mknode("#",(struct node*[]){mknode1("*"),mknode1(yyvsp[0]->token),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 2012 "y.tab.c"
    break;

  case 52: /* value: STRING_VALUE  */
#line 436 "parser.y"
                 {yyval = mknode1(yyvsp[0]->token);}
#line 2018 "y.tab.c"
    break;

  case 53: /* value: CHAR_VALUE  */
#line 437 "parser.y"
                 {yyval = mknode1(yyvsp[0]->token);}
#line 2024 "y.tab.c"
    break;

  case 54: /* value: TRUE_  */
#line 438 "parser.y"
            {yyval = mknode1("TRUE");}
#line 2030 "y.tab.c"
    break;

  case 55: /* value: FALSE_  */
#line 439 "parser.y"
             {yyval = mknode1("FALSE");}
#line 2036 "y.tab.c"
    break;

  case 56: /* value: NULL_  */
#line 440 "parser.y"
            {yyval = mknode1("NULL");}
#line 2042 "y.tab.c"
    break;

  case 57: /* value: HEX_VALUE  */
#line 441 "parser.y"
                {yyval = mknode1(yyvsp[0]->token);}
#line 2048 "y.tab.c"
    break;

  case 58: /* value: DIGITS_VALUE  */
#line 442 "parser.y"
                   {yyval = mknode1(yyvsp[0]->token);}
#line 2054 "y.tab.c"
    break;

  case 59: /* value: REAL_VALUE  */
#line 443 "parser.y"
                 {yyval = mknode1(yyvsp[0]->token);}
#line 2060 "y.tab.c"
    break;

  case 60: /* var_st: VAR var_list ';'  */
#line 447 "parser.y"
                         {
            yyval = mknode("#",(struct node*[]){mknode1("(VAR ")
            ,nl()
            ,mknode("",(struct node*[]){yyvsp[-1],NULL})
            ,nl()
            ,mknode1(")"),nl(),NULL});
            yyval->scope = newScope();
            get_var_list(yyvsp[-1],yyval->scope->varArr);
            
        }
#line 2075 "y.tab.c"
    break;

  case 61: /* var_st: STRING var_string_list ';'  */
#line 457 "parser.y"
                                    {
            yyval = mknode("#",(struct node*[]){mknode1("(VAR_STRING ")
            ,nl()
            ,mknode("",(struct node*[]){yyvsp[-1],NULL})
            ,nl()
            ,mknode1(")"),nl(),NULL});
            yyval->scope = newScope();
            get_var_string_list(yyvsp[-1],yyval->scope->varArr);
        }
#line 2089 "y.tab.c"
    break;

  case 62: /* var_list: var_op ':' type  */
#line 469 "parser.y"
                        {yyval = mknode("#",(struct node*[]){yyvsp[-2],nl(),mknode1("Type: "),yyvsp[0],NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type;}
#line 2095 "y.tab.c"
    break;

  case 63: /* var_list: var_op ',' var_list  */
#line 470 "parser.y"
                             {yyval = mknode("#",(struct node*[]){yyvsp[-2],nl(),yyvsp[0],NULL});yyval->type = yyvsp[0]->type;yyvsp[-2]->type = yyvsp[0]->type; }
#line 2101 "y.tab.c"
    break;

  case 64: /* var_op: ID  */
#line 474 "parser.y"
           {yyval = mknode1(yyvsp[0]->token);}
#line 2107 "y.tab.c"
    break;

  case 65: /* var_op: assignment_st  */
#line 475 "parser.y"
                       {yyval = mknode("#ass_in_var",(struct node*[]){yyvsp[0],NULL});}
#line 2113 "y.tab.c"
    break;

  case 66: /* var_string_list: var_string_opt  */
#line 479 "parser.y"
                       {yyval = mknode("#",(struct node*[]){yyvsp[0],nl(),NULL});}
#line 2119 "y.tab.c"
    break;

  case 67: /* var_string_list: var_string_opt ',' var_string_list  */
#line 480 "parser.y"
                                            {yyval = mknode("#",(struct node*[]){yyvsp[-2],nl(),yyvsp[0],NULL});}
#line 2125 "y.tab.c"
    break;

  case 68: /* var_string_opt: ID '[' exp ']'  */
#line 484 "parser.y"
                       {yyval = mknode("#",(struct node*[]){mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});}
#line 2131 "y.tab.c"
    break;

  case 69: /* var_string_opt: assignment_st  */
#line 485 "parser.y"
                       {yyval = mknode("#ass_in_str",(struct node*[]){yyvsp[0],NULL});}
#line 2137 "y.tab.c"
    break;

  case 70: /* func_call: ID '(' exp_list ')'  */
#line 489 "parser.y"
                            {
            yyval = mknode("#",(struct node*[]){mknode1("function call "),mknode1(yyvsp[-3]->token),mknode1("("),yyvsp[-1],mknode1(")"),NULL});
            yyval->use_scope = newScope();
            add_args_to_scope(yyvsp[-1], yyval->use_scope);
            appendFunctionArr(yyval->use_scope->funcsArr, newFunction(yyvsp[-3]->token,NONE_T,newVarArr()));
        }
#line 2148 "y.tab.c"
    break;

  case 71: /* exp_list: exp  */
#line 498 "parser.y"
            {yyval = mknode("#exp_list",(struct node*[]){yyvsp[0],NULL});}
#line 2154 "y.tab.c"
    break;

  case 72: /* exp_list: exp ',' exp_list  */
#line 499 "parser.y"
                           {yyval = mknode("#exp_list",(struct node*[]){yyvsp[-2],mknode1(","),yyvsp[0],NULL});}
#line 2160 "y.tab.c"
    break;

  case 73: /* exp_list: %empty  */
#line 500 "parser.y"
          {yyval=mknode1("#");}
#line 2166 "y.tab.c"
    break;

  case 74: /* exp: exp '+' exp  */
#line 504 "parser.y"
                      {yyval = expNode("( +",yyvsp[-2],yyvsp[0]);}
#line 2172 "y.tab.c"
    break;

  case 75: /* exp: exp '-' exp  */
#line 505 "parser.y"
                      {yyval = expNode("( -",yyvsp[-2],yyvsp[0]);}
#line 2178 "y.tab.c"
    break;

  case 76: /* exp: exp '*' exp  */
#line 506 "parser.y"
                      {yyval = expNode("( *",yyvsp[-2],yyvsp[0]);}
#line 2184 "y.tab.c"
    break;

  case 77: /* exp: exp '/' exp  */
#line 507 "parser.y"
                      {yyval = expNode("( /",yyvsp[-2],yyvsp[0]);}
#line 2190 "y.tab.c"
    break;

  case 78: /* exp: exp EQEQ exp  */
#line 508 "parser.y"
                       {yyval = expNode("( ==",yyvsp[-2],yyvsp[0]);}
#line 2196 "y.tab.c"
    break;

  case 79: /* exp: exp NOT_EQ exp  */
#line 509 "parser.y"
                         {yyval = expNode("( !=",yyvsp[-2],yyvsp[0]);}
#line 2202 "y.tab.c"
    break;

  case 80: /* exp: exp '<' exp  */
#line 510 "parser.y"
                      {yyval = expNode("( <",yyvsp[-2],yyvsp[0]);}
#line 2208 "y.tab.c"
    break;

  case 81: /* exp: exp SMALL_EQ exp  */
#line 511 "parser.y"
                           {yyval = expNode("( <=",yyvsp[-2],yyvsp[0]);}
#line 2214 "y.tab.c"
    break;

  case 82: /* exp: exp '>' exp  */
#line 512 "parser.y"
                      {yyval = expNode("( >",yyvsp[-2],yyvsp[0]);}
#line 2220 "y.tab.c"
    break;

  case 83: /* exp: exp BIG_EQ exp  */
#line 513 "parser.y"
                         {yyval = expNode("( >=",yyvsp[-2],yyvsp[0]);}
#line 2226 "y.tab.c"
    break;

  case 84: /* exp: exp OR exp  */
#line 514 "parser.y"
                     {yyval = expNode("( ||",yyvsp[-2],yyvsp[0]);}
#line 2232 "y.tab.c"
    break;

  case 85: /* exp: exp AND exp  */
#line 515 "parser.y"
                      {yyval = expNode("( &&",yyvsp[-2],yyvsp[0]);}
#line 2238 "y.tab.c"
    break;

  case 86: /* exp: '!' exp  */
#line 516 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){mknode1("!"),nl(),yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2249 "y.tab.c"
    break;

  case 87: /* exp: ID  */
#line 522 "parser.y"
             {
            yyval = mknode1(yyvsp[0]->token);
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 2259 "y.tab.c"
    break;

  case 88: /* exp: func_call  */
#line 527 "parser.y"
                    {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2270 "y.tab.c"
    break;

  case 89: /* exp: '|' ID '|'  */
#line 533 "parser.y"
                     {
            yyval = mknode("#",(struct node*[]){mknode1("lenOf("),mknode1(yyvsp[-1]->token),mknode1(")"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-1]->token));
        }
#line 2280 "y.tab.c"
    break;

  case 90: /* exp: '(' exp ')'  */
#line 538 "parser.y"
                      {yyval = yyvsp[-1];}
#line 2286 "y.tab.c"
    break;

  case 91: /* exp: '&' ID  */
#line 539 "parser.y"
                 {
            yyval = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1(yyvsp[0]->token),mknode1(")"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));    
        }
#line 2296 "y.tab.c"
    break;

  case 92: /* exp: '&' ID '[' exp ']'  */
#line 544 "parser.y"
                             {
            yyval = mknode("#",(struct node*[]){mknode1("addressOf("),mknode1(yyvsp[-3]->token),mknode1("["),yyvsp[-1],mknode1("]"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[-3]->token));
            addVarArrToScope(yyvsp[-1]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[-1]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2308 "y.tab.c"
    break;

  case 93: /* exp: '*' ID  */
#line 551 "parser.y"
                 {
            yyval = mknode("#",(struct node*[]){mknode1("dereference("),mknode1(yyvsp[0]->token),mknode1(")"),NULL});
            yyval->use_scope = newScope();
            appendVarArr(yyval->use_scope->varArr, newVar_(yyvsp[0]->token));
        }
#line 2318 "y.tab.c"
    break;

  case 94: /* exp: value  */
#line 556 "parser.y"
                {
            yyval = mknode("#",(struct node*[]){yyvsp[0],NULL});
            yyval->use_scope = newScope();
        }
#line 2327 "y.tab.c"
    break;

  case 95: /* exp: '-' exp  */
#line 560 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){mknode1("-"),yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2338 "y.tab.c"
    break;

  case 96: /* exp: '+' exp  */
#line 566 "parser.y"
                  {
            yyval = mknode("#",(struct node*[]){mknode1("+"),yyvsp[0],NULL});
            yyval->use_scope = newScope();
            addVarArrToScope(yyvsp[0]->use_scope->varArr, yyval->use_scope);
            addFunctionArrToScope(yyvsp[0]->use_scope->funcsArr, yyval->use_scope);
        }
#line 2349 "y.tab.c"
    break;


#line 2353 "y.tab.c"

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

#line 575 "parser.y"


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
    /* semanticsCheck(temp); */
}

int yyerror(char* e){
    int yydebug = 1;
    fflush(stdout);
    fprintf(stderr,"Error %s at Line %d\n",e,yylineno);
    fprintf(stderr,"%s Rejected\n",yytext);
    return 0;
}
