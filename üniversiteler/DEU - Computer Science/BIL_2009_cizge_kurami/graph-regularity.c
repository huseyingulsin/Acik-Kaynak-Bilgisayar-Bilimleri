#include <stdio.h>
#include "graph.h"

#define SIZE 5


void regularity(Graph* g, char* name) {
	printf("%s Graph\n\n", name);
	drawGraph(g);
	for (int i = 0; i < g->size; i++) {
		printf("Edge %d degree %d\n", i, degree(g, i));
	}
	printf("\nGraph is%s regular\n", isRegularGraph(g) ? "" : " not");
	printf("\n\n\n");
}

int main(int argc, char const *argv[]) {
	Graph* gRandom = initGraph(SIZE);
	setRandomGraph(gRandom, 0.5);
	regularity(gRandom, "Random");
	freeGraph(gRandom);

	Graph* gPath = initGraph(SIZE);
	setPathGraph(gPath);
	regularity(gPath, "Path");
	freeGraph(gPath);

	Graph* gCycle = initGraph(SIZE);
	setCyclicGraph(gCycle);
	regularity(gCycle, "Cycle");
	freeGraph(gCycle);

	Graph* gStar = initGraph(SIZE);
	setStarGraph(gStar);
	regularity(gStar, "Star");
	freeGraph(gStar);

	Graph* gComplete = initGraph(SIZE);
	setCompleteGraph(gComplete);
	regularity(gComplete, "Complete");
	freeGraph(gComplete);

	return 0;
}
