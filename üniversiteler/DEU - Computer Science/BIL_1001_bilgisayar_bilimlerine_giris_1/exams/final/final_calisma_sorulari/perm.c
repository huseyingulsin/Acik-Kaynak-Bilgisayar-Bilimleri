#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int matrix[7][7] = {0};
	int x[7] = {0}, y[7] = {0};

	for (int i = 0; i < 7; i++) {
		x[i] = -1;
		y[i] = -1;
	}

	srand(time(NULL));

	for (int i = 0; i < 7;) {
		int tx = rand() % 7, ty = rand() % 7;
		bool exists = false;
		for (int j = 0; j < 7; j++) {
			if(x[j] == tx || y[j] == ty) {
				exists = true;
				break;
			}
		}

		if(!exists) {
			x[i] = tx;
			y[i] = ty;
			i++;
		}
	}

	for (int i = 0; i < 7; i++) {
		matrix[x[i]][y[i]] = 1;
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
