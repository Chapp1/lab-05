// lab5 aud.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
//Число Фібоначі123

int fib_tail(int n, int p, int c)
{
	int f;
	if (n <= 2) {
		f = c;
		printf("%d\n", c);
		return f;
	}
	return fib_tail(n - 1, c, p + c);
}

int main()
{
	int i, j;
	for (i = 1; i <= 20; i++) {
		j = fib_tail(i, 1, 1);
	}
	
	system("pause");
	return 0;
}