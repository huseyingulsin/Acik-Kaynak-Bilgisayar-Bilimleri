CC = gcc
CFLAGS =-Wextra -Wall -lrt -lpthread -pthread

UTILS_SRC = src/utils.c
UTILS_HEADER = include/utils.h

MAIN = main.c

OUT = makeFileSystem
ARGS = 4 400 myFile.data

CLEAN = $(OUT)

.DEFAULT_GOAL = all # default goal

muo: $(UTILS_SRC) $(UTILS_HEADER) $(MAIN)
	$(CC) $(CFLAGS) $(UTILS_SRC) $(MAIN) -o $(OUT) -lm

all: muo

run:
	./$(OUT) $(ARGS)

clean:
	rm $(CLEAN)

# Check memory leaks with valgrind
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(OUT) $(ARGS)

# show all zombie processes
# if you want to run this command in your terminal, you can use this
# ps aux | awk '"[Zz]" ~ $8 { printf("%s, PID = %d\n", $8, $2); }'
zombies:
	ps aux | awk '"[Zz]" ~ $$8 { printf("%s, PID = %d\n", $$8, $$2); }'

# Show all not freed shared memroy, semaphore, and mutexes
memory:
	ipcs
	ls /dev/shm -a
	
# check controlling terminal (for midterm project but I dont removed it)
controling_terminal:
	ps -xj | grep serverY

# Send sigint to process
kill: 
	killall $(OUT) -2
