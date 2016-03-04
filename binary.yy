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
%token <std::string> SEMICOLON
%token <std::string> RETURN
%token <std::string> BREAK
%token <std::string> Name

%type <Node> S
%type <Node> block
%type <std::string> chunk_layer
%type <std::string> chunk
%type <std::string> stat
%type <std::string> laststat

%token END 0 "end of file"
%%

S : block { $$ = Node("Start", ""); root = $$; }
  ;

block : chunk {}
      ;

chunk : { std::cout << "EMPTY CHUNK"; }
      | chunk_layer
      ;
                        //MÅSTE TESTAS, FINNS SHIFT/REDUCE ERRORS
chunk_layer:  stat                                                    {std::cout << $1;}
            | stat SEMICOLON                                          {std::cout << $1 << "" << $2;}
            | stat laststat                                           {std::cout << $1 << "" << $2;}
            | stat laststat SEMICOLON                                 {std::cout << $1 << "" << $2 << $3;}
            | stat SEMICOLON laststat                                 {std::cout << $1 << "" << $2 << $3;}
            | stat SEMICOLON laststat SEMICOLON                       {std::cout << $1 << "" << $2 << $3 << $4;}
            | chunk_layer stat                                        {std::cout << $1 << "" << $2;}
            | chunk_layer stat SEMICOLON                              {std::cout << $1 << "" << $2 << $3; }
            | chunk_layer stat laststat                               {std::cout << $1 << "" << $2 << $3; }
            | chunk_layer stat laststat SEMICOLON                     {std::cout << $1 << "" << $2 << $3 << $4; }
            | chunk_layer stat SEMICOLON laststat                     {std::cout << $1 << "" << $2 << $3 << $4; }
            | chunk_layer stat stat SEMICOLON laststat SEMICOLON      {std::cout << $1 << "" << $2 << $3 << $4 << $5; }
            ;


stat : Name { $$ = $1; }
     ;
    /*
       varlist EQUAL explist  {}
     | functioncall           {}
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
     */

laststat : RETURN         { $$ = $1;}
         | BREAK          { $$ = $1;}
         //| RETURN explist {}
         ;
    /*
funcname : Name                         {}
         | Name COLON Name              {}
         | Name DOT funcname            {}
         ;

varlist : var                  {}
        | varlist COMMA var    {}
        ;

var : Name                           {}
    | prefixexp BRACKET exp BRACKET  {}
    | prefixexp DOT Name             {}
    ;

namelist : Name                {}
         | Name COMMA namelist {}
         ;
*/
