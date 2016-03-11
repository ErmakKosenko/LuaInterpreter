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
%token <std::string> DEVIDE
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

%token <std::string> STRING
%token <std::string> NAME



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
%type <Node> exp_trail
%type <Node> Number
%type <Node> Name
%type <Node> String
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

S : block { $$ = Node("start", ""); $$.children.push_back($1); root = $$; }
  ;

block : chunk { $$ = $1; }
      ;

chunk : 							  { $$ = Node("block", "empty"); }
      | chunk_layer                   { $$ = Node("block", ""); $$.children.push_back($1); }
      | chunk_layer laststat_layer    { $$ = Node("block", ""); $$.children.push_back($1); $$.children.push_back($2); }
	  | laststat_layer				  { $$ = Node("block", ""); $$.children.push_back($1);}
      ;

chunk_layer:  stat                              { $$ = Node("statementchunk",""); $$.children.push_back($1); }
            | stat SEMICOLON                    { $$ = Node("statementchunk",""); $$.children.push_back($1); $$.children.push_back(Node("semicolon",";")); }
			| chunk_layer stat                  { $$ = Node("statementchunk",""); for(Node e : $1.children){$$.children.push_back(e);} $$.children.push_back($2);  }
            | chunk_layer stat SEMICOLON        { $$ = Node("statementchunk",""); for(Node e : $1.children){$$.children.push_back(e);} $$.children.push_back($2); $$.children.push_back(Node("semicolon",";")); }
			;

laststat_layer : laststat               { $$ = $1; }
               | laststat SEMICOLON     { $$ = $1; $$.children.push_back(Node("semicolon",";")); }
               ;


stat : varlist EQUAL explist  								{ $$ = Node("statement", ""); $$.children.push_back($1); $$.children.push_back(Node("equal","=")); $$.children.push_back($3); }
     | functioncall           								{ $$ = Node("statement",""); $$.children.push_back($1);}
     | DO block end           								{ $$ = Node("statement",""); $$.children.push_back(Node("do","do")); $$.children.push_back($2); $$.children.push_back(Node("end","end"));}
     | WHILE exp DO block end 								{ $$ = Node("statement",""); $$.children.push_back(Node("while","while")); $$.children.push_back($2); $$.children.push_back(Node("do","do")); $$.children.push_back($4); $$.children.push_back(Node("end","end")); }
	 | REPEAT block UNTIL exp 								{ $$ = Node("statement",""); $$.children.push_back(Node("repeat", "")); $$.children.push_back($2); $$.children.push_back(Node("until", "")); $$.children.push_back($4); }
	 | IF exp THEN block end			    				{ $$ = Node("statement",""); $$.children.push_back(Node("if","if")); $$.children.push_back($2); $$.children.push_back(Node("then","then")); $$.children.push_back($4); $$.children.push_back(Node("end","end")); }
	 | IF exp THEN block ELSE block end 	   				{ $$ = Node("statement",""); $$.children.push_back(Node("if","if")); $$.children.push_back($2); $$.children.push_back(Node("then","then")); $$.children.push_back($4); $$.children.push_back(Node("else","else")); $$.children.push_back($6); $$.children.push_back(Node("end","end")); }
     | IF exp THEN block elseif_layer end    				{ $$ = Node("statement",""); $$.children.push_back(Node("if","if")); $$.children.push_back($2); $$.children.push_back(Node("then","then")); $$.children.push_back($4); $$.children.push_back(Node("elseif","elseif")); for (Node e : $5.children){ $$.children.push_back(e); } $$.children.push_back(Node("end","end")); }
	 | IF exp THEN block elseif_layer ELSE block end    	{ $$ = Node("statement",""); $$.children.push_back(Node("if","if")); $$.children.push_back($2); $$.children.push_back(Node("then","then")); $$.children.push_back($4); $$.children.push_back(Node("elseif","elseif")); for (Node e : $5.children){ $$.children.push_back(e); } $$.children.push_back(Node("else","else")); $$.children.push_back($7); $$.children.push_back(Node("end","end")); }
     | FOR Name EQUAL exp COMMA exp DO block end 			{ $$ = Node("statement",""); $$.children.push_back(Node("for","for")); $$.children.push_back($2); $$.children.push_back(Node("equal","=")); $$.children.push_back($4); $$.children.push_back(Node("comma",",")); $$.children.push_back($6); $$.children.push_back(Node("do","do")); $$.children.push_back($8); $$.children.push_back(Node("end","end"));}
     | FOR Name EQUAL exp COMMA exp COMMA exp DO block end  { $$ = Node("statement",""); $$.children.push_back(Node("for","for")); $$.children.push_back($2); $$.children.push_back(Node("equal","=")); $$.children.push_back($4); $$.children.push_back(Node("comma",",")); $$.children.push_back($6); $$.children.push_back(Node("comma",",")); $$.children.push_back($8); $$.children.push_back(Node("do","do")); $$.children.push_back($10); $$.children.push_back(Node("end","end")); }
     | FOR namelist IN explist DO block end 				{ $$ = Node("statement",""); $$.children.push_back(Node("for","for")); $$.children.push_back($2); $$.children.push_back(Node("in","in")); $$.children.push_back($4); $$.children.push_back(Node("do","do")); $$.children.push_back($6); $$.children.push_back(Node("end","end"));}
     | FUNCTION funcname funcbody 							{ $$ = Node("statement",""); $$.children.push_back(Node("function","function")); $$.children.push_back($2); $$.children.push_back($3); }
     | LOCAL FUNCTION Name funcbody 						{ $$ = Node("statement",""); $$.children.push_back(Node("local","local")); $$.children.push_back(Node("function","function")); $$.children.push_back($3); $$.children.push_back($4);}
     | LOCAL namelist 										{ $$ = Node("statement",""); $$.children.push_back(Node("local","local")); $$.children.push_back($2); }
     | LOCAL namelist EQUAL explist 						{ $$ = Node("statement",""); $$.children.push_back(Node("local","local")); $$.children.push_back($2); $$.children.push_back(Node("equal","=")); $$.children.push_back($4); }
     ;

elseif_layer : ELSEIF exp THEN block					{ $$ = Node("elseif","elseif"); $$.children.push_back($2); $$.children.push_back(Node("then","then")); $$.children.push_back($4); }
			 | elseif_layer ELSEIF exp THEN block		{ $$ = $1;  $$.children.push_back(Node("elseif","elseif")); $$.children.push_back($3); $$.children.push_back(Node("then","then")); $$.children.push_back($5);}
			 ;

laststat : RETURN         { $$ = Node("laststatement",""); $$.children.push_back(Node("return","return")); }
		 | RETURN explist { $$ = Node("laststatement",""); $$.children.push_back(Node("return","return")); $$.children.push_back($2); }
         | BREAK          { $$ = Node("laststatement",""); $$.children.push_back(Node("break","break")); }
         ;
funcname : Name											{ $$ = Node("funcname",""); $$.children.push_back($1);}
		 | Name COLON Name								{ $$ = Node("funcname",""); $$.children.push_back($1); $$.children.push_back(Node("colon",":")); $$.children.push_back($3); }
		 | Name funcname_layer                          { $$ = Node("funcname",""); $$.children.push_back($1); for(Node e : $2.children){$$.children.push_back(e);} 	}
         | Name funcname_layer COLON Name               { $$ = Node("funcname",""); $$.children.push_back($1); for(Node e : $2.children){$$.children.push_back(e);} $$.children.push_back(Node("colon",":")); $$.children.push_back($4);}
         ;

funcname_layer : DOT Name 					{ $$ = Node("dot","."); $$.children.push_back($2); }
			   | funcname_layer DOT Name	{ $$ = $1; $$.children.push_back(Node("dot",".")); $$.children.push_back($3); }
			   ;

varlist : var                  { $$ = Node("varlist",""); $$.children.push_back($1); }
		| var varlist_layer    { $$ = Node("varlist",""); $$.children.push_back($1); for(Node e : $2.children){$$.children.push_back(e);} }
        ;

varlist_layer : COMMA var					{ $$ = Node("comma",","); $$.children.push_back($2); }
			  | varlist_layer COMMA var		{ $$ = $1; $$.children.push_back(Node("comma",",")); $$.children.push_back($3);}
			  ;

var : Name                           		  { $$ = Node("var",""); $$.children.push_back($1); }
    | prefixexp LEFTBRACKET exp RIGHTBRACKET  { $$ = Node("var",""); $$.children.push_back($1); $$.children.push_back(Node("leftbracket","[")); $$.children.push_back($3); $$.children.push_back(Node("rightbracket","]")); }
    | prefixexp DOT Name             		  { $$ = Node("var",""); $$.children.push_back($1); $$.children.push_back(Node("dot",".")); $$.children.push_back($3); }
    ;

namelist : Name                { $$ = Node("namelist", ""); $$.children.push_back($1); }
         | Name namelist_layer { $$ = Node("namelist", ""); $$.children.push_back($1); for(Node e : $2.children){$$.children.push_back(e);} }
         ;

namelist_layer : COMMA Name					{ $$ = Node("namelist_layer",""); $$.children.push_back(Node("comma",",")); $$.children.push_back($2); }
			   | namelist_layer COMMA Name	{ $$ = $1; $$.children.push_back(Node("comma",",")); $$.children.push_back($3); }
			   ;

explist : exp					{ $$ = Node("explist", ""); $$.children.push_back($1); }
		| explist_layer exp 	{ $$ = Node("explist", ""); for(Node e: $1.children){$$.children.push_back(e);} $$.children.push_back($2); }
		;

explist_layer : exp COMMA				{ $$ = Node("explist_layer",""); $$.children.push_back($1); $$.children.push_back(Node("comma",",")); }
			  | explist_layer exp COMMA { $$ = $1; $$.children.push_back($1); $$.children.push_back(Node("comma",",")); }
			  ;


exp : exp_layer				{ $$ = Node("exp",""); $$.children.push_back($1); }
 	| exp binop exp_trail	{ $$ = Node("exp",""); for(Node e : $1.children){$$.children.push_back(e);} $$.children.push_back($3); $$.children.push_back($2); }
	| unop exp				{ $$ = Node("exp",""); $$.children.push_back($1); $$.children.push_back($2); }
	;

exp_trail : exp_layer {$$ = $1;}
		  ;

exp_layer : NIL					{ $$ = Node("nil",$1);}
		  | FALSE				{ $$ = Node("false",$1);}
		  | TRUE				{ $$ = Node("true",$1);}
		  | Number				{ $$ = $1;}
		  | String				{ $$ = $1;}
		  | DOTDOTDOT			{ $$ = Node("dotdotdot",$1);}
		  | function			{ $$ = $1;}
		  | prefixexp			{ $$ = $1;}
		  | tableconstructor	{ $$ = $1;}
		  ;

Number : INTEGER				{ $$ = Node("integer", $1); }
	   | DECIMAL				{ $$ = Node("decimal", $1);}
	   | POWEROF				{ $$ = Node("powerof", $1);}
	   | HEXADECIMAL			{ $$ = Node("hexadecimal", $1);}
	   ;

Name : NAME { $$ = Node("identifier", $1); }
	 ;

String : STRING { std::string temp; for(int i=1;i<$1.length()-1;i++){temp = temp + $1[i];}  $$ = Node("string",temp);}
	   ;

prefixexp : var 									{ $$ = Node("prefixexp",""); $$.children.push_back($1); }
		  | functioncall 							{ $$ = Node("prefixexp",""); $$.children.push_back($1);}
		  | LEFTPARENTHESES exp RIGHTPARENTHESES	{ $$ = Node("prefixexp",""); $$.children.push_back(Node("leftparentheses","(")); $$.children.push_back(Node($2)); $$.children.push_back(Node("rightparentheses",")")); }
		  ;

functioncall : prefixexp args				{ $$ = Node("functioncall",""); $$.children.push_back($1); $$.children.push_back($2); }
			 | prefixexp COLON Name args	{ $$ = Node("functioncall",""); $$.children.push_back($1); $$.children.push_back(Node("colon",":")); $$.children.push_back($3); $$.children.push_back($4);}
			 ;

args : LEFTPARENTHESES  RIGHTPARENTHESES		{ $$ = Node("args",""); $$.children.push_back(Node("leftparentheses","(")); $$.children.push_back(Node("rightparentheses",")")); }
	 | LEFTPARENTHESES explist RIGHTPARENTHESES	{ $$ = Node("args",""); $$.children.push_back(Node("leftparentheses","(")); $$.children.push_back($2); $$.children.push_back(Node("rightparentheses",")"));}
	 | tableconstructor							{ $$ = Node("args",""); $$.children.push_back($1); }
	 | String									{ $$ = Node("args",""); $$.children.push_back($1); }
	 ;

function : FUNCTION funcbody	{ $$ = Node("function","function"); $$.children.push_back(Node("function","function")); $$.children.push_back($2); }
		 ;

funcbody : LEFTPARENTHESES 		   RIGHTPARENTHESES block end   { $$ = Node("funcbody",""); $$.children.push_back(Node("leftparentheses","(")); $$.children.push_back(Node("rightparentheses",")")); $$.children.push_back($3); $$.children.push_back(Node("end","end")); }
		 | LEFTPARENTHESES parlist RIGHTPARENTHESES block end 	{ $$ = Node("funcbody",""); $$.children.push_back(Node("leftparentheses","(")); $$.children.push_back($2); $$.children.push_back(Node("rightparentheses",")")); $$.children.push_back($4); $$.children.push_back(Node("end","end"));}
		 ;

parlist : namelist					{ $$ = Node("funcbody",""); $$.children.push_back($1); }
		| namelist COMMA DOTDOTDOT	{ $$ = Node("funcbody",""); $$.children.push_back($1); $$.children.push_back(Node("comma",",")); $$.children.push_back(Node("dotdotdot","...")); }
		| 				 DOTDOTDOT	{ $$ = Node("funcbody",""); $$.children.push_back(Node("dotdotdot","..."));}
		;

tableconstructor : LEFTBRACES 			RIGHTBRACES		{ $$ = Node("tableconstructor",""); $$.children.push_back(Node("leftbraces","[")); $$.children.push_back(Node("rightbraces","]")); }
				 | LEFTBRACES fieldlist RIGHTBRACES		{ $$ = Node("tableconstructor",""); $$.children.push_back(Node("leftbraces","[")); $$.children.push_back($2); $$.children.push_back(Node("rightbraces","]"));}
				 ;

fieldlist : field 							{ $$ = Node("fieldlist",""); $$.children.push_back($1); }
		  | field fieldlist_layer			{ $$ = Node("fieldlist",""); $$.children.push_back($1); for(Node e : $2.children){$$.children.push_back(e);}}
		  | field 				  fieldsep	{ $$ = Node("fieldlist",""); $$.children.push_back($1); $$.children.push_back($2); }
		  | field fieldlist_layer fieldsep	{ $$ = Node("fieldlist",""); $$.children.push_back($1); for(Node e : $2.children){$$.children.push_back(e);} $$.children.push_back($3); }
		  ;

fieldlist_layer : 				  fieldsep field    { $$ = Node("fieldlist_layer",""); $$.children.push_back($1); $$.children.push_back($2); }
				| fieldlist_layer fieldsep field	{ $$ = $1; $$.children.push_back($2); $$.children.push_back($3);}
				;

field : LEFTBRACKET exp RIGHTBRACKET EQUAL exp 		{ $$ = Node("field",""); $$.children.push_back(Node("leftbracket","[")); $$.children.push_back($2); $$.children.push_back(Node("rightbracket","]")); $$.children.push_back(Node("equal","=")); $$.children.push_back($5); }
	  | Name EQUAL 	exp 							{ $$ = Node("field",""); $$.children.push_back($1); $$.children.push_back(Node("equal","=")); $$.children.push_back($3); }
	  | 			exp								{ $$ = Node("field",""); $$.children.push_back($1);}
	  ;

fieldsep : COMMA		{ $$ = Node("Fieldsep", $1);}
		 | SEMICOLON	{ $$ = Node("Fieldsep", $1);}
		 ;
//BYTA NAMN PÅ EQUALTO?
binop : PLUS			{ $$ = Node("binop", $1);}
	  | MINUS			{ $$ = Node("binop", $1);}
	  | MULTIPLY		{ $$ = Node("binop", $1);}
	  | DEVIDE			{ $$ = Node("binop", $1);}
	  | CARET			{ $$ = Node("binop", $1);}
	  | PERCENT			{ $$ = Node("binop", $1);}
	  | DOTDOT			{ $$ = Node("binop", $1);}
	  | LESSTHAN		{ $$ = Node("binop", $1);}
	  | LESSOREQUAL		{ $$ = Node("binop", $1);}
	  | GREATERTHAN		{ $$ = Node("binop", $1);}
	  | GREATEROREQUAL	{ $$ = Node("binop", $1);}
	  | EQUALTO			{ $$ = Node("binop", $1);}
	  | TILDEEQUAL		{ $$ = Node("binop", $1);}
	  | AND				{ $$ = Node("binop", $1);}
	  | OR				{ $$ = Node("binop", $1);}
	  ;

unop : MINUS 	{ $$ = Node("unop", $1);}
	 | NOT 		{ $$ = Node("unop", $1);}
	 | HASHTAG	{ $$ = Node("unop", $1);}
	 ;
