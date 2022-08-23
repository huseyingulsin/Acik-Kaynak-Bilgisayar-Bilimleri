#include <stdio.h>
#include <stdbool.h>

// Checks if a given point is below or above a given line
bool isAboveLine(float slope, float offset, float x, float y) {
	return x > slope * y + offset;
}

int main(int argc, char const *argv[]) {

	float x[3], y[3]; // Points of the triangle
	float qx, qy; // Point given to check if is inside the triangle
	float avgX = 0, avgY = 0; // Average of every point in the triangle

	// Input
	for (int i = 0; i < 3; i++) {
		scanf("%f %f", &x[i], &y[i]);
		avgX += x[i] / 3;
		avgY += y[i] / 3;
	}
	scanf("%f %f", &qx, &qy);

	float slope[3];
	float offset[3];

	// Calculate lines from every 2 points in the triangle
	for (int i = 0; i < 3; i++) {
		// Vector distance
		float deltaX = x[i] - x[(i+1) % 3];
		float deltaY = y[i] - y[(i+1) % 3];

		// Properties of the line
		slope[i] = deltaX / deltaY; // divby0 FIXME
		offset[i] = x[i] - (y[i] * slope[i]);
	}

	// Check for all the lines if the given point falls to the same area as the average point
	// We know for sure that average point of a triangle is inside the triangle itself
	bool inside = true;
	for (int i = 0; i < 3; i++) {
		if(isAboveLine(slope[i], offset[i], qx, qy) != isAboveLine(slope[i], offset[i], avgX, avgY)) {
			inside = false;
		}
	}

	printf("%s\n", inside ? "inside" : "outside");

	return 0;
}
