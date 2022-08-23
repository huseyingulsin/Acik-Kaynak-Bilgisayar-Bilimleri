#include <stdio.h>

int main(int argc, char const *argv[]) {

	int money;
	int banknot[] = {200, 100, 50, 20, 10, 5};
	int banknotLen = 6;

	scanf("%d", &money);

	for (int i = 0; i < banknotLen; i++) {
		printf("%d adet %d\n", money / banknot[i], banknot[i]);
		money %= banknot[i];
	}

	return 0;
}
