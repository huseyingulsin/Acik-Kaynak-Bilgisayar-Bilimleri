#include <stdio.h>

void menu(); //expected function #1
void read_news(char buffer[500],char file_path[10], int is_Only_Title); //expected function #2
void append_file(char* file_path, char c); //expected function #3
void read_magic_numbers(char buffer_magic[10],char buffer_news[500]); //expected function #4
double g_func(double f(int x),int a); //expected function #5
double f_func(int x); //expected function 6
void print_news_title(); //only write news title, helper function
void print_news_context(char txt);//write news whole context, helper function
void check_readed(char txt); //check if this new is readed or not, helper function
void list_readed_news(); //list readed news as said in function nmae :D, helper function
int wanna_continue(); //ask for yes or no, helper function
void decprted_massage(char txt); //helper function

#define PATH "%d.txt" //file directory on my PC (ubuntu).

/*NOTE 1:
Eger PATH == news/%d.txt olursa aşşağıdaki uyarıları almaktayım,
Ancak çalışırken herhangi bir sıkıntı çıkarmamakta
Sanırım sprintf sahip olabileceği byte sayılarıyla alakalı. 

warning: ‘sprintf’ writing a terminating nul past the end of the destination [-Wformat-overflow=]
note: in expansion of macro ‘PATH’
note: ‘sprintf’ output between 11 and 21 bytes into a destination of size 10 */

/*NOTE 2:
If readed_news_id.txt is not created in directory, some error occures, like segmentation fault (core dump). */

int main(void){
	menu();
}

void menu(){
	printf("Welcome to The Daily Bugle\n");
	printf("------------Daily Press------------\n");
	print_news_title(); //prints news title 
	int check=1;
	char choice,txt;
	while (check){
		printf("\n\nWhat do you want to do?\na.Read a new\nb.List the readed news\nc.Get decpryted information from the news\nd.exit\n");
		scanf(" %c",&choice);
		switch (choice){
			case 'a':printf("Which news do you want to read?\n");
					scanf(" %c",&txt);
					check_readed(txt);
					break;
			case 'b':list_readed_news();
					break;
			case 'c':printf("Which news would you like to decrypt?\n");
					scanf(" %c",&txt);
					decprted_massage(txt);
					break;
			case 'd':printf("Goodbyeee\n");
					return;
			default:printf("Invalid Operation\n");
					break;
		}printf("\nFor Menu ");
		check=wanna_continue(); //for yes assign 1, for no assign 0
		}printf("Goodbyeee\n"); //if wanna_continue chosed no, print goodbye
}


void read_news(char buffer[500], char file_path[10], int is_Only_Title){
	FILE *fp=fopen(file_path,"r");
	char line_buffer[100]; //I chose line size 100,
	fscanf(fp,"%[^\n]",line_buffer); //scan only first line
	if (is_Only_Title==1){
	printf("%s\n",line_buffer);}
	else if(is_Only_Title==0){
		printf("\n%s\n\n",line_buffer);
		while(fscanf(fp,"%s",buffer)!=EOF){ //scan whole file
			printf("%s ",buffer);
		}
	}
	fclose(fp);
}

void print_news_title(){
	char file_path[10],buffer[500];
	for (int i=1; i<=4; i++){
		printf("Title of the %d. news:",i);
		sprintf(file_path,PATH,i); //increment numeratic value in string with sprintf
		read_news(buffer,file_path,1); //CHECK THIS IN UBUNTU
	}
}

void print_news_context(char txt){
	int txt_num=txt-'0'; //convert char value to int value depend on the ascii table
	char file_path[10],buffer[500];
	sprintf(file_path,PATH,txt_num); //send a int value to a string
	read_news(buffer,file_path,0);
}

int wanna_continue(){
	char c;
	printf("Do you want to continue Yes(y)/No(n)\n");
	scanf(" %c",&c);
	switch(c){
		case 'y':return 1;
		case 'n':return 0;
		 default:printf("Invalid Operation\n");
				wanna_continue();
				break;
	}
}

void append_file(char* file_path, char c){
	FILE *fp=fopen(file_path,"a");
	fprintf(fp,"%c",c);
	fclose(fp);
}

void check_readed(char txt){
	FILE *fp=fopen("readed_news_id.txt","r");
	char check;
	int control=2; //set control variable value to 2
	while (fscanf(fp,"%c",&check)!=EOF){
		if(check==txt){
			printf("This new is readed, For reading ");
			control=wanna_continue(); //if answer is yes assign 1, if no assign 0 to control variable
			break;
		}
	}
	if (control==2){
		print_news_context(txt);
		append_file("readed_news_id.txt",txt);
	}
	else if(control ==1)
		print_news_context(txt);
	else if (control ==0)
		return;
}

void list_readed_news(){
	FILE *fp=fopen("readed_news_id.txt","r");
	char list;
	while (fscanf(fp,"%c",&list)!=EOF){
		printf("%c. news is readed\n",list);
	}
}

double f_func(int x){
	return (x*x*x)-(x*x)+2;
}

double g_func(double f(int x),int a){
	return f(a)*f(a);

}

void read_magic_numbers(char buffer_magic[10], char buffer_news[500]){
	FILE *fp=fopen(buffer_magic,"r");
	double total=0;
	int x;
	char check;
	while (fscanf(fp,"%c",&check)!=EOF){
		if (check=='#'){
			fscanf(fp,"%d",&x);
			x=g_func(f_func,x);
			total+=x;
		}
	}
	printf("%lf\n",total );
}

void decprted_massage(char txt){
	int txt_num=txt-'0'; //convert char value to int value depend on the ascii table
	char file_path[10],buffer[500];
	sprintf(file_path,PATH,txt_num); //send a int value to a string
	print_news_context(txt);
	switch (txt){
		case '1':printf("\nNumber of tests performed:");
				break;
		case '2':printf("\nNumber of sick people:");
				break;
		case '3':printf("\nNumber of deaths:");
				break;
		case '4':printf("\nExpected number of sick people:");
				break;
	}
	read_magic_numbers(file_path,buffer);
}
