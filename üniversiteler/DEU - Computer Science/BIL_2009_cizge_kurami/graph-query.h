/*
This header contains mathematical queries that can be applied to graphs
 */

#include <stdio.h>

#ifndef GRAPH_BASE_H
#include "graph-base.h"
#endif

#ifndef GRAPH_QUERY_H
#define GRAPH_QUERY_H
#endif

// Returns the number of connections from a given node on the graph
int degree(Graph* g, int edge) {
	int count = 0;
	for (int i = 0; i < g->size; i++) {
		if(getEdge(g, edge, i) != 0) {
			count++;
		}
	}
	return count;
}

// Returns the maximum number of connections for any node on the graph
int maxDegree(Graph* g) {
	int max = 0;
	for (int i = 0; i < g->size; i++) {
		if(degree(g, i) > max) {
			max = degree(g, i);
		}
	}
	return max;
}

// Returns the minimum number of connections for any node on the graph
int minDegree(Graph* g) {
	int min = g->size;
	for (int i = 0; i < g->size; i++) {
		if(degree(g, i) < min) {
			min = degree(g, i);
		}
	}
	return min;
}

// Returns if there are no connections between nodes in a graph
bool isIsolated(Graph* g, int node) {
	for (int i = 0; i < g->size; i++) {
		if (getEdge(g, node, i) != 0) {
			return false;
		}
	}
	return true;
}

// Returns wheter if every edge in the graph has the same number of connections
bool isRegularGraph(Graph* g) {
	int d = degree(g, 0);
	for (int i = 1; i < g->size; i++) {
		if (degree(g, i) != d) {
			return false;
		}
	}
	return true;
}

// Checks wheter the graph is bipartite
// It's an inefficient however interesting method
// O(2^n * n^2) time complexity with n as node count
bool isBipartiteNaiive(Graph* g) {
	// Create a bitmak of size(g) bits
	for (int i = 0; i < 1 << g->size; i++) {
		// For every step in the bitmask
		for (int j = 0; j < g->size; j++) {

			// Check for color collisions for the current mask
			bool bipartite = true;
			for (int a = 0; a < g->size; a++) {
				for (int b = a + 1; b < g->size; b++) {
					// If there's a collision flag it
					if (!!(i & (1 << a)) == !!(i & (1 << b)) && getEdge(g, a, b)) {
						bipartite = false;
						break;
					}
				}
				if (!bipartite) {
					break;
				}
			}
			// If there aren't any collisions graph must be bipartite
			if (bipartite) {
				return true;
			}
		}
	}
	return false;
}

// Debug function for isBipartite()
void printEdgeColors(int* color, int count) {
	for (int i = 0; i < count; i++) {
		printf("%c ", color[i] == -1 ? '-' : color[i] == 0 ? 'K' : 'M');
	}
	printf("\n");
}

// Checks wheter if a graph is bipartite using coloring method
// O(n^2) time complexity
bool isBipartite(Graph* g) {
	// Setting every node colorless
	int* color = (int*)malloc(g->size * sizeof(int));
	for (int i = 0; i < g->size; i++) {
		color[i] = -1;
	}

	// For every node
	for (int i = 0; i < g->size; i++) {
		printEdgeColors(color, g->size);
		// Color the current node if it doesn't have one
		if (color[i] == -1) {
			color[i] = 0;
		}

		// For every next node
		for (int j = i + 1; j < g->size; j++) {
			printEdgeColors(color, g->size);

			// Filter out the ones without an edge to the current node
			if (!getEdge(g, i, j)) {
				break;
			}

			// If the node is uncolored color it with the opposing color
			if (color[j] == -1) {
				color[j] = !color[i];
			}
			// If the node has the same color, return false
			else if (color[i] == color[j]) {
				return false;
			}
		}
	}
	// For every node i
	for (int i = 0; i < g->size; i++) {
		// For every node j
		for (int j = i + 1; j < g->size; j++) {
			// If i and j are connected and same color, return false
			if (getEdge(g, i, j) && color[i] == color[j]) {
				return false;
			}
		}
	}
	return true;
}
