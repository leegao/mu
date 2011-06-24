%{
#include <string>
#include "node.h"
#include "parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() { }
%}

%%

[ \t\n]					;
[\;]					return TOKEN(TERMINATE);
[\n][\n]				return TOKEN(TERMINATE);

"and"					return TOKEN(TAND);
"or"					return TOKEN(TOR);
"not"					return TOKEN(TUNOT);
"function"				return TOKEN(TFUNCTION);
"var"					return TOKEN(TVAR);
"true"					return TOKEN(TTRUE);
"false"					return TOKEN(TFALSE);
"if"					return TOKEN(TIF);
"for"					return TOKEN(TFOR);
"elseif"				return TOKEN(TELSEIF);
"else"					return TOKEN(TELSE);
"while"					return TOKEN(TWHILE);
"break"					return TOKEN(TBREAK);
"return"				return TOKEN(TRETURN);
"in"					return TOKEN(TIN);
"nil"					return TOKEN(TNIL);
"match"					return TOKEN(TMATCH);
"with"					return TOKEN(TWITH);

[a-zA-Z_$][a-zA-Z0-9_$]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]*			SAVE_TOKEN; return TDOUBLE;
[0-9]+					SAVE_TOKEN; return TINTEGER;
\"(\\.|[^\\"])*\"		SAVE_TOKEN; return TSTRING_LITERAL;
\'(\\.|[^\\'])*\'		SAVE_TOKEN; return TSTRING_LITERAL;
r\"(\\.|[^\\"])*\"		SAVE_TOKEN; return TSTRING_LITERAL;
r\'(\\.|[^\\'])*\'		SAVE_TOKEN; return TSTRING_LITERAL;

"="						return TOKEN(TEQUAL);
"=="					return TOKEN(TCEQ);
"!="					return TOKEN(TCNE);
"<"						return TOKEN(TCLT);
"<="					return TOKEN(TCLE);
">"						return TOKEN(TCGT);
">="					return TOKEN(TCGE);
"("						return TOKEN(TLPAREN);
")"						return TOKEN(TRPAREN);
"["						return TOKEN(TLBRACKET);
"]"						return TOKEN(TRBRACKET);
"{"						return TOKEN(TLBRACE);
"}"						return TOKEN(TRBRACE);
"."						return TOKEN(TDOT);
".."					return TOKEN(TCAT);
","						return TOKEN(TCOMMA);
"+"						return TOKEN(TPLUS);
"-"						return TOKEN(TMINUS);
"**"					return TOKEN(TEXP);
"*"						return TOKEN(TMUL);
"/"						return TOKEN(TDIV);
"|"						return TOKEN(TBITOR);
"&"						return TOKEN(TBITAND);
"^"						return TOKEN(TBITXOR);
"?"						return TOKEN(TQUESTION);
":"						return TOKEN(TCOLON);
"::"					return TOKEN(TPREPEND);

.						printf("Unknown token!\n"); yyterminate();

%%