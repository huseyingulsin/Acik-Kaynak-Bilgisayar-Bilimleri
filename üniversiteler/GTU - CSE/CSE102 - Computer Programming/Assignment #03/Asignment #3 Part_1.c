#include <stdio.h>

int sum (int n, int flag); 
int mult (int n, int flag); 

int main(void){
	int num,op,flag,check;
	printf("Please enter an integer:");
	scanf("%d",&num);
	printf("Please enter '0' for sum '1' for multiplation\n");
	scanf("%d",&op);
	printf("Please enter '0' for even '1' for odd num\n");
	scanf("%d",&flag);
	if (flag != 1 && flag !=0){ //if flag value is invalid, prints error message.
		printf("invalid operation '0' for even '1' for odd num.\n");
		return 1;
	}
	switch(op){
		case 0: //if op value is 0
			check=sum(num,flag);
			printf("%d\n",check);
			break;
		case 1: //if op value is 1
			check=mult(num,flag);
			printf("%d\n",check);
			break;
		default: //if op value is not 1 or 0
			printf("invalid operation '0' for sum '1' for multi\n");
			break;
	}
}

int sum (int n, int flag){
	int total=1;
	switch (flag){
		case 0:
			printf("1"); //for code beauty
			for (int i=2; i<n; i++){
				if (i%2==0){
					total+=i;
					printf(" + %d",i );
					}
				}
			printf("="); //for code beauty
			return total;
		case 1:
			printf("1");
			for (int i=2; i<n; i++){
				if (i%2==1){
					total+=i;
					printf(" + %d",i );
					}
				}
			printf("=");
			return total;
			}
}

int mult (int n, int flag){
	int total=1;
	switch (flag){
		case 0:
			printf("1");
			for (int i=2; i<n; i++){
				if (i%2==0){
					total*=i;
					printf(" * %d",i );
					}
				}
			printf("=");
			return total;
		case 1:
			printf("1");
			for (int i=2; i<n; i++){
				if (i%2==1){
					total*=i;
					printf(" * %d",i );
					}
				}
			printf("=");
			return total;
			}
}

