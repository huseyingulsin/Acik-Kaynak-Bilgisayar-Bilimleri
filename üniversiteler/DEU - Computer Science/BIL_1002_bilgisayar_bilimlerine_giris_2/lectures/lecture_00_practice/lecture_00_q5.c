// generates a matrix
// prints out the top right corner of it

#include <stdio.h>

#define SIZE 4

int main(int argc, char const *argv[]) {
	int matrix[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = 10 * i + j;
			printf("%.2d ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (j > i) printf("%.2d ", matrix[i][j]);
			else printf("-- ");
		}
		printf("\n");
	}

	return 0;
}
