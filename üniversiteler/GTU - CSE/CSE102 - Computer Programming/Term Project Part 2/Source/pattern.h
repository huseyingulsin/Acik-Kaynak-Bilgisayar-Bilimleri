/*  This library creates some islamic patterns
	due to the commands.txt and defaults.txt with Eps file format. */

/* Creator	: Muhammed Oğuz */ 
/* Date		: 28.06.2020	*/ 

/* Read User_Guide for understanding how to use commands and defaults settings */

#ifndef PATTERN_H
#define PATTERN_H



/* default commands for Geometric shape */
#define DEFAULT "defaults.txt"

#define PI 3.14

#define TRUE 1
#define FALSE 0
#define SQUARE 4
#define HEXAGON 6

typedef struct Point2D{
    double x,y;
    struct Point2D *next;
}Point2D;

typedef struct Color{
    double r,g,b;
}Color;

typedef struct Geometric{
    double Pattern_Thickness;
    double Grid_Thickness;
    double Tile_Size;
    double Angle;
    double Offset;

    int Show_Grid;
    int Type;

    char *File_Name;

    Point2D Start;
    Point2D End  ;

    Color Grid_Col;
    Color Foreground_Col;
    Color Background_Col;

    Point2D *Grid_Point_X;
    Point2D *Grid_Point_Y;
    Point2D *Point;
    
    struct Geometric *next;

}Geometric;

/* set default commands */
Geometric * default_commands(void);
/* read files for commadns */
void apply_command(char *filename, Geometric **Geo);
/* check mandatory files */
int check_mandatory(char *str);
/* check command type */
void check_command_type(char *str, Geometric *Geo);
/* print if Geo type is true */
void print_Geo(Geometric *Geo);
/* create new point2D */
Point2D * CreatePoint();
/* export points to an eps file */
void export_eps (Geometric *Geo);
/*free all points */
void free_point(Point2D *root);
/*free all geometric objects */
void free_geometric (Geometric *root);

/*set Geo Functions */
void set_back_col(char *str, Geometric *Geo);
void set_foreground_col(char *str, Geometric *Geo);
void set_tile_size (char *str, Geometric *Geo);
void set_angle_offset(char *str, Geometric *Geo);
void set_canvas_size(char *str, Geometric *Geo);
void set_show_grid(char *str, Geometric *Geo);
void set_archetype(char *str, Geometric *Geo);
void set_filename(char *str, Geometric *Geo);
void set_grid_col (char *str, Geometric *Geo);
void set_grid_thickness (char *str, Geometric *Geo);
void set_pattern_thickness(char *str, Geometric *Geo);

/*draw functions */
/* draw grid for square */
void draw_Grid_Square(Point2D **root_X, Point2D **root_Y, Geometric *Geo);
/* draw grid for Hexagon */
void draw_Grid_Hexagon (double x, double y, Geometric *Geo);
/* draw square object */
void draw_Geometric_Square(double x ,double y, Geometric *Geo);
#endif