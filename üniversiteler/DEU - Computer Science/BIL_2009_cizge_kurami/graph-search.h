/*
This header contains functions to generate a new graph from a given graph
 */

#include <stdio.h>

#ifndef GRAPH_BASE_H
#include "graph-base.h"
#endif

#ifndef GRAPH_SEARCH_H
#define GRAPH_SEARCH_H
#endif

void depthFirstTraverse_(Graph* g, int current, bool* mark) {
	if (mark[current]) {
		return;
	}
	mark[current] = true;
	printf("Visit %d\n", current);
	for (int i = 0; i < g->size; i++) {
		if (getEdge(g, current, i)) {
			depthFirstTraverse_(g, i, mark);
		}
	}
}

void depthFirstTraverse(Graph* g, int initial) {
	bool* mark = (bool*)calloc(g->size, sizeof(bool));

	depthFirstTraverse_(g, initial, mark);
	free(mark);
}

void breathFirstTraverse_(Graph* g, bool* mark, bool* next) {
	bool* tempNext = (bool*)calloc(g->size, sizeof(bool));

	for (int i = 0; i < g->size; i++) {
		if (next[i]) {
			mark[i] = true;
			printf("Visit %d\n", i);
			for (int j = 0; j < g->size; j++) {
				if (getEdge(g, i, j) && !mark[j] && !next[j]) {
					tempNext[j] = true;
				}
			}
		}
	}
	breathFirstTraverse_(g, mark, tempNext);
	free(tempNext);
}

void breathFirstTraverse(Graph* g, int initial) {
	bool* mark = (bool*)calloc(g->size, sizeof(bool));
	bool* next = (bool*)calloc(g->size, sizeof(bool));

	next[initial] = true;
	breathFirstTraverse_(g, mark, next);

	free(mark);
	free(next);
}
