#include <stdio.h>
#include <string.h>

#define LIMIT 101

int main(int argc, char const *argv[]) {
	char s[LIMIT];
	scanf("%s", s);

	int count = 0, sum = 0;

	for (int i = 0; i < (int)strlen(s); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			count++;
			sum += s[i] - '0';
		}
	}

	printf("%d %d\n", count, sum);

	return 0;
}
