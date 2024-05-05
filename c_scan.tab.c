/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     INLINE = 289,
     RESTRICT = 290,
     CHAR = 291,
     SHORT = 292,
     INT = 293,
     LONG = 294,
     SIGNED = 295,
     UNSIGNED = 296,
     FLOAT = 297,
     DOUBLE = 298,
     CONST = 299,
     VOLATILE = 300,
     VOID = 301,
     BOOL = 302,
     COMPLEX = 303,
     IMAGINARY = 304,
     STRUCT = 305,
     UNION = 306,
     ENUM = 307,
     ELLIPSIS = 308,
     CASE = 309,
     DEFAULT = 310,
     IF = 311,
     ELSE = 312,
     SWITCH = 313,
     WHILE = 314,
     DO = 315,
     FOR = 316,
     GOTO = 317,
     CONTINUE = 318,
     BREAK = 319,
     RETURN = 320
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define INLINE 289
#define RESTRICT 290
#define CHAR 291
#define SHORT 292
#define INT 293
#define LONG 294
#define SIGNED 295
#define UNSIGNED 296
#define FLOAT 297
#define DOUBLE 298
#define CONST 299
#define VOLATILE 300
#define VOID 301
#define BOOL 302
#define COMPLEX 303
#define IMAGINARY 304
#define STRUCT 305
#define UNION 306
#define ENUM 307
#define ELLIPSIS 308
#define CASE 309
#define DEFAULT 310
#define IF 311
#define ELSE 312
#define SWITCH 313
#define WHILE 314
#define DO 315
#define FOR 316
#define GOTO 317
#define CONTINUE 318
#define BREAK 319
#define RETURN 320




/* Copy the first part of user declarations.  */
#line 1 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "c_scan_common.h"

#define YYERROR_VERBOSE 1
#define YYDEBUG 1
int yylex();
void yyerror(const char *s);
extern Node *struct_link_list;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
{
	struct SYMBOL_INFO_T *symbol_info;
	struct Param_t_list *param_list;
	struct Function_D *function_d;
	struct Function_Pre *function_pre;
}
/* Line 193 of yacc.c.  */
#line 246 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 259 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  239
/* YYNRULES -- Number of states.  */
#define YYNSTATES  401

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,     2,     2,     2,    81,    75,     2,
       4,     5,     3,    76,    74,    77,    71,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,    89,
      82,    88,    83,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    85,    73,    78,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    50,    58,    60,    64,    66,
      69,    72,    75,    78,    83,    85,    87,    89,    91,    93,
      95,    97,   102,   104,   108,   112,   116,   118,   122,   126,
     128,   132,   136,   138,   142,   146,   150,   154,   156,   160,
     164,   166,   170,   172,   176,   178,   182,   184,   188,   190,
     194,   196,   202,   204,   208,   210,   212,   214,   216,   218,
     220,   222,   224,   226,   228,   230,   232,   236,   238,   241,
     245,   247,   250,   252,   255,   257,   260,   262,   265,   267,
     271,   273,   277,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   315,   317,   323,   328,   331,   334,   336,   338,   340,
     343,   347,   350,   352,   355,   357,   359,   363,   365,   368,
     372,   377,   383,   389,   396,   399,   401,   405,   407,   411,
     413,   415,   417,   419,   422,   424,   426,   430,   436,   441,
     446,   453,   460,   466,   471,   475,   480,   485,   489,   491,
     494,   497,   501,   503,   506,   508,   512,   514,   518,   521,
     524,   526,   528,   532,   534,   537,   539,   541,   544,   548,
     551,   555,   559,   564,   568,   573,   576,   580,   584,   589,
     591,   595,   600,   602,   605,   609,   614,   617,   619,   622,
     626,   629,   631,   633,   635,   637,   639,   641,   645,   650,
     654,   657,   661,   663,   666,   668,   670,   672,   675,   681,
     689,   695,   701,   709,   716,   724,   731,   739,   743,   746,
     749,   752,   756,   758,   761,   763,   765,   770,   774,   776
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     155,     0,    -1,     6,    -1,     7,    -1,     8,    -1,     4,
     110,     5,    -1,    91,    -1,    92,    69,   110,    70,    -1,
      92,     4,     5,    -1,    92,     4,    93,     5,    -1,    92,
      71,     6,    -1,    92,    10,     6,    -1,    92,    11,    -1,
      92,    12,    -1,     4,   138,     5,    72,   142,    73,    -1,
       4,   138,     5,    72,   142,    74,    73,    -1,   108,    -1,
      93,    74,   108,    -1,    92,    -1,    11,    94,    -1,    12,
      94,    -1,    95,    96,    -1,     9,    94,    -1,     9,     4,
     138,     5,    -1,    75,    -1,     3,    -1,    76,    -1,    77,
      -1,    78,    -1,    79,    -1,    94,    -1,     4,   138,     5,
      96,    -1,    96,    -1,    97,     3,    96,    -1,    97,    80,
      96,    -1,    97,    81,    96,    -1,    97,    -1,    98,    76,
      97,    -1,    98,    77,    97,    -1,    98,    -1,    99,    13,
      98,    -1,    99,    14,    98,    -1,    99,    -1,   100,    82,
      99,    -1,   100,    83,    99,    -1,   100,    15,    99,    -1,
     100,    16,    99,    -1,   100,    -1,   101,    17,   100,    -1,
     101,    18,   100,    -1,   101,    -1,   102,    75,   101,    -1,
     102,    -1,   103,    84,   102,    -1,   103,    -1,   104,    85,
     103,    -1,   104,    -1,   105,    19,   104,    -1,   105,    -1,
     106,    20,   105,    -1,   106,    -1,   106,    86,   110,    87,
     107,    -1,   107,    -1,    94,   109,   108,    -1,    88,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,
     108,    -1,   110,    74,   108,    -1,   107,    -1,   113,    89,
      -1,   113,   114,    89,    -1,   116,    -1,   116,   113,    -1,
     117,    -1,   117,   113,    -1,   128,    -1,   128,   113,    -1,
     129,    -1,   129,   113,    -1,   115,    -1,   114,    74,   115,
      -1,   130,    -1,   130,    88,   141,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1,    49,    -1,    39,
      -1,    40,    -1,    41,    -1,    42,    -1,    45,    -1,    46,
      -1,    43,    -1,    44,    -1,    50,    -1,    51,    -1,    52,
      -1,   118,    -1,   125,    -1,    31,    -1,   119,     6,    72,
     120,    73,    -1,   119,    72,   120,    73,    -1,   119,     6,
      -1,   119,    31,    -1,    53,    -1,    54,    -1,   121,    -1,
     120,   121,    -1,   122,   123,    89,    -1,   117,   122,    -1,
     117,    -1,   128,   122,    -1,   128,    -1,   124,    -1,   123,
      74,   124,    -1,   130,    -1,    87,   111,    -1,   130,    87,
     111,    -1,    55,    72,   126,    73,    -1,    55,     6,    72,
     126,    73,    -1,    55,    72,   126,    74,    73,    -1,    55,
       6,    72,   126,    74,    73,    -1,    55,     6,    -1,   127,
      -1,   126,    74,   127,    -1,     6,    -1,     6,    88,   111,
      -1,    47,    -1,    38,    -1,    48,    -1,    37,    -1,   132,
     131,    -1,   131,    -1,     6,    -1,     4,   130,     5,    -1,
     131,    69,   133,   108,    70,    -1,   131,    69,   133,    70,
      -1,   131,    69,   108,    70,    -1,   131,    69,    34,   133,
     108,    70,    -1,   131,    69,   133,    34,   108,    70,    -1,
     131,    69,   133,     3,    70,    -1,   131,    69,     3,    70,
      -1,   131,    69,    70,    -1,   131,     4,   134,     5,    -1,
     131,     4,   137,     5,    -1,   131,     4,     5,    -1,     3,
      -1,     3,   133,    -1,     3,   132,    -1,     3,   133,   132,
      -1,   128,    -1,   133,   128,    -1,   135,    -1,   135,    74,
      56,    -1,   136,    -1,   135,    74,   136,    -1,   113,   130,
      -1,   113,   139,    -1,   113,    -1,     6,    -1,   137,    74,
       6,    -1,   122,    -1,   122,   139,    -1,   132,    -1,   140,
      -1,   132,   140,    -1,     4,   139,     5,    -1,    69,    70,
      -1,    69,   108,    70,    -1,   140,    69,    70,    -1,   140,
      69,   108,    70,    -1,    69,     3,    70,    -1,   140,    69,
       3,    70,    -1,     4,     5,    -1,     4,   134,     5,    -1,
     140,     4,     5,    -1,   140,     4,   134,     5,    -1,   108,
      -1,    72,   142,    73,    -1,    72,   142,    74,    73,    -1,
     141,    -1,   143,   141,    -1,   142,    74,   141,    -1,   142,
      74,   143,   141,    -1,   144,    88,    -1,   145,    -1,   144,
     145,    -1,    69,   111,    70,    -1,    71,     6,    -1,   147,
      -1,   148,    -1,   151,    -1,   152,    -1,   153,    -1,   154,
      -1,     6,    87,   146,    -1,    57,   111,    87,   146,    -1,
      58,    87,   146,    -1,    72,    73,    -1,    72,   149,    73,
      -1,   150,    -1,   149,   150,    -1,   112,    -1,   146,    -1,
      89,    -1,   110,    89,    -1,    59,     4,   110,     5,   146,
      -1,    59,     4,   110,     5,   146,    60,   146,    -1,    61,
       4,   110,     5,   146,    -1,    62,     4,   110,     5,   146,
      -1,    63,   146,    62,     4,   110,     5,    89,    -1,    64,
       4,   151,   151,     5,   146,    -1,    64,     4,   151,   151,
     110,     5,   146,    -1,    64,     4,   112,   151,     5,   146,
      -1,    64,     4,   112,   151,   110,     5,   146,    -1,    65,
       6,    89,    -1,    66,    89,    -1,    67,    89,    -1,    68,
      89,    -1,    68,   110,    89,    -1,   156,    -1,   155,   156,
      -1,   157,    -1,   112,    -1,   113,   130,   158,   148,    -1,
     113,   130,   148,    -1,   112,    -1,   158,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    46,    47,    48,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    65,    66,    70,    71,
      72,    73,    74,    75,    79,    80,    81,    82,    83,    84,
      88,    89,    93,    94,    95,    96,   100,   101,   102,   106,
     107,   108,   112,   113,   114,   115,   116,   120,   121,   122,
     126,   127,   131,   132,   136,   137,   141,   142,   146,   147,
     151,   152,   156,   157,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   175,   176,   180,   184,   189,
     249,   275,   307,   325,   357,   362,   395,   400,   408,   412,
     420,   424,   432,   433,   434,   435,   436,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   458,   471,   473,   484,   488,   492,   499,   500,
     504,   508,   509,   510,   511,   515,   516,   520,   524,   525,
     532,   533,   534,   535,   536,   540,   541,   545,   546,   550,
     551,   552,   556,   560,   568,   578,   588,   596,   601,   606,
     611,   616,   621,   626,   632,   637,   658,   681,   697,   708,
     712,   727,   745,   746,   751,   755,   762,   772,   784,   814,
     835,   842,   851,   863,   864,   868,   872,   876,   884,   885,
     886,   887,   888,   889,   890,   891,   892,   896,   897,   906,
     907,   908,   912,   913,   914,   915,   919,   923,   924,   928,
     929,   933,   934,   935,   936,   937,   938,   942,   943,   944,
     948,   949,   953,   954,   958,   962,   966,   967,   971,   972,
     973,   977,   978,   979,   980,   981,   985,   992,   993,   994,
     995,   996,  1000,  1001,  1005,  1010,  1018,  1031,  1095,  1099
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'*'", "'('", "')'", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "RESTRICT", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID",
  "BOOL", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS",
  "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'['", "']'", "'.'", "'{'", "'}'", "','",
  "'&'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'",
  "'|'", "'?'", "':'", "'='", "';'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    42,    40,    41,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,    91,
      93,    46,   123,   125,    44,    38,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    58,    61,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      94,    94,    94,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    97,    97,    98,    98,    98,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   118,   118,   119,   119,   120,   120,
     121,   122,   122,   122,   122,   123,   123,   124,   124,   124,
     125,   125,   125,   125,   125,   126,   126,   127,   127,   128,
     128,   128,   129,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   132,   132,
     132,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     136,   137,   137,   138,   138,   139,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   141,
     141,   141,   142,   142,   142,   142,   143,   144,   144,   145,
     145,   146,   146,   146,   146,   146,   146,   147,   147,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     152,   153,   153,   153,   153,   153,   153,   154,   154,   154,
     154,   154,   155,   155,   156,   156,   157,   157,   158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     2,     2,     1,     1,     1,     2,
       3,     2,     1,     2,     1,     1,     3,     1,     2,     3,
       4,     5,     5,     6,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     1,     3,     5,     4,     4,
       6,     6,     5,     4,     3,     4,     4,     3,     1,     2,
       2,     3,     1,     2,     1,     3,     1,     3,     2,     2,
       1,     1,     3,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     2,     3,     4,     2,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     2,     1,     1,     1,     2,     5,     7,
       5,     5,     7,     6,     7,     6,     7,     3,     2,     2,
       2,     3,     1,     2,     1,     1,     4,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   111,    92,    93,    94,    95,    96,   142,   140,    98,
      99,   100,   101,   104,   105,   102,   103,   139,   141,    97,
     106,   107,   108,   116,   117,     0,   235,     0,    80,    82,
     109,     0,   110,    84,    86,     0,   232,   234,   134,     0,
     158,     0,   145,    78,     0,    88,    90,   144,     0,    81,
      83,   114,   115,     0,    85,    87,     1,   233,     0,   137,
       0,   135,   162,   160,   159,     0,     0,    79,     0,     0,
     238,     0,   237,     0,     0,     0,   143,     0,   122,     0,
     118,     0,   124,     0,     0,   130,     0,   163,   161,   146,
      89,    90,    25,     0,     2,     3,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,    24,    26,    27,    28,    29,   216,     6,    18,
      30,     0,    32,    36,    39,    42,    47,    50,    52,    54,
      56,    58,    60,    62,    75,     0,   214,   215,   201,   202,
       0,   212,   203,   204,   205,   206,     2,     0,   189,    91,
     239,   236,   157,   171,   170,     0,   164,   166,     0,    25,
       0,   154,     0,     0,     0,   121,   113,   119,     0,     0,
     125,   127,   123,   131,     0,    30,    77,   138,   132,   136,
       0,   173,     0,     0,     0,    22,     0,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   229,   230,
       0,     0,     0,    12,    13,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    64,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,   211,   213,     0,     0,   192,     0,     0,     0,   197,
       0,     0,   168,   175,   169,   176,   155,     0,   156,     0,
     153,     0,   149,    25,     0,   148,     0,   112,   128,     0,
     120,     0,   133,     5,     0,   175,   174,     0,   207,     0,
       0,     0,   209,     0,     0,     0,     0,     0,     0,   227,
     231,     8,     0,    16,    11,     0,    10,    63,    33,    34,
      35,    37,    38,    40,    41,    45,    46,    43,    44,    48,
      49,    51,    53,    55,    57,    59,     0,    76,     0,   200,
     190,     0,   193,   196,   198,   185,     0,     0,    25,   179,
       0,   177,     0,     0,   165,   167,   172,     0,   152,     0,
     147,   126,   129,     0,    31,    23,     0,   208,     0,     0,
       0,     0,     0,     0,     9,     0,     7,     0,   199,   191,
     194,     0,   186,   178,   183,   180,   187,     0,    25,   181,
       0,   150,   151,     0,   218,   220,   221,     0,     0,     0,
       0,     0,    17,    61,   195,   188,   184,   182,    14,     0,
       0,     0,   225,     0,   223,     0,    15,   219,   222,   226,
     224
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   118,   119,   292,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   218,
     135,   177,    26,    71,    44,    45,    28,    29,    30,    31,
      79,    80,    81,   169,   170,    32,    60,    61,    33,    34,
      65,    47,    48,    64,   326,   156,   157,   158,   182,   327,
     255,   245,   246,   247,   248,   249,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    35,    36,    37,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -304
static const yytype_int16 yypact[] =
{
    1167,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,    58,  -304,    51,  1167,  1167,
    -304,    66,  -304,  1167,  1167,   928,  -304,  -304,   -16,    82,
     244,   242,  -304,  -304,   -48,  -304,  1083,    80,   214,  -304,
    -304,    26,  -304,  1364,  -304,  -304,  -304,  -304,    82,    57,
     149,  -304,  -304,  -304,   244,    19,   242,  -304,   305,   749,
    -304,    51,  -304,  1296,  1141,   648,    80,  1364,  1364,  1217,
    -304,    77,  1364,   190,   913,  -304,    31,  -304,  -304,  -304,
    -304,    63,  -304,   595,   -28,  -304,  -304,   923,   942,   942,
     913,    85,   177,   223,   252,   516,   262,   266,   192,   200,
     322,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,   113,
     209,   913,  -304,    35,   110,   270,    74,   268,   229,   226,
     230,   299,    49,  -304,  -304,   100,  -304,  -304,  -304,  -304,
     384,  -304,  -304,  -304,  -304,  -304,  -304,   553,  -304,  -304,
    -304,  -304,  -304,  -304,   155,   318,   250,  -304,    11,   257,
     147,  -304,   291,   672,  1253,  -304,  -304,  -304,   913,   152,
    -304,   278,  -304,  -304,    64,  -304,  -304,  -304,  -304,  -304,
      17,   174,   369,   516,   595,  -304,   595,  -304,  -304,   288,
     516,   913,   913,   913,   314,   463,   290,  -304,  -304,  -304,
     178,   778,   379,  -304,  -304,   913,   380,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,   913,  -304,
     913,   913,   913,   913,   913,   913,   913,   913,   913,   913,
     913,   913,   913,   913,   913,   913,   913,   913,   913,   913,
    -304,  -304,  -304,   913,   383,  -304,   222,   749,   173,  -304,
     991,   788,  -304,   159,  -304,    98,  -304,  1338,  -304,   396,
    -304,   732,  -304,   333,   913,  -304,   336,  -304,  -304,    77,
    -304,   913,  -304,  -304,  1044,   156,  -304,   811,  -304,   409,
     435,   516,  -304,    18,    20,    44,   440,   401,   401,  -304,
    -304,  -304,    47,  -304,  -304,   118,  -304,  -304,  -304,  -304,
    -304,    35,    35,   110,   110,   270,   270,   270,   270,    74,
      74,   268,   229,   226,   230,   299,    52,  -304,   385,  -304,
    -304,   542,  -304,  -304,  -304,  -304,   448,   449,   388,  -304,
     394,    98,  1192,   826,  -304,  -304,  -304,   395,  -304,   398,
    -304,  -304,  -304,   553,  -304,   410,   410,  -304,   516,   516,
     516,   913,   836,   865,  -304,   913,  -304,   913,  -304,  -304,
    -304,   749,  -304,  -304,  -304,  -304,  -304,   476,   413,  -304,
     414,  -304,  -304,   225,   425,  -304,  -304,    53,   516,    55,
     516,    60,  -304,  -304,  -304,  -304,  -304,  -304,  -304,   696,
     516,   397,  -304,   516,  -304,   516,  -304,  -304,  -304,  -304,
    -304
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -304,  -304,  -304,  -304,   -22,  -304,  -108,    78,    81,    50,
      88,   254,   255,   253,   256,   284,  -304,   -81,   -68,  -304,
     -83,   -95,   -29,     0,  -304,   427,  -304,   -11,  -304,  -304,
     452,   -59,   -42,  -304,   261,  -304,   433,   -55,   -32,  -304,
     -18,   -36,   -34,   -64,   -70,  -304,   269,  -304,    87,   -13,
     -56,   -67,   188,  -303,  -304,   285,   -90,  -304,    97,  -304,
     392,  -181,  -304,  -304,  -304,  -304,   499,  -304,  -304
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      27,   148,   149,   176,   155,   189,    63,   162,    62,    46,
     180,   163,    76,   219,   288,   194,   258,    70,   361,   176,
     167,    82,   273,   348,    89,   349,    66,   200,    49,    50,
      88,   179,    87,    54,    55,    27,   165,    59,   220,   136,
     172,    67,    78,    62,   150,    82,    82,    82,    91,   350,
      82,   181,   354,    91,    40,    41,    58,    42,   391,   183,
     393,    82,   175,   171,    38,   395,    78,    78,    78,   237,
      59,    78,    51,   268,   154,   185,   187,   188,   175,   148,
      40,    41,    78,    42,    74,   259,   361,   176,    59,   227,
     228,   239,   239,   278,   239,   266,   261,    52,    77,   175,
     282,   180,   332,   180,   178,   167,   352,   353,   283,   284,
     285,   136,   298,   299,   300,   221,   222,   201,   239,   179,
     253,   355,   295,   202,   203,   204,   239,   239,    62,   239,
      39,    87,    82,   293,   239,   238,   252,   272,    53,   357,
      43,   254,   181,    72,   181,    84,   175,   275,   318,    75,
     297,    69,    82,    78,    82,   316,   229,   230,    40,   250,
     274,    42,   176,   250,   168,    42,   287,   333,   276,   344,
     151,   317,   190,    78,   239,    78,   342,    40,   274,   148,
     322,   191,   205,   330,   206,     8,   223,   224,   356,   240,
     176,   347,   239,   337,    17,    18,   339,   331,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   253,    76,    41,   331,
      42,   175,    85,    86,   251,   251,   269,   192,   251,    87,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     275,   270,   243,   251,   244,    40,    41,    40,    42,   175,
     154,   171,   239,   148,   360,   175,   193,   154,   374,   375,
     376,   323,   367,   173,   174,   370,   195,   290,   377,   379,
     381,   279,   196,   280,   154,   148,   383,   305,   306,   307,
     308,   197,     8,   225,   226,   231,   232,   382,   392,   198,
     394,    17,    18,   148,   384,   320,   321,   217,   388,   389,
     397,   301,   302,   399,   233,   400,   303,   304,    92,    93,
     234,    94,    95,    96,    97,   235,    98,    99,   236,   309,
     310,   148,   360,   256,   257,    92,    93,   260,   146,    95,
      96,    97,   154,    98,    99,   175,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   262,   100,   101,   102,   271,   103,   104,   105,   106,
     107,   108,   109,   110,   277,   281,   286,    68,   111,   289,
     112,   113,   114,   115,   116,   294,   296,    92,    93,   319,
      94,    95,    96,    97,   117,    98,    99,   112,   113,   114,
     115,   116,   336,   338,    92,    93,   340,   146,    95,    96,
      97,   199,    98,    99,   345,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     346,   100,   101,   102,   351,   103,   104,   105,   106,   107,
     108,   109,   110,   362,   363,   358,    68,   241,   364,   112,
     113,   114,   115,   116,   365,   371,    92,    93,   372,   146,
      95,    96,    97,   117,    98,    99,   112,   113,   114,   115,
     116,   385,   343,   386,   387,   390,   398,   311,   313,   312,
     117,    83,   314,    90,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    92,
      93,   315,    94,    95,    96,    97,   335,    98,    99,   164,
     341,   373,   242,   324,    57,     0,     0,     0,   112,   113,
     114,   115,   116,     0,     0,    92,    93,     0,   146,    95,
      96,    97,   117,    98,    99,     0,    92,    93,     0,   146,
      95,    96,    97,     0,    98,    99,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   103,   104,   105,
     106,   107,   108,   109,   110,     0,     0,     0,    68,     0,
       0,   112,   113,   114,   115,   116,     0,     0,    92,    93,
       0,   146,    95,    96,    97,   117,    98,    99,     0,     0,
       0,   243,     0,   244,   147,   359,     0,   112,   113,   114,
     115,   116,   243,     0,   244,   147,     1,     0,   112,   113,
     114,   115,   116,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   159,    93,     0,   146,    95,    96,    97,     0,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   263,    93,     0,   146,    95,
      96,    97,   160,    98,    99,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,     0,    92,
      93,     0,   146,    95,    96,    97,   264,    98,    99,     0,
       8,     0,     0,     0,     0,     0,     0,     0,   161,    17,
      18,     0,     0,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,    92,    93,     0,   146,    95,
      96,    97,   265,    98,    99,     0,     0,   112,   113,   114,
     115,   116,    92,    93,     0,   146,    95,    96,    97,     0,
      98,    99,     0,     0,     0,   243,     0,   244,   147,   396,
       8,   112,   113,   114,   115,   116,     0,     0,     0,    17,
      18,    92,    93,   291,   146,    95,    96,    97,     0,    98,
      99,   328,    93,     0,   146,    95,    96,    97,     0,    98,
      99,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,     0,     0,    92,    93,     0,   146,    95,    96,
      97,   147,    98,    99,   112,   113,   114,   115,   116,   368,
      93,     0,   146,    95,    96,    97,     0,    98,    99,    92,
      93,   378,   146,    95,    96,    97,     0,    98,    99,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   329,     0,
       0,     0,     0,   112,   113,   114,   115,   116,    92,    93,
     380,   146,    95,    96,    97,     0,    98,    99,     0,     0,
       0,     0,     0,   343,     0,     0,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,   369,     0,     0,     0,
       0,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,   112,   113,   114,   115,   116,    92,    93,     0,   146,
      95,    96,    97,     0,    98,    99,    92,   184,    56,   146,
      95,    96,    97,     0,    98,    99,     0,     0,     0,     0,
     112,   113,   114,   115,   116,    92,   186,     0,   146,    95,
      96,    97,     0,    98,    99,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,   112,   113,
     114,   115,   116,     0,    40,   250,   325,    42,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    40,   274,   325,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     251,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,   152,   153,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   366,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
     166,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   334,     1,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25
};

static const yytype_int16 yycheck[] =
{
       0,    69,    69,    84,    74,   100,    40,    75,    40,    27,
      93,    75,    48,   121,   195,   105,     5,    46,   321,   100,
      79,    53,     5,     5,     5,     5,    74,   110,    28,    29,
      64,    86,    64,    33,    34,    35,    78,     6,     3,    68,
      82,    89,    53,    75,    73,    77,    78,    79,    66,     5,
      82,    93,     5,    71,     3,     4,    72,     6,     5,    87,
       5,    93,    84,    81,     6,     5,    77,    78,    79,    20,
       6,    82,     6,   168,    74,    97,    98,    99,   100,   147,
       3,     4,    93,     6,     4,    74,   389,   168,     6,    15,
      16,    74,    74,   183,    74,   163,   160,    31,    72,   121,
     190,   184,     4,   186,    73,   164,   287,   288,   191,   192,
     193,   140,   220,   221,   222,    80,    81,     4,    74,   174,
     154,    74,   205,    10,    11,    12,    74,    74,   160,    74,
      72,   163,   164,   201,    74,    86,   154,    73,    72,    87,
      89,   154,   184,    46,   186,    88,   168,   181,   243,    69,
     218,    88,   184,   164,   186,   238,    82,    83,     3,     4,
       4,     6,   243,     4,    87,     6,   195,    69,   181,   277,
      73,   239,    87,   184,    74,   186,   271,     3,     4,   247,
     247,     4,    69,   251,    71,    38,    76,    77,    70,    89,
     271,   281,    74,   261,    47,    48,   264,   253,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   250,   253,     4,   275,
       6,   243,    73,    74,    69,    69,    74,     4,    69,   261,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
     274,    89,    69,    69,    71,     3,     4,     3,     6,   271,
     250,   269,    74,   321,   321,   277,     4,   257,   348,   349,
     350,    88,   332,    73,    74,   333,     4,    89,   351,   352,
     353,   184,     6,   186,   274,   343,   357,   227,   228,   229,
     230,    89,    38,    13,    14,    17,    18,   355,   378,    89,
     380,    47,    48,   361,   361,    73,    74,    88,    73,    74,
     390,   223,   224,   393,    75,   395,   225,   226,     3,     4,
      84,     6,     7,     8,     9,    85,    11,    12,    19,   231,
     232,   389,   389,     5,    74,     3,     4,    70,     6,     7,
       8,     9,   332,    11,    12,   357,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    70,    57,    58,    59,    87,    61,    62,    63,    64,
      65,    66,    67,    68,     5,    87,    62,    72,    73,    89,
      75,    76,    77,    78,    79,     6,     6,     3,     4,     6,
       6,     7,     8,     9,    89,    11,    12,    75,    76,    77,
      78,    79,     6,    70,     3,     4,    70,     6,     7,     8,
       9,    89,    11,    12,     5,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       5,    57,    58,    59,     4,    61,    62,    63,    64,    65,
      66,    67,    68,     5,     5,    70,    72,    73,    70,    75,
      76,    77,    78,    79,    70,    70,     3,     4,    70,     6,
       7,     8,     9,    89,    11,    12,    75,    76,    77,    78,
      79,     5,    72,    70,    70,    60,    89,   233,   235,   234,
      89,    58,   236,    66,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     3,
       4,   237,     6,     7,     8,     9,   257,    11,    12,    77,
     269,   343,   140,   248,    35,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    -1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    89,    11,    12,    -1,     3,     4,    -1,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    76,    77,    78,    79,    -1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    89,    11,    12,    -1,    -1,
      -1,    69,    -1,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    69,    -1,    71,    72,    31,    -1,    75,    76,
      77,    78,    79,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     3,     4,    -1,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,     3,     4,    -1,     6,     7,
       8,     9,    34,    11,    12,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    34,    11,    12,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    47,
      48,    -1,    -1,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    70,    11,    12,    -1,    -1,    75,    76,    77,
      78,    79,     3,     4,    -1,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    69,    -1,    71,    72,    73,
      38,    75,    76,    77,    78,    79,    -1,    -1,    -1,    47,
      48,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,     3,     4,    -1,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    -1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    72,    11,    12,    75,    76,    77,    78,    79,     3,
       4,    -1,     6,     7,     8,     9,    -1,    11,    12,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    70,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,     3,     4,    -1,     6,
       7,     8,     9,    -1,    11,    12,     3,     4,     0,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,     3,     4,    -1,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    -1,     3,     4,     5,     6,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     5,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      73,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,   112,   113,   116,   117,
     118,   119,   125,   128,   129,   155,   156,   157,     6,    72,
       3,     4,     6,    89,   114,   115,   130,   131,   132,   113,
     113,     6,    31,    72,   113,   113,     0,   156,    72,     6,
     126,   127,   128,   132,   133,   130,    74,    89,    72,    88,
     112,   113,   148,   158,     4,    69,   131,    72,   117,   120,
     121,   122,   128,   126,    88,    73,    74,   128,   132,     5,
     115,   130,     3,     4,     6,     7,     8,     9,    11,    12,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    67,
      68,    73,    75,    76,    77,    78,    79,    89,    91,    92,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   110,   112,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     6,    72,   108,   141,
     112,   148,     5,     6,   113,   134,   135,   136,   137,     3,
      34,    70,   108,   133,   120,   122,    73,   121,    87,   123,
     124,   130,   122,    73,    74,    94,   107,   111,    73,   127,
     110,   122,   138,    87,     4,    94,     4,    94,    94,   111,
      87,     4,     4,     4,   146,     4,     6,    89,    89,    89,
     110,     4,    10,    11,    12,    69,    71,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    88,   109,    96,
       3,    80,    81,    76,    77,    13,    14,    15,    16,    82,
      83,    17,    18,    75,    84,    85,    19,    20,    86,    74,
      89,    73,   150,    69,    71,   141,   142,   143,   144,   145,
       4,    69,   130,   132,   139,   140,     5,    74,     5,    74,
      70,   133,    70,     3,    34,    70,   108,    73,   111,    74,
      89,    87,    73,     5,     4,   132,   139,     5,   146,   138,
     138,    87,   146,   110,   110,   110,    62,   112,   151,    89,
      89,     5,    93,   108,     6,   110,     6,   108,    96,    96,
      96,    97,    97,    98,    98,    99,    99,    99,    99,   100,
     100,   101,   102,   103,   104,   105,   110,   108,   111,     6,
      73,    74,   141,    88,   145,     5,   134,   139,     3,    70,
     108,   140,     4,    69,    56,   136,     6,   108,    70,   108,
      70,   124,   111,    72,    96,     5,     5,   146,     5,     5,
       5,     4,   151,   151,     5,    74,    70,    87,    70,    73,
     141,   143,     5,     5,    70,    70,     5,   134,     3,    70,
     108,    70,    70,   142,   146,   146,   146,   110,     5,   110,
       5,   110,   108,   107,   141,     5,    70,    70,    73,    74,
      60,     5,   146,     5,   146,     5,    73,   146,    89,   146,
     146
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 78:
#line 185 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		Function_Pre* dummy_next_node = (Function_Pre*)RW_MALLOC(sizeof(Function_Pre) );
		(yyval.function_pre) = dummy_next_node;
	;}
    break;

  case 79:
#line 190 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		/* $1 means ret type, $2 means init param list and fuction name may be also have "*" */
		Function_D *tem_fuc_trace = (yyvsp[(2) - (3)].function_d);
		SYMBOL_INFO_T *temp_symbol_info0 = (yyvsp[(1) - (3)].symbol_info);

		if (tem_fuc_trace->fun_type NEQ FUN_NO_FUNC) //this is function reduce
		{
			Function_Pre* next_node =(Function_Pre*)RW_MALLOC(sizeof(Function_Pre) );
			memset(next_node,0,sizeof(Function_Pre));
			next_node->function_d = (yyvsp[(2) - (3)].function_d);
			//next_node->fun_location_desc.file_name =
			next_node->fun_location_desc.line =next_node->function_d->func_loc.line;
			next_node->fun_location_desc.column =next_node->function_d->func_loc.column;
			next_node->ret_value_type = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
			memset(next_node->ret_value_type,0,MAX_SYMBOL_LEN);
			memcpy(next_node->ret_value_type,temp_symbol_info0->symbol_name, strlen(temp_symbol_info0->symbol_name));
			if(tem_fuc_trace->is_ret_val_point EQ 1)
			{
				strcat(next_node->ret_value_type," ");
				strcat(next_node->ret_value_type,tem_fuc_trace->point_str);
			}
			if (FUN_IS_FUNC_BUT_UNKOWN_TYPE NEQ tem_fuc_trace->fun_type)
			{
				assert(0);
			} else {
				tem_fuc_trace->fun_type = FUN_DECLARATON;
			}

			printf("FUCTION_NAME:%s\n",tem_fuc_trace->fun_name);
			print_params(tem_fuc_trace->param_list);
			printf("function type is \"%d\"\n", tem_fuc_trace->fun_type);
			printf("ret TYPE is \"%s\"\n", next_node->ret_value_type);
			printf("func:line %d, col: %d\n", next_node->fun_location_desc.line,next_node->fun_location_desc.column);

			(yyval.function_pre) = next_node;

		} else { // this is struct or other state reduce like struct declare, we can not add all struct to it
			Function_D *temp_symbol_info = (yyvsp[(2) - (3)].function_d);
                        printf("STRUCT OR UNION NAME--> \"%s\"\n",temp_symbol_info->fun_name );
                        if ((NULL NEQ temp_symbol_info) && (NULL NEQ temp_symbol_info->fun_name) )
                        {
				if( (strcmp(temp_symbol_info0->symbol_name, "typedef struct") == 0)
				  ||(strcmp(temp_symbol_info0->symbol_name, "struct") == 0) ){
					insertAtHead(&struct_link_list,temp_symbol_info->fun_name);
#ifdef BISON_DEBUG
                        		printf("BISON_DEBUG ADD STRUCT TO LIST -->\"%s\"\n",temp_symbol_info->fun_name );
#endif

				 }
                        }
                        FREE_FUNC_D_NODE((yyvsp[(2) - (3)].function_d));
                        Function_Pre* dummy_next_node = (Function_Pre*)RW_MALLOC(sizeof(Function_Pre) );
                        (yyval.function_pre) = dummy_next_node;

		}
	;}
    break;

  case 80:
#line 250 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(0);
		}
		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
		SYMBOL_INFO_T* cur_node = (yyvsp[(1) - (1)].symbol_info);
		SYMBOL_INFO_T* old_node = (yyval.symbol_info);
		if (cur_node NEQ old_node) {
			strcat(next_node->symbol_name,old_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node->symbol_name);
		} else {
			strcat(next_node->symbol_name,cur_node->symbol_name);
		}
		(yyval.symbol_info) = next_node;

        	if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
        	{
#ifdef BISON_DEBUG
        		//printf("BISON_DEBUG-->storage_class_specifier get token \"%s\"\n",next_node->symbol_name );
#endif
		}
	;}
    break;

  case 81:
#line 276 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(0);
		}
		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
		SYMBOL_INFO_T* cur_node = (yyvsp[(1) - (2)].symbol_info);
		SYMBOL_INFO_T* cur_node2 = (yyvsp[(2) - (2)].symbol_info);
		SYMBOL_INFO_T* old_node = (yyval.symbol_info);
		if ( (cur_node NEQ old_node) && (cur_node2 NEQ old_node) ) {
			strcat(next_node->symbol_name,old_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);
		} else {
			strcat(next_node->symbol_name,cur_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);
		}
		(yyval.symbol_info) = next_node;

		if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
		{
#ifdef BISON_DEBUG
			//printf("BISON_DEBUG-->storage_class_specifier2 get token \"%s\"\n",next_node->symbol_name );
#endif
		}
	;}
    break;

  case 82:
#line 308 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(0);
		}
		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
		SYMBOL_INFO_T* cur_node = (yyvsp[(1) - (1)].symbol_info);
		strcat(next_node->symbol_name,cur_node->symbol_name);
		(yyval.symbol_info) = next_node;
        	if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
        	{
#ifdef BISON_DEBUG
        		//printf("BISON_DEBUG-->storage_class_specifier3 get token \"%s\"\n",next_node->symbol_name );
#endif
		}
	;}
    break;

  case 83:
#line 326 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(0);
		}
		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
		SYMBOL_INFO_T* cur_node = (yyvsp[(1) - (2)].symbol_info);
		SYMBOL_INFO_T* cur_node2 = (yyvsp[(2) - (2)].symbol_info);
		SYMBOL_INFO_T* old_node = (yyval.symbol_info);
		if ( (cur_node NEQ old_node) && (cur_node2 NEQ old_node) ) {
			strcat(next_node->symbol_name,old_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);
		} else {
			strcat(next_node->symbol_name,cur_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);

		}
		(yyval.symbol_info) = next_node;

		if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
		{
#ifdef BISON_DEBUG
			//printf("BISON_DEBUG-->storage_class_specifier4 get token \"%s\"\n",next_node->symbol_name );
#endif
		}
	;}
    break;

  case 84:
#line 358 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.symbol_info) = (yyvsp[(1) - (1)].symbol_info);
	;}
    break;

  case 85:
#line 363 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
        		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
        		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
        		if (NULL EQ next_node->symbol_name) {
        			assert(0);
        		}
        		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
        		SYMBOL_INFO_T* cur_node = (yyvsp[(1) - (2)].symbol_info);
        		SYMBOL_INFO_T* cur_node2 = (yyvsp[(2) - (2)].symbol_info);
        		SYMBOL_INFO_T* old_node = (yyval.symbol_info);
        		if ( (cur_node NEQ old_node) && (cur_node2 NEQ old_node) ) {
        			strcat(next_node->symbol_name,old_node->symbol_name);
        			strcat(next_node->symbol_name," ");
        			strcat(next_node->symbol_name,cur_node->symbol_name);
        			strcat(next_node->symbol_name," ");
        			strcat(next_node->symbol_name,cur_node2->symbol_name);
        			//free buffer for current node
        		} else {
        			strcat(next_node->symbol_name,cur_node->symbol_name);
        			strcat(next_node->symbol_name," ");
        			strcat(next_node->symbol_name,cur_node2->symbol_name);

        		}
        		(yyval.symbol_info) = next_node;

        		if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
        		{
        #ifdef BISON_DEBUG
        			//printf("BISON_DEBUG-->storage_class_specifier5 get token \"%s\"\n",next_node->symbol_name );
        #endif
        		}
        	;}
    break;

  case 86:
#line 396 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {

	;}
    break;

  case 87:
#line 402 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.symbol_info) = (yyvsp[(2) - (2)].symbol_info);
        ;}
    break;

  case 88:
#line 409 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.function_d) = (yyvsp[(1) - (1)].function_d);
	;}
    break;

  case 89:
#line 413 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	//currently do not support
	;}
    break;

  case 90:
#line 421 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	 	(yyval.function_d) = (yyvsp[(1) - (1)].function_d);
	;}
    break;

  case 91:
#line 425 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.function_d) = (yyvsp[(1) - (3)].function_d);
	;}
    break;

  case 112:
#line 459 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		SYMBOL_INFO_T *temp_symbol_info = (yyvsp[(2) - (5)].symbol_info);
		if ((NULL NEQ temp_symbol_info) && (NULL NEQ temp_symbol_info->symbol_name) )
		{
			insertAtHead(&struct_link_list,temp_symbol_info->symbol_name);
#ifdef BISON_DEBUG
                	//printf("IDENTIFIER get token %s \n",temp_symbol_info->symbol_name );
#endif
		}

	;}
    break;

  case 114:
#line 474 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		SYMBOL_INFO_T *temp_symbol_info = (yyvsp[(2) - (2)].symbol_info);
		if ((NULL NEQ temp_symbol_info) && (NULL NEQ temp_symbol_info->symbol_name) )
		{
			insertAtHead(&struct_link_list,temp_symbol_info->symbol_name);
#ifdef BISON_DEBUG
			//printf("IDENTIFIER get token %s \n", temp_symbol_info->symbol_name);
#endif
		}
	;}
    break;

  case 116:
#line 489 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	  (yyval.symbol_info) = (yyvsp[(1) - (1)].symbol_info);
	;}
    break;

  case 117:
#line 493 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	  (yyval.symbol_info) = (yyvsp[(1) - (1)].symbol_info);
	;}
    break;

  case 127:
#line 521 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	  FREE_FUNC_D_NODE((yyvsp[(1) - (1)].function_d));
	;}
    break;

  case 129:
#line 526 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	 FREE_FUNC_D_NODE((yyvsp[(1) - (3)].function_d));
	;}
    break;

  case 143:
#line 561 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		SYMBOL_INFO_T *temp_symbol = (yyvsp[(1) - (2)].symbol_info);
		Function_D *temp_func_d = (yyvsp[(2) - (2)].function_d);
		temp_func_d->is_ret_val_point = 1;
		memcpy(temp_func_d->point_str,temp_symbol->symbol_name,strlen(temp_symbol->symbol_name));
            	(yyval.function_d) = (yyvsp[(2) - (2)].function_d);
        ;}
    break;

  case 144:
#line 569 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		Function_D *temp_func_d = (yyvsp[(1) - (1)].function_d);
		temp_func_d->is_ret_val_point = 0;
		(yyval.function_d) = (yyvsp[(1) - (1)].function_d);
	;}
    break;

  case 145:
#line 579 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		Function_D* next_node =(Function_D*)RW_MALLOC(sizeof(Function_D));
		memset(next_node,ZERO,sizeof(Function_D));
		SYMBOL_INFO_T *temp_id  = (yyvsp[(1) - (1)].symbol_info);
		next_node->fun_type = FUN_NO_FUNC;
		next_node->fun_name = strdup(temp_id->symbol_name);
		(yyval.function_d) = next_node;
		ASSIGN_SYMBOL_LOC_TO_FUNC_D((yyval.function_d),(yyvsp[(1) - (1)].symbol_info));
	;}
    break;

  case 146:
#line 589 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	 //currently we do not support like ----void *test(int(*Test2)(int a, int b) )-----
	 //we need rel the buffer
	 FREE_FUNC_D_NODE((yyvsp[(2) - (3)].function_d));
	 (yyval.function_d) = NULL;
	;}
    break;

  case 147:
#line 597 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	 FREE_FUNC_D_NODE((yyvsp[(1) - (5)].function_d));
	 (yyval.function_d) = NULL;
	;}
    break;

  case 148:
#line 602 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	FREE_FUNC_D_NODE((yyvsp[(1) - (4)].function_d));
	(yyval.function_d) = NULL;
	;}
    break;

  case 149:
#line 607 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	FREE_FUNC_D_NODE((yyvsp[(1) - (4)].function_d));
	(yyval.function_d) = NULL;
	;}
    break;

  case 150:
#line 612 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	FREE_FUNC_D_NODE((yyvsp[(1) - (6)].function_d));
	(yyval.function_d) = NULL;
	;}
    break;

  case 151:
#line 617 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	FREE_FUNC_D_NODE((yyvsp[(1) - (6)].function_d));
	(yyval.function_d) = NULL;
	;}
    break;

  case 152:
#line 622 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	FREE_FUNC_D_NODE((yyvsp[(1) - (5)].function_d));
	(yyval.function_d) = NULL;
	;}
    break;

  case 153:
#line 627 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	FREE_FUNC_D_NODE((yyvsp[(1) - (4)].function_d));
	(yyval.function_d) = NULL;
	;}
    break;

  case 154:
#line 633 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	FREE_FUNC_D_NODE((yyvsp[(1) - (3)].function_d));
	(yyval.function_d) = NULL;
	;}
    break;

  case 155:
#line 638 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		Param_t_list *temp_param_list = (yyvsp[(3) - (4)].param_list);//$1 is function name ;$3 is the fuction params
		Function_D *temp_symbol_info = (yyvsp[(1) - (4)].function_d);
		Function_D *next_node = (Function_D*)RW_MALLOC(sizeof(Function_D));
		memset(next_node,ZERO,sizeof(Function_D));
		next_node->param_list = temp_param_list;
		next_node->fun_name = temp_symbol_info->fun_name;
		next_node->fun_type = FUN_IS_FUNC_BUT_UNKOWN_TYPE;
		ASSIGN_FUNC_D_LOC_TO_FUNC_D(next_node,(yyvsp[(1) - (4)].function_d));

		//printf("FUN_IS_FUNC --> \"%s\"\n",next_node->fun_name ); //this is the only function decl
		if ((NULL NEQ temp_param_list) && (NULL NEQ temp_param_list->param_list) )
		{
#ifdef BISON_DEBUG
		  //print_params(temp_param_list);
		}
#endif
		(yyval.function_d) = next_node;
		RW_FREE((yyvsp[(1) - (4)].function_d));
	;}
    break;

  case 156:
#line 659 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
{
		Param_t_list *temp_param_list = (yyvsp[(3) - (4)].param_list);//$1 is function name ;$3 is the fuction params
		Function_D* temp_symbol_info = (yyvsp[(1) - (4)].function_d);
		Function_D* next_node = (Function_D*)RW_MALLOC(sizeof(Function_D));
		memset(next_node,ZERO,sizeof(Function_D));
		next_node->param_list = temp_param_list;
		next_node->fun_name = temp_symbol_info->fun_name;
		next_node->fun_type = FUN_IS_FUNC_BUT_UNKOWN_TYPE;
		ASSIGN_FUNC_D_LOC_TO_FUNC_D(next_node,(yyvsp[(1) - (4)].function_d));
		//printf("parameter_type_list:get token \"%s\"\n",next_node->fun_name ); //this is the only function decl
		if ((NULL NEQ temp_param_list) && (NULL NEQ temp_param_list->param_list) )
		{
#ifdef BISON_DEBUG
		  printf("parameter_type_list:get token \"%s\"\n",temp_param_list->param_list[0].param_type );
		}
#endif
		(yyval.function_d) = next_node;
		RW_FREE((yyvsp[(1) - (4)].function_d));
	}
	;}
    break;

  case 157:
#line 682 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		Function_D *temp_symbol_info = (yyvsp[(1) - (3)].function_d);
		Function_D* next_node = (Function_D*)RW_MALLOC(sizeof(Function_D));
		memset(next_node,ZERO,sizeof(Function_D));
		next_node->fun_name = temp_symbol_info->fun_name;
		next_node->fun_type = FUN_IS_FUNC_BUT_UNKOWN_TYPE;
		ASSIGN_FUNC_D_LOC_TO_FUNC_D(next_node,(yyvsp[(1) - (3)].function_d));
#ifdef BISON_DEBUG
		 //printf("function without params:\"%s\"\n",next_node->fun_name ); //this is the only function decl
#endif
		(yyval.function_d) = next_node;
		RW_FREE((yyvsp[(1) - (3)].function_d));
       ;}
    break;

  case 158:
#line 698 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		 SYMBOL_INFO_T *temp_symbol_info = (yyvsp[(1) - (1)].symbol_info);
		 SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
		 memset(next_node,0,sizeof(SYMBOL_INFO_T));
		 next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		 memset(next_node->symbol_name,0, MAX_SYMBOL_LEN);
		 strcat(next_node->symbol_name,temp_symbol_info->symbol_name);
		 ASSIGN_SYMBOL_LOC(next_node,temp_symbol_info);
		 (yyval.symbol_info) = next_node;
	;}
    break;

  case 159:
#line 709 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	 (yyval.symbol_info) = (yyvsp[(1) - (2)].symbol_info);
	;}
    break;

  case 160:
#line 713 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		 SYMBOL_INFO_T *temp_symbol_info = (yyvsp[(1) - (2)].symbol_info);
		 SYMBOL_INFO_T *temp_symbol_info2 = (yyvsp[(2) - (2)].symbol_info);
        	 SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
                 memset(next_node,0,sizeof(SYMBOL_INFO_T));
                 next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
                 memset(next_node->symbol_name,0, MAX_SYMBOL_LEN);
                 strcat(next_node->symbol_name,temp_symbol_info->symbol_name);
                 strcat(next_node->symbol_name," ");
                 strcat(next_node->symbol_name,temp_symbol_info2->symbol_name);
        	 ASSIGN_SYMBOL_LOC(next_node,temp_symbol_info2);
        	 (yyval.symbol_info) = next_node;

	;}
    break;

  case 161:
#line 728 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {

	 		SYMBOL_INFO_T *temp_symbol_info = (yyvsp[(1) - (3)].symbol_info);
         		 SYMBOL_INFO_T *temp_symbol_info2 = (yyvsp[(3) - (3)].symbol_info);
                 	 SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
                          memset(next_node,0,sizeof(SYMBOL_INFO_T));
                          next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
                          memset(next_node->symbol_name,0, MAX_SYMBOL_LEN);
                          strcat(next_node->symbol_name,temp_symbol_info->symbol_name);
                          strcat(next_node->symbol_name," ");
                          strcat(next_node->symbol_name,temp_symbol_info2->symbol_name);
                 	 ASSIGN_SYMBOL_LOC(next_node,temp_symbol_info2);
                 	 (yyval.symbol_info) = next_node;
	;}
    break;

  case 164:
#line 752 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.param_list) = (yyvsp[(1) - (1)].param_list);
	;}
    break;

  case 165:
#line 756 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.param_list) = (yyvsp[(1) - (3)].param_list);
	;}
    break;

  case 166:
#line 763 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		SYMBOL_INFO_T *temp_symbol_info= (yyvsp[(1) - (1)].symbol_info);
		Param_t_list* param_list = (Param_t_list*)RW_MALLOC(sizeof(Param_t_list));
		memset(param_list,0,sizeof(Param_t_list));
		memcpy(param_list->param_list[param_list->no_param].param_type,temp_symbol_info->symbol_name,strlen(temp_symbol_info->symbol_name));
		param_list->no_param++;
		(yyval.param_list) = param_list;

	;}
    break;

  case 167:
#line 773 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		SYMBOL_INFO_T *temp_symbol_info= (yyvsp[(3) - (3)].symbol_info);
		Param_t_list* param_list = (yyvsp[(1) - (3)].param_list);
		memcpy(param_list->param_list[param_list->no_param].param_type,temp_symbol_info->symbol_name,strlen(temp_symbol_info->symbol_name));
		param_list->no_param++;
		(yyval.param_list) = (yyvsp[(1) - (3)].param_list);

	;}
    break;

  case 168:
#line 785 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
				//do nothing used in  delarator,but if it is a point we need to return
				//we define it is function_d so cannot use symbol_info_t
                		SYMBOL_INFO_T *cur_node1 = (yyvsp[(1) - (2)].symbol_info);

                		Function_D *cur_node2 = (yyvsp[(2) - (2)].function_d);

                		SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
                		memset(next_node,ZERO,sizeof(SYMBOL_INFO_T));

                		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
                		if (NULL EQ next_node->symbol_name) {
                			assert(ZERO);
                		}
                		memset(next_node->symbol_name, ZERO, MAX_SYMBOL_LEN);

                		strcat(next_node->symbol_name,cur_node1->symbol_name);
                		if (1 EQ cur_node2->is_ret_val_point ) {
                			strcat(next_node->symbol_name," ");
                                        strcat(next_node->symbol_name,cur_node2->point_str);
                		}
                		(yyval.symbol_info) = next_node;
                		FREE_FUNC_D_NODE((yyvsp[(2) - (2)].function_d));
                		//print_symbols(next_node);
#ifdef BISON_DEBUG

#endif

	;}
    break;

  case 169:
#line 815 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		//do nothing used in abstract delarator,but if it is a point we need to return
		SYMBOL_INFO_T *cur_node1 = (yyvsp[(1) - (2)].symbol_info);
		SYMBOL_INFO_T *cur_node2 = (yyvsp[(2) - (2)].symbol_info);
		SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
		memset(next_node,ZERO,sizeof(SYMBOL_INFO_T));

		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(ZERO);
		}
		memset(next_node->symbol_name, ZERO, MAX_SYMBOL_LEN);

		strcat(next_node->symbol_name,cur_node1->symbol_name);
		if (ZERO EQ memcmp(cur_node2->symbol_name,"*",1) ) {
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);
		}
		(yyval.symbol_info) = next_node;
        ;}
    break;

  case 170:
#line 836 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.symbol_info) = (yyvsp[(1) - (1)].symbol_info);
        ;}
    break;

  case 171:
#line 843 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	  Param_t_list *next_node = (Param_t_list *)RW_MALLOC(sizeof(Param_t_list));
	  SYMBOL_INFO_T *temp_symbol_info= (yyvsp[(1) - (1)].symbol_info);
	  memset(next_node,0,sizeof(Param_t_list));
	  memcpy(next_node->param_list[next_node->no_param].param_type, temp_symbol_info->symbol_name, strlen(temp_symbol_info->symbol_name));
	  next_node->no_param++;
	  (yyval.param_list) = next_node;
	;}
    break;

  case 172:
#line 852 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {

	  Param_t_list *next_node = (yyvsp[(1) - (3)].param_list);
	  SYMBOL_INFO_T *temp_symbol_info= (yyvsp[(3) - (3)].symbol_info);
	  memcpy(next_node->param_list[next_node->no_param].param_type, temp_symbol_info->symbol_name, strlen(temp_symbol_info->symbol_name));
	  next_node->no_param++;
	  (yyval.param_list) = next_node;
        ;}
    break;

  case 175:
#line 869 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.symbol_info) = (yyvsp[(1) - (1)].symbol_info);
	;}
    break;

  case 176:
#line 873 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.symbol_info) = NULL;
	;}
    break;

  case 177:
#line 877 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		//abstract declarator usually used in runtime, we can not check it by using static analyzer
		(yyval.symbol_info) = NULL;
	;}
    break;

  case 186:
#line 893 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		RW_FREE((yyvsp[(2) - (3)].param_list));
	;}
    break;

  case 188:
#line 898 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		//abstract declarator usually used in runtime, we can not check it by using static analyzer
		//but we need to free buffer
		RW_FREE((yyvsp[(3) - (4)].param_list));
	;}
    break;

  case 214:
#line 959 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	 FREE_AST_NODE((yyvsp[(1) - (1)].function_pre));
	;}
    break;

  case 225:
#line 982 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		FREE_AST_NODE((yyvsp[(3) - (6)].function_pre));
	;}
    break;

  case 226:
#line 986 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		FREE_AST_NODE((yyvsp[(3) - (7)].function_pre));
	;}
    break;

  case 234:
#line 1006 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.function_pre) = (yyvsp[(1) - (1)].function_pre);
		FREE_AST_NODE((yyvsp[(1) - (1)].function_pre));
	;}
    break;

  case 235:
#line 1011 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.function_pre) = (yyvsp[(1) - (1)].function_pre);
		FREE_AST_NODE((yyvsp[(1) - (1)].function_pre));
	;}
    break;

  case 236:
#line 1019 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	/*
	for origin c grammer,it like this, we do not advise use this way, so we assert!
		int
		add_values (x, y)
		    int x;int y;
		{
		  return x + y;
		}
	*/
	assert(0);
	;}
    break;

  case 237:
#line 1032 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
	/* $1 means ret type, $2 means init param list and fuction name may be also have "*" */
	Function_D *tem_fuc_trace = (yyvsp[(2) - (3)].function_d);
	SYMBOL_INFO_T *temp_symbol_info0 = (yyvsp[(1) - (3)].symbol_info);

	if (tem_fuc_trace->fun_type NEQ FUN_NO_FUNC) //this is function reduce
	{
		Function_Pre* next_node =(Function_Pre*)RW_MALLOC(sizeof(Function_Pre) );
		memset(next_node,0,sizeof(Function_Pre));
		next_node->function_d = (yyvsp[(2) - (3)].function_d);
		//next_node->fun_location_desc.file_name =
		//next_node->fun_location_desc.line =
		//next_node->fun_location_desc.column =
		next_node->ret_value_type = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		memset(next_node->ret_value_type,0,MAX_SYMBOL_LEN);
		memcpy(next_node->ret_value_type,temp_symbol_info0->symbol_name, strlen(temp_symbol_info0->symbol_name));
		if(tem_fuc_trace->is_ret_val_point EQ 1)
		{
			strcat(next_node->ret_value_type," ");
			strcat(next_node->ret_value_type,tem_fuc_trace->point_str);
		}
		if (FUN_IS_FUNC_BUT_UNKOWN_TYPE NEQ tem_fuc_trace->fun_type)
		{
			assert(0);
		} else {
			tem_fuc_trace->fun_type = FUN_DEFINE;
		}

		printf("FUCTION_NAME:%s\n",tem_fuc_trace->fun_name);
		if (NULL NEQ tem_fuc_trace->param_list)
		{
		print_params(tem_fuc_trace->param_list);
		} else {
		printf("No params !\n");
		}

		printf("TYPE is \"%d\"\n", tem_fuc_trace->fun_type);
		printf("ret TYPE is \"%s\"\n", next_node->ret_value_type);
		(yyval.function_pre) = next_node;
	} else { // this is struct or other state reduce and it is also func
		//this will not reach
		assert(0);
		Function_D *temp_symbol_info = (yyvsp[(2) - (3)].function_d);
		printf("STRUCT OR UNION NAME--> \"%s\"\n",temp_symbol_info->fun_name );
		if ((NULL NEQ temp_symbol_info) && (NULL NEQ temp_symbol_info->fun_name) )
		{
			if( (strcmp(temp_symbol_info0->symbol_name, "typedef struct") == 0)
			  ||(strcmp(temp_symbol_info0->symbol_name, "struct") == 0) ){

				insertAtHead(&struct_link_list,temp_symbol_info->fun_name);
#ifdef BISON_DEBUG
				printf("BISON_DEBUG ADD STRUCT TO LIST -->\"%s\"\n",temp_symbol_info->fun_name );
#endif
			 (yyval.function_pre) = (yyvsp[(2) - (3)].function_d);
			 }
		}
		FREE_FUNC_D_NODE((yyvsp[(2) - (3)].function_d));

	}
;}
    break;

  case 238:
#line 1096 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.function_pre) = (yyvsp[(1) - (1)].function_pre);
	;}
    break;

  case 239:
#line 1100 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"
    {
		(yyval.function_pre) = (yyvsp[(2) - (2)].function_pre);
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 2925 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1104 "/Users/xumanwei/Documents/CLION_PROJ/c_scan_pro/c_scan.y"


extern char* yytext;
extern int column;

void yyerror(const char *s)

{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
