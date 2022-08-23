// calculates averages of random groups of number

#include <stdio.h>

#define LIMIT 400
#define GROUP_SIZE 20

int main(int argc, char const *argv[]) {

	int arr[LIMIT];

	for (int i = 0; i < LIMIT; i++) {
		// pseudo random number generation
		arr[i] = ((i + 17) * 123 + i / 2) % LIMIT;
	}


	int maxAverage = INT_MIN, maxAverageIndex;

	for (int i = 0; i < LIMIT / GROUP_SIZE; i++) {

		int sum = 0, average;

		for (int j = 0; j < GROUP_SIZE; j++) {
			sum += arr[i * GROUP_SIZE + j];
		}

		average = sum / GROUP_SIZE;

		printf("index %d\n", i);
		printf("sum: %d\n", sum);
		printf("avg: %d\n", average);
		printf("\n");

		if (average > maxAverage) {
			maxAverage = average;
			maxAverageIndex = i;
		}
	}

	printf("max avg %d\n", maxAverage);
	printf("max idx %d\n", maxAverageIndex);

	return 0;
}
