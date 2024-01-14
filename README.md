# Compiler Project

## Introduction

This project, developed as part of the "Introduction to Compilation" course, entails the creation of a compiler for a C-like language. The compiler is implemented using Lex and Yacc to build a lexical scanner and parser. The parser is designed to construct an Abstract Syntax Tree (AST) for any valid code in the specified language. If there are any syntax errors, the parser is responsible for printing an error message indicating the type of error.

## Project Structure

Here's a brief overview of the project structure:

- [`scanner.l`](scanner.l): Lex file defining the lexical analyzer and tokens recognized by the compiler.

- [`parser.y`](parser.y): Yacc file containing the grammar of the language that the compiler is parsing.
  
- [`compiled_files/`](compiled_files/): This directory contains output files generated during the compilation process.

- [`helper.c`](helper.c) and [`helper.h`](helper.h): These files contain helper functions used in the project.

- [`inputs/`](inputs/): Various input files for testing the code.

- [`run.sh`](run.sh): Shell script automating the compilation and execution process.


## Lexical Scanner

The lexical scanner, implemented in Lex, tokenizes the input code and passes it to the parser. If there are any lexical errors, appropriate error messages are generated. The scanner also includes a function to scan the AST in preorder and print it if the code is valid. The code is printed with indentation and parentheses to emphasize the code structure.

## Semantics

The parser includes semantic checks implemented with the help of a symbol table. Various semantic rules are enforced, covering aspects such as function declarations, variable names, scoping, argument matching, and type compatibility. The compiler prints specific error messages corresponding to different semantic errors. The goal is to ensure the validity and consistency of the code in terms of semantics.

### Semantic Rules Checked:

1. There exists a unique main function, having no arguments and returning void.
2. No two functions in the same scope share the same name.
3. No two variables in the same scope share the same name.
4. Functions must be defined before they are called.
5. Variables must be declared before they are used.
6. The actual number of arguments in a function call must match the formal number of arguments in the function definition.
7. The types of arguments in a function call must match the types of formal parameters in the function definition.
8. The return type of a function call must match the declared return type of the function. Additionally, the return type cannot be a string.
9. The type of the condition in an if statement must be boolean.
10. The type of the condition in loops (while, for) must be boolean.
11. The type of the expression within square brackets `[]` (used for string indexing) must be int.
12. The operator `[]` is only allowed for strings.
13. The type of the left operand in an assignment (`=`) must match the type of the right operand. Note: For strings, only characters and null are allowed.
14. Types in expressions must match according to specific rules:
    - For operators (`+`, `-`, `*`, `/`), operands can be int or real, and the result is int if both operands are int; otherwise, it's real.
    - For logical operators (`&&`, `||`), operands must be boolean, and the result is boolean.
    - For relational operators (`>`, `<`, `>=`, `<=`), operands can be int or real, and the result is boolean.
    - For equality operators (`==`, `!=`), operands can be int, boolean, real, char, or pointers to the same type, and the result is boolean.
    - The absolute value operator `||` is only allowed for strings, and the result is int.
    - The negation operator `!` is only allowed for a boolean, and the result is a boolean.
    - The operator `&` is only allowed for int, real, char, or string[i].
    - The unary operator `*` is only allowed for pointers.

## Three Address Code Generation

The compiler further translates the code into Three Address Code (3AC) based on the principles discussed in class. The compiler takes an input file containing any program written in the language, performs compilation steps, and outputs the generated 3AC code to a file. In case of any errors during the compilation process, the compiler halts and prints an appropriate error message.

## Compilation and Execution (Linux Environment)

To compile and run the project on a Linux system, follow these steps:
```bash
# Install Lex, Yacc, and GCC
sudo apt install bison flex gcc
```

### Configure Input and Output
Edit the run.sh script to specify the input file and output file locations according to your requirements.
The script is configured to take input from the inputs directory and save the output to the specified location.

### Run the shell script to compile the code and generate Three Address Code (3AC).
```bash
sh run.sh
```

The compiler will check for syntax errors, perform semantic analysis, and generate 3AC code.
If any errors occur, the script will display an appropriate error message.

Please note that this setup assumes a Linux environment.
Make sure you are using Linux and have the necessary packages installed before running the script.
If you encounter any issues or have questions, refer to the error messages or reach out for assistance.

## Encouragement for Exploration and Deeper Understanding

Feel free to explore and experiment with the compiler for a deeper understanding of the compilation process and its intricacies. If you encounter any issues or have questions, refer to the error messages and feel free to reach out for clarification.

This project reflects the culmination of efforts in mastering the concepts of lexical analysis, parsing, semantics, and code generation in the context of compilation theory.
