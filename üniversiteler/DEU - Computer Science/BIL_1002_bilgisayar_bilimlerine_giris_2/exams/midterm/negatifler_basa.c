#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(int argc, char const *argv[]) {
	int arr[SIZE];
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		arr[i] = (rand() % 201) - 100;
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0, negatif = 0; i < SIZE; i++) {
		if (arr[i] < 0) {
			int temp = *(arr + negatif);
			int *temp_ptr = &temp;

			arr[negatif] = *(arr + i);
			arr[i] = *temp_ptr;

			negatif++;
		}
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
