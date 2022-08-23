# Explanation

## Files

gpp_lexer.l: flex lexer file
gpp_lexer.c: result of the flex lexer

example_input.txt: contains the inputs
example_output.txt: contains the generated outputs

makefile: contains instructions to compile the program

## Makefile

`make` command: Generates gpp_lexer.c and runs it.

`make input` command: Sends example_input.txt file to gpp_lexer.c and prints to the terminal

`make output` command: Sends example_input.txt file to gpp_lexer.c and prints result to example_output.txt
