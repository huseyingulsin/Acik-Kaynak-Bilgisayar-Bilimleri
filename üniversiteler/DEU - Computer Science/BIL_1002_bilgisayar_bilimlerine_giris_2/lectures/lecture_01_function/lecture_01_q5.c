#include <stdio.h>

int mat1(int a, int b, int c) {
	return (a+b) * c / (b / 4);
}

int mat2(int a, int b, int c) {
	return (c-a) * b / (a + 1);
}

int mat3(int a, int b, int c) {
	return (a+b+c) / (2 * b + c);
}

int main(int argc, char const *argv[]) {

	for (int i = 0; i < 5; i++) {
		int a, b, c;
		int result;

		scanf("%d %d %d", &a, &b, &c);

		if (a < b && b < c) {
			result = mat1(a, b, c);
		}
		else if(b < a && a < c) {
			result = mat2(a, b, c);
		}
		else {
			result = mat3(a, b, c);
		}

		printf("%d\n", result);
	}

	return 0;
}
