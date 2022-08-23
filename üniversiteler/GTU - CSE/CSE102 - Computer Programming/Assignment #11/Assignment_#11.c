#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <time.h>
#include <math.h>


#define N 100000 //Change this acording to the size of the file.
#define PATH "list.txt"

typedef struct nodes {
	int data;
	struct nodes * next;
}node;

typedef struct differents{
	int n1,n2;
}different;



void array_part();
void linked_part();
int * read_array(char *filename,int *count,  double *time_taken);
float * stats_array(int *arr, int count,  double *time_taken);
node * read_linkedlist(char *filename, int *count, double *time_taken);
float * stats_linkedlist(node *root, int count, double *time_taken);
void free_linked(node *root);
void time_taken();
void part_2();
node * insert(node *head, int num);
different * compare(node *head, int * arr,int counter, int *count_dif);
void print_arr(int *arr,int counter);
void print_linked(node *head);


int main(void){
	array_part();
	linked_part();
	time_taken();
	printf("\n\nPart 2 starting!!!\n");
	part_2();

}

void array_part(){
	int *arr,count;
	float *stats_dynamic;
	double a,b;

	arr=read_array(PATH,&count,&a);
	stats_dynamic=stats_array(arr,count,&b);

	printf("-------------------------------------------------\n");
	printf("For (*read_array)\n");
	printf("Number of byte used:%ld\n",count * sizeof(int));
	printf("Min\tMax\t\tMean\t\tSTD\n" );
	printf("%.2f\t%.2f\t%.2f\t%.2f\n",stats_dynamic[0],stats_dynamic[1],stats_dynamic[2],stats_dynamic[3] );
	printf("-------------------------------------------------\n\n");
	free(arr); //we do not need this veriable anymore, so free it
	free(stats_dynamic);
}

void linked_part(){
	int count_linked; //keep count of numbers 
	node *root=NULL; 
	float *linked_stats;
	double a,b;

	root=read_linkedlist(PATH,&count_linked,&a);
	linked_stats=stats_linkedlist(root,count_linked,&b);

	printf("-------------------------------------------------\n");
	printf("For (*read_linkedlist)\n");
	printf("Number of byte used:%ld\n",count_linked * sizeof(node));
	printf("Min\tMax\t\tMean\t\tSTD\n" );
	printf("%.2f\t%.2f\t%.2f\t%.2f\n",linked_stats[0],linked_stats[1],linked_stats[2],linked_stats[3] );
	printf("-------------------------------------------------\n\n");
	free(linked_stats);
	free_linked(root);
}

void time_taken(){
	int *arr,count,count_linked;
	float *stats_dynamic,*linked_stats;
	node *root=NULL;

	double  t1, temp1=0, //passed time variables for (*read_array)
			t2, temp2=0, //passed time variables for (*stats_array)
			t3, temp3=0, //passed time variables for (*read_linkedlist)
			t4, temp4=0; //passed time variables for (*stats_linked)
		
		
	/*take average time passed  for four times*/
		arr=read_array(PATH,&count,&t1);
		stats_dynamic=stats_array(arr,count,&t2);	
		temp1+=t1;
		temp2+=t2;
		free(arr);
		free(stats_dynamic);
		

		root=read_linkedlist(PATH,&count_linked,&t3);
		linked_stats=stats_linkedlist(root,count_linked,&t4);
		temp3+=t3;
		temp4+=t4;
		free_linked(root);
		free(linked_stats);

		root=read_linkedlist(PATH,&count_linked,&t3);
		linked_stats=stats_linkedlist(root,count_linked,&t4);
		temp3+=t3;
		temp4+=t4;
		free_linked(root);
		free(linked_stats);

		arr=read_array(PATH,&count,&t1);
		stats_dynamic=stats_array(arr,count,&t2);	
		temp1+=t1;
		temp2+=t2;
		free(arr);
		free(stats_dynamic);

		arr=read_array(PATH,&count,&t1);
		stats_dynamic=stats_array(arr,count,&t2);	
		temp1+=t1;
		temp2+=t2;
		free(arr);
		free(stats_dynamic);

		root=read_linkedlist(PATH,&count_linked,&t3);
		linked_stats=stats_linkedlist(root,count_linked,&t4);
		temp3+=t3;
		temp4+=t4;
		free_linked(root);
		free(linked_stats);

		arr=read_array(PATH,&count,&t1);
		stats_dynamic=stats_array(arr,count,&t2);	
		temp1+=t1;
		temp2+=t2;
		free(arr);
		free(stats_dynamic);

		root=read_linkedlist(PATH,&count_linked,&t3);
		linked_stats=stats_linkedlist(root,count_linked,&t4);
		temp3+=t3;
		temp4+=t4;
		free_linked(root);
		free(linked_stats);

	
	if (temp1!=0) {temp1/=4;} if (temp2!=0) {temp2/=4; }
	if (temp3!=0) {temp3/=4;} if (temp4!=0) {temp4/=4; }
	printf("Average Time (Calculated 4 time) passed in (*read_array)\t %lf(s) \n",temp1);
	printf("Average Time (Calculated 4 time) passed in (*stats_array)\t %lf(s) \n",temp2 );
	printf("Average Time (Calculated 4 time) passed in (*read_linkedlist)\t %lf(s) \n",temp3);
	printf("Average Time (Calculated 4 time) passed in (*stats_linkedlist)\t %lf(s) \n",temp4 );
}

int * read_array(char *filename, int *i, double *time_taken){
	clock_t start, end;
	
	start = clock();

	FILE *fp=fopen(filename, "rb");
	if (fp==NULL){ printf("File does not exist\n"); *i=0; return 0;  }
	int a=0,counter=1;

	int *arr;
	arr=(int*)malloc(counter*N*sizeof(int));

	while(fscanf(fp,"%d,",&arr[a]) == 1){
		a++;
		/* When all allocated memory is filed, do this */
		if (counter*N<=a){
			counter++;
			arr=(int*)realloc(arr,counter*N*sizeof(int));
		}
		
	}
	fclose(fp);
	/* If array size bigger than input size, realloc array to input size */
	if (a < counter*N) arr=(int*)realloc(arr,a*sizeof(int)); //it provides unncessary allocation.
	*i=a; //returns how many numbers in this file

	end=clock();
	*time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	return arr;
}

float * stats_array(int *arr, int count, double *time_taken){
	clock_t start, end;
	
	start = clock();

	float *stats=(float*)malloc(4*sizeof(float));
	float temp=0; //keeps sum of totals for std calculation
	stats[0]=arr[0]; //min
	stats[1]=0; 	 //max

	for (int i=0; i<count; i++){
		stats[2]+=arr[i]; //finds mean
		if (stats[0] > arr[i] )
			stats[0]=arr[i];
		else if (stats[1] < arr[i])
			stats[1]=arr[i];
	}
	stats[2]/=count; //mean
	for (int i=0; i<count; i++){
		temp+= (stats[2]-arr[i])*(stats[2]-arr[i]);
	}
	stats[3]= sqrt(temp/(count)); //final std calculation
	
	end=clock();
	*time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	return stats;
}

node * read_linkedlist(char *filename, int *count,  double *time_taken){
	clock_t start, end;
	
	start = clock();

	FILE *fp=fopen(filename, "rb");
	if (fp==NULL){ printf("File does not exist\n"); *count=0; return NULL;  }

	int a=0; //counts number of inputs
	node *iter=NULL;
	node *root=NULL;

	iter=(node*)malloc(sizeof(node));
	iter->next=root;
	root=iter;

	while(fscanf(fp,"%d,",&iter->data)==1){
		a++;
		iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;
	}

	iter=root;
	
	fclose(fp); //close the file
	node *head=root;
	
	*count=a; //for returning number of inputs

	end=clock();
	*time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

	return head;
}

float * stats_linkedlist(node *head, int count, double *time_taken){
	clock_t start, end;
	
	start = clock();
	node *root=head;
	node *root2=head;
	float *stats=(float*)malloc(4*sizeof(float));
	float temp=0; //keeps sum of totals for std calculation
	stats[0]=root->data; //min
	stats[1]=0; 		 //max


	while(root->next!=NULL){
		stats[2]+=root->data;
		if (stats[0]>root->data)
			stats[0]=root->data;
		if (stats[1]<root->data)
			stats[1]=root->data;
		root=root->next;
	}

	stats[2]/=count; //mean
	while(root2->next!=NULL){
		temp+= (stats[2]-root2->data) * (stats[2]-root2->data);
		root2=root2->next;
	}
	stats[3]= sqrt(temp/(count)); //final std calculation

	end=clock();
	*time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

	return stats;
}

void free_linked(node *root){
	node *head=root;
   while (head){
   	node *tmp=head;
   	head=head->next;
   	free(tmp);
   }
    
    return;
}

void part_2(){
	int *arr;
	node *head=NULL;
	int counter=1,input=1,count_dif=0;
	different *dif;


	arr=(int*)malloc(sizeof(int));
	/*Fill array with inputs */
	printf("'q' for stop entering new number\n");
	printf("Input:");
	while (scanf(" %d",&input)==1){
		printf("Input:");
		arr[counter-1]=input;
		counter++;
		arr=(int*)realloc(arr,counter*sizeof(int));
	}
	getchar(); //there is invalid value from scanf, it catches it

	counter-=2; //make counter useable
	printf("You are entered %d num for the Dynamic Array list\nEnter %d num for the Linked list\n",counter,counter );

	/*Fill linked list with inputs */
	for (int i=0; i<counter; i++){
		printf("Input:");
		scanf(" %d",&input);
		head=insert(head,input);
	}
	/* Print lists */
	print_arr(arr,counter);
	print_linked(head);


	node *temp_head=head;
	dif=compare(temp_head,arr,counter,&count_dif);

	printf("There are %d different num in the lists\nDifferent Number is showed below area.\n",count_dif );
	printf("Difference In Dynamic Array list: ");
	for (int i=0; i<count_dif; i++){
		printf(" %d",dif[i].n1 );
	}printf("\n");
	printf("Difference In Linked list:        ");
	for (int i=0; i<count_dif; i++){
		printf(" %d",dif[i].n2 );
	}printf("\n");

	free(arr);
	free(dif);
	free_linked(head);
}

node * insert(node *head, int num){
	node *new = (node *) malloc(sizeof(node));
    new->data = num;
    new->next = NULL;

    //if head is null execute
    if (head == NULL){
        head = new;
    } 
    else{
        node *current = head;

        while (current->next != NULL){
            current = current->next;
        }
        current->next = new;
    }

    return head;
}

different * compare(node *head, int * arr,int counter, int *count_dif){
	different *dif;
	int diff_num=1;

	for (int i=0; i<counter; i++){
		if (arr[i]!=head->data){

			dif=(different*)realloc(dif,diff_num*sizeof(different));
			dif[diff_num-1].n1=arr[i];
			dif[diff_num-1].n2=head->data;
			diff_num++;
		}

		head=head->next;
	}

	*count_dif=diff_num-1;
	return dif;
}

void print_arr(int *arr,int counter){
	printf("Dynamic array:{ ");
	for (int i=0; i<counter; i++) printf("%d ",arr[i] );
	printf("}\n");
}

void print_linked(node *head){
	printf("Linked list  :{ ");
	node *print=head;
	while(print){
		printf("%d ",print->data );
		print=print->next;
	}printf("}\n");
}