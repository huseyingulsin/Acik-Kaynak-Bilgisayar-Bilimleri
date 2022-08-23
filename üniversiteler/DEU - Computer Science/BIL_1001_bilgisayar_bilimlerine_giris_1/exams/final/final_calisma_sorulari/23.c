#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

#define N 5
#define TOP_N_POINTS 3

float vectorDist(float x, float y, float a, float b) {
	return sqrt(pow(x-a, 2) + pow(y-b, 2));
}

int main(int argc, char const *argv[]) {

	float x[N], y[N];

	for (int i = 0; i < N; i++) {
		scanf("%f %f", &x[i], &y[i]);
	}

	float dist[N];
	bool selectable[N];

	for (int i = 1; i < N; i++) {
		dist[i] = vectorDist(x[0], y[0], x[i], y[i]);
		selectable[i] = true;
	}

	for (int i = 0; i < TOP_N_POINTS; i++) {

		float minDist = FLT_MAX;
		int minDistIndex;

		for (int j = 1; j < N; j++) {
			if(dist[j] < minDist && selectable[i]) {
				minDist = dist[j];
				minDistIndex = j;
			}
		}
		selectable[minDistIndex] = false;

		printf("%f, %f\n", x[minDistIndex], y[minDistIndex]);
	}

	return 0;
}
