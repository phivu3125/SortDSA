#include "bubbleSort.h"

void countBubbleSort(int arr[], int n, long long &countCmp)
{
	int i, j;
	for (i = 0; ++countCmp, i < n - 1; i++)
		for (j = 0; ++countCmp, j < n - i - 1; j++)
			if (++countCmp && arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}


void bubbleSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}
