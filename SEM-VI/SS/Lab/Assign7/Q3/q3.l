%{
#include "y.tab.h"
%}


SYMB [+*]

%%

a                      {yylval.str = yytext; return STRING;}
\+                    {return PLUS;}
\*                    {return MULT;}
[ \t\n]                 {return 0;}
.                       {return 0;}

%%

int yywrap() {
    return 1;
}