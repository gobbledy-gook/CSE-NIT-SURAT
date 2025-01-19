%{
#include <stdlib.h>
#include <stdio.h>
void yyerror(char *s);
#include "lex.yy.h"

%}

%union {int num;}
%start S
%token NUM
%type <num> NUM


%%
S   :   NUM           {printf("%d", $1);}
    |   NUM '+' NUM   {printf("%d", $1 + $3);}
    |   NUM '-' NUM   {printf("%d", $1 - $3);}
    |   NUM '*' NUM   {printf("%d", $1 * $3);}
    |   NUM '/' NUM   {printf("%d", $1 / $3);}
    ;

%%

int main(){
    return yyparse();
}

void yyerror(char *s) {
    printf("\nExpression is invalid\n");
}
