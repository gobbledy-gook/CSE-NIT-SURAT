%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
%}

DIGIT [0-9]
%%
{DIGIT}+(\.{DIGIT}+)? { 
    float radius = atof(yytext); 
    float area = M_PI * radius * radius; 
    printf("The area of the circle with radius %.2f is: %.2f\n", radius, area); 
}
\n   ; /* ignore newline characters */
.    ; /* ignore all other characters */
%%

int main() {
    yylex();
    return 0;
}
