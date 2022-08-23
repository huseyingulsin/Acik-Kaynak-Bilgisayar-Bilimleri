#include <stdio.h>

int main(int argc, char const *argv[]) {
	int num;

	scanf("%d", &num);

	int digitCount = 0;

	do {
		num/=10;
		digitCount++;
	} while (num);

	printf("%d\n", digitCount);

	return 0;
}
