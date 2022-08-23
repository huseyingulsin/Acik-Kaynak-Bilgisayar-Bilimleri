#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define PRINT_PREC 8

// Question f(x) = 0
// Alternate form g(x) = x
// Derivative d(x) = f'(x)
double f(double num) {
	return pow(num, 3) - num - 3;
}
double g1(double num) {
	return pow(num, 3) - 3;
}
double g2(double num) {
	return pow(num + 3, 1/3.);
}
double g3(double num) {
	return 3 / (pow(num, 2) - 1);
}
double d(double num) {
	return 3 * pow(num, 2) - 1;
}

// Formatted printing
void printPrecise(double num) {
	printf("%+.*lf\n", PRINT_PREC, num);
}

double newtonRaphson(double(*func)(double), double(*derivative)(double), double num, double precision) {
	double newNum = num - func(num) / derivative(num);
	printPrecise(num);

	if (fabs(newNum - num) < precision) {
		return newNum;
	}

	return newtonRaphson(func, derivative, newNum, precision);
}

double fixedPointIteration(double(*func)(double), double(*alternate)(double), double num, double precision) {
	double newNum = alternate(num);
	printPrecise(newNum);

	if (fabs(newNum - num) < precision) {
		return newNum;
	}

	return fixedPointIteration(func, alternate, newNum, precision);
}

double bisection(double (*func)(double), double min, double max, double precision) {
	double mid = (min + max) / 2;
	double fMid = func(mid);
	printPrecise(mid);

	double pMin = func(min) * fMid;
	double pMax = fMid * func(max);

	if (fabs(pMax - pMin) < precision) {
		return mid;
	}
	if (pMin < 0) {
		return bisection(func, min, mid, precision);
	}
	if (pMax < 0) {
		return bisection(func, mid, max, precision);
	}

	return mid;
}

double regulaFalsi(double (*func)(double), double min, double max, double precision) {
	double rfPoint = (func(max) * min - func(min) * max) / (func(max) - func(min));
	printPrecise(rfPoint);

	double pMin = func(min) * func(rfPoint);
	double pMax = func(rfPoint) * func(max);

	if (fabs(pMax - pMin) < precision) {
		return rfPoint;
	}
	if (pMin < 0) {
		return regulaFalsi(func, min, rfPoint, precision);
	}
	if (pMax < 0) {
		return regulaFalsi(func, rfPoint, max, precision);
	}

	return rfPoint;
}

int main(int argc, char const *argv[]) {
	double precision = +10E-4;

	double initial = +1.5;
	printf("Newton Raphson:\n");
	printPrecise(newtonRaphson(f, d, initial, precision));
	printf("\n");

	printf("Fixed Point Iteration:\n");
	printPrecise(fixedPointIteration(f, g2, initial, precision));
	printf("\n");

	double min = -2.0;
	double max = +4.0;
	printf("Bisection:\n");
	printPrecise(bisection(f, min, max, precision));
	printf("\n");

	printf("Regula Falsi:\n");
	printPrecise(regulaFalsi(f, min, max, precision));
	printf("\n");

	return 0;
}
