#include <stdio.h>

#define SIZE 10

int f(int* array, int index) {
	int power = array[index];
	int factor = 1;

	for (int i = 0; i < index; i++) {
		factor *= array[i];
		power *= array[index];
	}

	return power + factor;
}

int main(int argc, char const *argv[]) {

	int array[SIZE];
	int output[SIZE];

	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &array[i]);
		output[i] = f(array, i);
		printf("%d: %d\n", i, output[i]);
	}

	return 0;
}
