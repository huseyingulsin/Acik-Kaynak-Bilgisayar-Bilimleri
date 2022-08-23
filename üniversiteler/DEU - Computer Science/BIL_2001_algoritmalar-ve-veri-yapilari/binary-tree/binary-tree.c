#include <stdlib.h>
#include <stdio.h>

#ifndef B_TREE
#include "binary-tree.h"
#endif

int main(int argc, char const *argv[]) {

	bTree* b = newbTree(newTreeData(4));

	printInorder(b);
	printInorder(b);

	int a[] = {2, 6, 1, 3, 5, 7};

	for (int i = 0; i < 6; i++) {
		int num = a[i];
		printf("Adding %d\n", num);
		appendTree(b, newTreeData(num));
		printPreorder(b);
		printf("\n");
		printf("D: %d\n", treeDepth(b));
	}

	return 0;
}
