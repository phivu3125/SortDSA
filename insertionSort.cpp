#include "insertionSort.h"

void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

void countInsertionSort(int a[], int n, long long& c)
{
	for (int i = 1; ++c, i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while ((++c && a[k] > key) && (++c && k >= 0))
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}