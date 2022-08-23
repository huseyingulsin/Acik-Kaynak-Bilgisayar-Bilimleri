#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PATH "words.txt" //name of the file
#define NUM_ROW 20 		//number of rows
#define NUM_COL 20		//number of collums
#define WORD_NUM 100	//number of words in file
#define WORD_LEN 20		//avarage word lenght +10
#define HACK_MOD_ON_OFF 0 //opens cheat/hack mode,1 for open, 0 for close showes the words on the puzzle table,

void welcome(); //print Opening Massage
void rand_word_from_file(); //reads entire file line by line
void choise_random_10_word(char s[WORD_NUM][WORD_LEN]); //chose 10 random words each of them
void create_puzzle_table(char words[10][WORD_LEN]); //creates the gamae area which called puzzle table
void print_puzzle_table(char puzzle_table[NUM_COL][NUM_ROW],char words[10][WORD_LEN],int resume,int *counter,int *finish_counter,char input_list[100][WORD_LEN]); //pritns puzzle tablle
void fill_with_random_char(char puzzle_table[NUM_COL][NUM_ROW],char words[10][WORD_LEN]); //fill the null or '*' characters with random char
int check_condition(char puzzle_table[NUM_COL][NUM_ROW],int random_col, int random_row,int lenght,int check,char words[10][WORD_LEN],int num_word); //check some conditions
void find_words(char puzzle_table[NUM_COL][NUM_ROW],char words[10][WORD_LEN],int *counter,int *finish_counter,char input_list[100][WORD_LEN]); //find waords due to user
void check_direction(char puzzle_table[NUM_COL][NUM_ROW],int col,int row,char word[10][WORD_LEN],int num_word,int lenght,int *counter,int *finish_counter,char input_list[100][WORD_LEN]); //check directions of the words which user choice in puzzle table
void hack_mod(int hack,char words[10][WORD_LEN]); //showes words, kind of cheat mode.

int main(void){
	srand(time(NULL)); //each time creates different random numbers
	welcome();
	rand_word_from_file();
	return 0;
}

void welcome(){
	printf("--------------------------------------------------------------------------------\n");
	printf("Welcome to *ONLY GENIUS ONES CAN SOLVE THOS PUZZLE* puzzle\n");
	printf("When you found all 10 words it will be finished\n");
	printf("Or simply you can write 'Exit' if you are not enough *GENIUS* to solve this.\n");
	printf("--------------------------------------------------------------------------------\n");
}

void rand_word_from_file(){ //read all line from the file
	FILE *fp =fopen(PATH,"r"); //open file
	char s[WORD_NUM][WORD_LEN];
	for (int i=0; i<WORD_NUM; i++){
		fgets(s[i],WORD_LEN,fp); //read entire file line by line
	}
	fclose(fp); //close file
	choise_random_10_word(s); //send whole readed information to funciton
}

void choise_random_10_word(char s[WORD_NUM][WORD_LEN]){ //chose 10 random word from file whcih readed before
	char s1[10][WORD_LEN];
	for (int i=0; i<10; i++){
		strcpy(s1[i],s[rand()%WORD_NUM-1]); //copy the context of the random word from file onto s1
	}
	create_puzzle_table(s1); //pass selected random words to funciton
}

void create_puzzle_table(char words[10][WORD_LEN]){
	int random_row,random_col,lenght,continue_counter=0;
	char puzzle_table[NUM_COL][NUM_ROW]; //fill blnaks with '*'
	for (int i=0; i < NUM_ROW; i++){
		for (int j=0; j<NUM_COL; j++){
			puzzle_table[i][j]='*';
		}
	}
	int i=0;
	while (i<10){
		/*
		It does almost same thing, for all directions
		1-check if is there an another char on the way our word which we want to print
		2-if return value is 1, jumps begining to while loop again
		3-if return value is not 1, assign chosed word character to random places with same direction
		4-break the switch case.
		*/
		lenght=strlen(words[i])-2; //it finds lenght of strings wrong, so we substract 2.
		random_col=rand()%NUM_COL;
		random_row=rand()%NUM_ROW;
		if (random_col+lenght <=20 && random_row+lenght<=20){ //posibility #1
			switch (rand()%3){
				case 0://to left to right
					continue_counter= check_condition(puzzle_table,random_col,random_row,lenght,1,words,i);
					if(continue_counter==1)	break;	
					for (int j=0; j<lenght; j++){
						puzzle_table[random_col][random_row+j]=words[i][j];
						}break;
				case 1://to up to buttom
					continue_counter= check_condition(puzzle_table,random_col,random_row,lenght,2,words,i);
					if(continue_counter==1)	break;
					for (int j=0; j<lenght; j++){ 
						puzzle_table[random_col+j][random_row]=words[i][j];
						}break;
				case 2://to right down corner
					continue_counter= check_condition(puzzle_table,random_col,random_row,lenght,3,words,i);
					if(continue_counter==1)	break;	
					for (int j=0; j<lenght; j++){ 
						puzzle_table[random_col+j][random_row+j]=words[i][j];
						}break;
				
				}
		}
		else if (random_col-lenght >=0 && random_row-lenght >=0){ //posibility #2
			switch (rand()%3){
				case 0://to right to left
					continue_counter= check_condition(puzzle_table,random_col,random_row,lenght,4,words,i);
					if(continue_counter==1)	break;	
					for (int j=0; j<lenght; j++){ 
						puzzle_table[random_col][random_row-j]=words[i][j];
						}break;
				case 1://to buttom to up
					continue_counter= check_condition(puzzle_table,random_col,random_row,lenght,5,words,i);
					if(continue_counter==1)	break;	
					for (int j=0; j<lenght; j++){ 
						puzzle_table[random_col-j][random_row]=words[i][j];
						}break;
				case 2://to left buttom corner
				continue_counter= check_condition(puzzle_table,random_col,random_row,lenght,6,words,i);
				if(continue_counter==1)	break;	
					for (int j=0; j<lenght; j++){ 
						puzzle_table[random_col-j][random_row-j]=words[i][j];
						}break;
				}
		}
		else if(random_col-lenght>=0 && random_row+lenght<=20){ //posibility #3
			continue_counter= check_condition(puzzle_table,random_col,random_row,lenght,7,words,i);
			if(continue_counter==1)	continue;
			else {	
				for (int j=0; j<lenght; j++){  //to right buttom corner
					puzzle_table[random_col-j][random_row+j]=words[i][j];
					}
				}
		}
		else if(random_col+lenght<=20 && random_row-lenght>=0){ //posibility #4
			continue_counter= check_condition(puzzle_table,random_col,random_row,lenght,8,words,i);
			if(continue_counter==1)	continue;
			else{	
				for (int j=0; j<lenght; j++){ //to left down corner
					puzzle_table[random_col+j][random_row-j]=words[i][j];
					}
				}
		}
		// not part of homework anymore -- else	printf("can not wrote in the table--%s\n",words[i]); //checks is there a word missing.
		if(continue_counter==1)	continue;	//jump to begining to while loop			
	i++;} //if everything is okay, increment i value by one which means chose the next random word.
	int a=0,b=0;
	char input_list[100][WORD_LEN];
	print_puzzle_table(puzzle_table,words,1,&a,&b,input_list);  //pass table and word strings array to funciton
}

int check_condition(char puzzle_table[NUM_COL][NUM_ROW],int random_col, int random_row,int lenght,int check,char word[10][WORD_LEN],int num_word){
	/*
	it checks, if there is a char in way of the words, it returns 1, otherwise it returns 0
	It specially checks all possibility, it is kinda mess, but ı have to do it like this way.
	*/
	int value=0,value2=0,value3=0;
	switch (check){
		case 1:
			for (int i=0; i<lenght; i++){
			if (puzzle_table[random_col][random_row+i]=='*')	value3++; else if (puzzle_table[random_col][random_row+i] == word[num_word][i])	value++; else value2++;
		}break;
		case 2:
			for (int i=0; i<lenght; i++){
			if (puzzle_table[random_col+i][random_row]=='*')	value3++; else if (puzzle_table[random_col+i][random_row] == word[num_word][i])	value++; else value2++;
		}break;
		case 3:
			for (int i=0; i<lenght; i++){
			if (puzzle_table[random_col+i][random_row+i]=='*')	value3++; else if (puzzle_table[random_col+i][random_row+i] == word[num_word][i])	value++; else value2++;
		}break;
		case 4:
			for (int i=0; i<lenght; i++){
			if (puzzle_table[random_col][random_row-i]=='*')	value3++; else if (puzzle_table[random_col][random_row-i] == word[num_word][i])	value++; else value2++;
		}break;
		case 5:
			for (int i=0; i<lenght; i++){
			if (puzzle_table[random_col-i][random_row]=='*')	value3++; else if (puzzle_table[random_col-i][random_row] == word[num_word][i])	value++; else value2++;
		}break;
		case 6:
			for (int i=0; i<lenght; i++){
			if (puzzle_table[random_col-i][random_row-i]=='*')	value3++; else if (puzzle_table[random_col-i][random_row-i] == word[num_word][i])	value++; else value2++;
		}break;
		case 7:
			for (int i=0; i<lenght; i++){
			if (puzzle_table[random_col-i][random_row+i]=='*')	value3++; else if (puzzle_table[random_col-i][random_row+i] == word[num_word][i])	value++; else value2++;
		}break;
		case 8:
			for (int i=0; i<lenght; i++){
			if (puzzle_table[random_col+i][random_row-i]=='*')	value3++; else if (puzzle_table[random_col+i][random_row-i] == word[num_word][i])	value++; else value2++;
		}break;
	}
	if (value+value3==lenght)
		return 0;
	else
		return 1;
}

void fill_with_random_char(char puzzle_table[NUM_COL][NUM_ROW],char words[10][WORD_LEN]){ //fill the puzzle table with random char
	for (int i=0; i<NUM_COL; i++){
		for (int j=0; j<NUM_ROW; j++){
			if (puzzle_table[i][j]=='*'){ //if there is a '*' sign
				puzzle_table[i][j]=rand()%(123-97)+97; //fill with random char
			}
		}
	}int a=0,b=0;
	char input_list[100][WORD_LEN];
	print_puzzle_table(puzzle_table,words,1,&a,&b,input_list); //pass argumants to the printing function
}

void print_puzzle_table(char puzzle_table[NUM_COL][NUM_ROW],char words[10][WORD_LEN],int resume,int *a,int *b,char input_list[100][WORD_LEN]){ //print the puzzle_table 
	for (int i=65; i < NUM_ROW+65; i++)	printf("%c ",i ); //print A to T for coordinate system
	printf("\n---------------------------------------\n"); 
	int k=0;
	for (int i=0; i < NUM_ROW; i++){
		for (int j=0; j<NUM_COL; j++){
			printf("%c ",puzzle_table[i][j]);
		}printf(" ||(%d)\n",k); k++; //print the number 0 to 19 for coordinate system
	}
	hack_mod(HACK_MOD_ON_OFF,words);
	int temp_a=*a,temp_b=*b;
	if(resume==1){ 
		find_words(puzzle_table,words,&temp_a,&temp_b,input_list); //if resume is 1, pass the argumantes to the function
	}
}

void find_words(char puzzle_table[NUM_COL][NUM_ROW],char words[10][WORD_LEN],int *counter1,int *finish_counter1,char input_list[100][WORD_LEN]){
	int row,col,check_on_list=1,a=0,lenght,j,k=0;
	char space,c1,choice[20],choice1[20];
	int counter=*counter1,finish_counter=*finish_counter1;
	while (1){
		printf("\nChoise Coordiante and write the word:");
		scanf(" %19[^\n]",choice1); 
		if (strncmp(choice1,"Exit",4)==0){ printf("Gooodbyee My Friend\n"); exit(1);} //if user types Exit terminate the program
		sscanf(choice1, "%c%d%s", &c1, &col, choice); //use sscanf to bring values to string to the paramteters
		row=c1-65; //convert capital char to a number depend on the ascii table
		lenght=strlen(choice);
		for (int i=0; i<10; i++){ //check if this word is on the list
			lenght=strlen(choice);
			if(strncmp(choice,words[i],lenght)==0 && strlen(choice)==strlen(words[i])-2){	check_on_list=0; j=i;}
		}
		if(check_on_list==1){ //if the word is not in the liste jump to begining the function
			printf("Wrong answer,it is not on word list on the puzzle, try again man!\n");
			strcpy(input_list[counter],choice); 
			counter+=1;
			printf("Entered words list:\n"); 
			for (int q=0; q<counter; q++){
			printf("%d.word is %s\n",q+1, input_list[q]); }
			find_words(puzzle_table,words,&counter,&finish_counter,input_list);
		}strcpy(input_list[counter],choice); 
		counter+=1;

		printf("Entered words list:\n"); 
		for (int q=0; q<counter; q++){
			printf("%d.word is %s\n",q+1, input_list[q]);
		}

		check_direction(puzzle_table,col,row,words,j,lenght,&counter,&finish_counter,input_list); //pass the argument to the function

		for (int l=0; l<lenght; l++){
			choice[l]-=32;
		}strcpy(input_list[counter-1],choice); 
		finish_counter+=1;
		printf("Entered words list:\n"); 
		for (int q=0; q<counter; q++){
			printf("%d.word is %s\n",q+1, input_list[q]);
		}

		if (finish_counter==10) {print_puzzle_table(puzzle_table,words,0,&counter,&finish_counter,input_list); printf("\n\nYou found all words, You are *GENIUS* Man!! GOODBYEEE!!\nGOOD JOOOBBB\nSERIOUSLY GOOD JOOB\nSO GOODBYEE :)\n"); exit(1);}
		print_puzzle_table(puzzle_table,words,1,&counter,&finish_counter,input_list); //pass the argumanet to the function
	}
}

void check_direction(char puzzle_table[NUM_COL][NUM_ROW],int col,int row,char word[10][WORD_LEN],int num_word,int lenght,int *counter1,int *finish_counter1,char input_list[100][WORD_LEN]){
	/*
	it almost does same thing each one, 
	it is kinde bad programing but I can not find another way 
	except malloc or like something but we are not allowed to do this yet
	so this part works like
	1-check if the word is on the puzzle table and check
	2-check the coordinate for is word char is equel to expected coordinates
	3-if it is correct coordinate and word convert the char to capital char
	4-finish
	*/
	int i=0;
	int counter=*counter1,finish_counter=*finish_counter1;
	if (puzzle_table[col][row]!=word[num_word][i]){
		printf("Wrong coordinate, try again my friend!\n");
		find_words(puzzle_table,word,&counter,&finish_counter,input_list);
	}i++; puzzle_table[col][row] -=32;

	if (puzzle_table[col][row+i] == word[num_word][i]){ //#1
		puzzle_table[col][row+i] -=32;
		for (int j=2; j<lenght; j++){
			//if(puzzle_table[col][row+j] != word[num_word][j]) {printf("1 Wrong coordinate, try again my friend!\n"); find_words(puzzle_table,word);}
			puzzle_table[col][row+j] -=32;
		}
	}
	else if (puzzle_table[col+i][row] == word[num_word][i]){ //#2
		puzzle_table[col+i][row] -=32;
		for (int j=2; j<lenght; j++){
			//if(puzzle_table[col+j][row] != word[num_word][j]) {printf("2 Wrong coordinate, try again my friend!\n"); find_words(puzzle_table,word);}
			puzzle_table[col+j][row] -=32;
		}
	}
	else if (puzzle_table[col+i][row+i] == word[num_word][i]){ //#3
		puzzle_table[col+i][row+i] -=32;
		for (int j=2; j<lenght; j++){
			//if(puzzle_table[col+j][row+j] != word[num_word][j]) {printf("3 Wrong coordinate, try again my friend!\n"); find_words(puzzle_table,word);}
			puzzle_table[col+j][row+j] -=32;
		}
	}
	else if (puzzle_table[col][row-i] == word[num_word][i]){ //#4
		puzzle_table[col][row-i] -=32;
		for (int j=2; j<lenght; j++){
			//if(puzzle_table[col][row-j] != word[num_word][j]) {printf("4 Wrong coordinate, try again my friend!\n"); find_words(puzzle_table,word);}
			puzzle_table[col][row-j] -=32;
		}
	}
	else if (puzzle_table[col-i][row] == word[num_word][i]){ //#5
		puzzle_table[col-i][row+i] -=32;
		for (int j=2; j<lenght; j++){
			//if(puzzle_table[col-j][row] != word[num_word][j]) {printf("5 Wrong coordinate, try again my friend!\n"); find_words(puzzle_table,word);}
			puzzle_table[col-j][row] -=32;
		}
	}
	else if (puzzle_table[col-i][row-i] == word[num_word][i]){ //#6
		puzzle_table[col-i][row-i] -=32;
		for (int j=2; j<lenght; j++){
			//if(puzzle_table[col-j][row-j] != word[num_word][j]) {printf("6 Wrong coordinate, try again my friend!\n"); find_words(puzzle_table,word);}
			puzzle_table[col-j][row-j] -=32;
		}
	}
	else if (puzzle_table[col-i][row+i] == word[num_word][i]){ //#7
		puzzle_table[col-i][row+i] -=32;
		for (int j=2; j<lenght; j++){
			//if(puzzle_table[col-j][row+j] != word[num_word][j]) {printf("7 Wrong coordinate, try again my friend!\n"); find_words(puzzle_table,word);}
			puzzle_table[col-j][row+j] -=32;
		}
	}
	else if (puzzle_table[col+i][row-i] == word[num_word][i]){ //#8
		puzzle_table[col+i][row-i] -=32;
		for (int j=2; j<lenght; j++){
			//if(puzzle_table[col+j][row-j] != word[num_word][j]) {printf("8 Wrong coordinate, try again my friend!\n"); find_words(puzzle_table,word);}
			puzzle_table[col+j][row-j] -=32;
		}
	}
}

void hack_mod(int hack,char words[10][WORD_LEN]){
	if (hack==1){
		printf("\t");
	for (int i=0; i<10; i++) printf("%d.cheat word is %s\t",i+1,words[i]);
	}
}

