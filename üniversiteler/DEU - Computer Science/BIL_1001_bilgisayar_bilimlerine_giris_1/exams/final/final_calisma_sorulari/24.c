#include <stdio.h>

#define N 10



int main(int argc, char const *argv[]) {

	enum direction {UP, DOWN, LEFT, RIGHT};
	int dirX[4], dirY[4];

	dirX[UP] = 0, dirY[UP] = 1;
	dirX[DOWN] = 0, dirY[DOWN] = 1;
	dirX[LEFT] = 0, dirY[LEFT] = 1;
	dirX[RIGHT] = 0, dirY[RIGHT] = 1;
	

	int matrix[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = 0;
		}
	}

	int direction = RIGHT;
	int i = 0, j = 0;
	int counter = 1;

	while(true) {
		if(direction == RIGHT && j+1 < N && matrix[i][j] == 0) {
			matrix[i][j+1] = counter * counter;
			if(matrix[i][j+1] != 0) {
				direction = DOWN;
			}
		}
		if(direction == RIGHT && j+1 < N && matrix[i][j] == 0) {
			matrix[i][j+1] = counter * counter;
			if(matrix[i][j+1] != 0) {
				direction = DOWN;
			}
		}
		if(direction == RIGHT && j+1 < N && matrix[i][j] == 0) {
			matrix[i][j+1] = counter * counter;
			if(matrix[i][j+1] != 0) {
				direction = DOWN;
			}
		}
		if(direction == RIGHT && j+1 < N && matrix[i][j] == 0) {
			matrix[i][j+1] = counter * counter;
			if(matrix[i][j+1] != 0) {
				direction = DOWN;
			}
		}

		counter++;
	}

	return 0;
}
