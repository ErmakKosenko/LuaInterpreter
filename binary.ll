%top{
#include "binary.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%
[a-z]                         { return yy::parser::make_ALL(yytext);       }

<<EOF>>                     return yy::parser::make_END();

%%
