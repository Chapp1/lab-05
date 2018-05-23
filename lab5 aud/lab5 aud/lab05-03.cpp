#include "stdafx.h"
#include <Windows.h>
#include <math.h>
#define ctg 1/tan
//123

typedef double(*func_t)(double);
double trapezia(double, double, double, func_t);
double f(double);
double res();

int main()
{
	double a = 2, b = 4, eps = 1e-5;
	printf("Integral:\nI=%.5f\n", trapezia(a, b, eps, f));
	printf("result: \nI=%.5f\n", res());
	system("pause");
	return 0;
}

double trapezia(double a, double b, double eps, func_t f)
{
	double S = 0, h = 0.01;
	while (a < b)
	{
		S = S + (f(a + h) + f(a))*h / 2;
		if (0.5*(f(a + h) + f(a))*h >= eps)
			a = a + h;
		else
			break;

	}
	
	return S;
}

double f(double t)
{
	return exp(t) / (1 + exp(2 * t));
}

double res()
{
	return ctg(exp(4)) - ctg(exp(2));
}