%{
#include "y.tab.h"
%}

LETTER [a-zA-Z]
SEMI [;]
%%

{LETTER}+{SEMI}     {yylval.str = yytext; ;return L;}

[ \t\n]     ;
.           ;

%%

int yywrap() {
    return 1;
}