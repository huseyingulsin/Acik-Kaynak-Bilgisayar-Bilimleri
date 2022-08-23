#ifndef QUEUE_LL
#define QUEUE_LL
#endif

#ifndef LINKED_LIST
#include "linked-list.h"
#endif

typedef struct QueueLL {
	LinkedList* l;
} QueueLL;

QueueLL* newQueueLL() {
	QueueLL* q = (QueueLL*)malloc(sizeof(QueueLL));
	q->l = newLinkedList();
	return q;
}

void freeQueueLL(QueueLL* q) {
	freeLinkedList(q->l);
	free(q);
}

void pushQueueLL(QueueLL* q, int value) {
	pushTailLinkedList(q->l, value);
}

int getQueueLL(QueueLL* q) {
	if (q->l->head == NULL) {
		return 0;
	}
	return q->l->head->value;
}

void popQueueLL(QueueLL* q) {
	popHeadLinkedList(q->l);
}

void printQueueLL(QueueLL* q) {
	printLinkedList(q->l);
}
