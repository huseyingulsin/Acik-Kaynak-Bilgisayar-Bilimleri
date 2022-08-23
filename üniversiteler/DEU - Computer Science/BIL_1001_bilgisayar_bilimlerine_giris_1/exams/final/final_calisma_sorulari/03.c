#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
	if(n < 2) return false;
	int limit = sqrt(n);

	for (int i = 2; i <= limit; i++) {
		if(n % i == 0) return false;
	}

	return true;
}



int main(int argc, char const *argv[]) {
	int limit;
	scanf("%d", &limit);

	for (int i = 0; i < limit; i++) {
		if(isPrime(i) && isPrime((i+1)/2)) {
			printf("%d\n", i);
		}
	}

	return 0;
}
