#include "stdafx.h"
#include <Windows.h>
#include <math.h>
//123123
#define SIGN_FUNC(func, x) ((func(x) > 0)? 1 : (func(x) < 0)? -1 : 0)
#define CHECK_ROOT_TOL(func, x, e)\
if (fabs(func(x)) <= (e))\
{\
return x;\
}
#define CHECK_DIFF_SIGN(s1, s2) s1 != s2
#define PRINT_MID_STAGE
typedef double(*func_t)(double);
int local(func_t, double, double);
double bisection(func_t, double, double, double);
double secant(func_t, double, double, double);
double f(double);

int main()
{
	double a = -3, b = 6, eps = 1e-8, h = 0.01;
	for (a; a < b; a += h)
	{
		if (local(f, a, a + h))
		{
			printf("interval [%.3f, %.3f]\n", a, a + h);
			double x0 = bisection(f, a, a + h, eps);
			printf("kor: %lf\n", x0);
			double x1 = secant(f, b, eps, a);
			printf("kor: %lf\n", x1);
		}
	}
	system("pause");
	return 0;
}


int local(func_t f, double a, double b)
{
	return SIGN_FUNC(f, a) != SIGN_FUNC(f, b);
}

double bisection(func_t f, double a, double b, double e) {
	double c = 0;
	printf("metod_bisek\n");
	do
	{
		c = (a + b) / 2;
		int sgn1 = SIGN_FUNC(f, a);
		int sgn2 = SIGN_FUNC(f, b);
		int sgn3 = SIGN_FUNC(f, c);
#ifdef PRINT_MID_STAGE
		printf("%.5f\t%.5f\t%.5f\n", a, c, b);
		printf("%d\t%d\t%d\n", sgn1, sgn3, sgn2);

#endif
		CHECK_ROOT_TOL(f, a, e);
		CHECK_ROOT_TOL(f, c, e);
		CHECK_ROOT_TOL(f, b, e);
		if (CHECK_DIFF_SIGN(sgn1, sgn3))
		{
			b = c;
		}
		else {
			if (CHECK_DIFF_SIGN(sgn3, sgn2))
			{
				a = c;
			}
		}
	} while (fabs(a - b) > e);
	return c;
}

double secant(func_t f, double a, double b, double eps) {
	printf("-----------------------Метод хорд------------------------\n");
	do {
		a = b - ((b - a) * f(b)) / (f(b) - f(a));
		b = a - ((a - b) * f(a)) / (f(a) - f(b));
	} while (fabs(f(b)) > eps);
	return b;
}

double f(double x) {
	return pow(x, 3) - 3 * x * x - 24 * x - 5;
}