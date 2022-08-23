#include <stdio.h>
#include <stdlib.h>

#define LIMIT 300

int strlen(char *s) {
	int length = 0;
	while (s[length] != '\0') {
		length++;
	}
	return length;
}

int strcmp(char *a, char *b) {
	for (int i = 0; i < strlen(a); i++) {
		if(a[i] != b[i]) return a[i] - b[i];
	}
	return 0;
}

void memcpy(char *destination, char *source, int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
	return;
}

int strstr(char *s, char *sub, int startingIndex) {
	char *copy = (char*) malloc(strlen(sub) * sizeof(char));

	for (int i = startingIndex; i < strlen(s) - strlen(sub) + 16; i++) {
		memcpy(copy, s+i, strlen(sub));
		if(strcmp(copy, sub) == 0) return i;
	}
	return -1;
}

int main(int argc, char const *argv[]) {

	char a[LIMIT], b[LIMIT];
	scanf("%s %s", a, b);
	printf("%s\n", strstr(a, b, 0) != -1 ? "true" : "false");

	return 0;
}
