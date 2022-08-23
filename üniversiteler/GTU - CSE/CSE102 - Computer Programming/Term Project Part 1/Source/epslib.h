/*
This library helps to draw
some figures with eps(Encapsulated PostScript) files.

for more info about postscript:http://paulbourke.net/dataformats/postscript/

Read User Guide for clear understanding

Creator: Muhammed Oguz
*/

/****************************************************************************
*				       USER GUIDE											*
*				 Proper Use Of Functions									*
*	Color C;																*
*	--NOTE_1--																*
* 	double width =xx.0 , height = xx.0; 									*
*	c.red=x.0 , c.green=x.0, c.blue=x.0; 									*	
*	double thickness=x.x, resolution=x;										*
*	Fig *Example= start_figure(width, height);								*
*																			*
*																			*
*	set_thickness_resolution(Example, thickness, resolution);				*
*	set_color(Example, c);													*
*																			*
*	draw_fx(Example, --NOTE_2-- , start_x, end_x, step_size);				*
*	draw_polyline(Example, Example->point, n);		--NOTE_3--				*
*	draw_polygon(Example->point);					--NOTE_3--				*
*	draw_ellipse(Example, centre, width_height);							*
*	draw_binary_tree(Example, Example->tree );								*
*																			*
*	scale_figure(Example,  scale_x,  scale_y);								*
*																			*
*	Figure *Other_Example;													*
*	append_figures(Example, Other_Example);									*
*																			*
*   --NOTE_4--																*
*	resize_fig(Example , Exapmle->start , Example->end);					*
*	resize_fig_tree(Example , Exapmle->start , Example->end);				*
*														 					*
*	export_eps(Exapmle ,"Example.eps");										*
*	draw_x_y_Axis(Example ,"Example.eps");									*
*	draw_xy_line(fig_fx_sin, "Example.eps", --NOTE_1--  ,start_x, end_x);	*
*																			*
*	free_fig (Example);														*
*																			*
*****************************************************************************
----------------------------------------------------------------------------
NOTE_1; Change x value to your own values
NOTE_2: You can use fx_square, fx_cube, sin, cos..etc for this veriable
NOTE_3: poly_line draws random n lines, polygon closes the path
NOTE_4: Strongly recommended after every draw function
---------------------------------------------------------------------------*/


#ifndef LIB_H
#define LIB_H

#define MOVE 0
#define LINE 1

typedef struct Color{ 		/* RGB color scale 		      	    */
	double red;
	double green;
	double blue;
}Color;

typedef struct Point2D{
	double x,y;				/* coordinates for a point  	    */
	struct Point2D* next;	/* show next Point2D				*/
}Point2D;

typedef struct Tree{
	int data;
	int check_type;
	Point2D point;
	struct Tree *next;
}Tree;

typedef struct Figure{
	double thick, res;		/* set thickness and resolution     */
	Point2D *start;			/* set canvas borders 				*/
	Point2D *end;
	Color col;

	Point2D *point;
	Tree *tree;
	int size_tree;
	struct Figure* next;
}Figure;


/* expected Functions from Instructions */
Figure* start_figure(double width, double height); 	/* initalize widght and height 		*/
void set_thickness_resolution(Figure* fig, double thickness, double resolution);  /* set thickness and resolution 	*/
void set_color(Figure* fig, Color c); /* set color from RGB scae */
void draw_fx(Figure* fig, double f(double x), double start_x, double end_x, double step_size); /* draw the given fx function */
void draw_polyline(Figure* fig, Point2D * poly_line, int n); /* draw random lines n time */
void draw_polygon(Point2D * poly_line); /* draw a polygon between given points and connect first and last point to finish */
void draw_ellipse(Figure* fig, Point2D * centre, Point2D * width_height); /* draw an elipse */
void draw_binary_tree(Figure*fig, Tree * root); /* draws binary tree */
void scale_figure(Figure* fig,double scale_x, double scale_y); /* scale the figure */
void resize_figure(Figure*fig, Point2D *start_roi, Point2D *end_roi); /* If figure pass the canvas borders, resize the canvas borders */
void append_figures(Figure * fig1, Figure * fig2); /* merge two figues */
void export_eps(Figure * fig, char * file_name); /* export the figures due to expectations of an EPS file */

/* helper functions */
Figure* createFigure(); /* create new figure */
Point2D* createPoint(); /* create new Point2D */
Tree * createTree();	/* create new Tree */
void draw_x_y_Axis(Figure *fig, char *file_name); /*draw x and y axix, for better shapes */
void free_point(Point2D *root); /* Free allocated memory of a point */
void free_fig(Figure* fig); /* Free allocated memory of a figure */
void free_tree(Tree *root); /* Free allocated memory of a tree */
double fx_square(double x); /* for drawing x^2 */
double fx_cube(double x); /* for drawing x^3 */ 
void draw_xy_line(Figure *fig, char *file_name, double f(double x), double start, double end); /* draw lines to starting end ending points of figure */
void draw_reverse_ellipse(Figure* fig, Point2D * centre, Point2D * width_height); /* works exactly draw_ellips but reverse */
void draw_circle(Figure* fig, Point2D * centre, Point2D * width_height); /* works exactly draw_ellips but draws circle */ 
void resize_figure_helper(Figure *fig, Point2D *start_roi, Point2D *end_roi); /* helps resize func */ 
void insert_end_tree(Tree **head, double x, double y, int check_type); /* insert new node to the Tree */
void resize_figure_tree(Figure *fig, Point2D *start_roi, Point2D *end_roi); /* resize if canvas borders is too small */
void export_tree(Figure *fig, char *file_name); /*export tree to an eps file */
#endif