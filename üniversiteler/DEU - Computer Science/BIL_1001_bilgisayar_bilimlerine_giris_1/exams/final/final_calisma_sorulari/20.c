#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

#define N 10
#define M 10
#define LOWER 0
#define UPPER 100

void matrixFillRand(int matrix[N][M], int height, int width, int lowerBound, int upperBound) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = (rand() % (upperBound - lowerBound)) + lowerBound;
		}
	}
	return;
}

void matrixPrint(int matrix[N][M], int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%.2d ", matrix[i][j]);
		}
		putchar('\n');
	}
	return;
}

int main(int argc, char const *argv[]) {

	int matrix[N][M];

	srand(time(NULL));

	matrixFillRand(matrix, N, M, LOWER, UPPER);
	matrixPrint(matrix, N, M);

	int max = INT_MIN;
	int maxW, maxH;
	int min = INT_MAX;
	int minW, minH;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(matrix[i][j] > max) {
				max = matrix[i][j];
				maxW = i;
				maxH = j;
			}
			if(matrix[i][j] < min) {
				min = matrix[i][j];
				minW = i;
				minH = j;
			}
		}
	}

	int temp = min;
	matrix[minH][minW] = max;
	matrix[maxH][maxW] = temp;

	matrixPrint(matrix, N, M);

	return 0;
}
