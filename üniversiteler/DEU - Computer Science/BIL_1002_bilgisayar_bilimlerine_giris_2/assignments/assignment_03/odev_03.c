#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CITY_COUNT 81
#define LETTER_CODE_LENGTH_MIN 2
#define LETTER_CODE_LENGTH_MAX 3
#define NUMBER_CODE_MIN 10
#define NUMBER_CODE_MAX 9999
#define BINARY_FILE_NAME "plaka.bin"
#define TXT_FILE_ALL "plakalar.txt"
#define TXT_FILE_ONE_PREFIX "plakalar_"
#define TXT_FILE_ONE_SUFFIX ".txt"

typedef struct {
	char letterCode[LETTER_CODE_LENGTH_MAX + 1];
	int numberCode;
} Car;

// memcmp() is not guarranteed to work because of strings
bool carEquals(Car* car1, Car* car2) {
	return strcmp(car1->letterCode, car2->letterCode) == 0 && car1->numberCode == car2->numberCode;
}

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


int readCityCode() {
	int cityCode;
	do {
		printf("Sehir kodunu giriniz: [int n: 1 <= n <= %d]\n", CITY_COUNT);
		scanf("%d", &cityCode);
	} while (!(1 <= cityCode && cityCode <= CITY_COUNT));

	return cityCode;
}

Car readCar() {
	Car car = {0};

	do {
		printf("Harf kodunu giriniz: [char a[n]: 'A' <= a[n] <= 'Z' && %d <= n <= %d]\n", LETTER_CODE_LENGTH_MIN, LETTER_CODE_LENGTH_MAX);
		// TODO replace with gets(), scanf unsafe
		//fgets(car->letterCode, LETTER_CODE_LENGTH_MAX + 1, stdin);
		scanf("%s", car.letterCode);
	} while (!isValidLetterCode(car.letterCode));

	do {
		printf("Sayi kodunu giriniz: [int n: %d <= n <= %d]\n", NUMBER_CODE_MIN, NUMBER_CODE_MAX);
		scanf("%d", &car.numberCode);
	} while (!(NUMBER_CODE_MIN <= car.numberCode && car.numberCode <= NUMBER_CODE_MAX));

	return car;
}

void addCar(City *cities) {
	int cityCode = readCityCode();
	City *city = &cities[cityCode];
	Car car = readCar();

	// Return if a duplicate record exists
	for (int i = 0; i < city->carCount; i++) {
		if (carEquals(&car, city->cars[i])) {
			printf("Ayni plakayla kayitli bir arac var\n");
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

	// Car* car = (Car *) malloc(sizeof(Car));

	city->cars[city->carCount] = (Car *) malloc(sizeof(Car));
	*city->cars[city->carCount] = car;

	city->carCount++;
	cities[0].carCount++;

	printf("Sehir %d icin yeni arac eklendi\n", cityCode);
	printCar(&car, cityCode);

	return;
}

void printByCityCode(City *cities) {
	int index = readCityCode();
	if (cities[index].carCount == 0) {
		printf("Sehir %d icin kayitli arac yok\n", index);
		return;
	}
	printCity(&cities[index], index);

	char query[100];
	printf("Plakalari dosyaya yazdirmak istiyor musunuz? [E/h]: ");
	scanf("%s", query);

	if (query[0] == 'e' || query[0] == 'E') {
		// TODO “plakalar_35.txt”
		//sprintf(buffer, "%s%d%s", TXT_FILE_NAME, plaka_no, SUFFIX)

		char fileName[100];
		sprintf(fileName, "%s%d%s", TXT_FILE_ONE_PREFIX, index, TXT_FILE_ONE_SUFFIX);


		FILE *plateFile = fopen(fileName, "w");
		fprintf(plateFile, "%d\n", cities[index].carCount);

		for (int i = 0; i < cities[index].carCount; i++) {
			fprintf(plateFile, "%d %s %d\n", index, cities[index].cars[i]->letterCode, cities[index].cars[i]->numberCode);
		}
		fclose(plateFile);
		printf("Plakar %s dosyasina yazdirildi\n", fileName);
	}

	return;
}

void printAllCities(City *cities) {
	printf("Kayitli toplam arac sayisi: %d\n", cities[0].carCount);
	for (int i = 1; i < CITY_COUNT + 1; i++) {
		printCity(&cities[i], i);
	}

	char query[100];
	printf("Plakalari dosyaya yazdirmak istiyor musunuz? [E/h]: ");
	scanf("%s", query);

	if (query[0] == 'e' || query[0] == 'E') {
		FILE *plateFile = fopen(TXT_FILE_ALL, "w");

		fprintf(plateFile, "%d\n", cities[0].carCount);

		for (int i = 1; i < CITY_COUNT + 1; i++) {
			for (int j = 0; j < cities[i].carCount; j++) {
				fprintf(plateFile, "%d %s %d\n", i, cities[i].cars[j]->letterCode, cities[i].cars[j]->numberCode);
			}
		}
		fclose(plateFile);
		printf("Plakar %s dosyasina yazdirildi\n", TXT_FILE_ALL);
	}

	return;
}

void checkCarExistance(City *cities) {
	int cityCode = readCityCode();
	Car car = readCar();

	bool exists = false;
	City *city = &cities[cityCode];

	for (int i = 0; i < city->carCount; i++) {
		if (carEquals(&car, city->cars[i])) {
			exists = true;
			break;
		}
	}

	printf("Bu plakayla kayitli bir arac %s\n", exists ? "var" : "yok");

	return;
}

void readCarsFromFile(City *cities) {
	FILE* binaryFile = fopen(BINARY_FILE_NAME, "rb");

	fread(&cities[0].carCount, sizeof(cities[0].carCount), 1, binaryFile);

	// For every city
	for (int i = 1; i < CITY_COUNT + 1; i++) {
		fread(&cities[i].carCount, sizeof(cities[i].carCount), 1, binaryFile);

		cities[i].cars = (Car **) malloc(sizeof(Car *));

		for (int j = 0; j < cities[i].carCount; j++) {
			cities[i].cars[j] = (Car *) malloc(sizeof(Car));
			fread(cities[i].cars[j], sizeof(Car), 1, binaryFile);
		}
	}

	fclose(binaryFile);

	return;
}

void writeCarsToFile(City *cities) {
	FILE* binaryFile = fopen(BINARY_FILE_NAME, "wb");

	fwrite(&cities[0].carCount, sizeof(cities[0].carCount), 1, binaryFile);

	// For every city
	for (int i = 1; i < CITY_COUNT + 1; i++) {
		fwrite(&cities[i].carCount, sizeof(cities[i].carCount), 1, binaryFile);

		for (int j = 0; j < cities[i].carCount; j++) {
			fwrite(cities[i].cars[j], sizeof(Car), 1, binaryFile);
		}
	}

	fclose(binaryFile);

	return;
}

int main(int argc, char const *argv[]) {
	City cities[CITY_COUNT + 1] = {0};
	readCarsFromFile(cities);

	while (true) {
		printf("Bir islem seciniz: [int n: 0 <= n <= 6]\n");
		printf("[0] Programi sonlandir\n");
		printf("[1] Plaka ekle\n");
		printf("[2] Sehir koduna gore plakalari listele\n");
		printf("[3] Tum sehirleri listele\n");
		printf("[4] Plaka gecerliligi kontrol et\n");
		printf("[5] Plaka bilgilerini dosyadan oku\n");
		printf("[6] Plaka bilgilerini dosyaya yaz\n");

		int selection;
		scanf("%d", &selection);
		putchar('\n');

		switch (selection) {
			case 0: {
				printf("Program sonlandiriliyor\n");
				return 0;
			}
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
				checkCarExistance(cities);
				break;
			}
			case 5: {
				readCarsFromFile(cities);
				break;
			}
			case 6: {
				writeCarsToFile(cities);
				break;
			}
			default: {
				printf("Gecersiz secim! Tekrar secim yapiniz\n");
				break;
			}
		}
		putchar('\n');
	}

	for (int i = 0; i < CITY_COUNT; i++) {
		for (int j = 0; j < cities[i].carCount; j++) {
			free(cities[i].cars[j]);
		}
		free(cities[i].cars);
	}

	return 0;
}
