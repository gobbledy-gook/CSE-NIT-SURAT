%{
#include <stdio.h>
#include <stdlib.h>
%}

DIGIT [0-9]

%%
{DIGIT}+(\.{DIGIT}+)? {
                    float principal = atof(yytext); 
                    float rate, time;
                    printf("Enter the rate of interest: ");
                    scanf("%f", &rate);
                    printf("Enter the time period: ");
                    scanf("%f", &time);
                    float simple_interest = (principal * rate * time) / 100.0;
                    printf("The simple interest is: %.2f\n", simple_interest);
                    printf("Total amount after interest is: %.2f\n", principal + simple_interest);
                    return 0;
}
\n   ; /* ignore newline characters */
.    ; /* ignore all other characters */
%%

int main() {
    printf("Enter the principal amount: ");
    yylex();
    return 0;
}