#include "shellSort.h"

void shellSort(int a[], int n)
{
	for (size_t gap = n / 2; gap > 0; gap /= 2)
	{
		for (size_t i = gap; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (; j >= gap && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}

	}
}

void countShellSort(int a[], int n, long long& c)
{
	for (size_t gap = n / 2; ++c, gap > 0; gap /= 2)
	{
		for (size_t i = gap; ++c, i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (; ++c && j >= gap && ++c && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}