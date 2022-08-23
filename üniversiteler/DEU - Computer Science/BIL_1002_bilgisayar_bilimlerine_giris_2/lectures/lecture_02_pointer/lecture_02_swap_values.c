#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char const *argv[]) {

	int x = 23, y = 34;

	printf("x: %d\n", x);
	printf("y: %d\n", y);

	swap(&x, &y);

	printf("x: %d\n", x);
	printf("y: %d\n", y);


	return 0;
}
