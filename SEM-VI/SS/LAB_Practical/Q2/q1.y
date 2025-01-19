%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lex.yy.h"

void yyerror(char *s);
%}

%union {char * str;}
%start S
%token EO EC TF AND NOT OR 
%type <str> S EXP EO EC TF AND NOT OR


%%
S   :   EO EXP EC       {printf("%s%s%s", $1, $2, $3);}
    |   EXP             {printf("D");strcpy($$, $1); printf("%s", $1);}
    ;
EXP :   EXP AND TF       {printf("A\t");
                        if(strcmp($1, "true") && strcmp($3, "true")){
                            strcpy($$, "false");
                            printf("false");
                        }
                        else{
                            strcpy($$, "true");
                            printf("true");
                            
                        }
                            }
    |   TF OR TF        {if(strcmp($1, "true") || strcmp($3, "true")){
                            strcpy($$, "true");
                            printf("true");
                        }
                        else{
                            strcpy($$, "false");
                            printf("false");
                        }
                            }
    |   NOT TF          {if(strcmp($2, "true") ){
                            strcpy($$, "true");
                            printf("true");

                        }
                        else{
                            strcpy($$, "false");
                            printf("false");
                        };}
    |   TF AND TF      {printf("C\t");
                        if(strcmp($1, "true") && strcmp($3, "true")){
                            strcpy($$, "false"); 
                            printf("false"); 
                        }
                        else{
                            strcpy($$, "true");
                            printf("true");
                            
                        }}
    |   TF                {strcpy($$, $1);}
    ;  
%%

int main(){
    printf("Enter a string: ");
    return yyparse();
}

void yyerror(char *s) {
    printf("\nExpression is invalid\n");
}