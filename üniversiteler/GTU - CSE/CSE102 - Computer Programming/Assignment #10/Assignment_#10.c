#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FILE_PATH "commands.txt" //path of commands
#define SIZE 100		 		//size of line in commands file
#define POLY_SIZE 20			//max size of each polygons data
#define CONVERT_DEGRE 180 /3.14159265 //for convertig radiant data to degree

typedef struct point{
	float x;
	float y;
}points;

typedef struct line{
	points point_1;
	points point_2;
}lines;

typedef struct polygon{
	int poly_num;
	points point[POLY_SIZE];
	lines line[POLY_SIZE];
}polygons;

typedef struct object{
	char name[3];
	points point;
	lines line;
	polygons polygon;
}objects;


void read_file(); 	//reads file
void data_operations(char data[SIZE][SIZE], int num_data, objects object[]); //fill struct with data inputs
void action_operations(char actions[SIZE][SIZE], int num_actions, char path[20], objects object[], int num_data); //execute function oreder to actions input
int check_type(char str[SIZE], int len, int *check_comment); //check tpyes for data
int check_action_type(char str[SIZE],int len); //check type for actions
float calc_distance(float x1, float y1, float x2, float y2); //calculate the distance two point
float calc_distance_line_point(float xa, float ya, float xb, float yb, float xc, float yc); //calculate the distance point to line 
float find_angle(float xa1, float ya1, float xa2, float ya2, float xb1, float yb1, float xb2, float yb2); //find angle between two line
float slope(float x1, float y1, float x2, float y2); //find slope a line, it neccesary for find_angle func
float find_area(int repeat, int type, polygons polygon); //find area a polygon

int main(void){
	printf("Reading File...\n");
	read_file();
	printf("Writing File...\n");
	printf("Succeed!!!\n");
}

void read_file(){
	FILE *fp= fopen(FILE_PATH, "r");
	char buffer_data[SIZE][SIZE], buffer_actions[SIZE][SIZE];
	char path_output[20];
	int num_data=0,num_actions=0; //keeps line size

	if (fp==NULL) { 
		printf("Can not find the file\n"); exit(1);
	}
	//Read all data input into buffer_data
	int i=0;
	while (fgets(buffer_data[i],SIZE,fp)) //find data for starting point.
		if (strncmp(buffer_data[i],"data",4)==0) //move curser until find string of "data"
			break;
	fscanf(fp," %d",&num_data); //read number of data
	fgets(buffer_data[i],SIZE,fp); //after fscanf there is a newline char, it skips this.
	for (i; i<num_data; i++)
		fgets(buffer_data[i],SIZE,fp);

	//Read all actions input into buffer_actions
	i=0; 
	while (fgets(buffer_actions[i],SIZE,fp))
		if (strncmp(buffer_actions[i],"actions",7)==0)
			break;
	fscanf(fp," %s",path_output); //read path of the output
	fscanf(fp," %d",&num_actions); //read number of actions
	fgets(buffer_actions[i],SIZE,fp); //after fscanf there is a newline char, it skips this
	for (i; i<num_actions; i++)
		fgets(buffer_actions[i],SIZE,fp);

	fclose(fp); //done with file
	objects object[num_data];
	data_operations(buffer_data, num_data, object); //fill struct and send to action operations
	action_operations(buffer_actions, num_actions, path_output, object, num_data);
}

void data_operations(char data[SIZE][SIZE], int num_data, objects object[]){
	int i=0,len=0;
	int check=0;
	char temp_point[2][2];
	char temp_poly[20][2],*token;
	while (i <num_data){
		len=strlen(data[i]);
		check=check_type(data[i],len,&object[i].polygon.poly_num);
		switch (check){
			case 1: //for Points
				sscanf(data[i],"%f %f %s",&object[i].point.x, &object[i].point.y, object[i].name);
				//printf("%f %f %s\n",object[i].point.x, object[i].point.y, object[i].name ); break;
			case 2: //for Lines
				sscanf(data[i],"%s %s %s",temp_point[0],temp_point[1],object[i].name);
				for (int j=0; j<num_data; j++){
					if (strncmp(temp_point[0],object[j].name,2)==0)
						object[i].line.point_1=object[j].point;
					else if (strncmp(temp_point[1],object[j].name,2)==0)
						object[i].line.point_2=object[j].point;
				}
				break;
			case 3: //for Poloygons with Points
				token=strtok(data[i]," "); //split string in order to white spaces
				for (int j=0; j<object[i].polygon.poly_num; j++){
					strncpy(temp_poly[j],token,2);
					token=strtok(NULL," ");		
				}
				strncpy(object[i].name,token,3); //copy the name of the polygon
				for (int j=0,count=0; j<num_data; j++){
					if (strncmp(temp_poly[count],object[j].name,2)==0){
						object[i].polygon.point[count]=object[j].point;
						count++;
					}
				}
				break;
			case 4: //for Polygons with lines
				token=strtok(data[i]," ");
				for (int j=0; j<object[i].polygon.poly_num; j++){
					strncpy(temp_poly[j],token,2);
					token=strtok(NULL," ");		
				}
				strncpy(object[i].name,token,3);
				for (int j=0,count=0; j<num_data; j++){
					if (strncmp(temp_poly[count],object[j].name,2)==0){
						object[i].polygon.line[count]=object[j].line;
						count++;
					}
				}
				//printf("%f %f %f %f %s\n",object[i].polygon.line[0].point_1.x,object[i].polygon.line[0].point_1.y,object[i].polygon.line[0].point_2.x, object[i].polygon.line[0].point_2.y, object[i].name );
				break;
			default: printf("There is something wrong!!!\n"); break;
		}
		i++;
	}
}

int check_type(char str[SIZE], int len, int *pg_size){
	int p=0,l=0,pg=0;
	*pg_size=0;
	
	for (int i=0; i<len; i++){
		if (str[i] == '/') break; //When see this, it means comment line, break
		if (str[i]=='P') p++; //When see a big P, increment p. P1 P2 etc..
		else if (str[i] =='L') l++; //When see a big L, increment l. L12, L23 etc..
		else if (str[i] == 'G') pg++; //When see a big G, increment pg++. PG1, PG2 etc..
	}
	//printf("p %d l %d pg %d\n",p,l,pg );
	if (p==1 && l!=1 && pg != 1) return 1; //it means point data
	else if (l==1 && p!= 1 && pg !=1) return 2; //it means line data
	else {
		if (p !=0 && l==0){ //it means polygon data with points
			*pg_size=p-1; //send number of inputes information
			return 3; 
			}
		else if (l != 0){ //it means polygon data with lines
			*pg_size=l; //send number of inputes information
			return 4;
			}
		}
}

void action_operations(char actions[SIZE][SIZE], int num_actions, char path[20], objects object[],int num_data){
	FILE *fp=fopen(path, "w"); //open file for writing
	int i=0;
	while (i<num_actions){
		int len=0,keep[2],poly_check_p=0,poly_check_l=0;
		float value=0;
		char temp[2][4];
		len=strlen(actions[i]);
		int check=check_action_type(actions[i],len);
		//printf("%s",actions[i] );
		switch (check){
			case 1: //distance between two points		
				sscanf(actions[i],"Distance %s %s", temp[0], temp[1]);
				for (int j=0,count=0; j<num_data; j++){
					if (strncmp(object[j].name,temp[0],3)==0){ //compare to find expected value
						keep[count]=j; count++;
					}
					if (strncmp(object[j].name,temp[1],3)==0){ //compare to find expected value
						keep[count]=j; count++;
					}
				}
				fprintf(fp,"Distance(%s,%s) = %.1f\n",object[keep[0]].name, object[keep[1]].name, calc_distance(object[keep[0]].point.x, object[keep[0]].point.y, object[keep[1]].point.x, object[keep[1]].point.y) );
				break;
			case 2: //distance between a line and a point
				sscanf(actions[i],"Distance %s %s",temp[0],temp[1]);
				//printf("%s %s\n",temp[0],temp[1] ); 
				for (int j=0,count=0; j<num_data; j++){
					if (strncmp(object[j].name,temp[0],3)==0){ //compare to find expected value
						keep[count]=j; count++;
					}
					if (strncmp(object[j].name,temp[1],3)==0){
						keep[count]=j; count++;
					}
				}
				if (object[keep[0]].name[0]=='L') //it means first value is a line
					value=calc_distance_line_point(object[keep[0]].line.point_1.x, object[keep[0]].line.point_1.y, object[keep[0]].line.point_2.x, object[keep[0]].line.point_2.y, object[keep[1]].point.x, object[keep[1]].point.y); 
				else //it means first data is a point
					value=calc_distance_line_point(object[keep[1]].line.point_1.x, object[keep[1]].line.point_1.y, object[keep[1]].line.point_2.x, object[keep[1]].line.point_2.y, object[keep[0]].point.x, object[keep[0]].point.y);
				fprintf(fp,"Distance(%s,%s) = %.1f\n",object[keep[0]].name, object[keep[1]].name, value);
				break;
			case 3: //angle between two line
				sscanf(actions[i],"Angle %s %s",temp[0],temp[1]);
				//printf("%s %s\n",temp[0],temp[1] ); 
				for (int j=0,count=0; j<num_data; j++){
					if (strncmp(object[j].name,temp[0],3)==0){ //compare to find expected value
						keep[count]=j; count++;
					}
					if (strncmp(object[j].name,temp[1],3)==0){
						keep[count]=j; count++;
					}
				}
				fprintf(fp,"Angle(%s,%s) = %.1f\n",object[keep[0]].name, object[keep[1]].name, find_angle(object[keep[0]].line.point_1.x, object[keep[0]].line.point_1.y, object[keep[0]].line.point_2.x,  object[keep[0]].line.point_2.y,
					 object[keep[1]].line.point_1.x,  object[keep[1]].line.point_1.y,  object[keep[1]].line.point_2.x,  object[keep[1]].line.point_2.y));
				break;
			case 4: //length a line
				sscanf(actions[i],"Length %s",temp[0]);
				//printf("%s\n",temp[0]); 
				for (int j=0,count=0; j<num_data; j++){ //compare to find expected value
					if (strncmp(object[j].name,temp[0],3)==0){
						keep[count]=j; count++;
					}
				}
				fprintf(fp,"Length(%s) = %.1f\n",object[keep[0]].name, calc_distance(object[keep[0]].line.point_1.x, 
					object[keep[0]].line.point_1.y, object[keep[0]].line.point_2.x, object[keep[0]].line.point_2.y) );
				break;
			case 5: //lingth a polygon 
				sscanf(actions[i],"Length %s",temp[0]);
				//printf("%s\n",temp[0]); 
				for (int j=0,count=0; j<num_data; j++){
					if (strncmp(object[j].name,temp[0],3)==0){ //compare to search expected value
						keep[count]=j; count++;
					}
				}
				poly_check_p=0; poly_check_l=0; 
				for (int j=0; j<object[keep[0]].polygon.poly_num; j++){ //detect what kind of polygon, fill with point or line?
					if (object[keep[0]].polygon.point[j].x >0.0)
						poly_check_p++;
					if (object[keep[0]].polygon.line[j].point_1.x > 0.0 || object[keep[0]].polygon.line[j].point_1.y > 0.0)
						poly_check_l++;
				}

				//printf("p num %d l num %d\n",poly_check_p, poly_check_l );
				//printf("pg_size %d\n",object[keep[0]].polygon.poly_num );
				
				if (poly_check_p > poly_check_l){ //if polygon variables are point
					//if else blocks stands for, when loop arives last point, it should connect to the first point.
					for (int j=0; j<object[keep[0]].polygon.poly_num; j++){
						if (j != object[keep[0]].polygon.poly_num-1)
							value+= calc_distance(object[keep[0]].polygon.point[j].x, object[keep[0]].polygon.point[j].y, object[keep[0]].polygon.point[j+1].x, object[keep[0]].polygon.point[j+1].y );
						else 
							value+= calc_distance(object[keep[0]].polygon.point[j].x, object[keep[0]].polygon.point[j].y, object[keep[0]].polygon.point[0].x, object[keep[0]].polygon.point[0].y );
						//printf("%f\n",value );
					}
				}
				
				else if (poly_check_l > poly_check_p) { //if polygon variables are line
					for (int j=0; j<object[keep[0]].polygon.poly_num; j++){
						value+= calc_distance(object[keep[0]].polygon.line[j].point_1.x, object[keep[0]].polygon.line[j].point_1.y, object[keep[0]].polygon.line[j].point_2.x, object[keep[0]].polygon.line[j].point_2.y );
						//printf("%f\n",value );
					}
				}
				else //for debugging
					printf("There is something wrong!!!\n");

				fprintf(fp,"Length(%s) = %.1f\n",object[keep[0]].name,value);
				break;
			case 6: //area a polygon
				sscanf(actions[i],"Area %s",temp[0]);
				//printf("%s\n",temp[0]); 
				for (int j=0,count=0; j<num_data; j++){ //compare to search expected value
					if (strncmp(object[j].name,temp[0],3)==0){
						keep[count]=j; count++;
					}
				}
				poly_check_p=0; poly_check_l=0; 
				for (int j=0; j<object[keep[0]].polygon.poly_num; j++){ //detect what kind of polygon, fill with point or line?
					if (object[keep[0]].polygon.point[j].x >0.0)
						poly_check_p++;
					if (object[keep[0]].polygon.line[j].point_1.x > 0.0 || object[keep[0]].polygon.line[j].point_1.y > 0.0)
						poly_check_l++;
				}

				//printf("p num %d l num %d\n",poly_check_p, poly_check_l );
				//printf("pg_size %d\n",object[keep[0]].polygon.poly_num );
				
				if (poly_check_p > poly_check_l){ //if polygon variables are point
					value= find_area(object[keep[0]].polygon.poly_num, 1 , object[keep[0]].polygon);
				}
				
				else if (poly_check_l > poly_check_p) { //if polygon variables are line
					value= find_area(object[keep[0]].polygon.poly_num, 2 , object[keep[0]].polygon);
				}
				else //for debugging
					printf("There is something wrong!!!\n");
				fprintf(fp,"Area(%s) = %.1f\n",object[keep[0]].name,value);
				break;
			default: printf("There is something worng !!!\n"); break;
		}
		i++;
	}
	fclose(fp); //close writed file
}

int check_action_type(char str[SIZE],int len) {
	int p=0,l=0,pg=0;

	for (int i=0; i<len; i++){
		if (str[i] == '/') break; //When see this, it means comment line, break
		if (str[i]=='P') p++; //When see a big P, increment p. P1 P2 etc..
		else if (str[i] =='L') l++; //When see a big L, increment l. L12, L23 etc..
		else if (str[i] == 'G') pg++; //When see a big G, increment pg++. PG1, PG2 etc..
	}
	//printf("p %d l %d pg %d\n",p,l,pg );
	if (strncmp(str,"Distance",8)==0 && l<1) return 1;
	else if (strncmp(str,"Distance",8)==0 && l>=1) return 2;
	else if (strncmp(str,"Angle",5)==0) return 3;
	else if (strncmp(str,"Length L",8)==0) return 4;
	else if (strncmp(str,"Length PG",9)==0) return 5;
	else if (strncmp(str,"Area",4)==0) return 6;
}

float calc_distance(float x1, float y1, float x2, float y2){
	return sqrt(pow( (x1-x2),2 ) + pow( (y1-y2),2 ));
}

float calc_distance_line_point(float xa, float ya, float xb, float yb, float xc, float yc){
	//formula from https://math.stackexchange.com/questions/2757318/distance-between-a-point-and-a-line-defined-by-2-points
	return abs( ((xb-xa) * (yc-ya)) - ((yb-ya)* (xc- xa)) ) / (sqrt(pow( (xa-xb),2 ) + pow( (ya-yb),2 )));
}

float find_angle(float xa1, float ya1, float xa2, float ya2, float xb1, float yb1, float xb2, float yb2){
	float m1=slope(xa1,ya1,xa2,ya2);
	//printf("%f %f %f %f m1: %f\n",xa1,ya1,xa2,ya2 ,m1 );
	float m2=slope(xb1,yb1,xb2,yb2);
	//printf("%f %f %f %f m2: %f\n",xb1,yb1,xb2,yb2,m2 );
	if (isinf(m2)) //checks if this value is goint to infinity
		m2=9999999999.0; //if goes inf value, assign with a very big num
	if (isinf(m1))
		m1=9999999999.0;
	double x= (m2-m1) / (1+ (m2*m1));
	return fabs(atan(x) *CONVERT_DEGRE);
}

float slope(float x1, float y1, float x2, float y2){
	return (y2-y1)/(x2-x1);
}

float find_area(int repeat, int type, polygons polygon){
	float value=0;
	if (type==1){ //if polygon fill with points
		//If else blocks check, If loop has arrived last point, it connect it to first point
		for (int i=0; i<repeat; i++){
			if (i!= repeat-1)
				value+= ( polygon.point[i].x * polygon.point[i+1].y ) - ( polygon.point[i].y * polygon.point[i+1].x );
			else
				value+= ( polygon.point[i].x * polygon.point[0].y ) - ( polygon.point[i].y * polygon.point[0].x );
		}
	}
	else if (type==2){ //if polygon fill with lines
		for (int i=0; i<repeat; i++){
			value+= ( polygon.line[i].point_1.x * polygon.line[i].point_2.y ) - ( polygon.line[i].point_1.y * polygon.line[i].point_2.x );
		}
	}
	return value/2;
}
