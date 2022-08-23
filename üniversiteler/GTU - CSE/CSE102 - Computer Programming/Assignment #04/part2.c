#include <stdio.h>
char decrypt_numbers (int number);
void deep_decrypt_and_print (char* file_path);
int apply_formula_part_2 (FILE *fp,char c);


int main(void){
	deep_decrypt_and_print("encrypted_p2.img");
}

void deep_decrypt_and_print (char* file_path){
	FILE *fp=fopen(file_path,"r"); //open file
	char c1,c2;
	int total,seek_position=0;
	fseek(fp,seek_position,SEEK_SET); //set the seeker position to starting point
	while(fscanf(fp,"%c",&c1)!=EOF){
		if (c1-48 <0 || c1-48 > 6) 
			continue;
		total=apply_formula_part_2(fp,c1); //send file pointer and c1 to func
		if (total==10)
			continue;
		c2=decrypt_numbers(total);
		printf("%c",c2);
		seek_position+=1; //increment seeker per 1 each time
		fseek(fp,seek_position,SEEK_SET); //set seeker to next step from to starting position	
		}
	fclose(fp); //close file
	}

int apply_formula_part_2 (FILE *fp,char c){
	//apply the formule which given in the homeworok pdf
	int total=0;
	total+=(c-'0'); //convert char value to int value depend to the ASCII table
	for(int i=0; i<2; i++){
		if (c-48 <0 || c-48 > 6)
			return 10;
		fscanf(fp,"%c",&c);
		total+=(c-'0');
	}
	return total%7; 
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

