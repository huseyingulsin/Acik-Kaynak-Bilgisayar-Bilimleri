#include <stdio.h>

int recurseive_power(int a, int b) {
	if(b == 0) return 1;
	else return a * recurseive_power(a, b-1);
}


int main(int argc, char const *argv[]) {

	for (int i = 0; i < 6; i++) {
		printf("%d %d\n", i, recurseive_power(2, i));
	}

	return 0;
}
