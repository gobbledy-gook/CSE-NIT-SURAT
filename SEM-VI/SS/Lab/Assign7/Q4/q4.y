%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lex.yy.h"

void yyerror(char *s);
%}

%start S
%token STRING

%%
S   :   STRING      {printf("Valid");}
    ;           

%%

int main(){
    printf("Enter a string: ");
    return yyparse();
}

void yyerror(char *s) {
    printf("\nExpression is invalid\n");
}
