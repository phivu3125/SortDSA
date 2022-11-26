#include "Header.h"

int countGetMax(int* a, int n, long long &countCmp)
{
	int max = a[0];
	for (int i = 0; ++countCmp, i < n; i++)
	{
		if (++countCmp && a[i] > max )
		{
			max = a[i];
		}
	}
	return max;
}

int getMax(int* a, int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

void countSortDigit(int*& a, int n, int d, long long&countCmp)
{
	int count[10] = { {0} };
	int* outPut = new int[n];

	for (int i = 0; ++countCmp, i < n; i++)
	{
		count[a[i] / d % 10]++;
	}
	//--------------------------------

	for (int i = 1; ++countCmp, i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	//--------------------------------

	for (int i = n - 1; ++countCmp, i >= 0; i--)
	{
		outPut[count[a[i] / d % 10] - 1] = a[i];
		count[a[i] / d % 10]--;
	}
	//--------------------------------

	for (int i = 0; ++countCmp, i < n; i++)
	{
		a[i] = outPut[i];
	}
}

void SortDigit(int*& a, int n, int d)
{
	int count[10] = { {0} };
	int* outPut = new int[n];

	for (int i = 0; i < n; i++)
	{
		count[a[i] / d % 10]++;
	}
	//--------------------------------

	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	//--------------------------------

	for (int i = n - 1; i >= 0; i--)
	{
		outPut[count[a[i] / d % 10] - 1] = a[i];
		count[a[i] / d % 10]--;
	}
	//--------------------------------

	for (int i = 0; i < n; i++)
	{
		a[i] = outPut[i];
	}
}

void countRadixSort(int*& a, int n, int d, long long&countCmp)
{
	int m = countGetMax(a, n, countCmp);

	for (int i = 0; ++countCmp, i < d; i++)
	{
		countSortDigit(a, n, pow(10, i), countCmp);
	}
}

void radixSort(int*& a, int n, int d)
{
	int m = getMax(a, n);

	for (int i = 0; i < d; i++)
	{
		SortDigit(a, n, pow(10, i));
	}
}