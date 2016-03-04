%top{
#include "binary.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%

"return"                        { return yy::parser::make_RETURN(yytext); }
"break"                         { return yy::parser::make_BREAK(yytext); }
;                               { return yy::parser::make_SEMICOLON(yytext);  }
[a-zA-Z0-9_]+                   { return yy::parser::make_Name(yytext);       }


<<EOF>>                     return yy::parser::make_END();

%%
