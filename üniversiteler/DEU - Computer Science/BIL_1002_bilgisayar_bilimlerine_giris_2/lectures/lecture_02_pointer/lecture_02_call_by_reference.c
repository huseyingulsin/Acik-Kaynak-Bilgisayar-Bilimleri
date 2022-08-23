#include <stdio.h>

#define PI 3.1415

void circle(float radius, float *area, float *circumference) {

	*area = PI * radius * radius;
	*circumference = 2 * PI * radius;

	return;
}

int main(int argc, char const *argv[]) {

	float radius = 1;
	float area, circumference;

	printf("radi: ");
	scanf("%f", &radius);

	circle(radius, &area, &circumference);

	printf("circ: %f\n", circumference);
	printf("area: %f\n", area);

	return 0;
}
