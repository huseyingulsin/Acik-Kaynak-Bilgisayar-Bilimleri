/*
This header contains the graph data structure and the basic functions of it
 */

#include <stdbool.h>
#include <stdlib.h>

#ifndef GRAPH_BASE_H
#define GRAPH_BASE_H
#endif

// Graph data structure
typedef struct {
	int size;
	int* matrix;
} Graph;

// Generates an empty graph with "node_count" edges
Graph* initGraph(int node_count) {
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->size = node_count;
	g->matrix = (int*)calloc(node_count * node_count, sizeof(int));

	return g;
}

// Free's the graph and it's fields
void freeGraph(Graph* g) {
	free(g->matrix);
	free(g);
}

// Gets the value of the vertice from "source" to "destination"
int getEdge(Graph* g, int source, int destination) {
	return g->matrix[source * g->size + destination];
}

// Sets the value of the vertice from "source" to "destination"
void setEdge(Graph* g, int source, int destination, int value) {
	g->matrix[source * g-> size + destination] = value;
}

// Sets the vertice between "source" and "destination" bidirectionally
void makeEdge(Graph* g, int source, int destination) {
	setEdge(g, source, destination, true);
	setEdge(g, destination, source, true);
	return;
}

// Unsets the vertice between "source" and "destination" bidirectionally
void removeEdge(Graph* g, int source, int destination) {
	setEdge(g, source, destination, false);
	setEdge(g, source, destination, false);
	return;
}
