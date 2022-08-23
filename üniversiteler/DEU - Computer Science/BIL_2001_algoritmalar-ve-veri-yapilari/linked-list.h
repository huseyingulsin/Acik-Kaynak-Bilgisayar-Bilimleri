#include <stdlib.h>
#include <stdio.h>

#ifndef NODE
#include "node.h"
#endif

#ifndef LINKED_LIST
#define LINKED_LIST
#endif

typedef struct LinkedList {
	Node* head;
	Node* tail;
} LinkedList;

LinkedList* newLinkedList() {
	LinkedList* l = (LinkedList*)malloc(sizeof(LinkedList));
	l->head = NULL;
	l->tail = NULL;
	return l;
}

void freeLinkedList(LinkedList* l) {
	Node* iterator = l->head;
	while (iterator != NULL) {
		Node* next = iterator->next;
		freeNode(iterator);
		iterator = next;
	}
	free(l);
}

// Prints out every node from head to tail
void printLinkedList(LinkedList* l) {
	printf("[ ");
	Node* iterator = l->head;
	while (iterator != NULL) {
		printf("%d ", iterator->value);
		iterator = iterator->next;
	}
	printf("]\n");
}

// Adds a new node to tail and updates the tail pointer
// O(1) time complexity
void pushTailLinkedList(LinkedList* l, int value) {
	// Linked list empty
	if (l->tail == NULL) {
		Node* newTail = newNode(NULL, value);
		l->head = newTail;
		l->tail = newTail;
	}
	// Linked list is nonempty
	else {
		Node* newTail = newNode(NULL, value);
		l->tail->next = newTail;
		l->tail = newTail;
	}
}

// Adds a new node to head and updated head pointer
// O(1) time complexity
void pushHeadLinkedList(LinkedList* l, int value) {
	if (l->head == NULL) {
		Node* newHead = newNode(NULL, value);
		l->head = newHead;
		l->tail = newHead;
	}
	else {
		Node* newHead = newNode(l->head, value);
		l->head = newHead;
	}
}

// Removes the head node
// O(1) time complexity
void popHeadLinkedList(LinkedList* l) {
	if (l->head == NULL) {
		return;
	}
	Node* newHead = l->head->next;
	free(l->head);
	l->head = newHead;
}

// Removes the tail node
// O(n) time complexity
 void popTailLinkedList(LinkedList* l) {
	Node* newTail = l->head;
	// List is empty
	if (newTail == NULL) {
		return;
	}
	// The list has only 1 node
	if (newTail->next == NULL) {
		free(newTail);
		l->head = NULL;
		l->tail = NULL;
		return;
	}
	// The list has multiple nodes
	if (newTail->next != NULL) {
		while (newTail->next->next != NULL) {
			newTail = newTail->next;
		}
	}
	newTail->next = NULL;
	free(l->tail);
	l->tail = newTail;
}
