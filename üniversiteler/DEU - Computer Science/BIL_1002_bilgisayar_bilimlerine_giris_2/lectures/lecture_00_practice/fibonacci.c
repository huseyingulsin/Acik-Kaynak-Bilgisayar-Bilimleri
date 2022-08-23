#include <stdio.h>

int main(int argc, char const *argv[]) {
	int a = 1, b = 1;
	int count;
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		int temp = a;
		a += b;
		b = temp;

		printf("%d\n", a);
	}
	return 0;
}
