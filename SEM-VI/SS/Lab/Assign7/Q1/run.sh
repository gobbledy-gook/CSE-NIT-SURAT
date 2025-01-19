flex q4.l
flex -o lex.yy.h -d q1.l
echo "Lexer compiled"
yacc -d q1.y
echo "Yacc file compiled"
gcc -o parser y.tab.c
echo "Starting Parser.."
./parser