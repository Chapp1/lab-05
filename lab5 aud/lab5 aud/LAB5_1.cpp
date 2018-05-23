#include "stdafx.h"
#include <iostream>
using namespace std;
bool PALINDROM(int a) {
	int temp = a; //Объявляем временную переменную со значением исходного числа

	int b = 0; //Число перевернутое123123123123123
	while (temp != 0)
	{
		b = b * 10 + temp % 10; //Переворачиваем число по цифрам
		temp /= 10; //Отбрасываем последнюю цифру
	}

	if (a == b)
		return true;
	return false;
}
bool prost(int x)
{
	for (int i = sqrt(x); i > 1; i--)
		if (!(x % i))
			return false;

	return true;
}
int main()
{
	for (int i = 1001; i < 10000; i++)
	{
		if (!prost(i))
			continue;
		for (int j = i; j < 10000; j++) {
			if (prost(j)) {
				if (PALINDROM(i*j)) {
					cout << i << " " << j << endl;
					
				}
			}
		}
	}
	
system("pause");
return 0;
}