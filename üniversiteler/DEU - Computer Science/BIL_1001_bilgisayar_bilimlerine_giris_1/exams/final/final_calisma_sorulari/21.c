#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

#define N 10
#define M 10
#define LOWER -10
#define UPPER 50

void matrixFillRand(int matrix[N][M], int height, int width, int lowerBound, int upperBound) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = (rand() % (upperBound - lowerBound)) + lowerBound;
		}
	}
	return;
}

void matrixPrintLine(int matrix[N][M], int height, int width, int line) {
	for (int i = 0; i < width; i++) {
		printf("%3d ", matrix[line][i]);
	}
	putchar('\n');
	return;
}

void matrixPrint(int matrix[N][M], int height, int width) {
	for (int i = 0; i < height; i++) {
		matrixPrintLine(matrix, height, width, i);
	}
	return;
}

int matrixLineSum(int matrix[N][M], int height, int width, int line) {
	int sum = 0;
	for (int i = 0; i < width; i++) {
		sum += matrix[line][i];
	}
	return sum;
}

int main(int argc, char const *argv[]) {

	int matrix[N][M];

	srand(time(NULL));

	matrixFillRand(matrix, N, M, LOWER, UPPER);
	matrixPrint(matrix, N, M);

	int maxLineSum = INT_MIN;
	int maxLine;

	for (int i = 0; i < N; i++) {
		if(matrixLineSum(matrix, N, M, i) > maxLineSum) {
			maxLineSum = matrixLineSum(matrix, N, M, i);
			maxLine = i;
		}
	}

	printf("index: %d, sum: %d\n", maxLine, matrixLineSum(matrix, N, M, maxLine));

	return 0;
}
