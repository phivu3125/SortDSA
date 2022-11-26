#include "heapSort.h"

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void countHeapRebuild(int*& a, int k, int n, long long& countCmp)
{
	bool isHeap = 0;
	int j;
	while (++countCmp && isHeap == 0 && ++countCmp && 2 * k + 1 < n)
	{
		j = 2 * k + 1;
		if (++countCmp && j < n - 1)
		{
			if (a[j] < a[j + 1])
			{
				j++;
			}
		}
		if (++countCmp && a[k] >= a[j])
		{
			isHeap = 1;
		}
		else
		{
			swap(a[k], a[j]);
			k = j;
		}
	}
}

void heapRebuild(int*& a, int k, int n)
{
	bool isHeap = 0;
	int j;
	while (isHeap == 0 && 2 * k + 1 < n)
	{
		j = 2 * k + 1;
		if (j < n - 1)
		{
			if (a[j] < a[j + 1])
			{
				j++;
			}
		}
		if (a[k] >= a[j])
		{
			isHeap = 1;
		}
		else
		{
			swap(a[k], a[j]);
			k = j;
		}
	}
}

void countHeapConstruct(int*& a, int n, long long& countCmp)
{
	int index = (n - 1) / 2;

	while (++countCmp && index >= 0)
	{
		countHeapRebuild(a, index, n, countCmp);
		index--;
	}
}


void heapConstruct(int*& a, int n)
{
	int index = (n - 1) / 2;

	while (index >= 0)
	{
		heapRebuild(a, index, n);
		index--;
	}
}

void countHeapSort(int*& a, int n, long long& countCmp)
{
	countHeapConstruct(a, n, countCmp);
	for (int i = n - 1; ++countCmp, i > 0; i--)
	{
		swap(a[0], a[i]);
		countHeapRebuild(a, 0, i, countCmp);
	}
}

void heapSort(int*& a, int n)
{
	heapConstruct(a, n);
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapRebuild(a, 0, i);
	}
}