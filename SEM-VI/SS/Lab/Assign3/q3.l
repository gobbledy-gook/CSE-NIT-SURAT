%{
#include <stdio.h>
#include <stdlib.h>
%}

DIGIT [0-9]
%%
{DIGIT}+(\.{DIGIT}+)? {
    float farhen = atof(yytext); 
    float celcius = (float)(((farhen - 32)*5)/9);
    printf("The temperature in Celcius: %f\n", celcius);
    return 0;
}
\n   ; /* ignore newline characters */
.    ; /* ignore all other characters */
%%

int main() {
    printf("Enter the temp in farhenheit: ");
    yylex();
    return 0;
}