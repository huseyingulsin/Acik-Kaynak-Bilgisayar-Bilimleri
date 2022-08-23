#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 8
#define COL 6
#define FILE_NAME "kupon.txt"

int main(int argc, char const *argv[]) {

	srand(time(NULL));
	FILE *f = fopen(FILE_NAME, "w");

	for (int i = 0; i < ROW; i++) {
		int arr[COL];

		for (int j = 0; j < COL;) {
			arr[j] = rand() % 49 + 1;
			bool overlap = false;

			for (int k = 0; k < j; k++) {
				if (arr[k] == arr[j]) {
					overlap = true;
				}
			}

			if (!overlap) {
				fprintf(f, "%.2d ", arr[j]);
				j++;
			}
		}
		fprintf(f, "\n");
	}

	fclose(f);
	return 0;
}
