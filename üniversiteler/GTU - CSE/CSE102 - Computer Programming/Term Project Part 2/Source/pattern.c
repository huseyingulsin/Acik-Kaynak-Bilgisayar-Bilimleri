#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pattern.h"

Geometric * default_commands(void){
    FILE *fp =fopen(DEFAULT, "r");
    if (fp==NULL){
        printf("File (%s) can not found\n", DEFAULT);
        exit (1);
    }

    Geometric *Geo= (Geometric*) malloc (sizeof(Geometric));
    Geo->Point=NULL;
    Geo->Grid_Point_X=NULL;
    Geo->Grid_Point_Y=NULL;
    Geo->next=NULL;
    char str[500];
    while(fscanf(fp,"%[^\n]\n",str)==1){

        /* separete string until see " "(space) */
        char *token= strtok(str," ");

        while (token){
            if (strncmp("//", token,2)==0) break;
            check_command_type(token,Geo);
            token =strtok(NULL, " ");
        }
    }
    fclose (fp);
    return Geo;
}

void apply_command(char *filename,Geometric **Geo_head){
    FILE *fp= fopen(filename, "r");
    if (fp==NULL){
        printf("File (%s) can not found\n", filename);
        return;
    }
    printf("Reading %s...\n",filename);
    char str[500];
    Geometric *Geo=NULL;
    Geometric *Tail=NULL;
    while(fscanf(fp,"%[^\n]\n",str)==1){
        
        if (check_mandatory(str)==0){
            printf("Error!! There are not mandatory commands in this line (Archetype or File_Name )\n\n-----------\n %s\n------------\n",str);
            continue;
          }

        /* set default commnads from defaults.txt */
        Geo=default_commands();

        char *token= strtok(str," ");
        while (token){
            if (strncmp("//", token,2)==0) break;
            check_command_type(token,Geo);
            token =strtok(NULL, " ");
        }
        
        if (*Geo_head==NULL)
            *Geo_head=Geo;
        else
            Tail->next=Geo;
        Tail=Geo;  
    }

    fclose (fp);
    printf("\nReading %s is finished.\n",filename);
}

int check_mandatory(char *str){
    char temp[500];
    strncpy(temp,str,500);
    char *token = strtok(temp, " ");
    int count=0;

    while (token){ 
        if (strncmp("archetype",token,5)==0){
            count++;
        }
        if (strncmp( "file_name",token,5)==0){
            count++;
        }
        if (strncmp("//", token , 2)==0){
            break;
        }
        token = strtok(NULL, " ");
    }

    /* if mandatory files are found, return 1, otherwise return 0. */
    if (count==2)
        return 1;
    else
        return 0;
}

void check_command_type(char *str,Geometric *Geo){
    if (strncmp("grid_color", str, 7)==0){
        set_grid_col(str,Geo);
    }
    else if (strncmp("foreground_color", str, 12)==0){
        set_foreground_col(str, Geo);
    }
    else if (strncmp("background_color", str, 12)==0){
        set_back_col(str, Geo);
    }
    else if (strncmp("pattern_thickness", str, 7)==0){
        set_pattern_thickness(str,Geo);
    }
    else if (strncmp("grid_thickness", str, 7)==0){
        set_grid_thickness(str,Geo);
    }
    else if (strncmp("tile_size", str, 7)==0){
        set_tile_size(str,Geo);
    }
    else if (strncmp("canvas_size", str, 7)==0){
        set_canvas_size(str,Geo);
    }
    else if (strncmp("show_grid", str, 7)==0){
        set_show_grid(str, Geo);
    }
    else if (strncmp("angle_offset", str, 7)==0){
        set_angle_offset(str,Geo);
    }
    else if (strncmp("archetype", str, 7)==0){
        set_archetype(str,Geo);
    }
    else if (strncmp("file_name", str, 7)==0){
        set_filename(str,Geo);
    }
}

void set_back_col(char *str, Geometric *Geo){
    sscanf(str, "background_color:(%lf,%lf,%lf)",&Geo->Background_Col.r, &Geo->Background_Col.g, &Geo->Background_Col.b);
}

void set_foreground_col(char *str, Geometric *Geo){
    sscanf(str, "foreground_color:(%lf,%lf,%lf)",&Geo->Foreground_Col.r, &Geo->Foreground_Col.g, &Geo->Foreground_Col.b );
}

void set_tile_size (char *str, Geometric *Geo){
    sscanf(str,"tile_size:%lf",&Geo->Tile_Size);
}

void set_angle_offset(char *str, Geometric *Geo){
    sscanf(str, "angle_offset:(%lf,%lf)",&Geo->Angle, &Geo->Offset);
}

void set_canvas_size(char *str, Geometric *Geo){
    double width, height;
    sscanf(str,"canvas_size:(%lf,%lf)",&width, &height);
    Geo -> Start.x= -width/2;
	Geo -> Start.y= -height/2;
	Geo -> End.x  = width/2;
	Geo -> End.y  = height/2;
}

void set_show_grid(char *str, Geometric *Geo){
    if (strncmp("show_grid:True",str, 13 )==0){
        Geo->Show_Grid=TRUE;
    }
    else
        Geo->Show_Grid=FALSE;
}

void set_archetype(char *str, Geometric *Geo){
    if (strncmp("archetype:Square", str, 12)==0){
        Geo->Type= SQUARE;
    }
    else{
        Geo->Type= HEXAGON;
    }
}

void set_filename(char *str, Geometric *Geo){
    char *token=strtok(str, ":");
    token =strtok(NULL, " ");
    int len=strlen(token);
    Geo->File_Name=(char*) calloc(len, sizeof(char));
    strncpy(Geo->File_Name,token,len);
}

void set_grid_col (char *str, Geometric *Geo){
    sscanf(str, "grid_color:(%lf,%lf,%lf)", &Geo->Grid_Col.r,&Geo->Grid_Col.g, &Geo->Grid_Col.b);
}

void set_grid_thickness (char *str, Geometric *Geo ){
    sscanf(str,"grid_thickness:%lf", &Geo->Grid_Thickness);
}

void set_pattern_thickness(char *str, Geometric *Geo){
    sscanf(str, "pattern_thickness:%lf", &Geo->Pattern_Thickness);
}

void print_Geo(Geometric *Geo){
    printf("Grid_colr:(%lf %lf %lf)\n",Geo->Grid_Col.r, Geo->Grid_Col.g, Geo->Grid_Col.b );
    printf("foreground_color:(%lf,%lf,%lf)\n", Geo->Foreground_Col.r, Geo->Foreground_Col.g, Geo->Foreground_Col.b);
    printf("background_color:(%lf,%lf,%lf)\n",Geo->Background_Col.r, Geo->Background_Col.g, Geo->Background_Col.b);
    printf("pattern_thickness:%.2lf\n",Geo->Pattern_Thickness);
    printf("grid_thickness:%.2lf\n",Geo->Grid_Thickness);
    printf("tile_size:%.2lf\n",Geo->Tile_Size);
    printf("canvas_size:(upper x: %lf, y: %lf, lower  x: %lf, y: %lf)\n",Geo->Start.x, Geo->Start.y, Geo->End.x, Geo->End.y);

    if (Geo->Show_Grid==TRUE)
        printf("show_grid:True\n");
    else
        printf("show_grid:False\n");

    printf("angle_offset(%lf,%lf)\n",Geo->Angle, Geo->Offset);

    if (Geo->Type==SQUARE)
        printf("Archtpye: SQUARE\n");
    else
        printf("Archtpye: HEXAGON\n");

    printf("File_name: %s\n",Geo->File_Name);
}

void draw_Grid_Square(Point2D **root_X, Point2D **root_Y, Geometric *Geo){
    Point2D *temp_X=CreatePoint();
    temp_X->x= Geo->Start.x;
    temp_X->y= Geo->Start.y;
    if (*root_X==NULL)
        *root_X=temp_X;
    Point2D *Tail_X=temp_X;
    double temp=0;
    while (temp_X->x <= Geo->End.x){
        temp=temp_X->x;
        temp +=Geo->Tile_Size;
        temp_X=CreatePoint();
        temp_X->x=temp;
        temp_X->y=Geo->Start.y;
    
        Tail_X->next=temp_X;
        Tail_X=temp_X;
    }

    Point2D *temp_Y=CreatePoint();
    temp_Y->x= Geo->Start.x;
    temp_Y->y= Geo->Start.y;
    if (*root_Y==NULL)
        *root_Y=temp_Y;
    Point2D *Tail_Y=temp_Y;

    while (temp_Y->y <= Geo->End.y){
        temp=temp_Y->y;
        temp += Geo->Tile_Size;
        temp_Y=CreatePoint();
        temp_Y->y=temp;
        temp_Y->x=Geo->Start.x;
        
        Tail_Y->next=temp_Y;
        Tail_Y=temp_Y;
    }
}

void draw_Grid_Hexagon (double x, double y, Geometric *Geo){
    FILE *fp =fopen(Geo->File_Name, "a+");

    Point2D move;
    Point2D line;

    move.x=x;
    move.y=y;
    double tile_size = Geo->Tile_Size;

    line.x= -tile_size;
    line.y= -tile_size*0.6;

    fprintf(fp,"%lf %lf moveto\n",move.x, move.y);
    fprintf(fp,"%lf %lf rlineto\n",0.0,- tile_size);

    move.y= y - tile_size;
    fprintf(fp,"%lf %lf moveto\n",move.x, move.y);
    fprintf(fp,"%lf %lf rlineto\n",line.x,line.y);
    fprintf(fp,"%lf %lf moveto\n",move.x, move.y);

    line.x= +tile_size;
    fprintf(fp,"%lf %lf rlineto\n",line.x,line.y);
    move.x+=line.x;
    move.y+=line.y;
    fprintf(fp,"%lf %lf moveto\n",move.x, move.y);
    fprintf(fp,"%lf %lf rlineto\n",0.0,-tile_size);

    fclose(fp);
}

void draw_Geometric_Square(double x ,double y, Geometric *Geo){
    FILE *fp =fopen(Geo->File_Name, "a+");
    Point2D move;
    Point2D line;
    double title_size =Geo->Tile_Size, angle=Geo->Angle, offset=Geo->Offset; //for short wiritng
    
    /* calculation for finding each ray */
    double b= (title_size/2 +offset) * sqrt(2); 
    b= b*b;
    double a=b / (2- 2* cos ( (90 + (2* angle)) * PI /180));
    a=sqrt(a); 

    /*if angle bigger than 45, convert */
    if (angle > 45) 
    angle=90 - angle;

    /* assign divide to same value for set ray lenght */
    double divide=1;
    if (angle <=5)
        divide =1000;
    else if (angle <=10)
        divide =9.4;
    else if (angle <=15)
        divide =5.6;
    else if ( angle <= 20)
        divide= 4;
    else if (angle <=25)
        divide =2.7;
    else if (angle <=30)
        divide =2.3;
    else if (angle <=35)
        divide =1.85;
    else if (angle <= 40)
        divide =1.45;
    else if (angle <=45)
        divide =1.2;

    /* Draw 1.two ray */
    move.x= x + title_size/2 - offset;
    move.y= y;

    line.x=title_size/2 + offset - (a/divide * cos(angle * PI/180) );
    line.y=-(a* sin(angle * PI/180) );

    fprintf(fp,"%lf %lf moveto\n", move.x ,move.y);
    fprintf(fp,"%lf %lf rlineto\n", line.x, line.y);
    
    move.x= x + title_size/2 + offset;
    move.y= y;

    line.x=-title_size/2 - offset + (a/divide * cos(angle * PI/180) );
    line.y=-(a* sin(angle * PI/180) );

    fprintf(fp,"%lf %lf moveto\n", move.x ,move.y);
    fprintf(fp,"%lf %lf rlineto\n", line.x, line.y);
    
    /* draw 2.two ray */   
    move.x= x;
    move.y= y - title_size/2 - offset;

    line.x=+(a* sin(angle * PI/180) );
    line.y=+title_size/2 + offset - (a/divide * cos(angle * PI/180) );

    fprintf(fp,"%lf %lf moveto\n", move.x ,move.y);
    fprintf(fp,"%lf %lf rlineto\n", line.x, line.y);

    move.x= x;
    move.y= y - title_size/2 + offset;

    line.x=+(a* sin(angle * PI/180) );
    line.y=-title_size/2 - offset + (a/divide * cos(angle * PI/180) );

    fprintf(fp,"%lf %lf moveto\n", move.x ,move.y);
    fprintf(fp,"%lf %lf rlineto\n", line.x, line.y);
        
    /* Draw 3.two ray */
    move.x= x + title_size/2 - offset;
    move.y= y - title_size;

    line.x=title_size/2 + offset - (a/divide * cos(angle * PI/180) );
    line.y=(a* sin(angle * PI/180) );

    fprintf(fp,"%lf %lf moveto\n", move.x ,move.y);
    fprintf(fp,"%lf %lf rlineto\n", line.x, line.y);

    move.x= x + title_size/2 + offset;
    move.y= y - title_size;

    line.x=-title_size/2 - offset + (a/divide * cos(angle * PI/180) );
    line.y=(a* sin(angle * PI/180) );

    fprintf(fp,"%lf %lf moveto\n", move.x ,move.y);
    fprintf(fp,"%lf %lf rlineto\n", line.x, line.y);

    /* Draw 4.two ray */
    move.x= x + title_size;
    move.y= y - title_size/2 - offset;

    line.x=-(a* sin(angle * PI/180) );
    line.y=+title_size/2 + offset - (a/divide * cos(angle * PI/180) );

    fprintf(fp,"%lf %lf moveto\n", move.x ,move.y);
    fprintf(fp,"%lf %lf rlineto\n", line.x, line.y);

    move.x= x + title_size;
    move.y= y - title_size/2 + offset;

    line.x=-(a* sin(angle * PI/180) );
    line.y=-title_size/2 - offset + (a/divide * cos(angle * PI/180) );

    fprintf(fp,"%lf %lf moveto\n", move.x ,move.y);
    fprintf(fp,"%lf %lf rlineto\n", line.x, line.y);

    fclose(fp);
}

void export_eps(Geometric *Geo){
    FILE *fp =fopen(Geo->File_Name, "wt");
    if (fp==NULL){
        printf("Can not created new file named %s\nExiting...\n",Geo->File_Name);
        exit(1);
    }

    fprintf(fp,"%%!PS-Adobe-3.0 EPSF-3.0\n");
    fprintf(fp,"%%%%BoundingBox: %lf %lf %lf %lf\n", Geo->Start.x ,Geo->Start.y ,Geo->End.x ,Geo->End.y);
    
    /* draw background color */
    fprintf(fp,"\n\nnewpath\n");
    fprintf(fp,"%lf %lf moveto\n",Geo->Start.x, Geo->Start.y);
    fprintf(fp,"%lf %lf lineto\n",Geo->Start.x,Geo->End.y);
    fprintf(fp,"%lf %lf lineto\n",Geo->End.x,Geo->End.y);
    fprintf(fp,"%lf %lf lineto\n",Geo->End.x,Geo->Start.y);
    fprintf(fp,"closepath gsave\n");
    fprintf(fp,"0.%0.lf 0.%0.lf 0.%0.lf setrgbcolor\n",Geo->Background_Col.r*5, Geo->Background_Col.g*5, Geo->Background_Col.b*5);
    fprintf(fp,"fill stroke\n");

    /* draw Grid if it is True */
    if (Geo->Show_Grid==TRUE){

        fprintf(fp,"\n\nnewpath\n");
        fprintf(fp,"%.2lf setlinewidth\n", Geo->Grid_Thickness);
        fprintf(fp,"0.%.0lf 0.%.0lf 0.%.0lf setrgbcolor\n",Geo->Grid_Col.r*3, Geo->Grid_Col.g*3, Geo->Grid_Col.b*3);

        /* if shape a Square */
        if (Geo->Type==SQUARE){
            while (Geo->Grid_Point_X){
                fprintf(fp,"%lf %lf moveto\n",Geo->Grid_Point_X->x, Geo->Grid_Point_X->y);
                fprintf(fp,"%lf %lf lineto\n",Geo->Grid_Point_X->x, Geo->End.y);
                Geo->Grid_Point_X=Geo->Grid_Point_X->next;
            }
            while (Geo->Grid_Point_Y){
                fprintf(fp,"%lf %lf moveto\n",Geo->Grid_Point_Y->x, Geo->Grid_Point_Y->y);
                fprintf(fp,"%lf %lf lineto\n",Geo->End.x ,Geo->Grid_Point_Y->y);
                Geo->Grid_Point_Y=Geo->Grid_Point_Y->next;
            }
        }

        /* if shape a Hexagon */
        if (Geo->Type==HEXAGON){
            printf("before grid hex \n");
            fclose(fp);
            int keep=0;
            double add=0;
            for (double i=Geo->End.y; i>=Geo->Start.y; i-=Geo->Tile_Size*2){
                if (keep%2) add=Geo->Tile_Size;
                else add=0;
                keep++;
                for (double j=Geo->Start.x+add; j<=Geo->End.x; j+=Geo->Tile_Size*2){
                    draw_Grid_Hexagon(j,i,Geo);
                }
            }
            fp =fopen(Geo->File_Name, "a+");
        }

        fprintf(fp,"stroke\n");
    }

    
    /* draw Geomatric object */
    fprintf(fp,"\n\nnewpath\n");
    fprintf(fp,"%.2lf setlinewidth\n", Geo->Pattern_Thickness);
    fprintf(fp,"0.%.0lf 0.%.0lf 0.%.0lf setrgbcolor\n",Geo->Foreground_Col.r*3,Geo->Foreground_Col.g*3,Geo->Foreground_Col.b*3);
    
    fclose(fp);
    

    if (Geo->Type==SQUARE){
        for (double i = Geo->End.y; i>= Geo->Start.y; i-=Geo->Tile_Size){
            for (double j= Geo->Start.x; j<= Geo->End.x; j+=Geo->Tile_Size){
                draw_Geometric_Square(j,i,Geo);
            }
        }
    }

    if (Geo->Type==HEXAGON){
            int keep=0;
            double add=0;
            for (double i=Geo->End.y; i>=Geo->Start.y; i-=Geo->Tile_Size*2){
                if (keep%2) add=Geo->Tile_Size;
                else add=0;
                keep++;
                for (double j=Geo->Start.x+add; j<=Geo->End.x; j+=Geo->Tile_Size*2){
                    draw_Grid_Hexagon(j,i,Geo);
                }
            }
        
    }

    fp =fopen(Geo->File_Name, "a+");
    fprintf(fp,"stroke\n");

    fclose(fp);
}

Point2D * CreatePoint(){
    Point2D *Point= (Point2D *) malloc(sizeof(Point2D));
    Point->next=NULL;
    return Point; 
}

void free_point(Point2D *root){
    Point2D *head=root;
    if (head==NULL)
        return;
    while (head){
   		Point2D *temp=head;
   		head=head->next;
   		free(temp);
   	}
}

void free_geometric (Geometric *root){
    Geometric *head=root;
    while (head->next){
   		Geometric *temp=head;
   		head=head->next;
        if (temp->Grid_Point_X)
            free_point(temp->Grid_Point_X);
        if (temp->Grid_Point_Y)
            free_point(temp->Grid_Point_Y);
        if (temp->File_Name)
            free(temp->File_Name);
   		free(temp);
   	}
}

