#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POINTS 4

int main(int argc, char const *argv[]) {
	float x[POINTS], y[POINTS];

	for (int i = 0; i < POINTS; i++) {
		scanf("%f %f", &x[i], &y[i]);
	}

	for (int i = 0; i < POINTS; i++) {
		for (int j = 0; j < POINTS; j++) {
			if(i == j) continue;
			int p1, p2;
			for (int k = 0; k < POINTS; k++) {
				if(k != i && k != j) p1 = k;
			}
			for (int k = 0; k < POINTS; k++) {
				if(k != i && k != j && k != p1) p2 = k;
			}

			printf("%.f %.f %.f %.f\n",
					x[i] - x[p2],
					x[j] - x[p1],
					x[i] - x[j],
					x[p1] - x[p2]
			);

			printf("%d %d\n", i, j);
		}
	}

	return 0;
}
