#include <stdio.h>
#include <math.h>
#include <string.h>

#define SIZE 500 //recomended array size for part 1
#define N 8 
#define SHOW_HOFSTADTERS 0//when it is 1, it shows the content of the hofstadters nums.
#define STAGES 0 //when it is 1, it shows the table of stages for each possiblity,
#define LOOP_PIPE 10 //it shows how many time it calculate combination of the pipes.
#define MAX_STR_SZ 500 //size of the string in part 3

void part1_menu(); //menu of the part 1
void generate_hofstadters_sequence (int *arr,int n);
int find_max (int arr[], int index, int max_value);
int sum_array (int arr[]);
double std_array (int arr[], double *mean, int n, int index);
void menu();
void install_pipes (int visited[N][N], int x, int y, int orientation, int counter);
char* remove_duplicates (char* str);

int main(void){
	menu();

}

void part1_menu(){
	int choice=0,n=0,max_value=1,sum;
	double std,mean;
	int arr[SIZE]={ 0 }; //fill array with Zero's
	printf("\nPlease Make Your Choice\n------------\n1) Fill Array\n2) Find Biggest Number\n3) Calculate Sum\n4) Calculate Standart Deviation\n5) Exit\n");
	while(choice!=5){
		scanf(" %d",&choice);
		switch (choice){
			case 1: for (int i=0; i<SIZE-1; i++) arr[i]=0; mean=0; //whenewer user choice 1, it resets values.
				printf("Enter a number:"); scanf(" %d",&n);
				generate_hofstadters_sequence(arr,n-1); 
				if (SHOW_HOFSTADTERS==1){
					for (int i=0; i<n; i++) printf("%d ",arr[i] ); //not neccessary, just somehow see for content.
				}break;
			case 2:max_value= find_max(arr,0,max_value); printf("Max Value:%d\n",max_value ); break;
			case 3: sum=sum_array(arr); printf("Sum:%d\n",sum ); break;
			case 4:std = std_array(arr,&mean,n,n); printf("Std:%lf Mean %lf\n",std,mean ); break;
			case 5:printf("Goodbye...!!!<3<3\n"); break;
			default:printf("Invalid Operation\n"); break;
		}
	}
}

void generate_hofstadters_sequence (int *arr,int n){
	arr[0]=arr[1]=1;
	if (n==1) //when n equels 1, execute
		return;
	else{
		if(arr[n-1]==0 || arr[n-2]==0) 
			generate_hofstadters_sequence(arr,n-1);
		arr[n]=arr[n-arr[n-1]] + arr[n- arr[n-2]];
	}
}

int find_max (int arr[], int index, int max_value){
	if (arr[0]==0) {printf("First fill the array!!!\n"); return 0; } //if first element is 0, it means the array is not filled.
	if (max_value < arr[index])
		max_value = arr[index];
	if (arr[index+1]!=0) //if next char is not filled with zero, execute
		find_max(arr,index+1,max_value);
	else
		return max_value;		
}

int sum_array (int arr[]){
	if (arr[0]==0) {printf("First fill the array!!!\n"); return 0; } //if first element is 0, it means the array is not filled.
	if (arr[1]==0) //check if next index is filled zero, execute
		return *arr;
	else
		return *arr+sum_array(arr+1);
}

double std_array (int arr[], double *mean, int n, int index){
	double flag;
	if (arr[0]==0) {printf("First fill the array!!!\n"); return 0; } //if first element is 0, it means the array is not filled.
	if (n>0){
		*mean+=(arr[n-1]/1.0)/(index/1.0); //calculate mean
		std_array(arr,mean,n-1,index);     //discrement n value

		if (n==index){ //when n equel index do this part
			flag =std_array(arr,mean,0,0); //it assign n value to 0, so it skips first if and does other parts.
			return sqrt(flag/(n-1)); //return std formula
		}
	}

	flag=pow(arr[index]-*mean,2); //calculate this for std formula
	if (arr[index+1]==0) //when items are out, return
		return flag;
	else{
		flag+=std_array(arr,mean,0,index+1); //increment index value and leave n value with 0
		return flag;
	}
}

void menu(){
	printf("Welcome to Excellent HW8");
	int choice=0,garbage;
	int visited[N][N]={ 0 };
	char str[MAX_STR_SZ];
	while (choice!=4){
		printf("\nPlease chose one of this\n1) Execute part 1\n2) Execute part 2\n3) Execute part 3\n4) Exit\n");
		scanf(" %d",&choice);
		switch(choice){
			case 1:part1_menu(); break;
			case 2:install_pipes(visited,0,0,1,1); printf("\n"); break;
			case 3:printf("Enter a word:");
					scanf("%d",&garbage); //for fgets to catch next input.
					fgets(str, MAX_STR_SZ, stdin); //I used this, because scanf does not detect white spaces.
					remove_duplicates(str);
					printf("%s\n",str ); break;
			case 4:printf("Goodbyee!!<<33\n"); break;
			default:printf("Invalid Operation\n"); break;
		}
	}
}

void install_pipes (int visited[N][N], int x, int y, int orientation, int counter){
	/*
	for all options, this function checks and if it is suitable
	it detects and write on it.
	*/
	if (visited[y+2][x+1]==0 && x+1 < 8 && y+2 < 8 && x+1 >= 0 && y+2 >= 0){ 
		visited[y][x]=orientation;
		printf("01,");
		install_pipes(visited,x+1,y+2,orientation+1,counter);
	}
	else if (visited[y+1][x+2]==0 && x+2 < 8 && y+1 < 8 && x+2 >= 0 && y+1 >= 0){
		visited[y][x]=orientation;
		printf("05,");
		install_pipes(visited,x+2,y+1,orientation+1,counter);
	}
	else if (visited[y-1][x+2]==0 && x+2 < 8 && y-1 < 8 && x+2 >= 0 && y-1 >= 0){
		visited[y][x]=orientation;
		printf("04,");
		install_pipes(visited,x+2,y-1,orientation+1,counter);
	}
	else if (visited[y+1][x-2]==0 && x-2 < 8 && y+1 < 8 && x-2 >= 0 && y+1 >= 0){
		visited[y][x]=orientation;
		printf("02,");
		install_pipes(visited,x-2,y+1,orientation+1,counter);
	}
	else if (visited[y-2][x-1]==0 && x-1 < 8 && y-2 < 8 && x-1 >= 0 && y-2 >= 0){
		visited[y][x]=orientation;
		printf("03,");
		install_pipes(visited,x-1,y-2,orientation+1,counter);
	}
	else if (visited[y-2][x+1]==0 && x+1 < 8 && y-2 < 8 && x+1 >= 0 && y-2 >= 0){
		visited[y][x]=orientation;
		printf("08,");
		install_pipes(visited,x+1,y-2,orientation+1,counter);
	}
	else if (visited[y+2][x-1]==0 && x-1 < 8 && y+2 < 8 && x-1 >= 0 && y+2 >= 0){
		visited[y][x]=orientation;
		printf("06,");
		install_pipes(visited,x-1,y+2,orientation+1,counter);
	}
	else if (visited[y-1][x-2]==0 && x-2 < 8 && y-1 < 8 && x-2 >= 0 && y-1 >= 0){
		visited[y][x]=orientation;
		printf("07,");
		install_pipes(visited,x-2,y-1,orientation+1,counter);
	}
	else{ //if possible areas are finished, it will create new array and do this things again.
	printf("\nThat was %d.chance\n",counter );
	if (STAGES==1){ //it is not neccessary, for showing the table of stages.
		for (int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				printf("%d\t",visited[i][j] );
				}printf("\n");
			}
	}
	if (counter==LOOP_PIPE) //if it will equal LOOP_PİPE it will return, it is 10 originally acording to the moodle page.
		return;
	counter++; //increment each time
	int visited[N][N]={ 0 }; //recreate the func for do things right
	if (counter<LOOP_PIPE-3)
		install_pipes(visited,x-1,y-1,1,counter); //discrement x and y for new locations. do not change other values like in menu func.
	else
		install_pipes(visited,x+2,y+2,1,counter); //increment x and y this time, because sometimes it may give same results.
	}
}

char* remove_duplicates (char* str){
	if (str[0]=='\0')
		return str;
	if (str[0]==str[1])//if there is a equality it copies to content of the incremented string
		strncpy(str,str+1,strlen(str)); 
	remove_duplicates(str+1); //I wrote it twice otherwise it only
	remove_duplicates(str+1); //delete duplicate char
}