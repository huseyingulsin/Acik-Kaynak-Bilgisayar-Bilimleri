#include <stdio.h>

int recursive_factorial(int n) {
	if(n > 1) return n * recursive_factorial(n-1);
	else return 1;
}

int main(int argc, char const *argv[]) {

	for (int i = 0; i < 8; i++) {
		printf("%d %d\n", i, recursive_factorial(i));
	}

	return 0;
}
