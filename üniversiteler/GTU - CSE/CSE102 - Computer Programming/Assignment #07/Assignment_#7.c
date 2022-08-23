#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PATH "Video_Games.txt"
#define MAX_SIZE 2000	//max game number
#define GAME_LEN 100	//max game name lenght
#define MAX_GENRE 20	//max genre number
#define GENRE_LEN 20	//max genre name lenght
#define MAX_PLATFORM 20	//max platform size
#define PLATFORM_LEN 20	//max platform name lenght
#define LINE_LEN 200	//max line lenght
#define MIN_YEAR 1985	//starting year of the games in file
#define MAX_YEAR 2005	//ending year of the games in the file

void welcome(); //a welcome seronomy!!
void read_file(); //reads file and keeps in a buffer
void seperate_string(char buffer[MAX_SIZE][LINE_LEN]); //seperate the buffer 8 pieces
void list_of(char genre[MAX_GENRE][GENRE_LEN],int genre_num); //part #2 	prints genres and platforms
void list_due_to_years(char game[MAX_SIZE][GAME_LEN],float data[MAX_SIZE][7]); //part #3 
void game_info(char game[MAX_SIZE][GAME_LEN], char genre[MAX_GENRE][GENRE_LEN], char platform[MAX_PLATFORM][PLATFORM_LEN],float data[MAX_SIZE][7]); //part #4
void avarage_score(float data[MAX_SIZE][7]); //part #5
void poplarity(char game[MAX_SIZE][GAME_LEN], float data[MAX_SIZE][7]); //part #6
void frequence_of(char g_p[MAX_GENRE][PLATFORM_LEN], float data[MAX_SIZE][7],int number_ind, int choice); //part #7

int main(void){
	welcome();
	read_file();
	return 0;
}

void welcome(){
	printf("Welcome to ULTIMATE GAME INFO FINDER PLUS\n");
	printf("Here is the commands that you can perform\n");
	printf("0: List of the Genres\n");
	printf("1: List of the Platforms\n");
	printf("2: List of the Game Through the Years\n");
	printf("3: All information of a Single Game\n");
	printf("4: Average of the User Score\n");
	printf("5: Georagraphical Information of a Single Game\n");
	printf("6: Frequence of the Genres\n");
	printf("7: Frequence of the Platforms\n");
	printf("8: Exit\n");
}

void read_file(){
	char buffer[MAX_SIZE][LINE_LEN];
	int i=0;
	FILE *fp=fopen(PATH,"r");
	fgets(buffer[i],LINE_LEN,fp); //for skiping first line, it is not neccessary,
	if (fp==NULL) return;
	while(fgets(buffer[i],LINE_LEN,fp)){
		i++;
		if (fp==NULL) break;
	}
	fclose(fp);
	seperate_string(buffer);
}

void seperate_string(char buffer[MAX_SIZE][LINE_LEN]){
	char game[MAX_SIZE][GAME_LEN], genre[MAX_GENRE][GENRE_LEN], platform[MAX_PLATFORM][PLATFORM_LEN];
	char temp_g[GENRE_LEN],temp_p[PLATFORM_LEN],junk[20];
	float data[MAX_SIZE][7]; //INDEX ARE |#0=year|#1=na|#2=eu|#3=global|#4=user_score|#5=genre|#6=platform||
	int genre_ind=0,platform_ind=0,genre_check=1,platform_check=1,i=0;
	while (i<MAX_SIZE){
		sscanf(buffer[i],"%[^,],%[^,],%[^,],%f,%f,%f,%f,%f",game[i],temp_g,temp_p,&data[i][0],
												&data[i][1],&data[i][2],&data[i][3],&data[i][4]);
		if (data[i][3] ==0) //prevent not_avaliable values for global_sales<
			sscanf(buffer[i],"%[^,],%[^,],%[^,],%f,%f,%f,%[^,],%f",game[i],temp_g,temp_p,&data[i][0],
												&data[i][1],&data[i][2],junk,&data[i][4]);
		//assign index value to data of genres	
		for (int j=0; j<genre_ind; j++){
			if(strcmp(genre[j],temp_g)==0){ genre_check=0; //if this genre already readed, assign check value to 0,
			data[i][5]=j;	break;} //when if block executed, assign last j value to data and break the loop
			else genre_check=1;} //if if-block never executed, assign check value to 1}
		if (genre_check==1){ //if this value was not in the array
			strcpy(genre[genre_ind],temp_g);  //copy the context of the temp value to main value
			data[i][5]=genre_ind; genre_ind++;} //assign index value to data value and increment index}
		//assign index value to data of platforms, same things like genre.
		for (int j=0; j<platform_ind; j++){
			if(strcmp(platform[j],temp_p)==0){ platform_check=0; 
			data[i][6]=j;	break;}
			else platform_check=1;}
		if (platform_check==1){
			strcpy(platform[platform_ind],temp_p); 
			data[i][6]=platform_ind; platform_ind++;}
		i++; //increment the value of i each time.
	}

	//!!!OPERATIONS STARTS HERE!!!
	int choice;
	while (1){
		printf("\nPlease select an operation:");
		if(scanf(" %d",&choice)!=1){ printf("It is not an int\n"); return;} //if user enter a value without int, it gives error.
		switch (choice){
			case 0:list_of(genre,genre_ind); break;			
			case 1:list_of(platform,platform_ind); break;
			case 2:list_due_to_years(game,data); break;
			case 3:game_info(game,genre,platform,data); break;
			case 4:avarage_score(data); break;
			case 5:poplarity(game,data); break;
			case 6:frequence_of(genre,data,genre_ind,5); break;
			case 7:frequence_of(platform,data,platform_ind,6); break;
			case 8:printf("Gooodbyeee My frieendd!!!\n"); return;
			default:printf("Invalid Operation, TRY AGAIN!\n"); break;	
		}
	}
}

void list_of(char genre[MAX_GENRE][GENRE_LEN],int genre_num){	for (int i=0; i<genre_num; i++) printf("%s\n",genre[i]); }

void list_due_to_years(char game[MAX_SIZE][GAME_LEN],float data[MAX_SIZE][7]){
	float year; int choice;
	while (1){
		printf("Enter a year:");
		scanf(" %f",&year);
		if (year<MIN_YEAR || year>MAX_YEAR){printf("This year is not in range, TRY AGAIN!\n"); continue;} //works if user input is in invalid range
		printf("Until (0) or since (1) %.f:",year);
		scanf(" %d",&choice);
		if (!(choice ==0 || choice ==1)){ printf("Invalid Operation, TRY AGAIN!\n"); continue;} //if input is invalid
		if ((year <=MIN_YEAR && choice==0)||(year >=MAX_YEAR && choice==1)){printf("There is no game, TRY AGAİN!\n"); continue;} //if user enter invalid renge of year, it will ask again
		break;}
	for (int i=0; i<MAX_SIZE; i++){ //checks each game year and prints due to condition
		if (choice==0 && data[i][0]<year){printf("Year:%.f\tGame:%s\n",data[i][0],game[i]);}
		if (choice==1 && data[i][0]>year){printf("Year:%.f\tGame:%s\n",data[i][0],game[i]);}
	}
}

void game_info(char game[MAX_SIZE][GAME_LEN], char genre[MAX_GENRE][GENRE_LEN], char platform[MAX_PLATFORM][PLATFORM_LEN],float data[MAX_SIZE][7]){
	char choice[GAME_LEN];
	printf("Chosa a game:");
	scanf(" %s",choice);
	for (int i=0; i<MAX_SIZE; i++){ //search every game for same name. pick the first match.
		int genre_ind=data[i][5],platform_ind=data[i][6]; //convert floats value to int for use as array index
		if (strcmp(game[i],choice)==0){
			if (data[i][3]==0){ //for printing not avaliable value.
				printf("Name:\t\t%s\nGenre:\t\t%s\nPlatform:\t%s\nYear:\t\t%.f\nSales In NA:\t%.5f\nSales In EU:\t%.5f\nTotal Sales:\tNot Available\nUser Score:\t%.5f\n"
				,game[i],genre[genre_ind],platform[platform_ind],data[i][0],data[i][1],data[i][2],data[i][4]); return;}
			else{
				printf("Name:\t\t%s\nGenre:\t\t%s\nPlatform:\t%s\nYear:\t\t%.f\nSales In NA:\t%.5f\nSales In EU:\t%.5f\nTotal Sales:\t%.5f\nUser Score:\t%.5f\n"
				,game[i],genre[genre_ind],platform[platform_ind],data[i][0],data[i][1],data[i][2],data[i][3],data[i][4]); return;}
		}
	}printf("Invalid game name %s\n",choice); game_info(game,genre,platform,data); //if user input is not match, return to funciton
}

void avarage_score(float data[MAX_SIZE][7]){
	float total=0;
	for (int i=0; i<MAX_SIZE; i++){
		total+=data[i][4]; //#4 means user_scores, add all of them
	}printf("Avarage is %f\n",total/MAX_SIZE);
}

void poplarity(char game[MAX_SIZE][GAME_LEN], float data[MAX_SIZE][7]){
	char choice[GAME_LEN];
	printf("Chosa a game:");
	scanf(" %s",choice);
	for (int i=0; i<MAX_SIZE; i++){
		if (strcmp(game[i],choice)==0){
			if (data[i][1]>data[i][2]) {printf("Game:%s\nNA Sales %.4f\nEU Sales %.4f\nThis game was more populer in North America",game[i],data[i][1],data[i][2]); return;}
			else if (data[i][1]<data[i][2]) {printf("Game:%s\nNA Sales %.4f\nEU Sales %.4f\nThis game was more populer in Europe",game[i],data[i][1],data[i][2]); return;}	
			else if (data[i][1]>data[i][2]) {printf("Game:%s\nNA Sales %.4f\nEU Sales %.4f\nThis game had equal popularity in North America and Europa",game[i],data[i][1],data[i][2]); return;}
		}
	}printf("Invalid game name %s\n",choice); poplarity(game,data); //if user input is not match, return to funciton
}

void frequence_of(char g_p[MAX_GENRE][PLATFORM_LEN], float data[MAX_SIZE][7],int number_ind, int choice){
	int counter=0;
	for (int i=0; i<number_ind; i++){
		counter=0;
		for (int j=0; j<MAX_SIZE; j++){
			if(data[j][choice]==i) counter++;
		}
		if (strlen(g_p[i])<=7) printf("%s\t\t%d\n",g_p[i],counter ); //when string size is bigger then 7, terminal does not showes weell.
		else printf("%s\t%d\n",g_p[i],counter );
	}
}