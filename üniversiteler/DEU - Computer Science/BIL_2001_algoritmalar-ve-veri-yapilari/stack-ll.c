#include <stdlib.h>
#include <stdio.h>

#ifndef STACK_LL
#include "stack-ll.h"
#endif

#define LIMIT 100

int main(int argc, char const *argv[]) {
	StackLL* s = newStackLL();

	for (int i = 0; i < 5; i++) {
		pushStackLL(s, rand() % LIMIT);
		printf("Pushed stack");
		printStackLL(s);
		printf("\n");
	}

	for (int i = 0; i < 6; i++) {
		printf("Get stack %d\n", getStackLL(s));

		popStackLL(s);
		printf("Pop stack\n");
		printStackLL(s);
		printf("\n");
	}

	freeStackLL(s);

	printf("Exit\n");
	return 0;
}
