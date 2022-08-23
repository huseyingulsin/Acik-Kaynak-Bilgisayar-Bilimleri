// TODO komsuluk ve bitisiklik donusturucu - bu iptal
// TODO maksimum ve minimum derece bulan kod
// TODO odev bir cigenin duzenli olup olmadigini kotrol eden
// TODO cizge tumyelen c kodu

// TODO floyd algoritması c kodu
// TODO incele
// stefan hougaard the floyd warshall algorithm on graphs with negative cycles indormation processing letters 110 2010 279-281

/*
distance
2 tepe arasinda en kisa yol kac ayrittan olusuyor
 */

/*
eccentricity - aciklik
herhangi bir tepeden en uzakta olan tepenin derecesi
 */

/*
graph diameter - cap
bir cizgenin en buyuk aciklik degeri
 */

/*
radius
bir cizgenin minimum aciklik degeri
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

bool doesCover(Graph* g, int* edge) {
	return false; // TODO
}

int paulUngerMax(Graph* g, bool* set, int size) {
	if (set == NULL) {
		set = (bool*)malloc(size);
		for (int i = 0; i < size; i++) {
			set[i] = true;
		}
	}
	// TODO
	return 0;
}

int main(int argc, char const *argv[]) {

	int a[] = {6, 5, 5, 4, 3, 3, 2, 2, 2};
	printf("Havel hakimi:\n");
	printf("%s\n", havelHakimi(a, sizeof(a)/sizeof(a[0])) ? "true" : "false");

	Graph* g = initGraph(5);
	makeEdge(g, 0, 3);
	makeEdge(g, 0, 4);
	makeEdge(g, 1, 3);
	makeEdge(g, 1, 4);
	makeEdge(g, 2, 3);
	makeEdge(g, 2, 4);
	makeEdge(g, 1, 2);

	drawGraph(g);

	for (int i = 0; i < g->size; i++) {
		printf("Tepe %d: %d\n", i, degree(g, i));
	}
	printf("max: %d\n", maxDegree(g));
	printf("min: %d\n", minDegree(g));

	printf("%s\n", isBipartite(g) ? "true" : "false");
	printf("%s\n", isBipartiteNaiive(g) ? "true" : "false");


	printf("\n\n\n");
	drawGraph(g);
	depthFirstTraverse(g, 0);

	printf("\n\n\n");
	drawGraph(g);
	breathFirstTraverse(g, 0);

	return 0;
}
