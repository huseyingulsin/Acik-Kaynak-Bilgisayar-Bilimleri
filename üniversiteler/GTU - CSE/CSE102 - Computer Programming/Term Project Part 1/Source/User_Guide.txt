/********************************************************************************
*				       USER GUIDE			    	
*				 Proper Use Of Functions		    
*							                   	
*	--NOTE_1--							    	
*	Fig *Example= start_figure(width, height);				
*										
*	set_thickness_resolution(Example, thickness, resolution);		
*	set_color(Example, c);							
*										
*	draw_fx(Example, --NOTE_2-- , start_x, end_x, step_size);		
*	draw_polyline(Example, Example->point, n);		--NOTE_3--	
*	draw_polygon(Example->point);				--NOTE_3--	
*	draw_ellipse(Example, centre, width_height);				
*	draw_binary_tree(Example, Example->tree );				
*										
*	scale_figure(Example,  scale_x,  scale_y);				
*										
*	Figure *Other_Example;							
*	append_figures(Example, Other_Example);					
*										
*   --NOTE_4--									
*	resize_fig(Example , Exapmle->start , Example->end);			
*	resize_fig_tree(Example , Exapmle->start , Example->end);		
*										
*	export_eps(Exapmle ,"Example.eps");					
*	draw_x_y_Axis(Example ,"Example.eps");					
*	draw_xy_line(fig_fx_sin, "Example.eps", --NOTE_1--  ,start_x, end_x);	
*										
*	free_fig (Example);							
*										
*********************************************************************************
----------------------------------------------------------------------------
NOTE_1; Change your fig name with Example
NOTE_2: You can use fx_square, fx_cube, sin, cos..etc for this veriable
NOTE_3: poly_line draws random n lines, polygon closes the path
NOTE_4: Strongly recommended after every draw function
---------------------------------------------------------------------------*/