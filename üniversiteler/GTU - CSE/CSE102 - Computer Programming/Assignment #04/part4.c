#include <stdio.h>

void encrypt_messages (char* file_path); //expected funciton
int encrypt_character (char character); //converting function
int apply_formula_part_4 (FILE *fp,int num); //apply given formula
void add_two_zeros(FILE fp); //add two zeros some points----------ADD SOME POINTS UNNCESSEARY ZEROES TOO :(

int main(void){
	encrypt_messages("decrypted_p4.img");
}

void encrypt_messages (char* file_path){
	FILE *fp_read =fopen(file_path, "r"); //open in reading mode
	FILE *fp_write=fopen("encrypted_p4.img","w"); //open in writing mode
	add_two_zeros(fp_write); //add two zero in encrypted_p4
	char c;
	int num1,num2,seek_position_read=0;
	fseek(fp_read,seek_position_read,SEEK_SET); //set poistion
	while (fscanf(fp_read,"%c",&c)!=EOF){
		num1=encrypt_character(c);
		if(num1==-1){
			fprintf(fp_write,"\n");
			add_two_zeros(fp_write); //whenever seeker goes to the end of line add two zeros in encrypted_p4
			continue;
		}
		num2=apply_formula_part_4(fp_read,num1);
		if (num2==-1){
			fprintf(fp_write,"\n"); 
			add_two_zeros(fp_write); //whenever seeker goes to the end of line add two zeros in encrypted_p4
			continue;
			}
		fseek(fp_read,-2,SEEK_CUR); //move seeker to the left for 2 point
		fprintf(fp_write,"%d",num2); //write in encrypted_p4
	}	
}

int apply_formula_part_4 (FILE *fp,int num){
	char c;
	int total=0;
	total+=num;
	for (int i=0; i<2; i++){
		fscanf(fp,"%c",&c);
		if (c=='\n') //when goes to the end of line, return 1
			return -1;
		num=encrypt_character(c);
		total+=num;
	}
	return total%7;
}

void add_two_zeros(FILE fp){
	for (int i=0; i<2; i++){
		fprintf(fp,"0");
	}
}

int encrypt_character (char character){
	switch (character){
		case ' ':return 0;
		case '-':return 1;
		case '_':return 2;
		case '|':return 3;
		case '/':return 4;
		case '\\':return 5;
		case 'O':return 6;
		case '\n':return -1;
	}
}
