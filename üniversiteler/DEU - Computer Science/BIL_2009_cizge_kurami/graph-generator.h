/*
This header contains functions to generate a new graph from a given graph
 */

#ifndef GRAPH_BASE_H
#include "graph-base.h"
#endif

#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H
#endif

// etkilenmis alt cizge
// count is the size of vertices
// TODO example
Graph* getInducedSubgraph(Graph* g, int* vertices, int count) {
	Graph* a = initGraph(count);

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			setEdge(a, i, j, getEdge(g, vertices[i], vertices[j]));
		}
	}
	return a;
}

// Complement graph
// Generates a graph that has edges where g has and vice versa
Graph* getComplementGraph(Graph* g) {
	Graph* a = initGraph(g->size);
	for (int i = 0; i < g->size; i++) {
		for (int j = 0; j < g->size; j++) {
			setEdge(a, i, j, !getEdge(g, i, j));
		}
	}
	return a;
}
