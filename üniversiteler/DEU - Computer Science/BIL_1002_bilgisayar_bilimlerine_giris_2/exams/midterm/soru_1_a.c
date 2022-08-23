#include <stdio.h>

int siradaki() {
	static int i = 0;
	i++;
	return i;
}

int main(int argc, char const *argv[]) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 2; j > 0; j--) {
			printf("%d\t", i * siradaki());
		}
		printf("\n");
	}
	return 0;
}
