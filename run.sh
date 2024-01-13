# Create the directory if it doesn't exist
mkdir -p compiled_files

# Clear the screen
clear

# Run Lex
lex -o compiled_files/lex.yy.c scanner.l

# Run Yacc
yacc -d -o compiled_files/y.tab.c parser.y

# Compile the C code
cc -I . -o compiled_files/out compiled_files/y.tab.c -ll -Ly

# Run the compiled code and redirect output
compiled_files/out < inputs/part3.c > output.r

# to debug use
# gdb ./out
