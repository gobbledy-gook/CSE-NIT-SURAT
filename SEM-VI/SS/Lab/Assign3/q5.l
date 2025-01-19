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
    if(b == 0){
        printf("Error: Division not possible!");
    }
    else{
        printf("Divison of %d with %d is %f", a, b, (float)a/b);
    }
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