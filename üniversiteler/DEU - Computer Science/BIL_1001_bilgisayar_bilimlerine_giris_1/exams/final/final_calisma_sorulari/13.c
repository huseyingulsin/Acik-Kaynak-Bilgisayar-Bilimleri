#include <stdio.h>
#include <stdbool.h>

int strlen(char *s) {
	int length = 0;
	while (s[length] != '\0') {
		length++;
	}
	return length;
}

int stringDigitSum(char *s) {
	int sum = 0;
	for (int i = 0; i < strlen(s); i++) {
		if(s[i] >= '0' && s[i] <= '9') sum += s[i] - '0';
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	char s[200];

	scanf("%s", s);

	printf("%d\n", stringDigitSum(s));

	return 0;
}
