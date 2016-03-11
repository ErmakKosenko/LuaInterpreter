%top{
#include "binary.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%

"and"                           { return yy::parser::make_AND(yytext); }
"break"                         { return yy::parser::make_BREAK(yytext); }
"do"                            { return yy::parser::make_DO(yytext); }
"else"                          { return yy::parser::make_ELSE(yytext); }
"elseif"                        { return yy::parser::make_ELSEIF(yytext); }
"end"                           { return yy::parser::make_end(yytext); }
"false"                         { return yy::parser::make_FALSE(yytext); }
"for"                           { return yy::parser::make_FOR(yytext); }
"function"                      { return yy::parser::make_FUNCTION(yytext); }
"if"                            { return yy::parser::make_IF(yytext); }
"in"                            { return yy::parser::make_IN(yytext); }
"local"                         { return yy::parser::make_LOCAL(yytext); }
"nil"                           { return yy::parser::make_NIL(yytext); }
"not"                           { return yy::parser::make_NOT(yytext); }
"or"                            { return yy::parser::make_OR(yytext); }
"repeat"                        { return yy::parser::make_REPEAT(yytext); }
"return"                        { return yy::parser::make_RETURN(yytext); }
"then"                          { return yy::parser::make_THEN(yytext); }
"true"                          { return yy::parser::make_TRUE(yytext); }
"until"                         { return yy::parser::make_UNTIL(yytext); }
"while"                         { return yy::parser::make_WHILE(yytext); }

"+"                               { return yy::parser::make_PLUS(yytext); }
"-"                               { return yy::parser::make_MINUS(yytext); }
"*"                               { return yy::parser::make_MULTIPLY(yytext); }
"/"                               { return yy::parser::make_DEVIDE(yytext); }
"%"                               { return yy::parser::make_PERCENT(yytext); }
"^"                               { return yy::parser::make_CARET(yytext); }
"#"                               { return yy::parser::make_HASHTAG(yytext); }
"=="                              { return yy::parser::make_EQUALTO(yytext); }
"~="                              { return yy::parser::make_TILDEEQUAL(yytext); }
"<="                              { return yy::parser::make_LESSOREQUAL(yytext); }
">="                             { return yy::parser::make_GREATEROREQUAL(yytext); }
"<"                               { return yy::parser::make_LESSTHAN(yytext); }
">"                               { return yy::parser::make_GREATERTHAN(yytext); }
"="                               { return yy::parser::make_EQUAL(yytext); }
"("                               { return yy::parser::make_LEFTPARENTHESES(yytext); }
")"                               { return yy::parser::make_RIGHTPARENTHESES(yytext); }
"{"                               { return yy::parser::make_LEFTBRACES(yytext); }
"}"                               { return yy::parser::make_RIGHTBRACES(yytext); }
"["                               { return yy::parser::make_LEFTBRACKET(yytext); }
"]"                               { return yy::parser::make_RIGHTBRACKET(yytext); }
";"                               { return yy::parser::make_SEMICOLON(yytext);  }
":"                               { return yy::parser::make_COLON(yytext); }
","                               { return yy::parser::make_COMMA(yytext); }
"."                             { return yy::parser::make_DOT(yytext); }
".."                            { return yy::parser::make_DOTDOT(yytext); }
"..."                           { return yy::parser::make_DOTDOTDOT(yytext); }


([0-9]+)                                             { return yy::parser::make_INTEGER(yytext); }
[0-9]+\.[0-9]+                                       { return yy::parser::make_DECIMAL(yytext); }
[0-9]+\.[0-9]+(e\-|E)[0-9]+                          { return yy::parser::make_POWEROF(yytext); }
0x[0-9a-fA-F]+                                       { return yy::parser::make_HEXADECIMAL(yytext); }

(_[0-9a-zA-Z_]+|[a-zA-Z]+([0-9a-zA-Z_]+)?)           { return yy::parser::make_NAME(yytext); }
(\"([a-zA-Z0-9 .,:;\-!#¤%&/()*^\0\'\"\\a\\b\\f\\n\\r\\t\\v\\])+\"|\'([a-zA-Z0-9 .,:;\-!#¤%&/()*^\0\'\"\a\b\f\n\r\t\v\\])+\')                                    { return yy::parser::make_STRING(yytext); }
<<EOF>>                                                return yy::parser::make_END();

%%
