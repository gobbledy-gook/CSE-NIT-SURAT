%{
#include <stdio.h>
#include <stdlib.h>

int neg = 0,pos = 0,frac = 0;
%}

/* Regular expressions for tokens */
DIGIT [0-9]

%%
\-{DIGIT}+ {neg++;}
{DIGIT}+\.{DIGIT}+ {frac++;}
{DIGIT}+ {pos++;}
. | \n ;

%%

int yywrap(void){
    printf("Total no. of positive numbers: %d\n Total no. of negative numbers: %d\n Total no. of fractions: %d", pos, neg, frac); 
    return 1; 
}

int main() {
    printf("Enter numbers: ");
    yylex();

    return 0;
}
