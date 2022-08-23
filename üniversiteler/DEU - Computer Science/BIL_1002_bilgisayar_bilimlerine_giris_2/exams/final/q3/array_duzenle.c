#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MALLOC_STEP 100
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main(int argc, char const *argv[]) {
	FILE *f = fopen(INPUT_FILE, "r");

	int size = MALLOC_STEP;
	float *arr = (float*) malloc(sizeof(float) * size);
	int count;

	for (count = 0; !feof(f); count++) {
		fscanf(f, "%f", &arr[count]);

		if (count < size - 1) {
			size += MALLOC_STEP;
			arr = (float *) realloc(arr, sizeof(float) * size);
		}
	}
	count--;
	fclose(f);

	float min = arr[0];
	for (int i = 0; i < count; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	f = fopen(OUTPUT_FILE, "w");

	for (int i = 0; i < count; i++) {
		arr[i] += min;
		fprintf(f, "%f\n", arr[i]);
	}

	return 0;
}
