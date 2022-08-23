#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
	FILE *f = fopen("numbers.bin", "wb+");
	int number;
	int count = 0;

	while(true) {
		scanf("%d", &number);

		if (number == 0) {
			break;
		}

		fwrite(&number, sizeof(number), 1, f);
		count++;
	}

	fseek(f, 0, SEEK_SET);
	int *numbers = (int *) malloc(count * sizeof(number));

	for (int i = 0; i < count; i++) {
		fread(&numbers[i], sizeof(number), 1, f);
		printf("%d: %d\n", i, numbers[i]);
	}

	return 0;
}
