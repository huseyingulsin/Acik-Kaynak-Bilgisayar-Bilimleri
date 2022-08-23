#include <stdio.h>

int andop(int a,int b); //does the job of & operation
int mypow(int sub,int tab); //works like pow func in math.h but integer 
int digit_lenght(int a); //finds lenght of nums


int main(void){
	int num1,num2,lenght_num1,lenght_num2,check1,check2,control,jump=1;

	while (1){
		jump=1; //everytime this assign 1 to jump
		printf("first binary num:	");
		scanf("%d",&num1);
		printf("second binary num:	");
		scanf("%d",&num2);
		int temp1=num1,temp2=num2; //for using the num values without changing them
		lenght_num1=digit_lenght(num1); //calculates the lenght of the nums
		lenght_num2=digit_lenght(num2);
		if (lenght_num1!=lenght_num2){ //if they are not the same lenght, it will give error message
			printf("They lenght should be the same. Enter two new num:\n");
			continue; //it will go to begining at while loop
		}
		else
			while (temp1 > 0){ //this wile loop detects, is there any non binary integer.
				if((temp1%10!=1 && temp1%10!=0) || (temp2%10!=1 && temp2%10!=0)){
					printf("Integers should be binary, please enter new two int\n");
					jump=0; //if there is any non binary digits, we will use this for jump at the while loop begining
					break;
					}
				temp1/=10; //for checking all digits.
				temp2/=10;
			}
		if (jump==1){ //if it will equel 1, does this things
		printf("%d AND %d =",num1,num2);
		while (lenght_num1>0){ //calculates how much time loop will execute
			int a=mypow(10,lenght_num1-1); //for do some type of operations, we assign a double veriable to an int. (pow gives a double return)
			check1=num1/a; //assign for the nums's each integer
			check1%=2;		//for binary nums, it converts other num to 1 or 0.
			check2=num2/a;
			check2%=2;
			control=andop(check1,check2); //sends values to funciton.
			printf("%d",control);
			num1%=a; //move next digit
			num2%=a;
			lenght_num1--; //counter
			}break; //when while loop ends it will break and exit upper while loop.
		}continue; //if jump value is not 1, goes to while loop begining.
	}
}

int andop(int num1,int num2){
	if (num1==1 & num2==1) //if both of them are 1
		return 1;		//it will return 1
	return 0;			//otherwise will return 0
}

int mypow(int sub,int tab){
	int result=1,i =0;
	while(i<tab){
		result*=sub;
		i++;
	}
	return result;
}

int digit_lenght(int a){
	int result=0;
	while(a!=0){
		a/=10;
		result++;
	}
	return result;
}
