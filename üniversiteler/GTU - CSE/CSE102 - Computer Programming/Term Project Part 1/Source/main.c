#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "epslib.h"



int main(void){
	Color c;
	double width, height, thickness, resolution;
	

/*------------------------------------------------------------------------*/
	/* Draw fx function */
	/* Settings 	    */
	width =100.0 , height = 100.0; 						/* borders of the canvas 	*/
	c.red=100.0 ,c.green=00.0, c.blue=0.0; 				/* color info's for fig 	*/
	thickness=0.1, resolution=15;						/* thickness and resolution */	
	double start_x=-20.0, end_x=20.0, step_size=0.5; 	/* set fx properties 		*/

	Figure *fig_fx_sin;
	fig_fx_sin = start_figure(width, height);						/* set width and height */	
	set_thickness_resolution(fig_fx_sin, thickness, resolution);	/* set thick and res 	*/
	set_color(fig_fx_sin, c);										/* set color 			*/

	draw_fx(fig_fx_sin, sin , start_x, end_x, step_size);			
	resize_figure(fig_fx_sin, fig_fx_sin->start, fig_fx_sin->end);	/* **recomended** If figure pass the borders, resize canvas borders */
	export_eps(fig_fx_sin,"fx_sin.eps");							
	draw_x_y_Axis(fig_fx_sin,"fx_sin.eps");
	draw_xy_line(fig_fx_sin, "fx_sin.eps", sin ,start_x, end_x);

/*------------------------------------------------------------------------*/
	/* draw poly_line */
	/* Settings 	  */
	width =100.0 , height = 100.0; 			/* borders of the canvas 	*/
	c.red=100.0 ,c.green=00.0, c.blue=0.0; 	/* color info's for fig 	*/
	thickness=0.1, resolution=15;			/* thickness and resolution */
	int n=3; 								/* set line count 			*/		

	Figure *fig_lines;
	fig_lines = start_figure(width, height);						/* set width and height */		
	set_thickness_resolution(fig_lines, thickness, resolution);		/* set thick and res 	*/
	set_color(fig_lines, c);										/* set color 			*/

	draw_polyline(fig_lines, fig_lines->point, n);
	resize_figure(fig_lines, fig_lines->start, fig_lines->end);	  /* **recomended** If figure pass the borders, resize canvas borders */
	export_eps(fig_lines,"poly_line.eps");
	draw_x_y_Axis(fig_lines,"poly_line.eps");

/*------------------------------------------------------------------------*/
	/* Draw Polygon */
	/* Settings 	*/
	width =100.0 , height = 100.0; 			/* borders of the canvas 	*/
	c.red=100.0 ,c.green=00.0, c.blue=0.0; 	/* color info's for fig 	*/
	thickness=0.1, resolution=15;			/* thickness and resolution */
	int edge=2;  							/* set edge count of polygon*/

	Figure *fig_polygon;
	fig_polygon = start_figure(width, height);						/* set width and height */	
	set_thickness_resolution(fig_polygon, thickness, resolution);	/* set thick and res 	*/
	set_color(fig_polygon, c);										/* set color 			*/
	draw_polyline(fig_polygon, fig_polygon->point , edge);			/* draw polygon's lines */


	draw_polygon(fig_polygon->point);
	resize_figure(fig_polygon, fig_polygon->start, fig_polygon->end);	  /* **recomended** If figure pass the borders, resize canvas borders */
	export_eps(fig_polygon,"polygon.eps");
	draw_x_y_Axis(fig_polygon,"polygon.eps");

/*------------------------------------------------------------------------*/
	/* Draw Ellips, Reverse Ellips and Circle 	   */
	/* Do not change those veriables (recomennded) */
	/* Settings 							 	   */
	width =100.0 , height = 100.0; 			/* borders of the canvas 	*/
	thickness=0.25, resolution=0.1;			/* thickness and resolution */

	Point2D *centre=createPoint();
	Point2D *width_height=createPoint();
	
/*------------------------------------------------------------------------*/

	/* Draw Ellips */
	Figure *fig_ellips;
	c.red=100.0 ,c.green=50.0, c.blue=0.0; 	/* color info's for fig 			*/
	centre->x=20; centre->y=20;				/* centre of  circle/ellips 		*/
	width_height->x=5.0; width_height->y=2.5; /* set diameter x and diameter y 	*/

	fig_ellips = start_figure(width, height);						/* set width and height */			
	set_thickness_resolution(fig_ellips, thickness, resolution);	/* set thick and res 	*/
	set_color(fig_ellips, c);										/* set color 			*/
	
	draw_ellipse(fig_ellips, centre, width_height);
	resize_figure(fig_ellips, fig_ellips->start, fig_ellips->end);	  /* **recomended** If figure pass the borders, resize canvas borders */
    export_eps(fig_ellips,"ellipse.eps");
	draw_x_y_Axis(fig_ellips,"ellipse.eps");

/*------------------------------------------------------------------------*/

	/* Draw Reverse Ellips */
	Figure *fig_ellips_r;
	c.red=00.0 ,c.green=00.0, c.blue=0.0; 	/* color info's for fig 			*/
	centre->x=-10; centre->y=-30;			/* centre of  circle/ellips 		*/
	width_height->x=5.0; width_height->y=2.5; /* set diameter x and diameter y 	*/

	fig_ellips_r = start_figure(width, height);						/* set width and height */	
	set_thickness_resolution(fig_ellips_r, thickness, resolution);	/* set thick and res 	*/
	set_color(fig_ellips_r, c);										/* set color 			*/

	draw_reverse_ellipse(fig_ellips_r, centre, width_height);
	resize_figure(fig_ellips_r, fig_ellips_r->start, fig_ellips_r->end);	  /* **recomended** If figure pass the borders, resize canvas borders */
    export_eps(fig_ellips_r,"ellipse_reverse.eps");
	draw_x_y_Axis(fig_ellips_r,"ellipse_reverse.eps");

/*------------------------------------------------------------------------*/

	/* Draw Circle */
	Figure *fig_circle;
	c.red=00.0 ,c.green=00.0, c.blue=100.0; /* color info's for fig 	*/
	centre->x=20; centre->y=10;				/* centre of  circle/ellips */
	width_height->x=5.0;					/* set diameter 			*/

	fig_circle = start_figure(width, height);						/* set width and height */	
	set_thickness_resolution(fig_circle, thickness, resolution);	/* set thick and res 	*/
	set_color(fig_circle, c);										/* set color 			*/

	draw_circle(fig_circle, centre, width_height);
	resize_figure(fig_circle, fig_circle->start, fig_circle->end);	  /* **recomended** If figure pass the borders, resize canvas borders */
    export_eps(fig_circle,"circle.eps");
	draw_x_y_Axis(fig_circle,"circle.eps");

/*------------------------------------------------------------------------*/
	/* Draw Tree 	 */
	/* Settings      */
	width =200.0 , height = 200.0; 						/* borders of the canvas 	*/
	c.red=0.0 ,c.green=100.0, c.blue=0.0; 				/* color info's for fig 	*/
	thickness=0.3, 										/* thickness 			    */	

	resolution=5; 										/* set size of circles in tree */

	Figure *fig_tree;
	fig_tree = start_figure(width, height);						/* set width and height */	
	set_thickness_resolution(fig_tree, thickness, resolution);	/* set thick and res 	*/
	set_color(fig_tree, c);										/* set color 			*/
	
	fig_tree->size_tree=3; 			/* set binary tree size, it increments parabolicly */
	draw_binary_tree(fig_tree, fig_tree->tree);						
	resize_figure_tree(fig_tree, fig_tree->start, fig_tree->end); /* **recommended** if tree pass the edges, resize the edges */
	export_eps(fig_tree,"binary_tree.eps");
	
/*------------------------------------------------------------------------*/
	
	/* Scale Figure 	*/
	double scale_x=2, scale_y=2; 			/* Set scale size 		*/

	/* Scale Circle 	*/
	scale_figure(fig_circle,  scale_x,  scale_y);
	resize_figure(fig_circle, fig_circle->start, fig_lines->end);	  /* **recomended** If figure pass the borders, resize canvas borders */
	export_eps(fig_circle,"circle_scaled.eps");
	draw_x_y_Axis(fig_circle,"circle_scaled.eps");

	/* Scale fx 		*/
	scale_figure(fig_fx_sin,  scale_x,  scale_y);
	resize_figure(fig_fx_sin, fig_fx_sin->start, fig_fx_sin->end);	  /* **recomended** If figure pass the borders, resize canvas borders */	
	export_eps(fig_fx_sin,"fx_sin_scaled.eps");
	draw_x_y_Axis(fig_fx_sin,"fx_sin_scaled.eps");
	draw_xy_line(fig_fx_sin, "fx_sin_scaled.eps", sin ,start_x*scale_x, end_x*scale_x);

/*------------------------------------------------------------------------*/
	
	/* Resize Figure, show how it is working	*/
	/* Settings 								*/

	width =100.0 , height = 100.0; 			/* borders of the canvas 	*/
	thickness=0.1, resolution=0.1;			/* thickness and resolution */

	Figure *fig_ellips_new;

	fig_ellips_new = start_figure(width, height);				
	set_thickness_resolution(fig_ellips_new, thickness, resolution);	
	set_color(fig_ellips_new, c);	

	centre->x=0; centre->y=45;				/* centre of  circle/ellips 		*/
	width_height->x=10; width_height->y=5;   /* set diameter x and diameter y 	*/

	draw_ellipse(fig_ellips_new, centre, width_height);

    export_eps(fig_ellips_new,"ellipse_before_resize.eps");
	draw_x_y_Axis(fig_ellips_new,"ellipse_before_resize.eps");

	resize_figure(fig_ellips_new, fig_ellips_new->start, fig_ellips_new->end);	 

    export_eps(fig_ellips_new,"ellipse_after_resize.eps");
	draw_x_y_Axis(fig_ellips_new,"ellipse_after_resize.eps");
	

/*------------------------------------------------------------------------*/
	
	/* Append Figure 	*/
	Figure *new_fig=fig_circle;
	append_figures(new_fig, fig_polygon);
	append_figures(new_fig, fig_ellips_r);
	export_eps(new_fig,"append.eps");
	draw_x_y_Axis(new_fig,"append.eps");

/*------------------------------------------------------------------------*/

	/* free all memory */
	free_fig(fig_circle);   free_fig(fig_fx_sin);
	free_fig(fig_lines);	free_fig(fig_ellips);   
	free_fig(fig_ellips_new); free_fig(fig_tree);
	free(centre); free(width_height);
/*------------------------------------------------------------------------*/
    return 0;
}