%{
#include <stdio.h>
#include <stdlib.h>
%}

DIGIT [0-9]
%%
{DIGIT}+(\.{DIGIT}+)? {
    int a = atof(yytext);
    int b;
    printf("Enter the second number: ");
    scanf("%d", &b); 
    a = a + b;
    b = a - b;
    a = a - b;
    printf("The swapped numbers are -- first: %d, second: %d", a, b);
    return 0;
}
\n   ; /* ignore newline characters */
.    ; /* ignore all other characters */
%%

int main() {
    printf("Enter the first number: ");
    yylex();
    return 0;
}