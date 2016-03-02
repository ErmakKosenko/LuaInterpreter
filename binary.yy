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
%type <Node> rootNode

%token END 0 "end of file"
%%

rootNode : ALL { std::cout << "MATCH"; }
         | rootNode ALL { std::cout << "MATCH";}
          ;
