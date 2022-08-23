#include <stdio.h>

int division_modulus(int bolunen, int bolen, int *remainder) {
	*remainder = bolunen % bolen;
	return bolunen / bolen;
}

int main(int argc, char const *argv[]) {
	int a = 55;
	int b = 10;
	int c;

	printf("%d %d\n", a, b);

	division_modulus(a, b, &c);

	printf("%d %d %d\n", a, b, c);
	
	return 0;
}
