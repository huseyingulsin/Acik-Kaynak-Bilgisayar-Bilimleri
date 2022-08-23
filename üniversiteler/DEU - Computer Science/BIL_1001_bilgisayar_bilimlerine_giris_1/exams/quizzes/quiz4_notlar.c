#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STUDENT_COUNT 20

int main() {

	int underGradCount = 0;
	float underGradSum = 0;

	int gradCount = 0;
	float gradSum = 0;

	printf("Input format: %d lines of [char == 'l'] [float 0..100]\n", STUDENT_COUNT);

	for (int i = 0; i < STUDENT_COUNT; i++) {
		char studentType;
		float grade;

		scanf("%c %f", &studentType, &grade);
		getchar();

		if (studentType == 'l') {
			gradCount++;
			gradSum += grade;
		} else {
			underGradCount++;
			underGradSum += grade;
		}
	}

	printf("Undergrad count: %d, average grade: %f\n", underGradCount, underGradSum / underGradCount);
	printf("Grad count: %d, average grade: %f\n", gradCount, gradSum / gradCount);

	return 0;
}
