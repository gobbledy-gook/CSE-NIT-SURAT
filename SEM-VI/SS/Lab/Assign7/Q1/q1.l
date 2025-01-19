%{
#include "y.tab.h"
%}

%%

[0-9]+      {yylval.num = atoi(yytext); return NUM;}
[ \t\n]     ;
[-+*/;]     {return yytext[0];}
.           ;

%%

int yywrap() {
    return 1;
}

