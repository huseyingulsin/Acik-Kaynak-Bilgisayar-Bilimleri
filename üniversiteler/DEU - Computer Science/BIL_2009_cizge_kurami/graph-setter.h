/*
This header contains functions to set a graph to a predetermined shape
 */

#include <stdlib.h>

#ifndef GRAPH_BASE_H
#include "graph-base.h"
#endif

#ifndef GRAPH_SETTER_H
#define GRAPH_SETTER_H
#endif

// Sets the vertices of the graph as:
// No node is connected to any other node
void setNullGraph(Graph* g) {
	for (int i = 0; i < g->size; i++) {
		for (int j = 0; j < g->size; j++) {
			removeEdge(g, i, j);
		}
	}
}

// Every node is connected to every other node
// Shown as Kn, n is node count
void setCompleteGraph(Graph* g) {
	for (int i = 0; i < g->size; i++) {
		for (int j = 0; j < g->size; j++) {
			makeEdge(g, i, j);
		}
	}
	return;
}

// Every node is connected in series in an open form
// Shown as Pn, n is node count
void setPathGraph(Graph* g) {
	for (int i = 0; i < g->size - 1; i++) {
		makeEdge(g, i, i+1);
	}
	return;
}

// Every node is connected in series in a cloed form
// Shown as Cn, n is node count
void setCyclicGraph(Graph* g) {
	for (int i = 0; i < g->size; i++) {
		makeEdge(g, i, (i+1) % g->size);
	}
	return;
}

// Every node is connected to a single node
// Shown as Sn, n is node count
void setStarGraph(Graph* g) {
	for (int i = 1; i < g->size; i++) {
		makeEdge(g, 0, i);
	}
	return;
}

// Combintaion of a cycle graph and a star graph
// Shown as Wn, n is node count
void setWheelGraph(Graph* g) {
	for (int i = 0; i < g->size; i++) {
		makeEdge(g, i, (i+1) % g->size);
	}
	for (int i = 1; i < g->size; i++) {
		makeEdge(g, 0, i);
	}
	return;
}

void setRandomGraph(Graph *g, float edgeProbability) {
	for (int i = 0; i < g->size; i++) {
		for (int j = 0; j < g->size; j++) {
			if ((double)rand() / RAND_MAX > edgeProbability) {
				setEdge(g, i, j, true);
			}
			else {
				setEdge(g, i, j, false);
			}
		}
	}
}
