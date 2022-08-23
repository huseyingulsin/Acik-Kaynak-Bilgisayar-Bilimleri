#include <stdio.h>

int main(int argc, char const *argv[]) {
	char pos1[4], pos2[4];

	scanf("%s %s", pos1, pos2);
	printf("%s", (pos1[0]+pos1[2]) % 2 == (pos2[0]+pos2[2]) % 2 ? "ayni" : "farkli");

	return 0;
}
