#include "stdafx.h"
#include <iostream>

//Сортування вставками123


void insertion_sort(int* arr, int size) {
	int n, k;
	for (int i = 0; i < size; i++) {
		n = arr[i];
		k = i - 1;
		while (k >= 0 && arr[k] > n) {
			arr[k + 1] = arr[k];
			k = k - 1;
		}
		arr[k + 1] = n;
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int i, size;
	printf("Введите размер массива: \n");
	scanf_s("%d", &size);
	printf("Массив: \n");
	int *sort_arr = (int*)malloc(size * sizeof(int));
	for (i = 0; i<size; i++) {
		sort_arr[i] = rand() % 100;
		printf("%d\t", sort_arr[i]);
	}
	printf("\n");
	insertion_sort(sort_arr, size);
	printf("Отсортированный массив: \n");
	for (int i = 0; i < size; i++) {
		printf("%d\t", sort_arr[i]);
	}
	printf("\n");
	 system("pause");
	return 0;
}