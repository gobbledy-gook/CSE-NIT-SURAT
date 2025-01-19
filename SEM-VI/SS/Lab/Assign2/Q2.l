%{ 
#include<stdio.h> 
int lc=0, wc=0, cc=0;
%} 

%% 
[\n] {lc++; cc+=yyleng;}
[^\t\n ]+ {wc++; cc+=yyleng;}
%% 
  
int main() 
{    
    printf("Enter the input:\n");
    yylex();
    printf("No. of words are: %d\n", wc); 
    printf("No. of character are: %d\n", cc);
    printf("No. of new lines are: %d\n", lc);
  
    return 0; 
} 

int yywrap()
{
    return 1;
}