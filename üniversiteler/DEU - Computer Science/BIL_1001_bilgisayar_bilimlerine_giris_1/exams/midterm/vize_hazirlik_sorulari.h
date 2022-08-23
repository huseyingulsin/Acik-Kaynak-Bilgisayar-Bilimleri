#include <math.h>

double double_equals(double a, double b) {
	return abs(a-b) < 0.000001;
}

// Soru 1:
bool f_01(double x, double y) {
	return abs(x) + abs(y) > 1 && abs(x) < 1 && abs(y) < 1;
}

// Soru 2:
bool f_02(double x, double y) {
	return x*x + y*y > 1 && abs(x) < 1 && abs(y) < 1;
}

// Soru 3:
bool f_03(double x, double y) {
	return y < -x*x + 2 && y > 0;
}

// Soru 4:
bool f_04(double x, double y) {
	return abs(x-1) + abs(y) < 1 && x < 1 && abs(y) < 1;
}

// Soru 5:
bool f_05(double x, double y) {
	return abs(y-x) > 1 && x*x + y*y < 1;
}

// Soru 6:
bool f_06(double x, double y) {
	return x*x + y*y < 4 && (x+1)*(x+1) + y*y > 1;
}

// Soru 7:
bool f_07(double x, double y) {
	return x*x + y*y > 1 && abs(x) < 2 && abs(y) < 1;
}

// Soru 8:
bool f_08(double x, double y) {
	return y < -x*x + 2 && y > abs(x);
}

// Soru 9:
bool f_09(double x, double y) {
	return false; // Sorunun grafigi acik degil
}

// Soru 10:
bool f_10(double x, double y) {
	return abs(x) + abs(y-1) < 1 && abs(x) < 1 && y < 1;
}

// Soru 11:
bool f_11(double x, double y) {
	return abs(x) + abs(abs(y)-1) < 1 && abs(x) < 1 && abs(y) < 1;
}

// Soru 12:
bool f_12(double x, double y) {
	return abs(x) + abs(y-1) < 1 && abs(x) < 1 && y < 1 || double_equals(x*x + y*y, 1);
}

// Soru 13:
bool f_13(double x, double y) {
	return y*y < x && x < 1;
}

// Soru 14:
bool f_14(double x, double y) {
	return abs(x) + abs(y) < 1 && y > 0 || float_equals(x*x + y*y, 1);
}

// Soru 15:
bool f_15(double x, double y) {
	return abs(x-1) + abs(y-1) < 1;
}

// Soru 16:
bool f_16(double x, double y) {
	return x*x + y*y < 1 && pow(x-2, 2) + y*y < 4;
}

// Soru 17:
bool f_17(double x, double y) {
	return abs(x-1.5) + abs(y) < .5;
}

// Soru 18:
bool f_18(double x, double y) {
	return y > x*x - 2 && y < x;
}

// Soru 19:
bool f_19(double x, double y) {
	return x*x + y*y > 1 && x*x + y*y < 4;
}

// Soru 20:
bool f_20(double x, double y) {
	return abs(x) + abs(y) > 2 && abs(x) < 2 && abs(y-1) < 1;
}

// Soru 21:
bool f_21(double x, double y) {
	return y > -x*x + 2 && x*x + y*y < 4;
}

// Soru 22:
bool f_22(double x, double y) {
	return x*x + y*y > 1 && abs(x) < 1 && abs(y-.5) < .5;
}

// Soru 23:
bool f_23(double x, double y) {
	return abs(x-1) + abs(y) < 1;
}

// Soru 24:
bool f_24(double x, double y) {
	return y > x*x-2 && y < abs(x);
}

// Soru 25:
bool f_25(double x, double y) {
	return abs(x) + abs(y+1) < 1 && y > -1;
}

// Soru 26:
bool f_26(double x, double y) {
	return abs(x) + abs(y) > 1 && abs(y-1) < 1 && abs(x) < 1;
}

// Soru 27:
bool f_27(double x, double y) {
	return y > 0 && 1-abs(x) + y < 1 && abs(x) < 1;
}

// Soru 28:
bool f_28(double x, double y) {
	return abs(x) + abs(y) > 1 && abs(x) + abs(y) < 2 && y > 0;
}

// Soru 29:
bool f_29(double x, double y) {
	return abs(x) < 1 && abs(y-.5) < .5 && x*x + pow(y-1, 2) > 1;
}

// Soru 30:
bool f_30(double x, double y) {
	return y < x*x && y > 0 && abs(x) < 1;
}
