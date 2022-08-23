// truck gas price problem

#include <stdio.h>
#include <limits.h>

#define LIMIT 10

// generates gas price from delivery distance
int distanceToPrice(int distance) {
	if (distance < 100) return distance * 5000;
	if (distance < 200) return distance * 6000;
	if (distance < 600) return distance * 7000;
	return distance * 9000;
}

int main(int argc, char const *argv[]) {

	int minPrice = INT_MAX, minIndex;

	int index = 0;
	while (index < 10) {
		int currentDistance;
		printf("kamyon %d km: ", index);
		scanf("%d", &currentDistance);

		if (distanceToPrice(currentDistance) < minPrice) {
			minPrice = distanceToPrice(currentDistance);
			minIndex = index;
		}

		index++;
	}

	printf("min index: %d\n", minIndex);
	printf("min price: %d\n", minPrice);

	return 0;
}
