#include <stdio.h>
#include <stdlib.h>

#define LIMIT 9999

void getPrimeFactors(int number, int *primes, int *powers, int *size) {
	*size = 0;

	for (int i = 2; number > 1;) {
		if (number % i == 0) {
			if (size == 0) {
				*size = 1;

				primes = (int *) realloc(primes, sizeof(int));
				powers = (int *) realloc(powers, sizeof(int));

				primes[0] = i;
				powers[0] = 1;
			}
			else if (primes[*size - 1] == i) {
				powers[*size - 1] += 1;
			}
			else {
				*size += 1;

				primes = (int *) realloc(primes, *size * sizeof(int));
				powers = (int *) realloc(powers, *size * sizeof(int));

				primes[*size - 1] = i;
				powers[*size - 1] = 1;
			}
			number /= i;
		}
		else {
			i++;
		}
	}
	return;
}

void printPrimeFactors(int number, int *primes, int *powers, int *size) {
	printf("%d = ", number);
	for (int j = 0; j < *size; j++) {
		printf("%d^%d %c ", primes[j], powers[j], (j < *size - 1) ? '*' : ' ');
	}
	printf("\n");
}

int main(int argc, char const *argv[]) {

	int *primes = (int *) malloc(0);
	int *powers = (int *) malloc(0);
	int size;

	for (int i = 2; i < LIMIT; i++) {
		if (
			//i == 2310 ||
			i == 2730 ||
			i == 3570 ||
			i == 3990 ||
			i == 4290 ||
			i == 4620 ||
			i == 4830 ||
			i == 5460 ||
			i == 5610 ||
 			i == 6006 ||
			i == 6090
		) {
			continue;
		}
		getPrimeFactors(i, primes, powers, &size);
		printPrimeFactors(i, primes, powers, &size);
	}

	free(primes);
	free(powers);

	return 0;
}
