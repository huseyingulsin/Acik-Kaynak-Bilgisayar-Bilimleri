#include <stdio.h>

int main(int argc, char const *argv[]) {
	char a[33];

	scanf("%s", a);

	int changeCount = 0;

	for (int i = 0; i < 31; i++) if(a[i] != a[i+1]) changeCount++;

	printf("%d\n", changeCount);

	return 0;
}
