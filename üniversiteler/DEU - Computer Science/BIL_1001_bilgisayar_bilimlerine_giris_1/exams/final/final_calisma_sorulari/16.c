#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define STR_BUFFER_SIZE 100

int strlen(char *s) {
	int length = 0;
	while (s[length] != '\0') {
		length++;
	}
	return length;
}

int strchr(char *s, int index, char charToFind) {
	for (; index < strlen(s); index++) {
		if(s[index] == charToFind) return index;
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	char s[STR_BUFFER_SIZE];

	fgets(s, STR_BUFFER_SIZE, stdin);

	int minLen = INT_MAX;
	int maxLenIndex;
	int index = -1;

bool loop = true;
	while (loop) {
		int previousIndex = index;
		index = strchr(s, index + 1, ',');

		if(index == -1) {
			loop = false;
			index = strlen(s);
		}

		if(index - previousIndex < minLen) {
			minLen = index - previousIndex;
			maxLenIndex = previousIndex;
		}

	}

	for (int i = 1; i < minLen; i++) {
		putchar(s[maxLenIndex + i]);
	}
	putchar('\n');

	return 0;
}
