#include "selectionSort.h"

int findIndexofLargest(int a[], int size)
{
	int largest = 0;
	for (int i = 0; i <= size; i++)
	{
		if (a[i] > a[largest])
		{
			largest = i;
		}
	}
	return largest;
}

int countFindIndexofLargest(int a[], int size, long long&countCmp)
{
	int largest = 0;
	for (int i = 0;++countCmp, i <= size; i++)
	{
		if (++countCmp && a[i] > a[largest])
		{
			largest = i;
		}
	}
	return largest;
}

void selectionSort(int a[], int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		int largest = findIndexofLargest(a, i);
		swap(a[largest], a[i]);
	}
}

void countSelectionSort(int a[], int n, long long&countCmp)
{
	for (int i = n - 1; ++countCmp, i > 0; i--)
	{
		int largest = countFindIndexofLargest(a, i, countCmp);
		swap(a[largest], a[i]);
	}
}