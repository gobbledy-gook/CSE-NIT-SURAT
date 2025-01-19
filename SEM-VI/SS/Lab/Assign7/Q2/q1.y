%{
#include <stdlib.h>
#include <stdio.h>
#include "lex.yy.h"

void yyerror(char *s);
int symbtab[26];
char word[16];
int x = 0;
%}

%union {char* str;}
%start S
%token L
%type <str> L S

%%
S   :   L       {
                    $$ = $1; 
                    int i =0, flag = 0;
                    for(i =0; $$[i]!=';'; i++){
                        word[i] = $$[i];
                    }
                    for(int j = 0; j < i/2; j++){
                        if(word[j]!=word[i-1-j]){
                            printf("Not Palindrome!");
                            flag = 1;
                        }
                    }
                    if(flag == 0){
                        printf("Palindrome");
                    }
                }
    ;

%%

int main(){
    printf("Enter a word of 16 characters to check if it is a Palindrome (end it with a ';'): ");
    return yyparse();
}

void yyerror(char *s) {
    printf("\nExpression is invalid\n");
}
