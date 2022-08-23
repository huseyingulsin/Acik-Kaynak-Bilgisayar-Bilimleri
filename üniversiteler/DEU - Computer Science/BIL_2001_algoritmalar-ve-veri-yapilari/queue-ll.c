#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_LL
#include "queue-ll.h"
#endif

#define LIMIT 100

int main(int argc, char const *argv[]) {
	QueueLL* q = newQueueLL();

	printf("New queue\n");
	printQueueLL(q);
	printf("\n");

	for (int i = 0; i < 5; i++) {
		pushQueueLL(q, rand() % LIMIT);
		printf("Pushed queue \n");
		printQueueLL(q);
		printf("\n");
	}

	for (int i = 0; i < 6; i++) {
		printf("Get queue %d\n", getQueueLL(q));

		popQueueLL(q);
		printf("Pop queue\n");
		printQueueLL(q);
		printf("\n");
	}

	freeQueueLL(q);

	printf("Exit\n");

	return 0;
}
