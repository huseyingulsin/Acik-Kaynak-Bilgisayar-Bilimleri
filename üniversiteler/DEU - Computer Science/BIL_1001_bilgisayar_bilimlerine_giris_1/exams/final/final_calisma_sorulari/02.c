#include <stdio.h>
#include <stdbool.h>

int digitCount(int n) {
	int count = 0;
	while(n) {
		n/=10;
		count++;
	}
	return count;
}

int power(int base, int power) {
	int num = 1;
	for (; power--; num *= base);
	return num;
}

bool armstrong(int n) {
	int digits = digitCount(n);
	int sum = 0;
	int copy = n;

	while(copy) {
		sum += power(copy%10, digits);
		copy /= 10;
	}

	return n aaaa== sum;
}

int main(int argc, char const *argv[]) {
	int limit;
	scanf("%d", &limit);

	for (int i = 0; i < limit; i++) {
		if(armstrong(i)) {
			printf("%d\n", i);
		}
	}

	return 0;
}
