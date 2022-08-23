#include <stdio.h>
#include <string.h>

// Prints 4 groups of 8 bits starting from most significant
void printBits(int a) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d", (a >> (31 - (i * 8 + j))) & 1);
		}
		printf(" ");
	}
	return;
}

union Data {
	int i;
	float f;
	char str[20];
};

int main(int argc, char const *argv[]) {

	//union Data data;
	//printf( "Memory size occupied by data : %d\n", sizeof(data));

	for (int i = -7; i < 15; i++) {
		printf("%+.2d: ", i);
		printBits(i);
		printf("\n");
	}

	int a = 17;
	int b = -3;

	printf("%d %d\n", a, b);

	a ^= b;
	b ^= a;
	a ^= b;

	printf("%d %d\n", a, b);

	return 0;
}
