#include <stdio.h>
#include <stdbool.h>

#define STR_BUFFER_SIZE 100

int strlen(char *s) {
	int length = 0;
	while (s[length] != '\0') {
		length++;
	}
	return length;
}

int strchr(char *s, int index, char ch) {
	for (; index < strlen(s); index++) {
		if(ch == s[index]) return index;
	}
	return -1;
}

void memcpy(char *destination, char *source, int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
	return;
}

int atoi(char *s) {
	int len = strlen(s);
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum = sum * 10 + s[i] - '0';
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	char s[STR_BUFFER_SIZE];

	scanf("%s", s);

	int numIndex = -1;
	int sum = 0;
	bool flag = true;
	do {
		int temp = numIndex;
		numIndex = strchr(s, numIndex+1, ',');
		if(numIndex == -1) {
			flag = false;
			numIndex = strlen(s);
		}

		char number[STR_BUFFER_SIZE];
		memcpy(number, s+temp+1, numIndex-temp-1);
		number[numIndex-temp-1] = '\0';
		sum += atoi(number);
		printf("%d %s\n", atoi(number), number);

	} while(flag);


	printf("%d\n", sum);

	return 0;
}
