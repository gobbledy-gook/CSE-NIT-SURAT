flex q3.l
flex -o lex.yy.h -d q3.l
echo "Lexer compiled"
yacc -d q3.y
echo "Yacc file compiled"
gcc -o parser y.tab.c
echo "Starting Parser.."
./parser