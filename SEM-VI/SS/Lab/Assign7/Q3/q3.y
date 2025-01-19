%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lex.yy.h"

void yyerror(char *s);
%}

%union {char * str;}
%start S
%token STRING
%token PLUS MULT
%type <str> STRING S 

%% 
S   :   S S MULT    {printf("A");}
    |   S S PLUS    {printf("B");}
    |   STRING      {$$ = $1;
                    }
    ;

%%

int main(){
    printf("Enter a string: ");
    return yyparse();
}

void yyerror(char *s) {
    printf("\nExpression is invalid\n");
}
