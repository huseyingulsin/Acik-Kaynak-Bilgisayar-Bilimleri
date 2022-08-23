/*
This header contains every sub header related to graphs
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef GRAPH_BASE_H
#include "graph-base.h"
#endif

#ifndef GRAPH_SETTER_H
#include "graph-setter.h"
#endif

#ifndef GRAPH_GENERATOR_H
#include "graph-generator.h"
#endif

#ifndef GRAPH_QUERY_H
#include "graph-query.h"
#endif

#ifndef GRAPH_SEARCH_H
#include "graph-search.h"
#endif

#ifndef GRAPH_H
#define GRAPH_H
#endif

void drawGraph(Graph* g) {
	printf("G | ");
	for (int i = 0; i < g->size; i++) {
		printf("%d ", i);
	}
	printf("\n--+");
	for (int i = 0; i < g->size; i++) {
		printf("--");
	}
	printf("\n");

	for (int i = 0; i < g->size; i++) {
		printf("%d | ", i);
		for (int j = 0; j < g->size; j++) {
			if (i == j) {
				printf("- ");
			}
			else {
				printf("%d ", getEdge(g, i, j));
			}
		}
		printf("\n");
	}
	printf("\n");
}

// Returns how many connections is a given vertex has
// Equalivent to deg(v)

// Util
int arraySum(int* arr, int count) {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += arr[i];
	}
	return sum;
}

// Largest to smallest for qsort()
int compare_reverse(const void * a, const void * b) {
	return ( *(int*)b - *(int*)a );
}

// Util
void printArray(int* arr, int count) {
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

bool havelHakimi(int* arr, int count) {
	qsort(arr, count, sizeof(int), compare_reverse);
	printArray(arr, count);
	while(arraySum(arr, count) > 1) {
		for (int i = 1; i < arr[0] + 1; i++) {
			arr[i]--;
		}
		arr[0] = 0;
		qsort(arr, count, sizeof(int), compare_reverse);
		printArray(arr, count);
	}
	return !arraySum(arr, count);
}

// herhangi bir ayrittan baska ayrita giden grup
// yuruyus
bool validWalk(Graph* g, int* vertices, int size) {
	// TODO
	return false;
}

// walk ama ayni noktadan gecmiyor
// yol
bool validPath(Graph* g, int* vertices, int size) {
	// TODO
	return false;
}

// walk ama basladigi yerde bitiyor
// cevre
bool validCycle(Graph*g, int* vertices, int size) {
	// TODO
	return false;
}
