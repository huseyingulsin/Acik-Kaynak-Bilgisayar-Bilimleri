#include <stdio.h>
#include <math.h>

int isprime(int a);

int main(void){
	int num,check;
	printf("Enter an integer:\n");
	scanf("%d",&num);
	for (int i=2; i<num; i++){ //starts from 2
		check=isprime(i);
		if (check==0)
			printf("%d is a prime number\n",i);
		else
			printf("%d is not a prime number, dividible by %d\n",i,check);
	}
}

int isprime(int a){
	int check=0;
	for (int i=sqrt(a); i>1; i--){ //take square root of the number, and decrease values one by one,
		if(a%i==0) 					//until this thing done
			check=i;				//assign the value of i to check.
	}
	return check; //returns check.
}