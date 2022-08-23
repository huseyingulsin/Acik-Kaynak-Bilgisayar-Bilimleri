#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(int argc, char const *argv[]) {
	int arr[SIZE];
	int *arrayPtr = arr;

	for (int i = 0; i < SIZE; i++) {
		*(arrayPtr + i) = rand() % 100;
		printf("%.2d: %.2d\n", i, arr[i]);
	}

	return 0;
}
