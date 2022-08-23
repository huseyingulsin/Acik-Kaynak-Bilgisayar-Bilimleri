#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "epslib.h"



Figure* start_figure(double width, double height){
	Figure *fig= createFigure();
	fig->start=createPoint(); fig->end=createPoint();

	fig -> start->x= -width/2;
	fig -> start->y= -height/2;
	fig -> end->x  = width/2;
	fig -> end->y  = height/2;

	return fig;
}

Figure* createFigure(){
	Figure* fig= (Figure*) malloc(sizeof(Figure));
	fig ->start=NULL;
	fig ->  end=NULL;
	fig ->point=NULL;
	fig -> tree=NULL;
	fig -> next=NULL;
	return fig;
}

Point2D* createPoint(){
	Point2D* point= (Point2D*) malloc(sizeof(Point2D));
	point->next=NULL;
	return point;
}

Tree* createTree(){
	Tree *tree= (Tree*) malloc(sizeof(Tree));
	tree->next=NULL;
	return tree;
}

void set_thickness_resolution(Figure* fig, double thickness, double resolution){
	fig->thick = thickness;
	fig->res   = resolution;
}

void set_color(Figure* fig, Color c){
	fig->col=c;
}

void draw_fx(Figure* fig, double f(double x), double start_x, double end_x, double step_size){
	Point2D *root=NULL;

	fig-> point = createPoint();
	fig-> point-> x= start_x;
	fig-> point-> y= f(start_x); /* find value of y coordinate due to func */
	start_x+= step_size; 

	root= fig-> point;
	fig->point->next=root;
	
	//printf("i=%.3f, f(i)=%.3f\n",fig-> point-> x,fig-> point-> y );

	fig->point=fig->point->next;

	while (start_x < end_x){

		fig-> point->next = createPoint();
		fig-> point->next-> x= start_x;
		fig-> point->next-> y= f(start_x); /* find value of y coordinate due to func */
		//printf("i=%.3f, f(i)=%.3f\n",fig-> point-> x,fig-> point-> y );
		fig->point=fig->point->next;
		start_x+= step_size;
	}
	fig->point=root;
}

void draw_polyline(Figure *fig, Point2D *poly_line, int n){
	Point2D *root=NULL;
	srand ( time ( NULL));
		
	poly_line=createPoint();
	/* generate random coordinate in range in canvas borders */
	poly_line->x= (double)rand()/RAND_MAX*fig->end->x*2.0-fig->end->x;  
	poly_line->y= (double)rand()/RAND_MAX*fig->end->x*2.0-fig->end->x; 
	root=poly_line;
	poly_line->next=root;

	//printf("%lf %lf \n",poly_line->x, poly_line->y );
	poly_line= poly_line->next;
	for (int i=0; i<n; i++){
		
		//printf("%lf %lf \n",poly_line->x, poly_line->y );
		poly_line->next =createPoint();
		poly_line->next->x= (double)rand()/RAND_MAX*fig->end->x*2.0-fig->end->x;  
		poly_line->next->y= (double)rand()/RAND_MAX*fig->end->x*2.0-fig->end->x; 
		poly_line= poly_line->next;
	}
	
	poly_line=root;	
	fig->point=poly_line;
}

void draw_polygon(Point2D * poly_line){
	Point2D *last=poly_line;
	while (last->next!=NULL){
		last=last->next;
	}

	last->next=createPoint();
	last->next->x=poly_line->x;
	last->next->y=poly_line->y;
}

void draw_ellipse(Figure* fig, Point2D * centre, Point2D * width_height){
	Point2D *root=NULL;
	double theta=0;
	double r=width_height->x, width= width_height->y;

	fig-> point = createPoint();
	fig-> point-> x=centre->x - (width* r)*cos(theta);
	fig-> point-> y=centre->y + r*sin(theta);
	theta+= fig->res;

	root= fig-> point;
	fig->point->next=root;

	fig->point=fig->point->next;

	while (theta <=360){
		fig-> point->next = createPoint();
		fig-> point->next-> x= centre->x -(width* r)*cos(theta);
		fig-> point->next-> y= centre->y + r*sin(theta);
		theta+= fig->res;
		fig->point=fig->point->next;
	}
	fig->point=root;
}

void draw_reverse_ellipse(Figure* fig, Point2D * centre, Point2D * width_height){
	Point2D *root=NULL;
	double theta=0;
	double r=width_height->x, width= width_height->y;

	fig-> point = createPoint();
	fig-> point-> x=centre->x + r*cos(theta);
	fig-> point-> y=centre->y - (width* r)*sin(theta);
	theta+= fig->res;

	root= fig-> point;
	fig->point->next=root;

	fig->point=fig->point->next;

	while (theta <=360){
		fig-> point->next = createPoint();
		fig-> point->next-> x= centre->x + r*cos(theta);
		fig-> point->next-> y= centre->y -(width* r)*sin(theta);
		theta+= fig->res;
		fig->point=fig->point->next;
	}
	fig->point=root;
}

void draw_circle(Figure* fig, Point2D * centre, Point2D * width_height){
	Point2D *root=NULL;
	double theta=0;
	double r=width_height->x;

	fig-> point = createPoint();
	fig-> point-> x=centre->x + r*cos(theta);
	fig-> point-> y=centre->y - r*sin(theta);
	theta+= fig->res;

	root= fig-> point;
	fig->point->next=root;

	fig->point=fig->point->next;

	while (theta <=360){
		fig-> point->next = createPoint();
		fig-> point->next-> x= centre->x + r*cos(theta);
		fig-> point->next-> y= centre->y - r*sin(theta);
		theta+= fig->res;
		fig->point=fig->point->next;
	}
	fig->point=root;
}

void draw_binary_tree(Figure *fig, Tree *root){
	Tree *iter=NULL, *left=NULL, *right=NULL;
	double s=fig->end->x/8;
	double c_x=6, c_y=1.3; /* used for increment and dicrement lines between nodes */
	double temp_x, temp_y;

	temp_x=fig->start->x + fig->end->x;
	temp_y=fig->end->y - fig->end->y/10;
	insert_end_tree(&root, temp_x, temp_y, MOVE );				//start
	insert_end_tree(&root, temp_x- s*c_x, temp_y -s*c_y, LINE ); //left
	insert_end_tree(&root, temp_x+ s*c_x, temp_y -s*c_y, LINE ); //right
	iter=root;

	int repeat= fig->size_tree;
	while (repeat > 0){
		c_x-= c_x/4;
		c_y+= c_y/2;

		left=iter->next;
		iter=left;
		temp_x=iter->point.x; temp_y=iter->point.y; 
		insert_end_tree(&root, temp_x , temp_y , MOVE);
		insert_end_tree(&root, temp_x- s*c_x, temp_y -s*c_y, LINE ); //left
		insert_end_tree(&root, temp_x+ s*c_x, temp_y -s*c_y, LINE ); //right

		right=iter->next;
		iter=right;
		temp_x=iter->point.x; temp_y=iter->point.y;
		insert_end_tree(&root, temp_x , temp_y , MOVE);
		insert_end_tree(&root, temp_x- s*c_x, temp_y -s*c_y, LINE ); //left
		insert_end_tree(&root, temp_x+ s*c_x, temp_y -s*c_y, LINE ); //right

		iter=iter->next;
		repeat--;
	}
	fig->tree=root;
}

void scale_figure(Figure *fig, double scale_x, double scale_y){
	Point2D *temp=fig->point;

		while(temp != NULL)
		{
			temp->x *= scale_x;
			temp->y *= scale_y;
			temp = temp->next;
		}	
}

void resize_figure(Figure *fig, Point2D *start_roi, Point2D *end_roi){
	/* check every point
	if a point pass the borders, resize border */

	Point2D *temp=fig->point;
	while (temp){
		if (temp->x < fig->start->x || temp->x > fig->end->x ){
			start_roi->x *=1.15; end_roi->x *=1.15;
			start_roi->y *=1.15; end_roi->y *=1.15;
			resize_figure(fig, start_roi, end_roi);
			break;
		}
		if (temp->y < fig->start->y || temp->y > fig->end->y ){
			start_roi->x *=1.15; end_roi->x *=1.15;
			start_roi->y *=1.15; end_roi->y *=1.15;
			resize_figure(fig, start_roi, end_roi);
			break;
		}
		temp=temp->next;
	}

	resize_figure_helper(fig, start_roi, end_roi);
}

void resize_figure_tree(Figure *fig, Point2D *start_roi, Point2D *end_roi){

	/* check every point
	if a point pass the borders, resize border */
	Tree *temp=fig->tree;
	Point2D point=temp->point;

	while (temp){
		point=temp->point;

		if (point.x < fig->start->x || point.x > fig->end->x ){
			start_roi->x *=1.3; end_roi->x *=1.3;
			start_roi->y *=1.3; end_roi->y *=1.3;
			resize_figure_tree(fig, start_roi, end_roi);
			break;
		}
		if (point.y < fig->start->y || point.y > fig->end->y ){
			start_roi->x *=1.3; end_roi->x *=1.3;
			start_roi->y *=1.3; end_roi->y *=1.3;
			resize_figure_tree(fig, start_roi, end_roi);
			break;
		}
		temp=temp->next;
	}

	resize_figure_helper(fig, start_roi, end_roi);
}

void resize_figure_helper(Figure *fig, Point2D *start_roi, Point2D *end_roi){

	fig->start->x= start_roi->x;
	fig->start->y= start_roi->y;

	fig->end->x  = end_roi->x ;
	fig->end->y  = end_roi->y ;
}

void append_figures(Figure * fig1, Figure * fig2){
	Figure *temp=fig1;

	/* change border to bigger one */
	if (fig1->end->x * fig1->end->y < fig2->end->x * fig2->end->y ){
		fig1->start= fig2->start;
		fig1->end  = fig2->end;
	}

	while (temp->next!=NULL)
		temp=temp->next;
	temp->next=fig2;
}

void export_eps(Figure * fig, char * file_name){	
	FILE* fp = fopen(file_name,"wt");
	if(fp == NULL){
		printf("Couldn't open file\n");
		exit(1);
	}
	
	Point2D* temp=NULL;

	fprintf(fp, "%%!PS-Adobe-3.0 EPSF-3.0 \n");
	fprintf(fp, "%%%%BoundingBox: %.2f %.2f %.2f %.2f\n",fig->start->x,fig-> start->y, fig->end->x, fig->end->y );

	
	
	while (fig!=NULL){
		if (fig->tree){
			export_tree(fig, file_name);
			fig=fig->next;
			if (fig==NULL) break;
		}
		
		temp=fig->point;
		fprintf(fp, "\n%.2f setlinewidth\n",fig->thick);
		fprintf(fp,	"%.2f %.2f %.2f setrgbcolor\n", fig->col.red, fig->col.green, fig->col.blue);
		fprintf(fp, "newpath\n\n" );
		fprintf(fp, "%.2f %.2f moveto\n", temp->x, temp->y );
		if(temp->next != NULL)
			temp = temp->next;
		if(temp==NULL){     
			printf("Figure is empty\n");
			exit(1);
		}

		while(temp != NULL){
			fprintf(fp,"%lf %lf lineto\n", temp->x, temp->y);
			temp = temp->next; 
		}
		fprintf(fp,"stroke\n");

		fig=fig->next;
	}

	fclose(fp);
}

void draw_x_y_Axis(Figure *fig, char * file_name){
	FILE* fp = fopen(file_name,"a+");
	
	fprintf(fp, "\n\n[0.75] 0 setdash\n");
	fprintf(fp, "newpath\n0.00 0.00 0.00 setrgbcolor\n");
	fprintf(fp, "%lf %lf moveto\n",fig->end->x, ( fig->start->x + fig-> end->x ) );
	fprintf(fp, "%lf %lf lineto\n",fig->start->x, ( fig->start->x + fig-> end->x ) );
	fprintf(fp, "0.20 setlinewidth\nstroke\n" );

	fprintf(fp, "\n\nnewpath\n0.00 0.00 0.00 setrgbcolor\n");
	fprintf(fp, "%lf %lf moveto\n",( fig->start->x + fig-> end->x ) , fig->end->x);
	fprintf(fp, "%lf %lf lineto\n", ( 	fig->start->x + fig-> end->x ) , fig->start->x);
	fprintf(fp, "0.10 setlinewidth\nstroke\n" );

	fclose(fp);
	return;
}

void draw_xy_line(Figure *fig, char* file_name, double f(double x), double start, double end){
	FILE* fp = fopen(file_name,"a+");
	
	fprintf(fp, "\n\n[0.50] 0 setdash\n");
	fprintf(fp, "newpath\n100.00 50.00 0.00 setrgbcolor\n");
	fprintf(fp, "%lf %lf moveto\n", start,  f(start) );
	fprintf(fp, "%lf %lf lineto\n",  start,(fig->start->x + fig-> end->x ) );
	fprintf(fp, "0.10 setlinewidth\nstroke\n" );

	fprintf(fp, "\n\n[0.50] 0 setdash\n");
	fprintf(fp, "newpath\n100.00 50.00 0.00 setrgbcolor\n");
	fprintf(fp, "%lf %lf moveto\n", end,  f(end) );
	fprintf(fp, "%lf %lf lineto\n",  end,(fig->start->x + fig-> end->x ) );
	fprintf(fp, "0.10 setlinewidth\nstroke\n" );

	fclose(fp);
}

void export_tree(Figure *fig, char *file_name){
	FILE *fp =fopen(file_name, "wt");
	Tree *head=fig->tree;
	double t=fig->res; /* keep diameter and size of text */
	Point2D move;

	fprintf(fp, "%%!PS-Adobe-3.0 EPSF-3.0 \n");
	fprintf(fp, "%%%%BoundingBox: %.2f %.2f %.2f %.2f\n",fig->start->x,fig-> start->y, fig->end->x, fig->end->y ); //
	fprintf(fp, "\n%.2f setlinewidth\n",fig->thick);
	fprintf(fp,	"%.2f %.2f %.2f setrgbcolor\n", fig->col.red, fig->col.green, fig->col.blue);
	fprintf(fp, "newpath\n\n" );
	fprintf(fp, "/monospace findfont\n");
	fprintf(fp, "%d scalefont\n", (int) t -1 );
	fprintf(fp, "setfont\n" );	

	while(head){
		if (head->check_type==MOVE){
			move=head->point;
		}
		else{
			fprintf(fp,"%lf %lf moveto\n",move.x,move.y );
			fprintf(fp,"%lf %lf lineto\n",head->point.x, head->point.y );
		}
		head=head->next;
	}
	fprintf(fp, "stroke\n\n");

	fprintf(fp, "\n0.00 0.00 0.00 setrgbcolor\n");
	srand ( time ( NULL));
	head = fig->tree;
	while (head){
			head->data=rand()%1000;
			fprintf(fp,"%lf %lf %lf 0 360 arc gsave 1 setgray fill grestore stroke\n", head->point.x, head->point.y , t);
			fprintf(fp,"%lf %lf moveto (%d) show stroke\n",head->point.x -(t/1.5), head->point.y - t/4 , head->data);
		
		head=head->next;
	}
	fprintf(fp, "showpage\n");
	fclose(fp);
}

void insert_end_tree(Tree **head, double x, double y, int check_type){
    Tree * new = NULL;
    Tree * last= NULL;
 	
 	new=createTree();
 	
    new->point.x=x;
    new->point.y=y;
    new->check_type=check_type;

    if( *head == NULL){
        *head = new;
        return;
    }
    /*Traverse to the last node*/
    last = *head;
    while(last->next) last = last->next;
    last->next = new;
}

void free_point(Point2D *root){
	Point2D *head=root;
    while (head){
   		Point2D *temp=head;
   		head=head->next;
   		free(temp);
   	}
}

void free_tree(Tree *root){
	Tree *head=root;
	while (head){
		Tree *temp=head;
		head=head->next;
		free(temp);
	}
}

void free_fig(Figure* root){
	Figure *head=root;
	while(head){
		Figure *temp=head;
   		head=head->next;
   		free_point(temp->start);
   		free_point(temp->end);
		free_point(temp->point);
		free_tree (temp->tree);
		free(temp);
	}
}

double fx_square(double x){
	return x*x;
}

double fx_cube(double x){
	return x*x*x;
}