%{
#include <stdio.h>
#include <stdlib.h>
%}

/* Regular expressions for tokens */
DIGIT [0-9]
LETTER [a-zA-Z]
ID {LETTER}({LETTER}|{DIGIT})*
OPERATOR [\+\-\*\/]

%%
{ID}    printf("Identifier: %s\n", yytext);
{OPERATOR}   printf("Operator: %s\n", yytext);
{DIGIT} printf("Digit or Operand: %s\n", yytext);
[ \t\n]   return 0;  ; /* skip whitespace and newline */
.       {printf("Invalid character: %s\n", yytext);return 0;}
%%

int main() {
    printf("Enter an arithmetic expression (without spaces): ");
    yylex();
    return 0;
}
