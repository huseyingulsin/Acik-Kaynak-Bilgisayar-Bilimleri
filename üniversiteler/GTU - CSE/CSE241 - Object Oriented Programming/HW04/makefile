CC = g++ -std=c++11
CFLAGS = -Wall -Wextra
OBJS = hex.cpp main.cpp

muo: hex.cpp main.cpp hex.h 
	$(CC) $(OBJS) $(CFLAGS) -o output
	./output

debug:
	$(CC) $(OBJS) $(CFLAGS) -g -o output
	gdb ./output

memory:
	valgrind ./output