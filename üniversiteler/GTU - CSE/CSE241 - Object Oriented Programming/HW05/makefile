CC = g++ -std=c++11
CFLAGS =
OBJS = src/AbstractHex.cpp src/Cell.cpp src/HexArray1D.cpp src/HexVector.cpp src/HexAdapter.cpp main.cpp

muo: 
	$(CC) $(OBJS) $(CFLAGS) -o output
	./output

debug:
	$(CC) $(OBJS) $(CFLAGS) -g -o output
	gdb ./output

memory:
	valgrind ./output