#include "quickSort.h"

int Median(int a[], int l ,int r)
{
	int mid = (l + r) / 2;
	if (a[r] < a[l] )
	{
		HoanVi(a[l], a[r]);
	}
	if (a[mid] < a[l])
	{
		HoanVi(a[l], a[mid]);
	}
	if (a[r] < a[mid])
	{
		HoanVi(a[mid], a[r]);
	}
	return mid;
}

int countMedian(int a[], int l, int r, long long& countCmp)
{
	int mid = (l + r) / 2;
	if (++countCmp && a[r] < a[l])
	{
		HoanVi(a[l], a[r]);
	}
	if (++countCmp && a[mid] < a[l])
	{
		HoanVi(a[l], a[mid]);
	}
	if (++countCmp && a[r] < a[mid])
	{
		HoanVi(a[mid], a[r]);
	}
	return mid;
}
int patrition(int a[], int l, int r)
{
	int l1 = l, fu = l + 1, p = l;
	while (fu <= r)
	{
		if (a[fu] < a[p])
		{
			HoanVi(a[fu], a[++l1]);
		}
		fu++;
	}
	HoanVi(a[l1], a[p]);
	p = l1;
	return p;
}

int countPatrition(int a[], int l, int r, long long& c)
{
	int l1 = l, fu = l + 1, p = l;
	while (++c && fu <= r)
	{
		if (++c && a[fu] < a[p])
		{
			HoanVi(a[fu], a[++l1]);
		}
		fu++;
	}
	HoanVi(a[l1], a[p]);
	p = l1;
	return p;
}

void quickSort(int a[], int l, int r)
{
	if (l < r)
	{
		HoanVi(a[l], a[Median(a, l, r)]);
		int p = patrition(a, l, r);
		quickSort(a, l, p - 1);
		quickSort(a, p + 1, r);
	}
}

void countQuickSort(int a[], int l, int r, long long& c)
{
	if (++c && l < r)
	{
		HoanVi(a[l], a[countMedian(a, l, r, c)]);
		int p = countPatrition(a, l, r, c);
		countQuickSort(a, l, p - 1, c);
		countQuickSort(a, p + 1, r, c);
	}
}