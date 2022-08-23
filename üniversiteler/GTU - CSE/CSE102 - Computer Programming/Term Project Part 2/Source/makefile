muho: main.c pattern.c pattern.h
	cc main.c pattern.c -Wall -Wextra -lm -o output
	./output

debug:
	cc main.c pattern.c -g -Wall -Wextra -lm -o output
	gdb -q output

memory:
	valgrind ./output

ekstra_memory:
	valgrind --leak-check=full ./output

