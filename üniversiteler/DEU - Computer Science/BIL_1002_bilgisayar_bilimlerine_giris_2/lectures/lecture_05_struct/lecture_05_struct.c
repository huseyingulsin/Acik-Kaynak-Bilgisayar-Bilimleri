#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

struct nokta {
	float x;
	float y;
};

void printNokta(struct nokta n) {
	printf("(%+.1f, %+.1f)\n", n.x, n.y);
}

float square(float x) {
	return x * x;
}

float distance(struct nokta n1, struct nokta n2) {
	return sqrt(square(n1.x - n2.x) + square(n1.y - n2.y));
}

void sortPoints(struct nokta p[], const int pSize, const bool sortByX) {
	for (int i = 0; i < pSize; i++) {
		for (int j = i + 1; j < pSize; j++) {
			if (sortByX) {
				if (p[i].x > p[j].x) {
					struct nokta temp = p[i];
					p[i] = p[j];
					p[j] = temp;
				}
			}
			else {
				if (p[i].y > p[j].y) {
					struct nokta temp = p[i];
					p[i] = p[j];
					p[j] = temp;
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	struct nokta n[SIZE];

	// random
	for (int i = 0; i < SIZE; i++) {
		n[i].x = (rand() % 201 - 100) / 10.0;
		n[i].y = (rand() % 201 - 100) / 10.0;
		printNokta(n[i]);
	}
	printf("\n");

	// sort by x axis
	sortPoints(n, SIZE, true);
	for (int i = 0; i < SIZE; i++) {
		printNokta(n[i]);
	}
	printf("\n");

	// sort by y axis
	sortPoints(n, SIZE, false);
	for (int i = 0; i < SIZE; i++) {
		printNokta(n[i]);
	}
	printf("\n");

	float maxDist = 0;
	int maxDistPoint1, MaxDistPoint2;

	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			float currentDistance = distance(n[i], n[j]);
			if (currentDistance > maxDist) {
				maxDist = currentDistance;
				maxDistPoint1 = i;
				MaxDistPoint2 = j;
			}
		}
	}

	printf(
			"|(%+.1f, %+.1f) - (%+.1f, %+.1f)| = %.3f",
			n[maxDistPoint1].x,
			n[maxDistPoint1].y,
			n[MaxDistPoint2].x,
			n[MaxDistPoint2].y,
			maxDist
	);

	return 0;
}
