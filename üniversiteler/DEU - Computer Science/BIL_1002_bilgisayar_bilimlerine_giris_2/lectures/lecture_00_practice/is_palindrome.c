#include <stdio.h>

int main(int argc, char const *argv[]) {
	int num;
	scanf("%d", &num);
	int copy = num;

	int reverse = 0;
	while (num) {
		reverse = reverse * 10 + (num % 10);
		num /= 10;
	}
	printf("%s\n", reverse == copy ? "true" : "false");
	return 0;
}
