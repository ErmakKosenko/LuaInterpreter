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
%token <std::string> ALL
%type <Node> S
%type block
%type chunk

%token END 0 "end of file"
%%

S : block { $$ = Node("Start", ""); root = $$; }
  ;

block : chunk {}
      ;

chunk : {}
      | stat                              {}
      | stat laststat                     {}
      | stat laststat SEMICOLON           {}
      | stat SEMICOLON                    {}
      | stat SEMICOLON laststat           {}
      | stat SEMICOLON laststat SEMICOLON {}
      | stat chunk                        {}
      | stat SEMICOLON chunk              {}
      ;

stat : varlist EQUAL explist  {}
     | finctioncall           {}
     | DO block end           {}
     | WHILE exp DO block END {}
     | IF exp THEN block      {}   // Does it have to have else if <-- INCOMPLETE
     | FOR Name EQUAL exp COMMA exp DO block END {}
     | FOR Name EQUAL exp COMMA exp COMMA exp DO block END {}
     | FOR namelist IN explist DO block END {}
     | FUNCTION funcname funcbody {}
     | LOCAL FUNCTION Name fincbody {}
     | LOCAL namelist {}
     | LOCAL namelist EQUAL explist {}
     ;

laststat : RETURN         {}
         | RETURN explist {}
         | BREAK          {}
         ;

funcname : Name                         {}
         | Name COLON Name              {}
         | Name DOT funcname            {}
         ;

varlist : var                  {}
        | var COMMA varlist    {}
        ;

var : Name                           {}
    | prefixexp BRACKET exp BRACKET  {}
    | prefixexp DOT Name             {}
    ;

namelist : Name                {}
         | Name COMMA namelist {}
         ;
