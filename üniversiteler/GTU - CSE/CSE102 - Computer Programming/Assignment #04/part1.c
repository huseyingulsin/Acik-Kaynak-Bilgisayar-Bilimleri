#include <stdio.h>
void decrypt_and_print (char* file_path);
char decrypt_numbers (int number);

int main(void){
	decrypt_and_print("encrypted_p1.img");
}

void decrypt_and_print (char* file_path){
	FILE *fp=fopen(file_path,"r"); //open file
	char c1,c2;
	int temp_c;
	while(fscanf(fp,"%c",&c1)!=EOF){
		temp_c=c1-48; //convert char to int value
		c2=decrypt_numbers(temp_c); //send temp_c value to func
		printf("%c",c2);
	}
	fclose(fp); //close file
}

char decrypt_numbers (int number){
	switch (number){
		case 0:return ' ';
		case 1:return '-';
		case 2:return '_';
		case 3:return '|';
		case 4:return '/';
		case 5:return '\\';
		case 6:return 'O';
		default:return '\n';
	}
}
