#ifndef LINKED_LIST
#include "linked-list.h"
#endif

#ifndef STACK_LL
#define STACK_LL
#endif


typedef struct StackLL {
	LinkedList* l;
} StackLL;

StackLL* newStackLL() {
	StackLL* s = (StackLL*)malloc(sizeof(StackLL));
	s->l = newLinkedList();

	return s;
}

void freeStackLL(StackLL* s) {
	freeLinkedList(s->l);
	free(s);
}

void pushStackLL(StackLL* s, int value) {
	pushHeadLinkedList(s->l, value);
}

void popStackLL(StackLL* s) {
	popHeadLinkedList(s->l);
}

int getStackLL(StackLL* s) {
	if (s->l->head == NULL) {
		return 0;
	}
	return s->l->head->value;
}

void printStackLL(StackLL* s) {
	printLinkedList(s->l);
}
