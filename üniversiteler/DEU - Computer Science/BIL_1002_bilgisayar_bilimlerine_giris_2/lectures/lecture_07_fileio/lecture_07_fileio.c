#include <stdio.h>

typedef struct {
	int accountNumber;
	char firstName[15];
	char lastName[15];
	double credit;
} Customer;

int main(int argc, char const *argv[]) {
	Customer c = {0, "", "", 0.0};

	FILE *customerFile = fopen("credit.bin", "rb+");

	if (customerFile == NULL) {
		printf("File could not be opened!\n");
		return 1;
	}


	do {
		printf("Account Number: [int n: 1 <= n <= 100]\n");
		printf("Enter 0 to exit\n");
		scanf("%d", &c.accountNumber);


	} while(c.accountNumber != );


	return 0;
}
