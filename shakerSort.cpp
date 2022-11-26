#include "shakerSort.h"

void countShakerSort(int a[], int n, long long& c)
{
	int l = 0, r = n - 1, k = 0;
	bool sw = 0;
	for (size_t i = l; ++c, i <= r; i++)
	{
		sw = 0;
		for (size_t j = l; ++c, j < r; j++)
		{
			if (++c && a[j] > a[j + 1])
			{
				sw = 1;
				HoanVi(a[j], a[j + 1]);
				k = j;
			}
		}
		if (++c && !sw) return;
		r = k;
		sw = 0;
		for (size_t j = r; ++c, j > l; j--)
		{
			if (++c && a[j] < a[j - 1])
			{
				sw = 1;
				HoanVi(a[j], a[j - 1]);
				k = j;
			}
		}
		if (++c && !sw) return;
		l = k;
	}
}

void shakerSort(int a[], int n)
{
	int l = 0, r = n - 1, k = 0;
	bool sw = 0;
	for (size_t i = l; i <= r; i++)
	{
		sw = 0;
		for (size_t j = l; j < r; j++)
		{
			if (a[j] > a[j + 1])
			{
				sw = 1;
				HoanVi(a[j], a[j + 1]);
				k = j;
			}
		}
		if (!sw) return;
		r = k;
		sw = 0;
		for (size_t j = r; j > l; j--)
		{
			if (a[j] < a[j - 1])
			{
				sw = 1;
				HoanVi(a[j], a[j - 1]);
				k = j;
			}
		}
		if (!sw) return;
		l = k;
	}
}
