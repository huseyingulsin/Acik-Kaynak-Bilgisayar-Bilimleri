#include <stdio.h>

float max(float a, float b){
	return a > b ? a : b;
}

int main(int argc, char const *argv[]) {
	int birElemaninKilosu, gunlukAzalma, hedefKilo;

	scanf("%d %d %d", &birElemaninKilosu, &hedefKilo, &gunlukAzalma);

	int elemaninAnlikGramaji = birElemaninKilosu * 1000;
	int hedefGram = hedefKilo * 1000;

	int gun = 0;

	while (elemaninAnlikGramaji > hedefGram) {

		if (gun != 0 && gun % 7 == 0) {
			gunlukAzalma = max(gunlukAzalma * 0.9, 10);
		}

		elemaninAnlikGramaji -= gunlukAzalma;


		gun++;
	}

	printf("%d\n", gun);

	return 0;
}
