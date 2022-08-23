#include <stdio.h>
#include <stdbool.h>

int hesapla(int a, int d, int n) {
	return a + (d * n);
}

int fonksiyon(int n, bool *tek_mi) {
	int faktoriyel = 1;
	for (int i = 0; i < n; i++) {
		faktoriyel *= i;
	}
	*tek_mi = faktoriyel % 2 == 1;

	return faktoriyel;
}

int main(int argc, char const *argv[]) {
	int a, d, N;
	scanf("%d %d %d", &a, &d, &N);

	for (int i = 0; i < N; i++) {
		bool *tek_mi = false;
		int sayi = fonksiyon(hesapla(a, d, i), tek_mi);

		printf("%d %s\n", sayi, *tek_mi ? "tek" : "cift");
	}

	return 0;
}
