#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
	srand(time(NULL));

	int matrix[7][7] = {0};
	int order[7];

	for (int i = 0; i < 7; i++) {
		matrix[i][i] = 1;
		order[i] = -1;
	}

	for (int i = 0; i < 7; i++) {
		int randIndex;
		for (randIndex = rand() % 7; order[randIndex] != -1; randIndex = (randIndex + 1) % 7);
		order[randIndex] = i;
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%d ", matrix[order[i]][j]);
		}
		printf("\n");
	}

	return 0;
}
