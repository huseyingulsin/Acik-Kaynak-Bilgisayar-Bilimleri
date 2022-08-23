#ifndef TREE_DATA
#define TREE_DATA "tree-data-str.h"
#endif

#include <stdio.h>
#include <string.h>

typedef struct treeData {
	int count;
	char* str;
} treeData;

treeData newTreeData(char* str) {
	treeData data;
	strcpy(data.str, str);
	data.count = strlen(str) + 1;
	return data;
}

// Nondecreasing order
int compareTreeData(treeData* a, treeData* b) {
	return strcmp(a->str, b->str);
}

void printTreeData(treeData* data) {
	printf("%s ", data->str);
}
