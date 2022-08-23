#include "pattern.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* set SHOW_INFO 1 for see info about each object */
#define SHOW_INFO 1

#define COMMANDS "commands.txt"


int main(void){

	Geometric *Geo=NULL;

	/* apply commands with commands.txt and defaults.txt */
	apply_command(COMMANDS, &Geo);
	Geometric *head=Geo;

	int i=1;
	while (head){
	
		/* If at the top, SHOW_INFO veraible equal to 1, show info */
		if (SHOW_INFO){
			printf("\n---------------------------- Shape %d Info ----------------------------\n\n",i);
			print_Geo(head);
			printf("\n");
			i++;
		}

		/* if shape is square do this */
		/* Ps: Hexagon part is in export_eps func, so I did not use it in main */
		if (Geo->Type==SQUARE){
			draw_Grid_Square(&head->Grid_Point_X,&head->Grid_Point_Y, head);
		}

		/* draw to an eps file  */
		export_eps(head);

		/* move to next pointer */
		head=head->next;
	}

	printf("\nAll files created succesfully \n\n");
	/* free all memory allocated */
	free_geometric(Geo);
}