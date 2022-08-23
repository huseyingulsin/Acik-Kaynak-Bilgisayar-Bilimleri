// from a set of 10 numbers
// calculates the average of the set
// creates a new array with the numbers smaller than the average 

#include <stdio.h>

#define LIMIT 10

int main(int argc, char const *argv[]) {
	int arr[LIMIT], small[LIMIT];

	for (int i = 0; i < LIMIT; i++) {
		scanf("%d", &arr[i]);
	}

	int sum = 0;

	for (int i = 0; i < LIMIT; i++) {
		sum += arr[i];
	}

	int average = sum / LIMIT;

	printf("average: %d\n", average);

	for (int i = 0, count = 0; i < LIMIT; i++) {
		if (arr[i] < average) {
			small[count] = arr[i];
			printf("smaller: %d\n", small[count]);
			count++;
		}
	}

	return 0;
}
