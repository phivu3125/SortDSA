#include "flashSort.h"

void flashSort(int a[], int n) {
	int minVal = a[0], maxIdx = 0;
	int buckets = int(0.45 * n);
	int* l = new int[buckets];
	for (size_t i = 0; i < buckets; i++)
	{
		l[i] = 0;
	}
	for (size_t i = 1; i < n; i++)
	{
		if (a[i] < minVal) minVal = a[i];
		if (a[i] > a[maxIdx]) maxIdx = i;
	}
	if (a[maxIdx] == minVal) {
		delete[]l;
		return;
	}
	double c1 = (double)(buckets - 1) / (a[maxIdx] - minVal);
	for (size_t i = 0; i < n; i++)
	{
		int bucketIdx = int(c1 * (a[i] - minVal));
		l[bucketIdx]++;
	}
	for (size_t i = 1; i < buckets; i++)
	{
		l[i] += l[i - 1];
	}
	HoanVi(a[maxIdx], a[0]);
	int nmove = 0;
	int j = 0;
	int k = buckets - 1;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			--l[k];
			HoanVi(flash, a[l[k]]);
			++nmove;
		}
	}
	delete[]l;
	insertionSort(a, n);
}

void countFlashSort(int a[], int n, long long& c) {
	int minVal = a[0], maxIdx = 0;
	int buckets = int(0.45 * n);
	int* l = new int[buckets];
	for (size_t i = 0; ++c, i < buckets; i++)
	{
		l[i] = 0;
	}
	for (size_t i = 1; ++c, i < n; i++)
	{
		if (++c && a[i] < minVal) minVal = a[i];
		if (++c && a[i] > a[maxIdx]) maxIdx = i;
	}
	if (++c && a[maxIdx] == minVal) {
		delete[]l;
		return;
	}
	double c1 = (double)(buckets - 1) / (a[maxIdx] - minVal);
	for (size_t i = 0; ++c, i < n; i++)
	{
		int bucketIdx = int(c1 * (a[i] - minVal));
		l[bucketIdx]++;
	}
	for (size_t i = 1; ++c, i < buckets; i++)
	{
		l[i] += l[i - 1];
	}
	HoanVi(a[maxIdx], a[0]);
	int nmove = 0;
	int j = 0;
	int k = buckets - 1;
	int flash;
	while (++c && nmove < n - 1)
	{
		while (++c && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++c && k < 0) break;
		while (++c && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			--l[k];
			HoanVi(flash, a[l[k]]);
			++nmove;
		}
	}
	delete[]l;
	countInsertionSort(a, n, c);
}
