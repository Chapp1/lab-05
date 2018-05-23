#include "stdafx.h"
#include "time.h"
#include <Windows.h>
void selectionsort(int*, const int);
#define SIZE 5

// Сортування вибором123

int main()
{
	srand(time(NULL));
	int *arr = (int*)malloc(SIZE * sizeof(int));
	printf("Arr:\n");
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = rand() % 100;
		printf("%d\n", arr[i]);
	}
	printf("\nSorted arr:\n");
	selectionsort(arr, SIZE);
	for (int i = 0; i < SIZE; ++i) {
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}

void selectionsort(int* arr, const int size) {
	int i, j, tmp;
	for (i = 0; i < size; ++i) {
		int maxi = i;
		for (j = i + 1; j < size; ++j) {
			if (arr[j] < arr[maxi]) {
				maxi = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[maxi];
		arr[maxi] = tmp;
	}
}