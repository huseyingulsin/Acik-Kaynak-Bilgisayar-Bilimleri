#include <stdio.h>

#define SIZE 30

typedef struct ogrenci {
	char ad[30];
	int vize;
	int final;
	int gecme;
} Ogrenci;

int hesapla(Ogrenci ogr) {
	ogr.gecme = ogr.vize * 0.4 + ogr.final * 0.6;
	return ogr.gecme;
}

Ogrenci enyukseknot(Ogrenci *arr, int size) {
	int max = arr[0].gecme;
	int index = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i].gecme > max) {
			max = arr[i].gecme;
			index = i;
		}
	}

	printf("%s %d\n", arr[index].ad, arr[index].gecme);

	return arr[index];
}

int main() {

	Ogrenci arr[SIZE];

	for (int i = 0; i < SIZE; i++) {
		scanf("%s %d %d", arr[i].ad, &arr[i].vize, &arr[i].final);
		printf("%d\n", hesapla(arr[i]));
	}

	return 0;
}
