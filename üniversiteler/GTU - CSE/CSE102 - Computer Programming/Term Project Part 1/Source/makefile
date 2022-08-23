muho:epslib.h epslib.c main.c
	gcc main.c epslib.c -lm -Wall -Wextra -o output
	./output

debug:
	gcc main.c epslib.c -lm -Wall -Wextra -g -o output
	gdb output

memory:
	valgrind ./output