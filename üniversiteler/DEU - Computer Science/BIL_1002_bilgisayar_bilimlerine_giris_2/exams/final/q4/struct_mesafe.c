#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define FILE_NAME "points.dat"

typedef struct {
	int x, y;
	float dist;
} point;

int main() {
	srand(time(NULL));
	point p[SIZE];
	FILE* f = fopen(FILE_NAME, "wb+");

	for (int i = 0; i < SIZE; i++) {
		p[i].x = rand() % 21 - 10;
		p[i].y = rand() % 21 - 10;
		p[i].dist = sqrt(pow(p[i].x, 2) + pow(p[i].y, 2));
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (p[i].dist > p[j].dist) {
				point tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
		fwrite(&p[i], sizeof(point), 1, f);
	}

	int selection;
	scanf("%d", &selection);

	point po;
	fseek(f, sizeof(point) * selection, SEEK_SET);
	fread(&po, sizeof(point), 1, f);

	printf("%d %d %f\n", po.x, po.y, po.dist);
}
