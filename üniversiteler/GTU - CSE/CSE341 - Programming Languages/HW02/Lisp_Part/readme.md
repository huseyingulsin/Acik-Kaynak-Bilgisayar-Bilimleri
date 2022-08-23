# Explanation

## Files

### Written by author

- gpp_lexer.lisp: Lexer lisp file from previous homework
- gpp_interpreter.lisp: Interpreter lisp file

### Test files

- helloworld.g++: contains the inputs
- helloworldOutput.txt: contains the generated outputs

### Other files

- makefile: contains instructions to compile the program
- readme.md: contains info about gpp_interpreter

## Makefile

`make` command: Generates gpp_lexer.c, gpp_interpreter.c and gpp_interpreter.h and brings all of them and runs it.

`make input` command: Sends helloworld.g++ file to gpp_interpreter.c && gpp_lexer.c and prints to the terminal

`make output` command: Sends helloworld.g++ file to gpp_interpreter.c && gpp_lexer.c and prints result to helloworldOutput.txt
