/*
An implementation of the stack data structure using arrays
The snippet in the main demonstrates
how to create a sorted queue using a buffer queue
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RAND_RANGE 10
#define SIZE 5

typedef struct {
	int count;
	int head;
	int* values;
} arrayStack;

// Allocates memory to queue fields of given size
arrayStack* initArrayStack(int count) {
	arrayStack* s = (arrayStack*)malloc(sizeof(arrayStack));
	s->count = count;
	s->head = 0;
	s->values = (int*)malloc(sizeof(int) * count);
	return s;
}

// Frees the stack and it's fields
void freeArrayStack(arrayStack* s) {
	free(s->values);
	free(s);
	return;
}

// Returns the top element without affecting the queue
int getArrayStack(arrayStack* s) {
	if (s->head > 0) {
		return s->values[s->head - 1];
	}
	return -1;
}

// Adds a new element to the queue
bool pushArrayStack(arrayStack* s, int value) {
	if (s->head < s->count) {
		s->values[s->head++] = value;
		return true;
	}
	return false;
}

// Removes and returns the top element of the queue
int popArrayStack(arrayStack* s) {
	if (s->head > 0) {
		return s->values[--s->head];
	}
	return -1;
}

// Prints out the queue bottom to top
void printArrayStack(arrayStack* s) {
	for (int i = 0; i < s->head; i++) {
		printf("%d, ", s->values[i]);
	}
	printf("\n");
}

// Checks if the queue has any elements
bool isEmptyArrayStack(arrayStack* s) {
	return s->head == 0;
}

int main(int argc, char const *argv[]) {
	// Initializing
	// Stack s will keep the values
	// Stack d will be used as a buffer
	arrayStack* s = initArrayStack(SIZE);
	arrayStack* b = initArrayStack(SIZE);

	for (int i = 0; i < SIZE; i++) {
		// Adding a new random number
		int temp = rand() % RAND_RANGE;
		printf("Number %d will be added\n", temp);

		// Shifting every number bigger than temp to buffer
		printf("Shifting larger elements from original to buffer\n");
		while (!isEmptyArrayStack(s) && getArrayStack(s) < temp) {
			pushArrayStack(b, popArrayStack(s));
			printf("Origin: ");
			printArrayStack(s);
			printf("Buffer: ");
			printArrayStack(b);
		}

		// Pushing the new number to the original stack
		pushArrayStack(s, temp);
		printf("Pushed %d to the original queue\n", temp);
		printArrayStack(s);

		// Re-adding every number in the spare queue to the original
		while (!isEmptyArrayStack(b)) {
			pushArrayStack(s, popArrayStack(b));
			printf("Origin: ");
			printArrayStack(s);
			printf("Buffer: ");
			printArrayStack(b);
		}
	}

	printf("\n");
	printf("Origin: ");
	printArrayStack(s);

	return 0;
}
