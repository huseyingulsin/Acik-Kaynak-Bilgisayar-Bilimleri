#include <stdio.h>
#include <stdlib.h> //for rand() funciton
#include <math.h> //for sqrt() abs() and pow() function

void menu();
void track_machine ();
void track_machine_interface(int x, int y, double r, double d);//helper interface func for track_machine
void refresh_position (int *X, int *Y, double *D, double *R);
double distance_point(int x1,int y1,int x2,int y2); //calculate distance of 2 point
void decrypt_and_print (char* file_path);
char decrypt_numbers (int number);
void deep_decrypt_and_print (char* file_path);
int apply_formula_part_2 (FILE *fp,char c);
void encrypt_messages (char* file_path); //expected funciton
int encrypt_character (char character); //converting function
int apply_formula_part_4 (FILE *fp,int num); //apply given formula
void add_two_zeros(FILE *fp); //add two zeros some points----------ADD SOME POINTS UNNCESSEARY ZEROES TOO :(

void menu();

int main(void){
	menu();
}

void menu(){
	int choice,check=1;
	while (check){
	printf("1-)Decrypt and print encrypted_p1.img\n2-)Decrypt and print encrypted_p1.img\n3-)Switch On the Track Machine\n4-)Encrypt the massage\n5-)Swtich Off...\n\nPlease make your choice:\n");
	scanf("%d",&choice);
	switch (choice){
		case 1:decrypt_and_print("encrypted_p1.img");
				break;
		case 2:deep_decrypt_and_print("encrypted_p2.img");
				break;
		case 3:track_machine();
				break;
		case 4:encrypt_messages("decrypted_p4.img");
				break;
		case 5:check=0;
				printf("Goodbyee\n");
				break;
		default:printf("Invalid Operation\n");
				break;
	}
}
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

void add_two_zeros(FILE *fp){
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

void track_machine(){
	//in order to moodle page, I assume that starting point of enemy is (1,1)
	int x=1,y=1,check=1;
	double d=7.07,r=0,q; //while starting, distance to (1,1) to (6,6) = 7.07 so d=7.07
	char control;
	track_machine_interface(x,y,r,d); //create interface for track machine
	scanf("%c",&control);
	while (check){
		scanf("%c",&control);
		switch (control){
			case 'R':refresh_position (&x,&y,&d,&r);
					scanf("%c",&control);
					break;
			case 'E':printf("Goodbyee....\n");
					check=0;
					break;
			default:printf("Invalid operation.\nEnter new Command:\n");
					scanf("%c",&control);
					break;
			}
		if (check==0)
			break;
		if (d==0){ //for fun
			printf("\nDistance: %lf\n",d);
			printf("Oh no they catch us\nWe do not need track machine anymore\nExploding Track Machine...\n&+'!/&CV+'^+& (bomb effect :D)\n\n");
			track_machine_interface(x,y,r,d);
			break;
		}
		track_machine_interface(x,y,r,d); //after some function job, recrate track machine interface
	}
}

void track_machine_interface(int x, int y, double r, double d){
	for (int i=0; i<11; i++){ //create track machine graphich interface
		for (int j=0; j<11; j++){
			if(j==x-1 && i==y-1){ //enemy position
				printf("E\t");
				j++;
			}
			if (j==5 && i==5){ //our position, it seems in machine like (6,6)
				printf("O\t");
				j++;
			}
			printf(".\t");
		}printf("\n");
	}
	printf("Enemies X position: %d, Enemies Y poisiton: %d, Displacament %.2lf, Distance to our camp: %.2lf, \nCommand waiting...\n",x,y,r,d);
}

void refresh_position (int *X, int *Y, double *D, double *R){
	int temp_x=*X,temp_y=*Y; //assing X and Y values to temp values
	*X=rand()%12; //makes random integer values 0 to 11
	*Y=rand()%12;
	*D=distance_point(*X,*Y,6,6);
	*R=distance_point(*X,*Y,temp_x,temp_y);
}

double distance_point(int x1,int y1,int x2,int y2){
	return sqrt(pow(abs(x1-x2),2)+pow(abs(y1-y2),2));
}
