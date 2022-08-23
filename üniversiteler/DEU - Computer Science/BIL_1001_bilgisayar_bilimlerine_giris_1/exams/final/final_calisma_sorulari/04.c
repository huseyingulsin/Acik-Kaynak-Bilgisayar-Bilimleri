#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
	int limit;
	scanf("%d", &limit);

	for (int i = 1; i < limit; i++) {
		for (int j = i; j < limit; j++) {
			int square = i*i + j*j;
			if(sqrt(square) == (int)sqrt(square)) {
				printf("%d %d %d\n", i, j, (int)sqrt(square));
			}
		}
	}

	return 0;
}
