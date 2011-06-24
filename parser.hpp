
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
     TCAT = 308,
     TPLUSEQ = 309,
     TMINUSEQ = 310
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 124 "parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


