%{
#include "y.tab.h"
%}



%%
and         {yylval.str = yytext; return AND;}
not         {yylval.str = yytext; return NOT;}
or         {yylval.str = yytext; return OR;}
true         {yylval.str = yytext; return TF;}
false         {yylval.str = yytext; return TF;}
\(          {yylval.str = yytext; return EO;}

[ \t\n]   ;
.           ;

%%

int yywrap() {
    return 1;
}