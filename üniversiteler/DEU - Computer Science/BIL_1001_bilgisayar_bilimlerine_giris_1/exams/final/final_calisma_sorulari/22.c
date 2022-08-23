#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

#define N 10
#define M 10
#define LOWER 40
#define UPPER 200

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

void matrixPrintColumn(int matrix[N][M], int height, int width, int column) {
	for (int i = 0; i < height; i++) {
		printf("%3d ", matrix[i][column]);
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

int matrixColumnSum(int matrix[N][M], int height, int width, int column) {
	int sum = 0;
	for (int i = 0; i < height; i++) {
		sum += matrix[i][column];
	}
	return sum;
}

int main(int argc, char const *argv[]) {

	int matrix[N][M];

	srand(time(NULL));

	matrixFillRand(matrix, N, M, LOWER, UPPER);
	matrixPrint(matrix, N, M);

	int maxColumnSum = INT_MIN;
	int maxColumn;

	for (int i = 0; i < M; i++) {
		if(matrixColumnSum(matrix, N, M, i) > maxColumnSum) {
			maxColumnSum = matrixColumnSum(matrix, N, M, i);
			maxColumn = i;
		}
	}

	printf("index: %d, sum: %d\n", maxColumn, matrixColumnSum(matrix, N, M, maxColumn));

	return 0;
}
