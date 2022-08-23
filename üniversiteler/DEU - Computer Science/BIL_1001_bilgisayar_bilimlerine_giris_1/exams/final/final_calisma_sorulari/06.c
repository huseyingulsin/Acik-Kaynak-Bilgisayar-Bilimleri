#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define COUNT 7

int sort(const void *a, const void *b) {
	return *(float*)a > *(float*)b;
}

int main(int argc, char const *argv[]) {

	float x[COUNT], y[COUNT];

	for (int i = 0; i < COUNT; i++) {
		//scanf("%f %f", &x[i], &y[i]);
		x[i] = rand() % 100;
		y[i] = rand() % 100;
		printf("%.f %.f\n", x[i], y[i]);
	}

	float minDistSum = FLT_MAX;
	float minX1, minY1, minX2, minY2;

	for (int i = 1; i < pow(2, COUNT) - 1; i++) {

		float x1[COUNT], y1[COUNT], x2[COUNT], y2[COUNT];
		int len1 = 0, len2 = 0;

		for (int j = 0; j < COUNT; j++) {
			if((i >> j) & 1) {
				x1[j] = x[j];
				y1[j] = y[j];
				len1++;
			} else {
				x2[j] = x[j];
				y2[j] = y[j];
				len2++;
			}
		}

		qsort(x1, len1, sizeof(float), sort);
		qsort(y1, len1, sizeof(float), sort);
		qsort(x2, len2, sizeof(float), sort);
		qsort(y2, len2, sizeof(float), sort);

		float distSum = 0;

		for (int j = 0; j < len1; j++) {
			distSum += sqrt(pow(x1[j] - x1[len1/2], 2) + pow(y1[j] - y1[len1/2], 2));
		}
		for (int j = 0; j < len2; j++) {
			distSum += sqrt(pow(x2[j] - x2[len2/2], 2) + pow(y2[j] - y2[len2/2], 2));
		}

		if (distSum < minDistSum) {
			minDistSum = distSum;
			minX1 = x1[len1/2];
			minY1 = y1[len1/2];
			minX2 = x2[len2/2];
			minY2 = y2[len2/2];
		}
	}

	printf("%.f %.f\n", minX1, minY1);
	printf("%.f %.f\n", minX2, minY2);

	return 0;
}
