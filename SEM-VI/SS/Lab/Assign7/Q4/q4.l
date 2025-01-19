%{
#include "y.tab.h"
%}

TERM [01]
%%

^0[01]*0$        { return STRING; }
^1[01]*1$           { return STRING; }
[ \t\n]           {return 0;}
.                 {return 0;}

%%

int yywrap() {
    return 1;
}