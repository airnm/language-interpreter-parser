%{
#include "token.h"
%}
DIGIT [-]*[0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n) /* skip whitespace */
\+ { return TOKEN_ADD; }
\- { return TOKEN_SUB; }
\< { return TOKEN_LESS; }
\> { return TOKEN_GREATER; }
\= { return TOKEN_EQUAL; }
\* { return TOKEN_MULTIPLY; }
\( { return TOKEN_PARENTHESES1; }
\) { return TOKEN_PARENTHESES2; }
\{ { return TOKEN_BRACKET1; } 
\} { return TOKEN_BRACKET2; }
\[ { return TOKEN_SQUARE_BRACKET1; }
\] { return TOKEN_SQUARE_BRACKET2; }
void { return TOKEN_VOID; }
main { return TOKEN_MAIN; }
sqrt { return TOKEN_SQRT; }
\" { return TOKEN_QUOTE; }
\; { return TOKEN_SEMICOLON; }
\: { return TOKEN_COLON; }
\' { return TOKEN_SINGLEQUOTE; }
\$ { return TOKEN_DOLLARSIGN; }
\/ { return TOKEN_SLASH; }
\, { return TOKEN_COMMA; } // New rule for comma
\. { return TOKEN_DOT; }   // New rule for dot
double { return TOKEN_DOUBLE; }
for { return TOKEN_FOR; }
if { return TOKEN_IF; }
int { return TOKEN_INT; }
print { return TOKEN_PRINT; }
else { return TOKEN_ELSE; }
import { return TOKEN_IMPORT; }
"//".*      /* skip comments */
while { return TOKEN_WHILE; }
{LETTER}+ { return TOKEN_IDENT; }
{DIGIT}+ { return TOKEN_NUMBER; }
\"[^\"\n]*\" { return TOKEN_STRING; }
. { return TOKEN_ERROR; }
%%
int yywrap() { return 1; }
