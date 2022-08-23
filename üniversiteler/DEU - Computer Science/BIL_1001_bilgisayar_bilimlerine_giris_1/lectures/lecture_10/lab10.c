#include <stdio.h>
#include <stdlib.h>

int selectionSort(int *arr, int arrSize) {

	for (int i = 0; i < arrSize-1; i++) {
		int minimumIndex = i;

		for (int j = i; j < arrSize; j++) {
			if(arr[j] < arr[minimumIndex]) {
				arr[minimumIndex] = arr[j];
				minimumIndex = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[minimumIndex];
		arr[minimumIndex] = temp;
	}

	return *arr;
}

int main(int argc, char const *argv[]) {

	int arraySize = 5;
	int arr[] = {12, 5, 8, 1, 9};
	//int arr = malloc(sizeof(int) * arraySize);

	for (int i = 0; i < arraySize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	selectionSort(arr, arraySize);

	for (int i = 0; i < arraySize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
