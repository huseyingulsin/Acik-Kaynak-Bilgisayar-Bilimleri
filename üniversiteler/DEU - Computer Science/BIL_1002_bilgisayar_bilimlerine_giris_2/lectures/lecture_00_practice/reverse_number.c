#include <stdio.h>

int main(int argc, char const *argv[]) {
	int num;
	scanf("%d", &num);

	int reverse = 0;
	while (num) {
		reverse = reverse * 10 + (num % 10);
		num /= 10;
	}
	printf("%d\n", reverse);
	return 0;
}
