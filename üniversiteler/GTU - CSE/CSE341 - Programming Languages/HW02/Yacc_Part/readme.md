# Explanation

## Files

### Written by author

- gpp_lexer.l: Flex lexer file
- gpp_interpreter.y: Yacc parser file
- yacc_helper.h: Header file for help to gpp_interpreter.y file. It contains the definitions and functions.

### Automatically generated

- gpp_lexer.c: Could be generated with lex compiler command.
- gpp_interpreter.c: Could be generated with yacc compiler command.
- gpp_interpreter.h: Could be generated with yacc compiler command.

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

## Notes about Yacc Part

This yacc file contains all necessary CFG Rules.
