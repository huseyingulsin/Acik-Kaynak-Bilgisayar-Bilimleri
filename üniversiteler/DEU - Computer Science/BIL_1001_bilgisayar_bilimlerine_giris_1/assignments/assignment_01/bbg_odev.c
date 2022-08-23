/*
	A C program that solves the skyline problem
	Author: Onat Saygi
	Written for: Dokuz Eylul University - Computer Science - Introduction to Computer Science 1 - First assingment
	Runs in O(n * log(n) + n * m) time
	N as the number of buildings, m as maximum concurrent shadowing buildings
	Could be improved to O(n * log(n)) by using a hashmap instead of an array for [buildingHeights]
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

// ARRAY FUNCTIONS ----------------------------------------------------------------------------------------------------

// Removes the first value specified from the array and reallocates memory to it
void arrayRemoveValue(int *array, int *arraySizePtr, int value) {
	for (int i = 0; i < *arraySizePtr; i++) {
		if(array[i] == value) {
			for (int j = i; j < *arraySizePtr-1; j++) array[j] = array[j+1];
			break;
		}
	}
	*arraySizePtr -= 1;
	// Disabled as a temporary memory fix
	//array = (int*) realloc(array, sizeof(int) * (*arraySizePtr));
}

// Reallocates the array and appends the specified value
void arrayAppendValue(int *array, int *arraySizePtr, int value) {
	array = (int*) realloc(array, sizeof(int) * (*arraySizePtr + 1));
	array[*arraySizePtr] = value;
	*arraySizePtr += 1;
}

// Prints an integer array
// For debug purposes only
void printArray(int *array, int arraySize) {
	printf("[");
	for (int i = 0; i < arraySize-1; i++) printf("%d, ", array[i]);
	if(arraySize > 0) printf("%d]\n", array[arraySize-1]);
	else printf("]\n");
}

// Returns the maximum value for a given array
int arrayMax(int *array, int arraySize) {
	if(arraySize < 1) return NULL;

	int max = array[0];
	for (int i = 1; i < arraySize; i++) max = MAX(max, array[i]);
	return max;
}

// WALL STRUCT --------------------------------------------------------------------------------------------------------

// Datatype for edges of buildings
typedef struct Wall {
	int position;
	int height;
	bool rising;
} Wall;


// Custom sorting function for [Wall]
// Sorts by position first then rising reversed
int compareWall (const void *a, const void *b) {
	Wall *s1 = (Wall *)a;
	Wall *s2 = (Wall *)b;

	int posDelta = s1->position - s2->position;

	if(posDelta == 0) return s1->rising < s2->rising;
	return posDelta;
}

// MAIN ---------------------------------------------------------------------------------------------------------------

int main(int argc, char const *argv[]) {
	Building buildings[BUILDING_COUNT_LIMIT];
	int buildingCount = 0;

	// Read buildings untill an invalid one is read
	while (true) {
		readBuilding(&buildings[buildingCount]);
		if(isValidBuilding(&buildings[buildingCount])) buildingCount++;
		else break;
	}

	// Edge case for no buildings
	if(buildingCount == 0) {
		printf("0\n");
		return 0;
	}

	/*for (int i = 0; i < buildingCount; i++) {
		printBuilding(&buildings[i]);
	}*/

	int wallsSize = buildingCount*2;
	Wall *walls = (Wall*) malloc(sizeof(Wall) * wallsSize);

	// Generate 2 [walls] from all [buildings] one for rising one for dipping walls
	for (int i = 0; i < buildingCount; i++) {
		walls[i].position = buildings[i].position;
		walls[i].height = buildings[i].height;
		walls[i].rising = true;

		walls[i + buildingCount].position = buildings[i].position + buildings[i].width;
		walls[i + buildingCount].height = buildings[i].height;
		walls[i + buildingCount].rising = false;
	}

	// Sort the building walls so height differences can be calculated
	qsort(walls, wallsSize, sizeof(Wall), compareWall);

	// As the walls are sorted we can now the total horizontalDistance for sure
	int horizontalDistance = walls[wallsSize-1].position - walls[0].position;
	int verticalDistanceSum = 0;

	int *buildingHeights = (int*) malloc(0);
	buildingHeights[0] = 0;
	int buildingHeightsSize = 0;

	// Iterating through all the rising and falling walls to calculate the vertical difference
	// Vertical difference will be the difference of the highest wall height
	for (int i = 0; i < wallsSize; i++) {
		int maxHeight = arrayMax(buildingHeights, buildingHeightsSize);

		if(walls[i].rising) arrayAppendValue(buildingHeights, &buildingHeightsSize, walls[i].height);
		else arrayRemoveValue(buildingHeights, &buildingHeightsSize, walls[i].height);

		horizontalDistance += abs(arrayMax(buildingHeights, buildingHeightsSize) - maxHeight);
	}

	// Output
	printf("%d\n", verticalDistanceSum + horizontalDistance);

	return 0;
}
