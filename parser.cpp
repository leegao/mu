
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
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "mu.y"

    #include "node.h"
    #include <cstdio>
    NBlock *programBlock = new NBlock(); /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }


/* Line 189 of yacc.c  */
#line 83 "parser.cpp"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIDENTIFIER = 258,
     TINTEGER = 259,
     TDOUBLE = 260,
     TSTRING_LITERAL = 261,
     TCEQ = 262,
     TCNE = 263,
     TCLT = 264,
     TCLE = 265,
     TCGT = 266,
     TCGE = 267,
     TEQUAL = 268,
     TLPAREN = 269,
     TRPAREN = 270,
     TLBRACE = 271,
     TRBRACE = 272,
     TCOMMA = 273,
     TDOT = 274,
     TPLUS = 275,
     TMINUS = 276,
     TMUL = 277,
     TDIV = 278,
     TAND = 279,
     TOR = 280,
     TUNOT = 281,
     TLBRACKET = 282,
     TRBRACKET = 283,
     TEXP = 284,
     TBITOR = 285,
     TBITAND = 286,
     TBITXOR = 287,
     TVAR = 288,
     TFUNCTION = 289,
     TTRUE = 290,
     TFALSE = 291,
     TMOD = 292,
     TFOR = 293,
     TIF = 294,
     TQUESTION = 295,
     TCOLON = 296,
     TPREPEND = 297,
     TELSEIF = 298,
     TELSE = 299,
     TWHILE = 300,
     TBREAK = 301,
     TRETURN = 302,
     TIN = 303,
     TERMINATE = 304,
     TNIL = 305,
     TMATCH = 306,
     TWITH = 307,
     TCAT = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 11 "mu.y"

    Node *node;
    NBlock *block;
    NExpression *expr;
    NStatement *stmt;
    NIdentifier *ident;
    NVariableDeclaration *var_decl;
    ForCounter *counter;
    std::vector<NVariableDeclaration*> *varvec;
    std::vector<NExpression*> *exprvec;
    std::string *string;
    
    int token;



/* Line 214 of yacc.c  */
#line 189 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 201 "parser.cpp"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   835

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    17,    19,
      21,    24,    27,    30,    34,    36,    40,    43,    46,    51,
      58,    59,    61,    65,    69,    73,    79,    85,    89,    93,
      97,    99,   104,   106,   110,   112,   114,   116,   118,   124,
     128,   133,   135,   137,   139,   141,   143,   145,   147,   149,
     151,   155,   158,   161,   165,   170,   173,   175,   180,   184,
     186,   188,   190,   192,   194,   196,   198,   201,   204,   207,
     211,   215,   219,   223,   228,   232,   236,   237,   239,   243,
     245,   247,   249,   251,   252,   254,   258,   262,   263,   265,
     269,   271,   273,   275,   277,   279,   281,   283,   285,   287,
     289,   291,   293,   295,   297,   299,   301,   303
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    57,    -1,    57,    -1,    56,    57,    -1,
      59,    49,    -1,    60,    -1,    62,    -1,    64,    -1,    67,
      -1,    72,    49,    -1,    46,    49,    -1,    47,    49,    -1,
      47,    72,    49,    -1,    49,    -1,    16,    56,    17,    -1,
      16,    17,    -1,    33,    68,    -1,    33,    68,    13,    72,
      -1,    34,    68,    14,    61,    15,    58,    -1,    -1,    59,
      -1,    61,    18,    59,    -1,    45,    72,    58,    -1,    68,
      48,    72,    -1,    72,    18,    72,    18,    72,    -1,    59,
      18,    72,    18,    72,    -1,    14,    63,    15,    -1,    38,
      63,    58,    -1,    39,    72,    58,    -1,    65,    -1,    66,
      43,    72,    58,    -1,    66,    -1,    66,    44,    58,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,    72,    40,
      72,    41,    72,    -1,    68,    13,    72,    -1,    68,    14,
      79,    15,    -1,    68,    -1,    69,    -1,    70,    -1,    80,
      -1,    71,    -1,    73,    -1,    35,    -1,    36,    -1,    50,
      -1,    72,    82,    72,    -1,    26,    72,    -1,    21,    72,
      -1,    14,    72,    15,    -1,    51,    72,    52,    74,    -1,
      75,    58,    -1,    75,    -1,    74,    30,    75,    58,    -1,
      74,    30,    75,    -1,    68,    -1,    70,    -1,    69,    -1,
      76,    -1,    50,    -1,    35,    -1,    36,    -1,    26,    68,
      -1,    21,    69,    -1,    21,    68,    -1,    75,    42,    75,
      -1,    68,    78,    69,    -1,    69,    78,    68,    -1,    69,
      82,    69,    -1,    68,    14,    79,    15,    -1,    14,    75,
      15,    -1,    27,    77,    28,    -1,    -1,    75,    -1,    77,
      18,    75,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    -1,    72,    -1,    79,    18,    72,    -1,    27,    81,
      28,    -1,    -1,    72,    -1,    81,    18,    72,    -1,     7,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    31,    -1,    30,    -1,    32,    -1,    53,
      -1,    37,    -1,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    63,    64,    67,    67,    67,    67,    67,
      68,    69,    70,    71,    72,    75,    76,    79,    80,    83,
      87,    88,    89,    92,    94,    95,    96,    97,   100,   102,
     105,   106,   109,   110,   113,   116,   117,   120,   123,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   143,   145,   149,   153,   168,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   202,   205,   206,   207,   210,
     210,   210,   210,   212,   213,   214,   217,   220,   221,   222,
     225,   225,   225,   225,   225,   225,   226,   226,   226,   226,
     226,   226,   226,   227,   227,   227,   227,   227
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENTIFIER", "TINTEGER", "TDOUBLE",
  "TSTRING_LITERAL", "TCEQ", "TCNE", "TCLT", "TCLE", "TCGT", "TCGE",
  "TEQUAL", "TLPAREN", "TRPAREN", "TLBRACE", "TRBRACE", "TCOMMA", "TDOT",
  "TPLUS", "TMINUS", "TMUL", "TDIV", "TAND", "TOR", "TUNOT", "TLBRACKET",
  "TRBRACKET", "TEXP", "TBITOR", "TBITAND", "TBITXOR", "TVAR", "TFUNCTION",
  "TTRUE", "TFALSE", "TMOD", "TFOR", "TIF", "TQUESTION", "TCOLON",
  "TPREPEND", "TELSEIF", "TELSE", "TWHILE", "TBREAK", "TRETURN", "TIN",
  "TERMINATE", "TNIL", "TMATCH", "TWITH", "TCAT", "$accept", "program",
  "stmts", "stmt", "block", "var_decl", "func_decl", "func_decl_args",
  "while_syn", "for_syn_decl", "for_syn", "if_syn", "elseif_syn",
  "elseend_syn", "ident", "numeric", "string", "inline_cond", "expr",
  "match", "match_pattern", "m_pattern", "list_pdecl", "list_pel",
  "pattern_cmp", "call_args", "list_decl", "list_el", "comparison", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    61,    62,    63,    63,    63,    63,    64,    65,
      66,    66,    67,    67,    68,    69,    69,    70,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    77,    77,    77,    78,
      78,    78,    78,    79,    79,    79,    80,    81,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       2,     2,     2,     3,     1,     3,     2,     2,     4,     6,
       0,     1,     3,     3,     3,     5,     5,     3,     3,     3,
       1,     4,     1,     3,     1,     1,     1,     1,     5,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     3,     4,     2,     1,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     3,
       3,     3,     3,     4,     3,     3,     0,     1,     3,     1,
       1,     1,     1,     0,     1,     3,     3,     0,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,    35,    36,    37,     0,     0,     0,    87,     0,
       0,    47,    48,     0,     0,     0,     0,     0,    14,    49,
       0,     0,     2,     0,     6,     7,     8,    30,    32,     9,
      41,    42,    43,    45,     0,    46,    44,     0,    52,    51,
      88,     0,    17,     0,     0,     0,     0,    41,     0,     0,
       0,    11,    12,     0,     0,     1,     5,     0,     0,     0,
      83,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   103,   102,   104,   106,     0,   107,    10,
     105,     0,    53,     0,    86,     0,    20,     0,     0,     0,
       0,    28,     0,     0,    29,    23,    13,     0,     0,    33,
      39,    84,     0,     0,    50,    89,    18,    21,     0,    27,
       0,    16,     0,     3,    24,     0,     0,     0,     0,    76,
      64,    65,    63,    59,    61,    60,    54,    56,    62,    31,
      40,     0,     0,     0,     0,     0,    15,     4,     0,     0,
      68,    67,    66,    77,     0,    83,    79,    80,    81,    82,
       0,    96,    97,    98,    99,     0,     0,     0,     0,    55,
      85,    38,    19,    22,    26,    25,    74,     0,    75,     0,
      70,    71,    72,    58,    69,    78,    73,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,   112,    22,    91,    23,    24,   108,    25,    46,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     126,   127,   128,   144,   150,   102,    36,    41,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int16 yypact[] =
{
     212,   -93,   -93,   -93,   -93,   302,   302,   302,   302,    20,
      20,   -93,   -93,   250,   302,   302,    -8,   276,   -93,   -93,
     302,    43,   -93,     1,   -93,   -93,   -93,   -93,    11,   -93,
      25,   -93,   -93,   -93,   386,   -93,   -93,   422,   782,   710,
     710,    -2,    45,    59,   250,    38,    58,     5,   458,   494,
     494,   -93,   -93,   530,   566,   -93,   -93,   302,    58,   302,
     302,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   302,   -93,   -93,
     -93,   302,   -93,   302,   -93,   302,    46,    61,   350,   302,
     136,   -93,   302,   302,   -93,   -93,   -93,   328,   494,   -93,
     710,   710,    10,   602,   710,   710,   710,   -93,    14,   -93,
     638,   -93,   174,   -93,   710,   674,   328,    42,    20,   328,
     -93,   -93,   -93,    49,   746,   -93,    48,     6,   -93,   -93,
     -93,   302,   302,    58,    46,   302,   -93,   -93,   302,    -5,
     -93,   -93,   -93,    52,     3,   302,   -93,   -93,   -93,   -93,
      63,    81,    84,    93,    94,    20,    63,   328,   328,   -93,
     710,   710,   -93,   -93,   710,   710,   -93,   328,   -93,    18,
     -93,   -93,   -93,     6,    52,    52,   -93,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,   -78,   -47,    -4,   -93,   -93,   -93,    54,
     -93,   -93,   -93,   -93,    -9,   -55,   -67,   -93,     0,   -93,
     -93,   -92,   -93,   -93,   -25,   -41,   -93,   -93,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -83
static const yytype_int16 yytable[] =
{
      42,    43,    94,    95,    47,    37,    38,    39,    40,    45,
     166,    99,   113,    48,    49,    50,    83,    53,    59,    60,
      54,   167,    90,     1,   139,   130,    84,   143,   131,   133,
     125,   168,   134,   176,   137,    47,   131,   158,    59,    60,
      45,    51,   124,    55,    88,     1,     2,     3,   158,   125,
      56,   129,   125,    92,    57,    58,    89,    98,    85,   100,
     101,   124,   141,   145,   124,   173,   174,     2,     3,   146,
     147,   148,   149,    86,    90,   175,   109,   103,   157,     9,
     159,   104,   107,   105,   -79,   106,   162,   -80,   123,   110,
     125,   125,   114,   115,   158,   170,   -81,   -82,    87,   155,
     125,   172,   124,   124,   169,   156,     0,   123,   140,   142,
     123,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,     0,     0,     0,
     163,   160,   161,     0,     0,   164,     0,     0,   165,     1,
       2,     3,     4,     0,     0,   101,   171,     0,   123,   123,
       5,     0,     0,   111,     0,     0,     0,     6,   123,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     9,
      10,    11,    12,     0,    13,    14,     0,     1,     2,     3,
       4,    15,    16,    17,     0,    18,    19,    20,     5,     0,
       0,   136,     0,     0,     0,     6,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     9,    10,    11,
      12,     0,    13,    14,     0,     1,     2,     3,     4,    15,
      16,    17,     0,    18,    19,    20,     5,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     9,    10,    11,    12,     0,
      13,    14,     0,     1,     2,     3,     4,    15,    16,    17,
       0,    18,    19,    20,    44,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     7,     8,     0,     1,
       2,     3,     4,     9,     0,    11,    12,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     6,     0,     0,
      19,    20,     7,     8,     0,     1,     2,     3,     4,     0,
       0,    11,    12,     0,     0,     0,     5,     0,     0,     0,
       0,     0,     0,     6,     0,    52,    19,    20,     7,     8,
       0,     1,     2,     3,     4,     0,     0,    11,    12,     0,
       0,     0,   116,     0,     0,     0,     0,     0,     0,   117,
       0,     0,    19,    20,   118,   119,     0,    61,    62,    63,
      64,    65,    66,   120,   121,    82,     0,     0,    93,     0,
      67,    68,    69,    70,    71,    72,     0,     0,   122,     0,
      73,    74,    75,     0,     0,     0,     0,    76,     0,     0,
      77,     0,    78,    61,    62,    63,    64,    65,    66,     0,
       0,     0,     0,    80,     0,     0,    67,    68,    69,    70,
      71,    72,     0,     0,     0,     0,    73,    74,    75,     0,
       0,     0,     0,    76,     0,     0,    77,     0,    78,    61,
      62,    63,    64,    65,    66,    79,     0,    82,     0,    80,
       0,     0,    67,    68,    69,    70,    71,    72,     0,     0,
       0,     0,    73,    74,    75,     0,     0,     0,     0,    76,
       0,     0,    77,     0,    78,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,    80,    93,     0,    67,    68,
      69,    70,    71,    72,     0,     0,     0,     0,    73,    74,
      75,     0,     0,     0,     0,    76,     0,     0,    77,     0,
      78,    61,    62,    63,    64,    65,    66,     0,     0,     0,
      90,    80,     0,     0,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,    73,    74,    75,     0,     0,     0,
       0,    76,     0,     0,    77,     0,    78,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,    80,     0,     0,
      67,    68,    69,    70,    71,    72,     0,     0,     0,     0,
      73,    74,    75,     0,     0,     0,     0,    76,     0,     0,
      77,     0,    78,    61,    62,    63,    64,    65,    66,    96,
       0,     0,     0,    80,     0,     0,    67,    68,    69,    70,
      71,    72,     0,     0,     0,     0,    73,    74,    75,     0,
       0,     0,     0,    76,     0,     0,    77,     0,    78,    61,
      62,    63,    64,    65,    66,     0,     0,     0,    97,    80,
       0,     0,    67,    68,    69,    70,    71,    72,     0,     0,
       0,     0,    73,    74,    75,     0,     0,     0,     0,    76,
       0,     0,    77,   132,    78,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,    80,   135,     0,    67,    68,
      69,    70,    71,    72,     0,     0,     0,     0,    73,    74,
      75,     0,     0,     0,     0,    76,     0,     0,    77,     0,
      78,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,    80,   138,     0,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,    73,    74,    75,     0,     0,     0,
       0,    76,     0,     0,    77,     0,    78,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,    80,     0,     0,
      67,    68,    69,    70,    71,    72,     0,     0,     0,     0,
      73,    74,    75,     0,     0,     0,     0,    76,     0,     0,
      77,     0,    78,    61,    62,    63,    64,    65,    66,     0,
       0,     0,     0,    80,     0,     0,   151,   152,   153,   154,
      71,    72,     0,     0,     0,     0,    73,    74,    75,     0,
       0,     0,     0,    76,     0,     0,     0,     0,    78,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,    80,
       0,     0,     0,     0,    69,    70,    71,    72,     0,     0,
       0,     0,    73,    74,    75,     0,     0,     0,     0,    76,
       0,     0,    77,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80
};

static const yytype_int16 yycheck[] =
{
       9,    10,    49,    50,    13,     5,     6,     7,     8,    13,
      15,    58,    90,    13,    14,    15,    18,    17,    13,    14,
      20,    18,    16,     3,   116,    15,    28,   119,    18,    15,
      97,    28,    18,    15,   112,    44,    18,    42,    13,    14,
      44,    49,    97,     0,    44,     3,     4,     5,    42,   116,
      49,    98,   119,    48,    43,    44,    18,    57,    13,    59,
      60,   116,   117,    14,   119,   157,   158,     4,     5,    20,
      21,    22,    23,    14,    16,   167,    15,    77,    30,    33,
     127,    81,    86,    83,     3,    85,   133,     3,    97,    89,
     157,   158,    92,    93,    42,   150,     3,     3,    44,   124,
     167,   156,   157,   158,   145,   124,    -1,   116,   117,   118,
     119,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     134,   131,   132,    -1,    -1,   135,    -1,    -1,   138,     3,
       4,     5,     6,    -1,    -1,   145,   155,    -1,   157,   158,
      14,    -1,    -1,    17,    -1,    -1,    -1,    21,   167,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    38,    39,    -1,     3,     4,     5,
       6,    45,    46,    47,    -1,    49,    50,    51,    14,    -1,
      -1,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    -1,    38,    39,    -1,     3,     4,     5,     6,    45,
      46,    47,    -1,    49,    50,    51,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      38,    39,    -1,     3,     4,     5,     6,    45,    46,    47,
      -1,    49,    50,    51,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,     3,
       4,     5,     6,    33,    -1,    35,    36,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      50,    51,    26,    27,    -1,     3,     4,     5,     6,    -1,
      -1,    35,    36,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    49,    50,    51,    26,    27,
      -1,     3,     4,     5,     6,    -1,    -1,    35,    36,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    50,    51,    26,    27,    -1,     7,     8,     9,
      10,    11,    12,    35,    36,    15,    -1,    -1,    18,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    50,    -1,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      40,    -1,    42,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    40,    -1,    42,     7,
       8,     9,    10,    11,    12,    49,    -1,    15,    -1,    53,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    40,    -1,    42,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    53,    18,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    -1,
      42,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    53,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    40,    -1,    42,     7,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      40,    -1,    42,     7,     8,     9,    10,    11,    12,    49,
      -1,    -1,    -1,    53,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    40,    -1,    42,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    52,    53,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    40,    41,    42,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    53,    18,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    -1,
      42,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    53,    18,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    40,    -1,    42,     7,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      40,    -1,    42,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    14,    21,    26,    27,    33,
      34,    35,    36,    38,    39,    45,    46,    47,    49,    50,
      51,    55,    57,    59,    60,    62,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    80,    72,    72,    72,
      72,    81,    68,    68,    14,    59,    63,    68,    72,    72,
      72,    49,    49,    72,    72,     0,    49,    43,    44,    13,
      14,     7,     8,     9,    10,    11,    12,    20,    21,    22,
      23,    24,    25,    30,    31,    32,    37,    40,    42,    49,
      53,    82,    15,    18,    28,    13,    14,    63,    72,    18,
      16,    58,    48,    18,    58,    58,    49,    52,    72,    58,
      72,    72,    79,    72,    72,    72,    72,    59,    61,    15,
      72,    17,    56,    57,    72,    72,    14,    21,    26,    27,
      35,    36,    50,    68,    69,    70,    74,    75,    76,    58,
      15,    18,    41,    15,    18,    18,    17,    57,    18,    75,
      68,    69,    68,    75,    77,    14,    20,    21,    22,    23,
      78,    20,    21,    22,    23,    78,    82,    30,    42,    58,
      72,    72,    58,    59,    72,    72,    15,    18,    28,    79,
      69,    68,    69,    75,    75,    75,    15,    58
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
        case 2:

/* Line 1455 of yacc.c  */
#line 60 "mu.y"
    { programBlock->statements.push_back((yyvsp[(1) - (1)].stmt)); return 0; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 63 "mu.y"
    { (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[(1) - (1)].stmt)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 64 "mu.y"
    { (yyvsp[(1) - (2)].block)->statements.push_back((yyvsp[(2) - (2)].stmt)); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 68 "mu.y"
    { (yyval.stmt) = new NExpressionStatement(*(yyvsp[(1) - (2)].expr)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 69 "mu.y"
    { (yyval.stmt) = new NBreak(); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 70 "mu.y"
    { (yyval.stmt) = new NReturn(*(new NNil())); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 71 "mu.y"
    { (yyval.stmt) = new NReturn(*(yyvsp[(2) - (3)].expr)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 72 "mu.y"
    { (yyval.stmt) = new NExpressionStatement(*(new NDoNothing())); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 75 "mu.y"
    { (yyval.block) = (yyvsp[(2) - (3)].block); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 76 "mu.y"
    { (yyval.block) = new NBlock(); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 79 "mu.y"
    { (yyval.stmt) = new NVariableDeclaration(*(yyvsp[(2) - (2)].ident)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 80 "mu.y"
    { (yyval.stmt) = new NVariableDeclaration(*(yyvsp[(2) - (4)].ident), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 84 "mu.y"
    { (yyval.stmt) = new NFunctionDeclaration(*(yyvsp[(2) - (6)].ident), *(yyvsp[(4) - (6)].varvec), *(yyvsp[(6) - (6)].block)); delete (yyvsp[(4) - (6)].varvec); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 87 "mu.y"
    { (yyval.varvec) = new VariableList(); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 88 "mu.y"
    { (yyval.varvec) = new VariableList(); (yyval.varvec)->push_back((yyvsp[(1) - (1)].var_decl)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 89 "mu.y"
    { (yyvsp[(1) - (3)].varvec)->push_back((yyvsp[(3) - (3)].var_decl)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 92 "mu.y"
    { (yyval.stmt) = new NWhileLoop(*(yyvsp[(2) - (3)].expr), *(yyvsp[(3) - (3)].block)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 94 "mu.y"
    { (yyval.counter) = new InCounter(*(yyvsp[(1) - (3)].ident), *(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 95 "mu.y"
    { (yyval.counter) = new LoopCounter(*(yyvsp[(1) - (5)].expr), *(yyvsp[(3) - (5)].expr), *(yyvsp[(5) - (5)].expr)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 96 "mu.y"
    { (yyval.counter) = new VarLoopCounter(*(yyvsp[(1) - (5)].stmt), *(yyvsp[(3) - (5)].expr), *(yyvsp[(5) - (5)].expr)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 97 "mu.y"
    { (yyval.counter) = (yyvsp[(2) - (3)].counter); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 100 "mu.y"
    { (yyval.stmt) = new NForLoop(*(yyvsp[(2) - (3)].counter), *(yyvsp[(3) - (3)].block)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 102 "mu.y"
    { (yyval.stmt) = new NIf(*(yyvsp[(2) - (3)].expr), *(yyvsp[(3) - (3)].block), *(new NBlock())); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 105 "mu.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 106 "mu.y"
    { (yyval.stmt) = (yyvsp[(1) - (4)].stmt); (dynamic_cast<NIf*> ((yyval.stmt)))->else_if(*(yyvsp[(3) - (4)].expr), *(yyvsp[(4) - (4)].block)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 109 "mu.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 110 "mu.y"
    { (yyval.stmt) = (yyvsp[(1) - (3)].stmt); (dynamic_cast<NIf*> ((yyval.stmt)))->else_end(*(yyvsp[(3) - (3)].block)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 113 "mu.y"
    { (yyval.ident) = new NIdentifier(*(yyvsp[(1) - (1)].string)); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 116 "mu.y"
    { (yyval.expr) = new NNumber(atof((yyvsp[(1) - (1)].string)->c_str())); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 117 "mu.y"
    { (yyval.expr) = new NNumber(atof((yyvsp[(1) - (1)].string)->c_str())); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 120 "mu.y"
    { (yyval.expr) = new NString(*(yyvsp[(1) - (1)].string)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 123 "mu.y"
    { (yyval.expr) = new NInlineCond(*(yyvsp[(1) - (5)].expr), *(yyvsp[(3) - (5)].expr), *(yyvsp[(5) - (5)].expr)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 126 "mu.y"
    { (yyval.expr) = new NAssignment(*(yyvsp[(1) - (3)].ident), *(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 127 "mu.y"
    { (yyval.expr) = new NMethodCall(*(yyvsp[(1) - (4)].ident), *(yyvsp[(3) - (4)].exprvec)); delete (yyvsp[(3) - (4)].exprvec); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 128 "mu.y"
    { (yyval.ident) = (yyvsp[(1) - (1)].ident); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 134 "mu.y"
    { (yyval.expr) = new NBoolean(true); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 135 "mu.y"
    { (yyval.expr) = new NBoolean(false); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 136 "mu.y"
    { (yyval.expr) = new NNil(); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 137 "mu.y"
    { (yyval.expr) = new NBinaryOperator(*(yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].token), *(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 138 "mu.y"
    { (yyval.expr) = new NNot(*(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 139 "mu.y"
    { (yyval.expr) = new NNegation(*(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 140 "mu.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 143 "mu.y"
    { (yyval.expr) = new NMatch(*(yyvsp[(2) - (4)].expr), *(yyvsp[(4) - (4)].exprvec)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 145 "mu.y"
    { 
                	(yyval.exprvec) = new ExpressionList(); 
                	(yyval.exprvec)->push_back(new MatchPattern((yyvsp[(1) - (2)].expr), *(yyvsp[(2) - (2)].block))); 
              ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 149 "mu.y"
    {
                	(yyval.exprvec) = new ExpressionList(); 
                	(yyval.exprvec)->push_back(new MatchPattern((yyvsp[(1) - (1)].expr), *(new NNil()))); 
              ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 153 "mu.y"
    {
                	// back track to make sure that back isn't NNil
                	MatchPattern* last = dynamic_cast<MatchPattern*>((yyvsp[(1) - (4)].exprvec)->back());
                	(yyval.exprvec) = (yyvsp[(1) - (4)].exprvec);
                	if (dynamic_cast<NNil*>(&(last->block))){
                		// push this pattern into last and set block
                		(yyval.exprvec) = (yyvsp[(1) - (4)].exprvec);
                		last->patterns.push_back((yyvsp[(3) - (4)].expr));
                		last->block = *(yyvsp[(4) - (4)].block);
                		
                	}else{
                		// create a new match pattern
                		(yyval.exprvec)->push_back(new MatchPattern((yyvsp[(3) - (4)].expr), *(yyvsp[(4) - (4)].block)));
                	}
              ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 168 "mu.y"
    {
                	// back track to make sure that back isn't NNil
                	MatchPattern* last = dynamic_cast<MatchPattern*>((yyvsp[(1) - (3)].exprvec)->back());
                	(yyval.exprvec) = (yyvsp[(1) - (3)].exprvec);
                	if (dynamic_cast<NNil*>(&(last->block))){
                		// push this pattern into last and set block
                		(yyval.exprvec) = (yyvsp[(1) - (3)].exprvec);
                		last->patterns.push_back((yyvsp[(3) - (3)].expr));
                		
                	}else{
                		// create a new match pattern
                		(yyval.exprvec)->push_back(new MatchPattern((yyvsp[(3) - (3)].expr), *(new NNil())));
                	}
              ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 184 "mu.y"
    { (yyval.ident) = (yyvsp[(1) - (1)].ident); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 188 "mu.y"
    { (yyval.expr) = new NNil(); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 189 "mu.y"
    { (yyval.expr) = new NBoolean(true); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 190 "mu.y"
    { (yyval.expr) = new NBoolean(false); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 191 "mu.y"
    { (yyval.expr) = new NNot(*(yyvsp[(2) - (2)].ident)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 192 "mu.y"
    { (yyval.expr) = new NNegation(*(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 193 "mu.y"
    { (yyval.expr) = new NNegation(*(yyvsp[(2) - (2)].ident)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 194 "mu.y"
    { (yyval.expr) = new NBinaryOperator(*(yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].token), *(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 195 "mu.y"
    { (yyval.expr) = new NBinaryOperator(*(yyvsp[(1) - (3)].ident), (yyvsp[(2) - (3)].token), *(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 196 "mu.y"
    { (yyval.expr) = new NBinaryOperator(*(yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].token), *(yyvsp[(3) - (3)].ident)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 197 "mu.y"
    { (yyval.expr) = new NBinaryOperator(*(yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].token), *(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 198 "mu.y"
    { (yyval.expr) = new NMethodCall(*(yyvsp[(1) - (4)].ident), *(yyvsp[(3) - (4)].exprvec)); delete (yyvsp[(3) - (4)].exprvec); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 199 "mu.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 202 "mu.y"
    { (yyval.expr) = new NListElements(*(yyvsp[(2) - (3)].exprvec)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 205 "mu.y"
    { (yyval.exprvec) = new ExpressionList(); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 206 "mu.y"
    { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 207 "mu.y"
    { (yyvsp[(1) - (3)].exprvec)->push_back((yyvsp[(3) - (3)].expr)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 212 "mu.y"
    { (yyval.exprvec) = new ExpressionList(); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 213 "mu.y"
    { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 214 "mu.y"
    { (yyvsp[(1) - (3)].exprvec)->push_back((yyvsp[(3) - (3)].expr)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 217 "mu.y"
    { (yyval.expr) = new NListElements(*(yyvsp[(2) - (3)].exprvec)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 220 "mu.y"
    { (yyval.exprvec) = new ExpressionList(); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 221 "mu.y"
    { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 222 "mu.y"
    { (yyvsp[(1) - (3)].exprvec)->push_back((yyvsp[(3) - (3)].expr)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2220 "parser.cpp"
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



/* Line 1675 of yacc.c  */
#line 230 "mu.y"

