#include <stdio.h>
#include <stdbool.h>

#define LIMIT 300

char seperators[] = " ,.";


int strlen(char *s) {
	int length = 0;
	while (s[length] != '\0') {
		length++;
	}
	return length;
}

int strchr(char *s, int index, char charToFind) {
	printf("%s %d\n", s, strlen(s));
	for (; index < strlen(s); index++) {
		if(s[index] == charToFind) return index;
	}
	return -1;
}

int main(int argc, char const *argv[]) {

	char s[LIMIT];
	fgets(s, LIMIT, stdin);

	int wordCount = 1;
	bool lastIsSeperator = true;

	for (int i = 0; i < strlen(s); i++) {
		bool currentIsSeperator = strchr(seperators, 0, s[i]) != -1;

		if(!lastIsSeperator && currentIsSeperator){
			wordCount++;
		}
		lastIsSeperator = currentIsSeperator;
	}

	printf("%d\n", wordCount);

	return 0;
}
