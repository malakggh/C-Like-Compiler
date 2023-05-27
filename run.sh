clear
lex scanner.l
yacc -d parser.y
cc -o out y.tab.c -ll -Ly
# ./out<inputTest.txt > output_part1.txt
# clear
./out<tests/test3.c > output_part1.r