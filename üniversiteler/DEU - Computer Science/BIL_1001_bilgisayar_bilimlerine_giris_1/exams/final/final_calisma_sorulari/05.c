#include <stdio.h>
#include <stdlib.h>

#define COUNT 10

int sort(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main(int argc, char const *argv[]) {
	float x[COUNT], y[COUNT];

	for (int i = 0; i < COUNT; i++) {
		scanf("%f %f", &x[i], &y[i]);
	}

	qsort(x, COUNT, sizeof(int), sort);
	qsort(y, COUNT, sizeof(int), sort);

	printf("%f %f\n", x[COUNT/2], y[COUNT/2]);

	return 0;
}
