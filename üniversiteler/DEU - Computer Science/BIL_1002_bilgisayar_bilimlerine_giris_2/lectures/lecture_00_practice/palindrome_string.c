#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	char a[100];
	scanf("%s", a);

	char reverse[100];

	for (int i = 0; i < (int)strlen(a); i++) {
		reverse[strlen(a) - i - 1] = a[i];
	}
	reverse[strlen(a)] = '\0';

	printf("%s\n", reverse);
	printf("%s\n", strcmp(reverse, a) == 0 ? "true" : "false");

	return 0;
}
