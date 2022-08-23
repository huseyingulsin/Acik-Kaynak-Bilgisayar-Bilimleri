#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define HOSPITAL_INFORMATION { {"1",{'C', 'E', 'F'}} , {"2",{'A', 'C', 'D'}} , {"3",{'B', 'F'}} ,  {"4",{'A','B','C'}}  } //for -> Hospital hospitals[4]
#define CITIES_INFORMATION  {'A','B','C','D','E','F'} //for -> cities[6]
#define LOCATION_INFORMATION  { {'A', 'B', 'C'}, {'A', 'C', 'D'}, {'B', 'F'}, {'C', 'E', 'F'} } //for -> locations[4][3]

struct Hospital{
char* name;
char citiesServed[3];
};

struct card{
char face[20];
char suit[20];
};

void menu(); //My menu function
void ali_decision(); //My menu func for part 1
int numPathsHome(int street, int avenue); //Part 1 expected function
void valid_hospital();
int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4]);
void mix_cards(struct card cards[52], int index);


int main(void){
	menu();
	
	return 0;
}



void menu(){
	srand(time(NULL));
	int choice=0;
	struct card cards[52];
	printf("Welcome to Perfect HW9 solutions from Muhammed Oguz\n");
	while (choice!=4){
		printf("\n1) Run part 1\n2) Run part 2\n3) Run part 3 \n4) Exit\nMake your choice:");
		scanf(" %d",&choice);
		switch(choice){
			case 1:ali_decision(); break;
			case 2:valid_hospital(); break;
			case 3:mix_cards(cards,0); break;
			case 4:printf("Gooddbyeee!!!!\n"); break;
			default:printf("Invalid Operation Try Again!!\n"); break;
		}
	}
}

void ali_decision(){
	int street,avenue;
	printf("Welcome to part 1, Ali's decision\n");
	printf("Enter the street number:");	scanf(" %d", &street);
	printf("Enter the avenue number:");	scanf(" %d", &avenue);
	printf("Ali can use %d different path to go to his home\n",numPathsHome(street,avenue) );
}

int numPathsHome(int street, int avenue){
	//Ali's home at 1,1 point so whatewer street or 
	//avenua value equals 1, function returns 1

	if (avenue == 1) //when avenue equals 1, return 1
		return 1;
	if (street == 1) //when street value equals 1, return 1
		return 1;
	int path_num = numPathsHome(street-1,avenue) + numPathsHome(street,avenue-1);
	return path_num;
}

void valid_hospital(){
	struct Hospital hospitals[4]= HOSPITAL_INFORMATION;
	char cities[6] =CITIES_INFORMATION;
	char locations[4][3] =LOCATION_INFORMATION;
	int numhospital=0,value=0;
	printf("Enter the max number of hospital:");
	scanf(" %d", &numhospital);

	value=canOfferCovidCoverage(cities,locations,numhospital-1,hospitals);
	if (value ==0)
		printf("No, some cities are not covered. :(\n");
	else{
		printf("Good Job, all cities covered\n");
		for (int i=0; i<numhospital; i++)
			printf("Hospital: %s\nHospital Localtions %s\n",hospitals[i].name,hospitals[i].citiesServed );
	}
}

int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4]){
	int return_check=1,return_value=0;
	for (int i=0; i<6; i++){ //it checks if all cities covered.
		if (_cities[i]!=0) //if not, return_check value is 0
			return_check=0;
	}
	if (return_check==1)
		return return_check;
	
	if (_numHospitals==-1) //when number of hospital equals -1 return 0
		return 0;
	
	//create a new array for covered cities, 
	//when hospital location and cities are matched,
	//initalize the array with those chars 
	char checked_cities[6]={ 0 };
	int a=0,check=1;
	for (int i=0; i<6; i++){
		for (int j=0; j<3; j++){
			if (_cities[i]==results[_numHospitals].citiesServed[j]){
				check=0;
				break;
			}
		}
		if (check==0){
			checked_cities[a]=_cities[i];
			a++;
			check=1;
		}
	}


	canOfferCovidCoverage(checked_cities,_locations,_numHospitals-1,results); //recursion part.
}

void mix_cards(struct card cards[52], int index){
	int check=0;
	if (index==52)
		return;

	switch (rand()%4){
		case 0: strcpy(cards[index].face,"Hearts"); break;
		case 1: strcpy(cards[index].face,"Diamonds"); break;
		case 2: strcpy(cards[index].face,"Clubs"); break;
		case 3: strcpy(cards[index].face,"Spades"); break;
	}
	switch (rand()%13){
		case 0: strcpy(cards[index].suit,"Ace"); break;
		case 1: strcpy(cards[index].suit,"Deuce"); break;
		case 2: strcpy(cards[index].suit,"Three"); break;
		case 3: strcpy(cards[index].suit,"Four"); break;
		case 4: strcpy(cards[index].suit,"Five"); break;
		case 5: strcpy(cards[index].suit,"Six"); break;
		case 6: strcpy(cards[index].suit,"Seven"); break;
		case 7: strcpy(cards[index].suit,"Eight"); break;
		case 8: strcpy(cards[index].suit,"Nine"); break;
		case 9: strcpy(cards[index].suit,"Ten"); break;
		case 10: strcpy(cards[index].suit,"Jack"); break;
		case 11: strcpy(cards[index].suit,"Queen"); break;
		case 12: strcpy(cards[index].suit,"King"); break;
	}

	for (int i=0; i<index; i++){
		if (strcmp(cards[index].face, cards[i].face) == 0 && strcmp(cards[index].suit, cards[i].suit) == 0){
			check=1;
			break;
		}
	}

	if (check==1) //if check is 1, it means there is same value 
		mix_cards(cards,index);
	
	else {
		if (index%2==0){ //if index is even num, print like this, it is for beauty in terminal
			printf("%5s of %-8s\t",cards[index].suit , cards[index].face );
			mix_cards(cards,index+1);
			}
		else {
			printf("%5s of %-8s\n",cards[index].suit , cards[index].face );
			mix_cards(cards,index+1);
		}
	}
}

