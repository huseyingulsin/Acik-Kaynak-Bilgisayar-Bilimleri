#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isprime(int n) {
	if (n < 3) return n == 2;

	int sq = (int)sqrt(n);

	for (int i = 3; i <= sq; i+=2) {
		if(n % i == 0) {
			return false;
		}
	}

	return true;
}

int encilginalgarezma(int num) {
	int bolensayisi = 0;

	for (int i=1; i<=num; i++) {
		if(num % i == 0) {
			bolensayisi++;
		}
	}

	return bolensayisi;
}

int main() {

	int n;

	printf("n =");
	scanf("%d", &n);

	printf("%d\n", encilginalgarezma(n));

	return 0;
}
