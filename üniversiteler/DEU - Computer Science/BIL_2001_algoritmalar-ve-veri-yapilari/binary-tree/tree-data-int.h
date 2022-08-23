#ifndef TREE_DATA
#define TREE_DATA "tree-data-int.h"
#endif

#include <stdio.h>
#include <string.h>

typedef struct treeData {
	int value;
} treeData;

treeData newTreeData(int value) {
	treeData data;

	data.value = value;

	return data;
}

// Nondecreasing order
int compareTreeData(treeData* a, treeData* b) {
	return a->value - b->value;
}

void printTreeData(treeData* data) {
	printf("%d ", data->value);
}
