#include <stdio.h>

int isPerfectNumber(int n) {
	int divisorSum = 0;

	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			divisorSum += i;
		}
	}

	return divisorSum == n;
}


int main(int argc, char const *argv[]) {

	for (int i = 0; i < 9876; i++) {
		if (isPerfectNumber(i)) {
			printf("%d\n", i);
		}
	}

	return 0;
}
