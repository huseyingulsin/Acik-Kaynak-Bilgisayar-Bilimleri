muo: helpers.cpp helpers.h main.cpp
	g++ -std=c++11 main.cpp helpers.cpp -Wall -Wextra -o output
	./output

debug:
	g++ -std=c++11 -g main.cpp helpers.cpp -Wall -Wextra -o output
	gdb ./output

memory:
	g++ -std=c++11 -g main.cpp helpers.cpp -Wall -Wextra -o output
	valgrind ./output