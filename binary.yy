%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define api.token.constructor
%code requires {
	#include <string>
	#include <iostream>
  #include <list>
  #include "Node.h"
}
%code{
  Node root;

	#define YY_DECL yy::parser::symbol_type yylex()
	YY_DECL;
}

%token <std::string> AND
%token <std::string> BREAK
%token <std::string> DO
%token <std::string> ELSE
%token <std::string> ELSEIF
%token <std::string> end
%token <std::string> FALSE
%token <std::string> FOR
%token <std::string> FUNCTION
%token <std::string> IF
%token <std::string> IN
%token <std::string> LOCAL
%token <std::string> NIL
%token <std::string> NOT
%token <std::string> OR
%token <std::string> REPEAT
%token <std::string> RETURN
%token <std::string> THEN
%token <std::string> TRUE
%token <std::string> UNTIL
%token <std::string> WHILE

%token <std::string> PLUS
%token <std::string> MINUS
%token <std::string> MULTIPLY
%token <std::string> FORWARDSLASH
%token <std::string> PERCENT
%token <std::string> CARET
%token <std::string> HASHTAG
%token <std::string> EQUALTO
%token <std::string> TILDEEQUAL
%token <std::string> LESSOREQUAL
%token <std::string> GREATEROREQUAL
%token <std::string> LESSTHAN
%token <std::string> GREATERTHAN
%token <std::string> EQUAL
%token <std::string> LEFTPARENTHESES
%token <std::string> RIGHTPARENTHESES
%token <std::string> LEFTBRACES
%token <std::string> RIGHTBRACES
%token <std::string> LEFTBRACKET
%token <std::string> RIGHTBRACKET
%token <std::string> SEMICOLON
%token <std::string> COLON
%token <std::string> COMMA
%token <std::string> DOT
%token <std::string> DOTDOT
%token <std::string> DOTDOTDOT


%token <std::string> INTEGER
%token <std::string> DECIMAL
%token <std::string> POWEROF
%token <std::string> HEXADECIMAL

%token <std::string> String
%token <std::string> Name



%type <Node> S
%type <Node> block
%type <Node> chunk
%type <Node> chunk_layer
%type <Node> laststat_layer
%type <Node> stat
%type <Node> elseif_layer
%type <Node> laststat
%type <Node> funcname
%type <Node> funcname_layer
%type <Node> varlist
%type <Node> varlist_layer
%type <Node> var
%type <Node> namelist
%type <Node> namelist_layer
%type <Node> explist
%type <Node> explist_layer
%type <Node> exp
%type <Node> exp_layer
%type <Node> Number
%type <Node> prefixexp
%type <Node> functioncall
%type <Node> args
%type <Node> function
%type <Node> funcbody
%type <Node> parlist
%type <Node> tableconstructor
%type <Node> fieldlist
%type <Node> fieldlist_layer
%type <Node> field
%type <Node> fieldsep
%type <Node> binop
%type <Node> unop

%token END 0 "end of file"
%%

S : block { $$ = Node("Start", ""); $$.children.push_back($1); root = $$; }
  ;

block : chunk { $$ = $1; }
      ;

chunk : 							  { $$ = Node("Block", "empty"); }
      | chunk_layer                   { $$ = Node("Block", ""); $$.children.push_back($1); }
      | chunk_layer laststat_layer    { $$ = Node("Block", ""); $$.children.push_back($1); $$.children.push_back($2); }
	  | laststat_layer				  { $$ = Node("Block", ""); $$.children.push_back($1);}
      ;

chunk_layer:  stat                              { $$ = Node("Statement", ""); $$.children.push_back($1); }
            | stat SEMICOLON                    { $$ = Node("Statement", ""); $$.children.push_back($1); }
			| chunk_layer stat                  { $$ = Node("Statement", ""); $$.children.push_back($1); $$.children.push_back($2); }
            | chunk_layer stat SEMICOLON        { $$ = Node("Statement", ""); $$.children.push_back($1); $$.children.push_back($2); }
			;

laststat_layer : laststat               { $$ = Node("Last statement", ""); $$.children.push_back($1); }
               | laststat SEMICOLON     { $$ = Node("Last statement", ""); $$.children.push_back($1); }
               ;


stat : varlist EQUAL explist  								{}
     | functioncall           								{}
     | DO block end           								{ $$ = $2;}
     | WHILE exp DO block end 								{}
	 | REPEAT block UNTIL exp 								{}
	 | IF exp THEN block end			    				{}
	 | IF exp THEN block ELSE block end 	   				{}
     | IF exp THEN block elseif_layer end    				{}
	 | IF exp THEN block elseif_layer ELSE block end    	{}
     | FOR Name EQUAL exp COMMA exp DO block end 			{}
     | FOR Name EQUAL exp COMMA exp COMMA exp DO block end  {}
     | FOR namelist IN explist DO block end 				{}
     | FUNCTION funcname funcbody 							{}
     | LOCAL FUNCTION Name funcbody 						{}
     | LOCAL namelist 										{ $$ = $2;}		/* HUR SKA LOCAL HANTERAS? */
     | LOCAL namelist EQUAL explist 						{}
     ;

elseif_layer : ELSEIF exp THEN block				{}
			 | elseif_layer ELSEIF exp THEN block		{}
			 ;

laststat : RETURN         { $$ = Node("Statement","return");}
		 | RETURN explist {}
         | BREAK          { $$ = Node("Statement","break");}
         ;
funcname : Name											{}
		 | Name COLON Name								{}
		 | Name funcname_layer                          {}
         | Name funcname_layer COLON Name               {}
         ;

funcname_layer : DOT Name 					{}
			   | funcname_layer DOT Name	{}
			   ;

varlist : var                  {$$ = $1;}
		| var varlist_layer    {}
        ;

varlist_layer : COMMA var					{}
			  | varlist_layer COMMA var		{}
			  ;

var : Name                           { $$ = Node("Identifier",$1); }
    | prefixexp LEFTBRACKET exp RIGHTBRACKET  {}
    | prefixexp DOT Name             {}
    ;

namelist : Name                { $$ = Node("Identifier", $1); }
         | Name namelist_layer {}
         ;

namelist_layer : COMMA Name					{}
			   | namelist_layer COMMA Name	{}
			   ;

explist : exp					{}
		| explist_layer exp 	{}
		;

explist_layer : exp COMMA				{}
			  | explist_layer exp COMMA {}
			  ;

  // EXP STRUKTUREN BEHÖVER DESIGNAS OM
exp : exp_layer								{}
	| exp_rec binop exp_layer				{}
	| unop exp_layer						{}
	;

exp_rec : exp_layer
		| exp_rec binop

exp_layer : NIL							{}
		  | FALSE						{}
		  | TRUE						{}
		  | Number						{}
		  | String						{}
		  | DOTDOTDOT					{}
		  | function					{}
		  | prefixexp					{}
		  | tableconstructor			{}

Number : INTEGER				{}
	   | DECIMAL				{}
	   | POWEROF				{}
	   | HEXADECIMAL			{}
	   ;

prefixexp : var 									{}
		  | functioncall 							{}
		  | LEFTPARENTHESES exp RIGHTPARENTHESES	{}
		  ;

functioncall : prefixexp args				{}
			 | prefixexp COLON Name args	{}
			 ;

args : LEFTPARENTHESES  RIGHTPARENTHESES		{}
	 | LEFTPARENTHESES parlist RIGHTPARENTHESES	{}
	 | tableconstructor							{}
	 | String									{}
	 ;

function : FUNCTION funcbody	{}
		 ;

funcbody : LEFTPARENTHESES 		   RIGHTPARENTHESES block end   {}
		 | LEFTPARENTHESES parlist RIGHTPARENTHESES block end 	{}
		 ;

parlist : namelist					{}
		| namelist COMMA DOTDOTDOT	{}
		| 				 DOTDOTDOT	{}
		;

tableconstructor : LEFTBRACES 			RIGHTBRACES		{}
				 | LEFTBRACES fieldlist RIGHTBRACES		{}
				 ;

fieldlist : field 							{}
		  | field fieldlist_layer			{}
		  | field 				  fieldsep	{}
		  | field fieldlist_layer fieldsep	{}
		  ;

fieldlist_layer : 				  fieldsep field    {}
				| fieldlist_layer fieldsep field	{}
				;

field : LEFTBRACKET exp RIGHTBRACKET EQUAL exp 		{}
	  | Name EQUAL 	exp 							{}
	  | 			exp								{}
	  ;

fieldsep : COLON		{}
		 | SEMICOLON	{}
		 ;
//BYTA NAMN PÅ EQUALTO?
binop : PLUS			{}
	  | MINUS			{}
	  | MULTIPLY		{}
	  | FORWARDSLASH	{}
	  | CARET			{}
	  | PERCENT			{}
	  | DOTDOT			{}
	  | LESSTHAN		{}
	  | LESSOREQUAL		{}
	  | GREATERTHAN		{}
	  | GREATEROREQUAL	{}
	  | EQUALTO			{}
	  | TILDEEQUAL		{}
	  | AND				{}
	  | OR				{}
	  ;

unop : MINUS 	{}
	 | NOT 		{}
	 | HASHTAG	{}
	 ;
