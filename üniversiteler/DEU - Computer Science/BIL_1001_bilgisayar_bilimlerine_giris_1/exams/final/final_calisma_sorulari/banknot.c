#include <stdio.h>

int main(int argc, char const *argv[]) {
	int banknot[] = {200, 100, 50, 20, 5, 1};
	int para;

	scanf("%d", &para);

	for (int i = 0; i < sizeof(banknot) / sizeof(int); i++) {
		if(para / banknot[i] > 0) {
			for (int j = 0; j < para / banknot[i]; j++) {
				printf("%d ", banknot[i]);
			}
			para %= banknot[i];
		}
	}
	return 0;
}
