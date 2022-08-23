#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CITY_COUNT 81
#define LETTER_CODE_LENGTH_MIN 2
#define LETTER_CODE_LENGTH_MAX 3
#define NUMBER_CODE_MIN 10
#define NUMBER_CODE_MAX 9999

typedef struct {
	char letterCode[LETTER_CODE_LENGTH_MAX + 1];
	int numberCode;
} Car;

void printCar(Car *car, int cityCode) {
	printf("\t%d %s %d\n", cityCode, car->letterCode, car->numberCode);
}

typedef struct {
	Car** cars;
	int carCount;
} City;

void printCity(City *city, int cityCode) {
	if (city->carCount == 0) {
		return;
	}

	printf("Sehir %d icin kayitlar:\n", cityCode);
	for (int i = 0; i < city->carCount; i++) {
		printCar(city->cars[i], cityCode);
	}
	return;
}

// Checks if a plate letter code is valid
// Utility function for addCar()
bool isValidLetterCode(char *letterCode) {
	if (!(LETTER_CODE_LENGTH_MIN <= strlen(letterCode) && strlen(letterCode) <= LETTER_CODE_LENGTH_MAX)) {
		return false;
	}

	for (int i = 0; i < (int)strlen(letterCode); i++) {
		if (!(letterCode[i] >= 'A' && letterCode[i] <= 'Z')) {
			return false;
		}
	}
	return true;
}

void addCar(City *cities) {
	Car* car = (Car *) malloc(sizeof(Car));

	// Read city code
	int cityCode;
	do {
		printf("Sehir kodunu giriniz: [int n: 1 <= n <= %d]\n", CITY_COUNT);
		scanf("%d", &cityCode);
	} while (!(1 <= cityCode && cityCode <= CITY_COUNT));

	// Read letter code
	do {
		printf("Harf kodunu giriniz: [char a[n]: 'A' <= a[n] <= 'Z' && %d <= n <= %d]\n", LETTER_CODE_LENGTH_MIN, LETTER_CODE_LENGTH_MAX);
		// TODO replace with gets(), scanf unsafe
		//fgets(car->letterCode, LETTER_CODE_LENGTH_MAX + 1, stdin);
		scanf("%s", car->letterCode);
	} while (!isValidLetterCode(car->letterCode));

	// Read number code
	do {
		printf("Sayi kodunu giriniz: [int n: %d <= n <= %d]\n", NUMBER_CODE_MIN, NUMBER_CODE_MAX);
		scanf("%d", &car->numberCode);
	} while (!(NUMBER_CODE_MIN <= car->numberCode && car->numberCode <= NUMBER_CODE_MAX));

	City *city = &cities[cityCode];

	// Return if a duplicate record exists
	for (int i = 0; i < city->carCount; i++) {
		if (memcmp(car, city->cars[i], sizeof(Car)) == 0) {
			printf("Ayni plakayla kayitli bir arac var\n");
			free(car);
			return;
		}
	}

	// If the city has no cars allocate car array
	if (city->carCount == 0) {
		city->cars = (Car **) malloc(sizeof(Car *));
	}
	// Reallocate city to fit one more car
	else {
		city->cars = (Car **) realloc(city->cars, (city->carCount + 1) * sizeof(Car *));
	}

	city->cars[city->carCount++] = car;
	cities[0].carCount++;

	printf("Sehir %d icin yeni arac eklendi\n", cityCode);
	printCar(car, cityCode);

	return;
}

void printByCityCode(City *cities) {
	int index;
	do {
		printf("Listelenecek sehrin kodunu giriniz [int n: 1 <= n <= %d]:\n", CITY_COUNT);
		scanf("%d", &index);
	} while (!(1 <= index && index <= CITY_COUNT));

	if (cities[index].carCount == 0) {
		printf("Sehir %d icin kayitli arac yok\n", index);
		return;
	}
	printCity(&cities[index], index);

	return;
}

void printAllCities(City *cities) {
	printf("Kayitli toplam arac sayisi: %d\n", cities[0].carCount);
	for (int i = 1; i < CITY_COUNT; i++) {
		printCity(&cities[i], i);
	}
	return;
}

int main(int argc, char const *argv[]) {
	City cities[CITY_COUNT] = {0};

	while (true) {
		printf("Bir islem seciniz: [int n: 1 <= n <= 4]\n");
		printf("[1] Plaka ekle\n");
		printf("[2] Sehir koduna gore listele\n");
		printf("[3] Tum sehirleri listele\n");
		printf("[4] Programi sonlandir\n");

		int selection = -1;
		scanf("%d", &selection);
		putchar('\n');

		switch (selection) {
			case 1: {
				addCar(cities);
				break;
			}
			case 2: {
				printByCityCode(cities);
				break;
			}
			case 3: {
				printAllCities(cities);
				break;
			}
			case 4: {
				printf("Program sonlandiriliyor\n");
				return 0;
			}
			default: {
				printf("Gecersiz secim! Tekrar secim yapiniz\n");
				break;
			}
		}
		putchar('\n');
	}
}
