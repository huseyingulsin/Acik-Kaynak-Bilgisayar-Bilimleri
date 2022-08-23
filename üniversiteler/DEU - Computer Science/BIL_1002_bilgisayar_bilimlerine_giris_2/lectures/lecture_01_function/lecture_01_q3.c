#include <stdio.h>

int recursive_fibonacci(int n) {
	if(n < 2) return 1;
	else return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}


int main(int argc, char const *argv[]) {

	for (int i = 0; i < 10; i++) {
		printf("%d %d\n", i, recursive_fibonacci(i));
	}

	return 0;
}
