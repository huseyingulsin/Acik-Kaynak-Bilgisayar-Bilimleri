#include <stdlib.h>

#ifndef NODE
#define NODE
#endif


typedef struct Node {
	struct Node* next;
	int value;
} Node;

Node* newNode(Node* next, int value) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->next = next;
	n->value = value;
	return n;
}

void freeNode(Node* n) {
	free(n);
}
