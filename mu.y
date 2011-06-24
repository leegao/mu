%{
    #include "node.h"
    #include <cstdio>
    NBlock *programBlock = new NBlock(); /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }
%}

/* Represents the many different ways we can access our data */
%union {
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
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> TIDENTIFIER TINTEGER TDOUBLE TSTRING_LITERAL
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT
%token <token> TPLUS TMINUS TMUL TDIV TAND TOR TUNOT
%token <token> TLBRACKET TRBRACKET TEXP TBITOR TBITAND TBITXOR
%token <token> TVAR TFUNCTION TTRUE TFALSE TMOD TFOR TIF TQUESTION TCOLON TPREPEND
%token <token> TELSEIF TELSE TWHILE TBREAK TRETURN TIN TERMINATE TNIL TMATCH TWITH TCAT

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident
%type <expr> numeric string expr list_decl inline_cond m_pattern list_pdecl match func_decl
%type <varvec> func_decl_args 
%type <exprvec> call_args list_el list_pel match_pattern
%type <block> program stmts block
%type <stmt> stmt var_decl func_new while_syn for_syn if_syn elseif_syn elseend_syn
%type <counter> for_syn_decl
%type <token> comparison pattern_cmp

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : stmt { programBlock->statements.push_back($1); return 0; }
        ;

stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
      | stmts stmt { $1->statements.push_back($<stmt>2); }
      ;

stmt : var_decl TERMINATE | func_new | while_syn | for_syn | elseend_syn
     | expr TERMINATE { $$ = new NExpressionStatement(*$1); }
     | expr TLBRACKET expr TRBRACKET TEQUAL expr TERMINATE { $$ = new NNewIndex(*$1, *$3, *$6); }
     | TBREAK TERMINATE { $$ = new NBreak(); }
     | TRETURN TERMINATE { $$ = new NReturn(*(new NNil())); }
     | TRETURN expr TERMINATE { $$ = new NReturn(*$2); }
     | TERMINATE { $$ = new NExpressionStatement(*(new NDoNothing())); }
     ;

block : TLBRACE stmts TRBRACE { $$ = $2; }
      | TLBRACE TRBRACE { $$ = new NBlock(); }
      ;

var_decl : TVAR ident { $$ = new NVariableDeclaration(*$2); }
         | TVAR ident TEQUAL expr { $$ = new NVariableDeclaration(*$2, $4); }
         ;

func_decl : TFUNCTION TLPAREN func_decl_args TRPAREN block
            { $$ = new NFunctionDeclaration(*$3, *$5); delete $3; }
          ;

func_new : TFUNCTION ident TLPAREN func_decl_args TRPAREN block { 
            	NFunctionDeclaration* dec = new NFunctionDeclaration(*$4, *$6); 
            	$$ = new NVariableDeclaration(*$2, dec);
            	delete $4; 
            }
          ;

func_decl_args : /*blank*/  { $$ = new VariableList(); }
          | var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
          | func_decl_args TCOMMA var_decl { $1->push_back($<var_decl>3); }
          ;

while_syn : TWHILE expr block { $$ = new NWhileLoop(*$2, *$3); };

for_syn_decl : ident TIN expr { $$ = new InCounter(*$1, *$3); }
             | expr TCOMMA expr TCOMMA expr { $$ = new LoopCounter(*$1, *$3, *$5); }
             | var_decl TCOMMA expr TCOMMA expr { $$ = new VarLoopCounter(*$1, *$3, *$5); }
             | TLPAREN for_syn_decl TRPAREN { $$ = $2; }
             ;

for_syn : TFOR for_syn_decl block { $$ = new NForLoop(*$2, *$3); };

if_syn : TIF expr block { $$ = new NIf(*$2, *$3, *(new NBlock())); }
       ;

elseif_syn : if_syn { $$ = $1; }
           | elseif_syn TELSEIF expr block { $$ = $1; (dynamic_cast<NIf*> ($$))->else_if(*$3, *$4); }
           ;

elseend_syn : elseif_syn { $$ = $1; }
            | elseif_syn TELSE block { $$ = $1; (dynamic_cast<NIf*> ($$))->else_end(*$3); }
            ;

ident : TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
      ;

numeric : TINTEGER { $$ = new NNumber(atof($1->c_str())); delete $1; }
        | TDOUBLE { $$ = new NNumber(atof($1->c_str())); delete $1; }
        ;

string : TSTRING_LITERAL { $$ = new NString(*$1); }
       ;

inline_cond : expr TQUESTION expr TCOLON expr { $$ = new NInlineCond(*$1, *$3, *$5); }
            ;

expr : ident TEQUAL expr { $$ = new NAssignment(*$<ident>1, *$3); }
     | expr TLPAREN call_args TRPAREN { $$ = new NMethodCall(*$1, *$3); delete $3; }
     | ident { $<ident>$ = $1; }
     | expr TLBRACKET expr TRBRACKET { $$ = new NListIndex(*$1, *$3); }
     | numeric
     | string
     | list_decl
     | inline_cond
     | match
     | func_decl
     | TTRUE { $$ = new NBoolean(true); }
     | TFALSE { $$ = new NBoolean(false); }
     | TNIL { $$ = new NNil(); }
     | expr comparison expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | TUNOT expr { $$ = new NNot(*$2); }
     | TMINUS expr { $$ = new NNegation(*$2); }
     | TLPAREN expr TRPAREN { $$ = $2; }
     ;

match : TMATCH expr TWITH match_pattern { $$ = new NMatch(*$2, *$4); };

match_pattern : m_pattern block { 
                	$$ = new ExpressionList(); 
                	$$->push_back(new MatchPattern($1, *$2)); 
              }
              | m_pattern {
                	$$ = new ExpressionList(); 
                	$$->push_back(new MatchPattern($1, *(new NNil()))); 
              }
              | match_pattern TBITOR m_pattern block {
                	// back track to make sure that back isn't NNil
                	MatchPattern* last = dynamic_cast<MatchPattern*>($1->back());
                	$$ = $1;
                	if (dynamic_cast<NNil*>(&(last->block))){
                		// push this pattern into last and set block
                		$$ = $1;
                		last->patterns.push_back($3);
                		last->block = *$4;
                		
                	}else{
                		// create a new match pattern
                		$$->push_back(new MatchPattern($3, *$4));
                	}
              }
              | match_pattern TBITOR m_pattern {
                	// back track to make sure that back isn't NNil
                	MatchPattern* last = dynamic_cast<MatchPattern*>($1->back());
                	$$ = $1;
                	if (dynamic_cast<NNil*>(&(last->block))){
                		// push this pattern into last and set block
                		$$ = $1;
                		last->patterns.push_back($3);
                		
                	}else{
                		// create a new match pattern
                		$$->push_back(new MatchPattern($3, *(new NNil())));
                	}
              }
              ;
     
m_pattern : ident { $<ident>$ = $1; }
          | string
          | numeric
          | list_pdecl
          | TNIL { $$ = new NNil(); }
          | TTRUE { $$ = new NBoolean(true); }
          | TFALSE { $$ = new NBoolean(false); }
          | TUNOT ident { $$ = new NNot(*$2); }
          | TMINUS numeric { $$ = new NNegation(*$2); }
          | TMINUS ident { $$ = new NNegation(*$2); }
          | m_pattern TPREPEND m_pattern { $$ = new NBinaryOperator(*$1, $2, *$3); }
          | ident pattern_cmp numeric { $$ = new NBinaryOperator(*$1, $2, *$3); }
          | numeric pattern_cmp ident { $$ = new NBinaryOperator(*$1, $2, *$3); }
          | numeric comparison numeric { $$ = new NBinaryOperator(*$1, $2, *$3); }
          | ident TLPAREN call_args TRPAREN { $$ = new NMethodCall(*$1, *$3); delete $3; }
          | TLPAREN m_pattern TRPAREN { $$ = $2; }
          ;

list_pdecl : TLBRACKET list_pel TRBRACKET { $$ = new NListElements(*$2); }
           ;

list_pel : /*blank*/ { $$ = new ExpressionList(); }
         | m_pattern { $$ = new ExpressionList(); $$->push_back($1); }
         | list_pel TCOMMA m_pattern { $1->push_back($3); }
         ;

pattern_cmp : TPLUS | TMINUS | TMUL | TDIV 

call_args : /*blank*/  { $$ = new ExpressionList(); }
          | expr { $$ = new ExpressionList(); $$->push_back($1); }
          | call_args TCOMMA expr  { $1->push_back($3); }
          ;
          
list_decl : TLBRACKET list_el TRBRACKET { $$ = new NListElements(*$2); }
          ;

list_el : /*blank*/ { $$ = new ExpressionList(); }
        | expr { $$ = new ExpressionList(); $$->push_back($1); }
        | list_el TCOMMA expr { $1->push_back($3); }
        ;

comparison : TCEQ | TCNE | TCLT | TCLE | TCGT | TCGE
           | TPLUS | TMINUS | TMUL | TDIV | TAND | TOR | TBITAND
           | TBITOR | TBITXOR | TCAT | TMOD | TPREPEND
           ;

%%