#include "writeFile.h"

void writeFile(const char fileInput[], int a[], int n)
{
	FILE* f = fopen(fileInput, "wt");
	if (f == NULL)
	{
		return;
	}

	fprintf(f, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d ", a[i]);
	}
	fclose(f);
}


