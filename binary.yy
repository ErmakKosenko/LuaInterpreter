%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define api.token.constructor
%code requires {
	#include <string>
	#include <iostream>
  #include <vector>
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

%token <std::string> Name
%token <std::string> Number

%type <Node> S
%type <Node> block
%type <std::string> chunk
%type <std::string> chunk_layer
%type <std::string> laststat_layer
%type <std::string> stat
%type <std::string> elseif_layer
%type <std::string> laststat
%type <std::string> funcname
%type <std::string> funcname_layer
%type <std::string> varlist
%type <std::string> varlist_layer
%type <std::string> namelist
%type <std::string> namelist_layer
%type <std::string> explist
%type <std::string> explist_layer
%type <std::string> exp
%type <std::string> prefixexp
%type <std::string> functioncall
%type <std::string> args
%type <std::string> function
%type <std::string> funcbody
%type <std::string> parlist
%type <std::string> tableconstructor
%type <std::string> fieldlist
%type <std::string> fieldlist_layer
%type <std::string> field
%type <std::string> fieldsep
%type <std::string> binop
%type <std::string> unop

%token END 0 "end of file"
%%

S : //block { $$ = Node("Start", ""); root = $$; }
	Number {std::cout << $1;	}
  ;
/*
block : chunk {}
      ;

chunk : { std::cout << "EMPTY CHUNK"; }
      | chunk_layer                   { std::cout << $1; }
      | chunk_layer laststat_layer    { std::cout << $1 << "" << $2;}
	  | laststat_layer				  { std::cout << $1; }
      ;

chunk_layer:  stat                                                    { $$ = $1;}
            | stat SEMICOLON                                          { $$ = $1 + $2;}
			| chunk_layer stat                                        { $$ = $1 + $2;}
            | chunk_layer stat SEMICOLON                              { $$ = $1 + $2 + $3;}
			;

laststat_layer : laststat               { $$ = $1;}
               | laststat SEMICOLON     { $$ = $1+$2;}
               ;


stat : varlist EQUAL explist  								{}
     | functioncall           								{}
     | DO block end           								{}
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
     | LOCAL namelist 										{}
     | LOCAL namelist EQUAL explist 						{}
     ;

elseif_layer : ELSEIF exp THEN block				{}
			 | elseif_layer ELSEIF exp THEN block		{}
			 ;

laststat : RETURN         { $$ = "RETURN";}
		 | RETURN explist {}
         | BREAK          { $$ = "BREAK";}
         ;
funcname : Name											{}
		 | Name COLON Name								{}
		 | Name funcname_layer                          {}
         | Name funcname_layer COLON Name               {}
         ;

funcname_layer : DOT Name 					{}
			   | funcname_layer DOT Name	{}
			   ;

varlist : var                  {}
		| var varlist_layer    {}
        ;

varlist_layer : COMMA var					{}
			  | varlist_layer COMMA var		{}
			  ;

var : Name                           {}
    | prefixexp LEFTBRACKET exp RIGHTBRACKET  {}
    | prefixexp DOT Name             {}
    ;

namelist : Name                {}
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
			  // KLART HIT NER
			  // Saknar regex för Number och String
exp : NIL						{}
	| FALSE						{}
	| TRUE						{}
	| Number					{}
	| String					{}
	| DOTDOTDOT					{}
	| function					{}
	| prefixexp					{}
	| tableconstructor			{}
	| exp binop exp				{}
	| unop exp					{}
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
*/
