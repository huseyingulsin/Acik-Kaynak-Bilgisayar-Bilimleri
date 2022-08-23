#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
	int time;

	scanf("%d", &time);

	int h = time / 60 / 60;
	int m = time / 60 % 60;
	int s = time % 60;
	bool pm = h >= 12;
	if(pm) h -= 12;

	printf("%s%d:%s%d:%s%d %s\n",
			h<10 ? "0":"", h,
			m<10 ? "0":"", m,
			s<10 ? "0":"", s,
			pm ? "AM" : "PM"
	);

	return 0;
}
