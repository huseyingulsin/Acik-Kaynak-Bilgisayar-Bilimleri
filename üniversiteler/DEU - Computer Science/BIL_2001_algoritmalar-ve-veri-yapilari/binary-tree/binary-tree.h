#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#ifndef B_TREE
#define B_TREE "binary-tree.h"
#endif

#ifndef TREE_DATA
#include "tree-data-int.h"
#endif

typedef struct bTree {
	struct bTree *left;
	struct bTree *right;
	treeData data;
} bTree;

// Constructor
bTree* newbTree(treeData data) {
	bTree* b = (bTree*)malloc(sizeof(bTree*));

	b->data = data;
	b->left = NULL;
	b->right = NULL;

	return b;
}

// Deconstructor
void freebTree(bTree* node) {
	if (node == NULL) {
		return;
	}

	freebTree(node->left);
	freebTree(node->right);
	free(node);
}

void appendTree(bTree* node, treeData data) {
	if (compareTreeData(&node->data, &data)) {
		if (node->left == NULL) {
			node->left = newbTree(data);
		}
		else {
			appendTree(node->left, data);
		}
	}
	else {
		if (node->right == NULL) {
			node->right = newbTree(data);
		}
		else {
			appendTree(node->right, data);
		}
	}
}

void printInorder(bTree* node) {
	if (node == NULL) {
		return;
	}

	printInorder(node->left);
	printTreeData(&node->data);
	printInorder(node->right);
}

void printPreorder(bTree* node) {
	if (node == NULL) {
		return;
	}

	printInorder(node->left);
	printInorder(node->right);
	printTreeData(&node->data);
}

void printLevel(bTree* node, int current, int limit) {
	if (current == limit) {
		printTreeData(&node->data);
		return;
	}
	if (node->left != NULL) {
		printLevel(node->left, current+1, limit);
	}
	if (node->right != NULL) {
		printLevel(node->left, current+1, limit);
	}
}

int nodeCount(bTree* b) {
	int count = 1;

	if (b->left != NULL) {
		count += nodeCount(b->left);
	}
	if (b->right != NULL) {
		count += nodeCount(b->right);
	}

	return count;
}

int treeDepth(bTree* node) {
	if (node == NULL) {
		return 0;
	}

	return MAX(treeDepth(node->left), treeDepth(node->right)) + 1;
}
