#include <stdio.h>
#include <stdlib.h> //for rand() funciton
#include <math.h> //for sqrt() abs() and pow() function

void track_machine ();
void refresh_position (int *X, int *Y, double *D, double *R);
double distance_point(int x1,int y1,int x2,int y2); //calculate distance of 2 point
void track_machine_interface(int x, int y, double r, double d);

int main(void){
	track_machine();
}


void track_machine(){
	//in order to moodle page, I assume that starting point of enemy is (1,1)
	int x=1,y=1,check=1;
	double d=7.07,r=0,q; //while starting, distance to (1,1) to (6,6) = 7.07 so d=7.07
	char control;
	track_machine_interface(x,y,r,d); //create interface for track machine
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
