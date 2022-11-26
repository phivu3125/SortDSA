#include "countingSort.h"


int getMin(int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}

int countGetMin(int a[], int n, long long& countCmp)
{
	int min = a[0];
	for (int i = 0; ++countCmp, i < n; i++)
	{
		if (++countCmp && min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}

void countingSort(int a[], int n, int min, int max)
{
	int d = 0; 
	int cs = max - min;

    int *count = new int [cs + 1];

    for (int i = 0; i <= cs; i++)
        count[i] = 0;
  
    for (int i = 0; i < n; i++)
        count[a[i] - min]++;

    for (int i = 0; i <= cs; i++)
        if (count[i] > 0)
            for (int j = 1; j <= count[i]; j++)
                a[d++] = i + min;
}

void countCountingSort(int a[], int n, int min, int max, long long&countCmp)
{
	int d = 0;
	int cs = max - min;

	int* count = new int[cs + 1];

	for (int i = 0; ++countCmp, i <= cs; i++)
		count[i] = 0;

	for (int i = 0; ++countCmp, i < n; i++)
		count[a[i] - min]++;

	for (int i = 0; ++countCmp, i <= cs; i++)
		if (++countCmp && count[i] > 0)
			for (int j = 1; ++countCmp, j <= count[i]; j++)
				a[d++] = i + min;
}