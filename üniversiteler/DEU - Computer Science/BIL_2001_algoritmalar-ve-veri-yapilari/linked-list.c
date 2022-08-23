#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked-list.h"

#define LIMIT 100

int main(int argc, char const *argv[]) {

	LinkedList* l = newLinkedList();
	printf("New linked list\n");
	printLinkedList(l);
	printf("\n");

	for (int i = 0; i < 3; i++) {
		pushHeadLinkedList(l, rand() % LIMIT);
		printf("Pushed head\n");
		printLinkedList(l);
		printf("\n");
	}

	for (int i = 0; i < 4; i++) {
		popTailLinkedList(l);
		printf("Pop tail\n");
		printLinkedList(l);
		printf("\n");
	}

	for (int i = 0; i < 3; i++) {
		pushTailLinkedList(l, rand() % LIMIT);
		printf("Push tail\n");
		printLinkedList(l);
		printf("\n");
	}

	for (int i = 0; i < 4; i++) {
		popHeadLinkedList(l);
		printf("Pop head\n");
		printLinkedList(l);
		printf("\n");
	}

	return 0;
}
