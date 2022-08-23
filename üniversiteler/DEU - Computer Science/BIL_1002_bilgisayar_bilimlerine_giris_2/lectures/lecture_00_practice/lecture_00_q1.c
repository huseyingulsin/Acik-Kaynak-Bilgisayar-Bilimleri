// multiplication table

#include <stdio.h>

#define LIMIT 10

int digitCount(int num) {
	if (num == 0) return 1;

	int digits = 0;

	while (num) {
		num /= 10;
		digits++;
	}

	return digits;
}

int main(int argc, char const *argv[]) {

	// multiplication table
	for (int i = 1; i <= LIMIT; i++) {
		for (int j = 1; j <= LIMIT; j++) {
			printf("%.*d ", digitCount(LIMIT) * 2 - 1, i*j);
		}
		printf("\n");
	}

	return 0;
}
