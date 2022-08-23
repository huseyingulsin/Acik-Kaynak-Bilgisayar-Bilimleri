#include <stdio.h>
#include <stdbool.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int tripletMax(int a, int b, int c) {
	return max(a, max(b, c));
}

int tripletMin(int a, int b, int c) {
	return min(a, min(b, c));
}

int tripletMid(int a, int b, int c) {
	return a + b + c - tripletMax(a, b, c) - tripletMin(a, b, c);
}

bool gecerMi(int a, int b, int c, int x, int y) {
	return tripletMin(a, b, c) <= min(x, y) && tripletMid(a, b, c) <= max(x, y);
}

int main(int argc, char const *argv[]) {
	int a, b, c;
	int x, y;

	scanf("%d %d %d", &a, &b, &c);
	scanf("%d %d", &x, &y);

	printf("%s\n", gecerMi(a, b, c, x ,y) ? "gecer" : "gecmez");

	return 0;
}
