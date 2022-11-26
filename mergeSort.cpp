#include "mergeSort.h"

void countMerge(int*& a, int left, int mid, int right, long long&countCmp)
{
	int n = right - left + 1;
	int* b = new int[n];

	int k = 0;
	int i = left; // chay tu left toi mid
	int j = mid + 1;// chay tu mid + 1 toi right

	while (++countCmp && j <= right && ++countCmp && i <= mid)// vong lap xet khi chua chay het nua mang
	{
		if (++countCmp && a[i] <= a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else
		{
			b[k] = a[j];
			k++;
			j++;
		}
	}
	while (++countCmp && j <= right && ++countCmp && i > mid)// neu mang dau da xong truoc
	{
		b[k] = a[j];
		k++;
		j++;
	}
	while (++countCmp && i <= mid && ++countCmp && j > right)// neu mang sau da xong truoc
	{
		b[k] = a[i];
		k++;
		i++;
	}

	i = left;
	for (int m = 0; ++countCmp, m < n; m++)
	{
		a[i] = b[m];
		i++;
	}
	delete[]b;
}

void Merge(int*& a, int left, int mid, int right)
{
	int n = right - left + 1;
	int* b = new int[n];

	int k = 0;
	int i = left; // chay tu left toi mid
	int j = mid + 1;// chay tu mid + 1 toi right

	while (j <= right && i <= mid)// vong lap xet khi chua chay het nua mang
	{
		if (a[i] <= a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else
		{
			b[k] = a[j];
			k++;
			j++;
		}
	}
	while (j <= right && i > mid)// neu mang dau da xong truoc
	{
		b[k] = a[j];
		k++;
		j++;
	}
	while (i <= mid && j > right)// neu mang sau da xong truoc
	{
		b[k] = a[i];
		k++;
		i++;
	}

	i = left;
	for (int m = 0; m < n; m++)
	{
		a[i] = b[m];
		i++;
	}
}

void countMergeSort(int*& a, int left, int right, long long& countCmp)
{
	if (++countCmp && left < right)
	{
		int mid = (left + right) / 2;
		countMergeSort(a, left, mid, countCmp);
		countMergeSort(a, mid + 1, right, countCmp);
		countMerge(a, left, mid, right, countCmp);
	}
}

void mergeSort(int*& a, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}