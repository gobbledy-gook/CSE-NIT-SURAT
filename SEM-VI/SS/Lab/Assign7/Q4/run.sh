flex q4.l
flex -o lex.yy.h -d q4.l
echo "Lexer compiled"
yacc -d q4.y
echo "Yacc file compiled"
gcc -o parser y.tab.c
echo "Starting Parser.."
./parser