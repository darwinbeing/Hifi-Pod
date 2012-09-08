
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 15 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"

#include "cli.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <s4.h>
#include <glib.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

static void yyerror (const char *);
static void ref_list (list_t *list);
static void unref_list (list_t *list);
static list_t *create_list (GList *data);
static GList *result_to_list (GList *prev, const s4_result_t *res);
static GList *set_to_list (const s4_resultset_t *set,
	int row_start, int row_end,
	int col_start, int col_end);
static void add_or_del (int (*func)(s4_transaction_t *, const char *,
									const s4_val_t*, const char *,
									const s4_val_t*, const char *),
						list_t *list_a, list_t *list_b);
static void cleanup (void);

GHashTable *cond_table, *res_table, *list_table, *fetch_table, *pref_table;
char **lines;
s4_t *s4;

#define SET_YYLLOC(l) (yylloc = (l))



/* Line 189 of yacc.c  */
#line 107 "main.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     QUOTED_STRING = 259,
     COND_VAR = 260,
     LIST_VAR = 261,
     RESULT_VAR = 262,
     FETCH_VAR = 263,
     PREF_VAR = 264,
     INT = 265,
     INFO = 266,
     QUERY = 267,
     ADD = 268,
     DEL = 269,
     VARS = 270,
     SET = 271,
     HELP = 272,
     EXIT = 273,
     GR_EQ = 274,
     LE_EQ = 275,
     NOT_EQ = 276
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 48 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"

	char *string;
	int32_t number;
	s4_condition_t *condition;
	s4_val_t *value;
	s4_filter_type_t filter_type;
	s4_resultset_t *result;
	s4_fetchspec_t *fetch;
	s4_sourcepref_t *sourcepref;
	list_t *list;
	list_data_t *list_data;
	GList *list_datas, *sourcepref_list;
	range_t range;



/* Line 214 of yacc.c  */
#line 181 "main.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 206 "main.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,     2,     2,     2,    23,     2,
      35,    36,     2,    41,    27,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    25,
      38,    26,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,    40,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,    22,    33,    37,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    10,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    35,    39,    43,    47,
      51,    55,    58,    60,    65,    70,    74,    77,    80,    82,
      84,    86,    90,    92,    95,    99,   102,   104,   108,   110,
     114,   116,   123,   130,   132,   134,   137,   139,   144,   148,
     150,   152,   154,   158,   160,   162,   164,   166,   168,   170,
     172,   174,   176,   178,   180,   182,   184,   185,   187,   191,
     195,   199,   202,   207,   211,   215
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    25,    -1,    43,    44,    25,    -1,
      -1,    63,    -1,    53,    -1,    58,    -1,    57,    -1,    46,
      -1,    47,    -1,    45,    -1,    17,    -1,    15,    -1,    18,
      -1,     5,    26,    63,    -1,     6,    26,    53,    -1,     8,
      26,    57,    -1,     9,    26,    50,    -1,     7,    26,    58,
      -1,    16,    59,    59,    -1,    16,    59,    -1,    16,    -1,
      13,    53,    27,    53,    -1,    14,    53,    27,    53,    -1,
      10,    28,    10,    -1,    10,    28,    -1,    28,    10,    -1,
      28,    -1,    10,    -1,    59,    -1,    49,    29,    59,    -1,
       9,    -1,    29,    49,    -1,    59,    60,    59,    -1,    59,
      60,    -1,    51,    -1,    52,    27,    51,    -1,     6,    -1,
      30,    52,    31,    -1,    51,    -1,    58,    32,    48,    27,
      48,    33,    -1,    58,    32,    48,    27,    59,    33,    -1,
      59,    -1,    34,    -1,    54,    62,    -1,    55,    -1,    56,
      27,    54,    62,    -1,    35,    56,    36,    -1,     8,    -1,
      55,    -1,     7,    -1,    12,    57,    63,    -1,     3,    -1,
       4,    -1,    10,    -1,    59,    -1,    26,    -1,    37,    -1,
      38,    -1,    39,    -1,    40,    -1,    20,    -1,    19,    -1,
      21,    -1,    50,    -1,    -1,     5,    -1,    35,    63,    36,
      -1,    63,    23,    63,    -1,    63,    22,    63,    -1,    24,
      63,    -1,    59,    61,    60,    62,    -1,    61,    60,    62,
      -1,    41,    59,    62,    -1,    41,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   100,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     121,   122,   123,   125,   128,   131,   132,   133,   134,   135,
     138,   139,   141,   152,   171,   178,   187,   188,   191,   202,
     203,   204,   209,   223,   224,   226,   237,   238,   249,   250,
     260,   263,   273,   285,   286,   288,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   302,   303,   306,   316,   320,
     328,   336,   342,   349,   356,   362
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "QUOTED_STRING", "COND_VAR",
  "LIST_VAR", "RESULT_VAR", "FETCH_VAR", "PREF_VAR", "INT", "INFO",
  "QUERY", "ADD", "DEL", "VARS", "SET", "HELP", "EXIT", "GR_EQ", "LE_EQ",
  "NOT_EQ", "'|'", "'&'", "'!'", "';'", "'='", "','", "'-'", "':'", "'['",
  "']'", "'{'", "'}'", "'_'", "'('", "')'", "'~'", "'<'", "'>'", "'^'",
  "'+'", "$accept", "input", "command", "set", "add", "del", "range",
  "pref_data", "pref", "list_data", "list_datas", "list", "fetch_key",
  "fetch_item", "fetch", "fetch_list", "result", "string", "value",
  "filter_type", "pref_or_not", "cond", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   124,    38,    33,    59,    61,    44,    45,    58,
      91,    93,   123,   125,    95,    40,    41,   126,    60,    62,
      94,    43
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      45,    45,    45,    46,    47,    48,    48,    48,    48,    48,
      49,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    54,    54,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     1,     4,     4,     3,     2,     2,     1,     1,
       1,     3,     1,     2,     3,     2,     1,     3,     1,     3,
       1,     6,     6,     1,     1,     2,     1,     4,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     3,     3,
       3,     2,     4,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    53,    54,    67,    38,    51,    49,     0,     0,     0,
       0,    13,    22,    12,    14,    63,    62,    64,     0,    57,
       0,    44,     0,    58,    59,    60,    61,    66,     4,     0,
      11,     9,    10,    40,     6,    66,    50,     8,     7,    43,
       0,     5,     0,     0,     0,     0,     0,    49,     0,     0,
      43,    38,    51,     0,     0,     0,     0,    21,    67,     0,
       0,    71,    36,     0,    46,     0,    43,     0,    32,     0,
      65,    66,    75,     1,     0,     2,    45,     0,    55,    56,
      35,     0,    66,     0,     0,    15,    16,    19,    17,    18,
      52,     0,     0,    20,     0,    39,     0,    48,    68,    33,
      30,    74,     3,    29,    28,     0,    34,    66,    73,    70,
      69,    23,    24,    37,    66,     0,    26,    27,     0,    72,
      47,    31,    25,     0,     0,    41,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    28,    29,    30,    31,    32,   105,    99,    70,    33,
      63,    34,    35,    36,    65,    37,    54,    55,    80,    40,
      72,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -36
static const yytype_int16 yypact[] =
{
     155,   -36,   -36,   -17,   -15,    -5,    40,    45,    26,   224,
     224,   -36,    16,   -36,   -36,   -36,   -36,   -36,   179,   -36,
      16,   -36,    69,   -36,   -36,   -36,   -36,    49,   116,    51,
     -36,   -36,   -36,   -36,   -36,    27,   -36,   -36,    -7,   203,
      88,    77,   179,   224,    58,    26,    27,   -36,    13,   179,
     -36,   -36,   -36,    52,    -7,    88,    55,    16,   -36,   179,
     213,   -36,   -36,    70,   -36,    -4,   213,    41,   -36,    16,
     -36,    27,   -36,   -36,    80,   -36,   -36,     3,   -36,   -36,
      16,    88,    27,   179,   179,    77,   -36,   -36,   -36,   -36,
      77,   224,   224,   -36,    16,   -36,    13,   -36,   -36,    73,
     -36,   -36,   -36,    83,   102,    86,   -36,    27,   -36,    91,
     -36,   -36,   -36,   -36,    27,    16,   107,   -36,   198,   -36,
     -36,   -36,   -36,    93,    94,   -36,   -36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   110,   -36,   -36,   -36,    21,   -36,    95,   -19,
     -36,    -6,    47,     2,   -36,    -1,    10,     0,   -35,   -25,
     -20,   -16
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    62,    61,    53,    56,    82,    67,    49,    50,    42,
      38,    43,    57,   103,    81,    76,     1,     2,    60,     1,
       2,    44,    66,    96,    64,    77,    85,    71,    39,     1,
       2,   104,    97,    90,    47,    81,    68,    86,    38,    79,
      79,    81,    60,    67,    88,    50,   107,    21,    50,    60,
      64,   101,     1,     2,    87,    79,    69,    93,    68,    60,
      21,    48,   108,    83,    84,    52,    45,   109,   110,   100,
       8,    46,     1,     2,    58,   113,    75,    98,    69,    91,
     106,    79,    92,    60,    60,   111,   112,   119,    15,    16,
      17,     1,     2,    18,   120,    19,    50,    94,    78,    83,
      84,    95,   115,    21,    59,   102,    23,    24,    25,    26,
      27,   116,   117,   118,    84,   121,    73,   122,   124,     1,
       2,     3,     4,     5,     6,     7,   125,   126,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    74,   123,
      18,    89,    19,   114,     0,     0,    20,     0,     0,     0,
      21,    22,     0,    23,    24,    25,    26,    27,     1,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,    18,
       0,    19,     1,     2,    58,    20,     0,     0,     0,    21,
      22,     0,    23,    24,    25,    26,    27,     0,    15,    16,
      17,     1,     2,    18,     0,    19,     1,     2,   103,     0,
       0,     0,     0,    78,    59,     0,    23,    24,    25,    26,
      27,     0,    15,    16,    17,     0,   104,     1,     2,    19,
      51,    52,    15,    16,    17,     0,     8,     0,     0,    19,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    20
};

static const yytype_int8 yycheck[] =
{
       0,    20,    18,     9,    10,    40,    22,     8,     8,    26,
       0,    26,    12,    10,    39,    35,     3,     4,    18,     3,
       4,    26,    22,    27,    22,    32,    42,    27,    28,     3,
       4,    28,    36,    49,     8,    60,     9,    43,    28,    39,
      40,    66,    42,    59,    45,    45,    81,    34,    48,    49,
      48,    71,     3,     4,    44,    55,    29,    57,     9,    59,
      34,    35,    82,    22,    23,     7,    26,    83,    84,    69,
      12,    26,     3,     4,     5,    94,    25,    36,    29,    27,
      80,    81,    27,    83,    84,    91,    92,   107,    19,    20,
      21,     3,     4,    24,   114,    26,    96,    27,    10,    22,
      23,    31,    29,    34,    35,    25,    37,    38,    39,    40,
      41,    28,    10,    27,    23,   115,     0,    10,   118,     3,
       4,     5,     6,     7,     8,     9,    33,    33,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    28,   118,
      24,    46,    26,    96,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    24,
      -1,    26,     3,     4,     5,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    -1,    19,    20,
      21,     3,     4,    24,    -1,    26,     3,     4,    10,    -1,
      -1,    -1,    -1,    10,    35,    -1,    37,    38,    39,    40,
      41,    -1,    19,    20,    21,    -1,    28,     3,     4,    26,
       6,     7,    19,    20,    21,    -1,    12,    -1,    -1,    26,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    24,    26,
      30,    34,    35,    37,    38,    39,    40,    41,    43,    44,
      45,    46,    47,    51,    53,    54,    55,    57,    58,    59,
      61,    63,    26,    26,    26,    26,    26,     8,    35,    57,
      59,     6,     7,    53,    58,    59,    53,    59,     5,    35,
      59,    63,    51,    52,    55,    56,    59,    63,     9,    29,
      50,    59,    62,     0,    44,    25,    62,    32,    10,    59,
      60,    61,    60,    22,    23,    63,    53,    58,    57,    50,
      63,    27,    27,    59,    27,    31,    27,    36,    36,    49,
      59,    62,    25,    10,    28,    48,    59,    60,    62,    63,
      63,    53,    53,    51,    54,    29,    28,    10,    27,    62,
      62,    59,    10,    48,    59,    33,    33
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
# if YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* "STRING" */

/* Line 1000 of yacc.c  */
#line 80 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->string)); };

/* Line 1000 of yacc.c  */
#line 1249 "main.tab.c"
	break;
      case 4: /* "QUOTED_STRING" */

/* Line 1000 of yacc.c  */
#line 80 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->string)); };

/* Line 1000 of yacc.c  */
#line 1258 "main.tab.c"
	break;
      case 5: /* "COND_VAR" */

/* Line 1000 of yacc.c  */
#line 80 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->string)); };

/* Line 1000 of yacc.c  */
#line 1267 "main.tab.c"
	break;
      case 6: /* "LIST_VAR" */

/* Line 1000 of yacc.c  */
#line 80 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->string)); };

/* Line 1000 of yacc.c  */
#line 1276 "main.tab.c"
	break;
      case 7: /* "RESULT_VAR" */

/* Line 1000 of yacc.c  */
#line 80 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->string)); };

/* Line 1000 of yacc.c  */
#line 1285 "main.tab.c"
	break;
      case 8: /* "FETCH_VAR" */

/* Line 1000 of yacc.c  */
#line 80 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->string)); };

/* Line 1000 of yacc.c  */
#line 1294 "main.tab.c"
	break;
      case 9: /* "PREF_VAR" */

/* Line 1000 of yacc.c  */
#line 80 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->string)); };

/* Line 1000 of yacc.c  */
#line 1303 "main.tab.c"
	break;
      case 49: /* "pref_data" */

/* Line 1000 of yacc.c  */
#line 89 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ for (; (yyvaluep->sourcepref_list) != NULL; (yyvaluep->sourcepref_list) = g_list_delete_link ((yyvaluep->sourcepref_list), (yyvaluep->sourcepref_list))) free ((yyvaluep->sourcepref_list)->data); };

/* Line 1000 of yacc.c  */
#line 1312 "main.tab.c"
	break;
      case 50: /* "pref" */

/* Line 1000 of yacc.c  */
#line 88 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ s4_sourcepref_unref ((yyvaluep->sourcepref)); };

/* Line 1000 of yacc.c  */
#line 1321 "main.tab.c"
	break;
      case 51: /* "list_data" */

/* Line 1000 of yacc.c  */
#line 85 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->list_data)); };

/* Line 1000 of yacc.c  */
#line 1330 "main.tab.c"
	break;
      case 52: /* "list_datas" */

/* Line 1000 of yacc.c  */
#line 86 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ unref_list (create_list ((yyvaluep->list_datas))); };

/* Line 1000 of yacc.c  */
#line 1339 "main.tab.c"
	break;
      case 53: /* "list" */

/* Line 1000 of yacc.c  */
#line 87 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ unref_list ((yyvaluep->list)); };

/* Line 1000 of yacc.c  */
#line 1348 "main.tab.c"
	break;
      case 54: /* "fetch_key" */

/* Line 1000 of yacc.c  */
#line 80 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->string)); };

/* Line 1000 of yacc.c  */
#line 1357 "main.tab.c"
	break;
      case 55: /* "fetch_item" */

/* Line 1000 of yacc.c  */
#line 84 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ s4_fetchspec_unref ((yyvaluep->fetch)); };

/* Line 1000 of yacc.c  */
#line 1366 "main.tab.c"
	break;
      case 56: /* "fetch" */

/* Line 1000 of yacc.c  */
#line 84 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ s4_fetchspec_unref ((yyvaluep->fetch)); };

/* Line 1000 of yacc.c  */
#line 1375 "main.tab.c"
	break;
      case 57: /* "fetch_list" */

/* Line 1000 of yacc.c  */
#line 84 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ s4_fetchspec_unref ((yyvaluep->fetch)); };

/* Line 1000 of yacc.c  */
#line 1384 "main.tab.c"
	break;
      case 58: /* "result" */

/* Line 1000 of yacc.c  */
#line 83 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ s4_resultset_unref ((yyvaluep->result)); };

/* Line 1000 of yacc.c  */
#line 1393 "main.tab.c"
	break;
      case 59: /* "string" */

/* Line 1000 of yacc.c  */
#line 80 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ free ((yyvaluep->string)); };

/* Line 1000 of yacc.c  */
#line 1402 "main.tab.c"
	break;
      case 60: /* "value" */

/* Line 1000 of yacc.c  */
#line 81 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ s4_val_free ((yyvaluep->value)); };

/* Line 1000 of yacc.c  */
#line 1411 "main.tab.c"
	break;
      case 62: /* "pref_or_not" */

/* Line 1000 of yacc.c  */
#line 88 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ s4_sourcepref_unref ((yyvaluep->sourcepref)); };

/* Line 1000 of yacc.c  */
#line 1420 "main.tab.c"
	break;
      case 63: /* "cond" */

/* Line 1000 of yacc.c  */
#line 82 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
	{ s4_cond_unref ((yyvaluep->condition)); };

/* Line 1000 of yacc.c  */
#line 1429 "main.tab.c"
	break;

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

/* Line 1455 of yacc.c  */
#line 104 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { print_cond ((yyvsp[(1) - (1)].condition)); printf ("\n"); s4_cond_unref ((yyvsp[(1) - (1)].condition)); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 105 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { print_list ((yyvsp[(1) - (1)].list)); unref_list ((yyvsp[(1) - (1)].list)); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 106 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { print_result ((yyvsp[(1) - (1)].result)); s4_resultset_unref ((yyvsp[(1) - (1)].result)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 107 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { print_fetch ((yyvsp[(1) - (1)].fetch)); s4_fetchspec_unref ((yyvsp[(1) - (1)].fetch)); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 111 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { print_help (); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 112 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { print_vars (); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 113 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { cleanup (); exit (0); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 114 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { g_hash_table_insert (cond_table, (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].condition)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 115 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { g_hash_table_insert (list_table, (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].list)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 116 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { g_hash_table_insert (fetch_table, (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].fetch)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 117 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { g_hash_table_insert (pref_table, (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].sourcepref)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 118 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { g_hash_table_insert (res_table, (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].result)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 121 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { set_var ((yyvsp[(2) - (3)].string), (yyvsp[(3) - (3)].string)); free ((yyvsp[(2) - (3)].string)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 122 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { print_set_var ((yyvsp[(2) - (2)].string)); free ((yyvsp[(2) - (2)].string)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 123 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { print_set_var (NULL); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 125 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { add_or_del (s4_add, (yyvsp[(2) - (4)].list), (yyvsp[(4) - (4)].list)); unref_list ((yyvsp[(2) - (4)].list)); unref_list ((yyvsp[(4) - (4)].list)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 128 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { add_or_del (s4_del, (yyvsp[(2) - (4)].list), (yyvsp[(4) - (4)].list)); unref_list ((yyvsp[(2) - (4)].list)); unref_list ((yyvsp[(4) - (4)].list)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 131 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.range).start = (yyvsp[(1) - (3)].number); (yyval.range).end = (yyvsp[(3) - (3)].number); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 132 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.range).start = (yyvsp[(1) - (2)].number); (yyval.range).end = INT_MAX; ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 133 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.range).start =  0; (yyval.range).end = (yyvsp[(2) - (2)].number); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 134 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.range).start =  0; (yyval.range).end = INT_MAX; ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 135 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.range).start = (yyvsp[(1) - (1)].number); (yyval.range).end = (yyvsp[(1) - (1)].number); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 138 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.sourcepref_list) = g_list_prepend (NULL, (yyvsp[(1) - (1)].string)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 139 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.sourcepref_list) = g_list_prepend ((yyvsp[(1) - (3)].sourcepref_list), (yyvsp[(3) - (3)].string)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 142 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.sourcepref) = g_hash_table_lookup (pref_table, (yyvsp[(1) - (1)].string));
		free ((yyvsp[(1) - (1)].string));
		if ((yyval.sourcepref) == NULL) {
			SET_YYLLOC ((yylsp[(1) - (1)]));
			yyerror ("Undefined source preference variable");
			YYERROR;
		}
		s4_sourcepref_ref ((yyval.sourcepref));
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 153 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		int i, len = g_list_length ((yyvsp[(2) - (2)].sourcepref_list));
		char **sources = malloc (sizeof (char*) * (len + 1));

		(yyvsp[(2) - (2)].sourcepref_list) = g_list_reverse ((yyvsp[(2) - (2)].sourcepref_list));

		for (i = 0; (yyvsp[(2) - (2)].sourcepref_list) != NULL; (yyvsp[(2) - (2)].sourcepref_list) = g_list_delete_link ((yyvsp[(2) - (2)].sourcepref_list), (yyvsp[(2) - (2)].sourcepref_list)), i++) {
			sources[i] = (yyvsp[(2) - (2)].sourcepref_list)->data;
		}
		sources[len] = NULL;

		(yyval.sourcepref) = s4_sourcepref_create ((const char **)sources);
		for (i = 0; i < len; i++) {
			free (sources[i]);
		}
		free (sources);
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 172 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
			 (yyval.list_data) = malloc (sizeof (list_data_t));
			 (yyval.list_data)->key = (yyvsp[(1) - (3)].string);
			 (yyval.list_data)->val = (yyvsp[(2) - (3)].value);
			 (yyval.list_data)->src = (yyvsp[(3) - (3)].string);
		 ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 179 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
			 (yyval.list_data) = malloc (sizeof (list_data_t));
			 (yyval.list_data)->key = (yyvsp[(1) - (2)].string);
			 (yyval.list_data)->val = (yyvsp[(2) - (2)].value);
			 (yyval.list_data)->src = strdup (get_var ("default_source"));
		 ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 187 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.list_datas) = g_list_prepend (NULL, (yyvsp[(1) - (1)].list_data)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 188 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.list_datas) = g_list_prepend ((yyvsp[(1) - (3)].list_datas), (yyvsp[(3) - (3)].list_data)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 192 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.list) = g_hash_table_lookup (list_table, (yyvsp[(1) - (1)].string));
		free ((yyvsp[(1) - (1)].string));
		if ((yyval.list) == NULL) {
			SET_YYLLOC ((yylsp[(1) - (1)]));
			yyerror ("Undefined list variable");
			YYERROR;
		}
		ref_list ((yyval.list));
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 202 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.list) = create_list ((yyvsp[(2) - (3)].list_datas)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 203 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.list) = create_list (g_list_prepend (NULL, (yyvsp[(1) - (1)].list_data))); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 205 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.list) = create_list (set_to_list ((yyvsp[(1) - (6)].result), (yyvsp[(3) - (6)].range).start, (yyvsp[(3) - (6)].range).end, (yyvsp[(5) - (6)].range).start, (yyvsp[(5) - (6)].range).end));
		s4_resultset_unref ((yyvsp[(1) - (6)].result));
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 210 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		int col = find_column ((yyvsp[(5) - (6)].string), (yyvsp[(1) - (6)].result));
		if (col != -1) {
			(yyval.list) = create_list (set_to_list ((yyvsp[(1) - (6)].result), (yyvsp[(3) - (6)].range).start, (yyvsp[(3) - (6)].range).end, col, col));
		} else {
			SET_YYLLOC ((yylsp[(5) - (6)]));
			yyerror ("No column with that key");
			YYERROR;
		}
		s4_resultset_unref ((yyvsp[(1) - (6)].result));
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 224 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.string) = NULL; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 227 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
			  (yyval.fetch) = s4_fetchspec_create ();
			  s4_fetchspec_add ((yyval.fetch), (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].sourcepref), S4_FETCH_PARENT | S4_FETCH_DATA);
			  if ((yyvsp[(2) - (2)].sourcepref) != NULL)
				  s4_sourcepref_unref ((yyvsp[(2) - (2)].sourcepref));
			  if ((yyvsp[(1) - (2)].string) != NULL)
				  free ((yyvsp[(1) - (2)].string));
		  ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 239 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		 (yyval.fetch) = (yyvsp[(1) - (4)].fetch);
		 s4_fetchspec_add ((yyval.fetch), (yyvsp[(3) - (4)].string), (yyvsp[(4) - (4)].sourcepref), S4_FETCH_PARENT | S4_FETCH_DATA);
		 if ((yyvsp[(4) - (4)].sourcepref) != NULL)
			 s4_sourcepref_unref ((yyvsp[(4) - (4)].sourcepref));
		 if ((yyvsp[(3) - (4)].string) != NULL)
			 free ((yyvsp[(3) - (4)].string));
	 ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 249 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.fetch) = (yyvsp[(2) - (3)].fetch); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 251 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
			  (yyval.fetch) = s4_fetchspec_ref (g_hash_table_lookup (fetch_table, (yyvsp[(1) - (1)].string)));
			  free ((yyvsp[(1) - (1)].string));
			  if ((yyval.fetch) == NULL) {
				  SET_YYLLOC ((yylsp[(1) - (1)]));
				  yyerror ("Undefined fetch variable");
				  YYERROR;
			  }
		  ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 264 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		  (yyval.result) = s4_resultset_ref (g_hash_table_lookup (res_table, (yyvsp[(1) - (1)].string)));
		  free ((yyvsp[(1) - (1)].string));
		  if ((yyval.result) == NULL) {
			  SET_YYLLOC ((yylsp[(1) - (1)]));
			  yyerror ("Undefined result variable");
			  YYERROR;
		  }
	  ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 274 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		  const int order[2] = {1, 0};
		  s4_transaction_t *trans = s4_begin (s4, 0);
		  (yyval.result) = s4_query (trans, (yyvsp[(2) - (3)].fetch),  (yyvsp[(3) - (3)].condition));
		  s4_commit (trans);
		  s4_resultset_sort ((yyval.result), order);
		  s4_cond_unref ((yyvsp[(3) - (3)].condition));
		  s4_fetchspec_unref ((yyvsp[(2) - (3)].fetch));
	  ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 288 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.value) = s4_val_new_int ((yyvsp[(1) - (1)].number)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 289 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.value) = s4_val_new_string ((yyvsp[(1) - (1)].string)); free ((yyvsp[(1) - (1)].string)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 292 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.filter_type) =  S4_FILTER_EQUAL; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 293 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.filter_type) =  S4_FILTER_MATCH; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 294 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.filter_type) =  S4_FILTER_SMALLER; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 295 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.filter_type) =  S4_FILTER_GREATER; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 296 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.filter_type) =  S4_FILTER_TOKEN; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 297 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.filter_type) =  S4_FILTER_SMALLEREQ; ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 298 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.filter_type) =  S4_FILTER_GREATEREQ; ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 299 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.filter_type) =  S4_FILTER_NOTEQUAL; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 303 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    { (yyval.sourcepref) = NULL; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 307 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.condition) = s4_cond_ref (g_hash_table_lookup (cond_table, (yyvsp[(1) - (1)].string)));
		free ((yyvsp[(1) - (1)].string));
		if ((yyval.condition) == NULL) {
			SET_YYLLOC ((yylsp[(1) - (1)]));
			yyerror ("Undefined condition variable");
			YYERROR;
		}
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 317 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.condition) = (yyvsp[(2) - (3)].condition);
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 321 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.condition) = s4_cond_new_combiner (S4_COMBINE_AND);
		s4_cond_add_operand ((yyval.condition), (yyvsp[(1) - (3)].condition));
		s4_cond_add_operand ((yyval.condition), (yyvsp[(3) - (3)].condition));
		s4_cond_unref ((yyvsp[(1) - (3)].condition));
		s4_cond_unref ((yyvsp[(3) - (3)].condition));
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 329 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.condition) = s4_cond_new_combiner (S4_COMBINE_OR);
		s4_cond_add_operand ((yyval.condition), (yyvsp[(1) - (3)].condition));
		s4_cond_add_operand ((yyval.condition), (yyvsp[(3) - (3)].condition));
		s4_cond_unref ((yyvsp[(1) - (3)].condition));
		s4_cond_unref ((yyvsp[(3) - (3)].condition));
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 337 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.condition) = s4_cond_new_combiner (S4_COMBINE_NOT);
		s4_cond_add_operand ((yyval.condition), (yyvsp[(2) - (2)].condition));
		s4_cond_unref ((yyvsp[(2) - (2)].condition));
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 343 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.condition) = s4_cond_new_filter ((yyvsp[(2) - (4)].filter_type), (yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].value), (yyvsp[(4) - (4)].sourcepref), S4_CMP_CASELESS, 0);
		s4_val_free ((yyvsp[(3) - (4)].value));
		if ((yyvsp[(4) - (4)].sourcepref) != NULL)
			s4_sourcepref_unref ((yyvsp[(4) - (4)].sourcepref));
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 350 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.condition) = s4_cond_new_filter ((yyvsp[(1) - (3)].filter_type), NULL, (yyvsp[(2) - (3)].value), (yyvsp[(3) - (3)].sourcepref), S4_CMP_CASELESS, 0);
		s4_val_free ((yyvsp[(2) - (3)].value));
		if ((yyvsp[(3) - (3)].sourcepref) != NULL)
			s4_sourcepref_unref ((yyvsp[(3) - (3)].sourcepref));
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 357 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.condition) = s4_cond_new_filter (S4_FILTER_EXISTS, (yyvsp[(2) - (3)].string), NULL, (yyvsp[(3) - (3)].sourcepref), S4_CMP_BINARY, 0);
		if ((yyvsp[(3) - (3)].sourcepref) != NULL)
			s4_sourcepref_unref ((yyvsp[(3) - (3)].sourcepref));
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 363 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"
    {
		(yyval.condition) = s4_cond_new_filter (S4_FILTER_EXISTS, NULL, NULL, (yyvsp[(2) - (2)].sourcepref), S4_CMP_BINARY, 0);
		if ((yyvsp[(2) - (2)].sourcepref) != NULL)
			s4_sourcepref_unref ((yyvsp[(2) - (2)].sourcepref));
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2334 "main.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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



/* Line 1675 of yacc.c  */
#line 370 "/root/Hifi-Pod/player/server/xmms2-devel/src/lib/s4/src/tools/s4/main.y"


void yyerror (const char *str)
{
	int i, line, col = yylloc.first_column;

	fprintf (stderr, "%s\n", str);

	for (line = yylloc.first_line; line <= yylloc.last_line; line++) {
		fprintf (stderr, "%s\n", lines[line]);
		for (i = 0; i < col; i++)
			fputc (' ', stderr);
		for (; (line < yylloc.last_line && col < strlen (lines[line])) || col < yylloc.last_column; col++)
			fputc ('^', stderr);

		col = 0;
		fputc ('\n', stderr);
	}
}

void ref_list (list_t *list)
{
	list->refs++;
}

void unref_list (list_t *list)
{
	list->refs--;
	if (list->refs <= 0) {
		GList *l = list->list;
		for (; l != NULL; l = g_list_next (l)) {
			list_data_t *data = l->data;
			free (data->key);
			if (data->src != NULL)
				free (data->src);
			s4_val_free (data->val);
			free (l->data);
		}

		g_list_free (list->list);
		free (list);
	}
}

list_t *create_list (GList *data)
{
	list_t *ret = malloc (sizeof (list_t));
	ret->refs = 1;
	ret->list = data;

	return ret;
}

GList *result_to_list (GList *prev, const s4_result_t *res)
{
	GList *ret = prev;
	list_data_t *data;

	for (; res != NULL; res = s4_result_next (res)) {
		data = malloc (sizeof (list_data_t));
		data->key = strdup (s4_result_get_key (res));
		data->val = s4_val_copy (s4_result_get_val (res));
		data->src = (char*)s4_result_get_src (res);
		if (data->src != NULL)
			data->src = strdup (data->src);
		ret = g_list_prepend (ret, data);
	}

	return ret;
}

GList *set_to_list (const s4_resultset_t *set,
	int row_start, int row_end,
	int col_start, int col_end)
{
	int row, col;
	GList *ret = NULL;

	for (row = row_start; row <= row_end && row < s4_resultset_get_rowcount (set); row++) {
		for (col = col_start; col <= col_end &&  col < s4_resultset_get_colcount (set); col++) {
			ret = result_to_list (ret, s4_resultset_get_result (set, row, col));
		}
	}

	return g_list_reverse (ret);
}

static void add_or_del (int (*func)(s4_transaction_t *t, const char *,
									const s4_val_t*, const char *,
									const s4_val_t*, const char *),
						list_t *list_a, list_t *list_b)
{
	list_data_t *da, *db;
	GList *a, *b;
	s4_transaction_t *trans = s4_begin (s4, 0);

	for (a = list_a->list; a != NULL; a = g_list_next (a)) {
		da = a->data;
		for (b = list_b->list; b != NULL; b = g_list_next (b)) {
			db = b->data;
			if (!func (trans, da->key, da->val, db->key, db->val, db->src)) {
				printf ("failed on %s %s, %s %s %s",
					da->key, value_to_string (da->val),
					db->key, value_to_string (db->val),
					db->src);
			}
		}
	}

	s4_commit (trans);
}

static int no_semicolon (const char *line)
{
	return line[strlen (line) - 1] != ';';
}

static void strip (char *line)
{
	int last = 0;
	int i;

	if (line == NULL)
		return;

	for (i = 0; line[i]; i++) {
		if (!isspace (line[i]))
			last = i;
	}

	line[last + 1] = '\0';
}

static char *rl_get_line (int first)
{
	char *ret = NULL;

	do {
		if (ret != NULL)
			free (ret);
		ret = readline (first?"s4> ":"..> ");
		strip (ret);
	} while (ret != NULL && !strlen (ret));

	add_history (ret);

	return ret;
}

static char **rl_get_lines (int *line_co)
{
	static char *lines[MAX_LINE_COUNT];
	static int line_count = 0;
	int i;

	/* Free old lines */
	while (--line_count >= 0) {
		free (lines[line_count]);
	}

	for (i = 0; (lines[i] = rl_get_line (i == 0)) != NULL && no_semicolon (lines[i]); i++);
	if (lines[i] == NULL) {
		return NULL;
	}
	line_count = *line_co = i + 1;

	return lines;
}

void cleanup ()
{
	s4_close (s4);

	g_hash_table_destroy (cond_table);
	g_hash_table_destroy (fetch_table);
	g_hash_table_destroy (list_table);
	g_hash_table_destroy (res_table);
	g_hash_table_destroy (pref_table);
}

int main(int argc, const char *argv[])
{
	int line_count;

	if (argc < 2) {
		printf("Not enough arguments\nUsage: %s <s4-file>\n", argv[0]);
		return 1;
	}

	printf ("S4 CLI tool\nEnter \".help;\" for instructions\n");

	cond_table = g_hash_table_new_full (g_str_hash, g_str_equal,
		free, (GDestroyNotify)s4_cond_unref);
	list_table = g_hash_table_new_full (g_str_hash, g_str_equal,
		free, (GDestroyNotify)unref_list);
	res_table = g_hash_table_new_full (g_str_hash, g_str_equal,
		free, (GDestroyNotify)s4_resultset_free);
	fetch_table = g_hash_table_new_full (g_str_hash, g_str_equal,
		free, (GDestroyNotify)s4_fetchspec_unref);
	pref_table = g_hash_table_new_full (g_str_hash, g_str_equal,
		free, (GDestroyNotify)s4_sourcepref_unref);

	g_thread_init (NULL);
	config_init ();

	s4 = s4_open (argv[1], NULL, S4_EXISTS);

	if (s4 == NULL) {
		printf ("Could not open %s - ", argv[1]);
		switch (s4_errno ()) {
		case S4E_MAGIC:
			printf ("Wrong magic number\n");
			break;
		case S4E_VERSION:
			printf ("Wrong version number\n");
			break;
		case S4E_NOENT:
			printf ("File does not exist\n");
			break;
		case S4E_INCONS:
			printf ("File is inconsistent (corrupted?)\n");
			break;
		case S4E_LOGOPEN:
			printf ("Could not open logfile: %s\n", strerror (errno));
			break;
		case S4E_LOGREDO:
			printf ("Could not redo log\n");
			break;
		case S4E_OPEN:
			printf ("%s\n", strerror (errno));
			break;
		case S4E_EXISTS:
			printf ("File exists?? If you see this, file a bug report!\n");
			break;
		}
		return 1;
	}

	while ((lines = rl_get_lines (&line_count)) != NULL) {
		init_lexer (lines, line_count);
		yyparse ();
	}

	config_cleanup ();
	cleanup ();

	printf (".exit;\n");

	return 0;
}

