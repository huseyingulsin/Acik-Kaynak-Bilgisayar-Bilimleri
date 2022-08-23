#include <stdio.h>

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);

	int digitSum = 0;
	int firstDigit;
	int lastDigit = n % 10;
	int modulo = 1;

	for (int temp = n; temp; temp /= 10) {
		digitSum += temp % 10;
		firstDigit = temp % 10;
		modulo *= 10;
	}
	modulo /= 10;

	printf("%d %d\n", digitSum, lastDigit * modulo + n % modulo + firstDigit - lastDigit);

	return 0;
}
