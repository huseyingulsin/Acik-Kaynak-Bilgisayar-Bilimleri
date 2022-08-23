#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

#define MAX(x,y) ((x>y)?x:y)
#define BUILDING_COUNT_LIMIT 100

// BUILDING STRUCT ----------------------------------------------------------------------------------------------------

// Building data type
typedef struct Building {
	int width;
	int height;
	int position;
} Building;

// Input function with break condition
void readBuilding(Building *building) {
	scanf("%d", &building->width);
	if(building->width == -1) return;
	scanf("%d", &building->height);
	if(building->height == -1) return;
	scanf("%d", &building->position);
	if(building->position == -1) return;
}

// To check for incomplete input
bool isValidBuilding(Building *building) {
	return building->width != -1 && building->height != -1 && building->position != -1;
}

// For debug purposes only
void printBuilding(Building *building) {
	printf("%d %d %d\n", building->width, building->height, building->position);
}

// MAIN ---------------------------------------------------------------------------------------------------------------

int main(int argc, char const *argv[]) {
	Building buildings[BUILDING_COUNT_LIMIT];
	int buildingCount = 0;


	char c;
	int n;

	do {
		printf("int: %d char: %c\n", n, c);

		printf("scanf int: ");
		scanf("%d", &n);

		printf("getch char: ");
		c = getchar();
		printf("\n");

	} while(c=='e' || c=='E');



	// Read buildings untill an invalid one is read
	while (false) {
		readBuilding(&buildings[buildingCount]);
		if(isValidBuilding(&buildings[buildingCount])) buildingCount++;
		else break;
	}

	return 0;
}
