#include "command1.h"

void readFile1(int*& a, int& n, const char fileInput[], bool &rightInput)
{
	FILE* f;
	
	f = fopen(fileInput, "rt");
	
	if (f == NULL)
	{
		cout << "File not exist\n";
		rightInput = 0;
		return;
	}
	else
	{
		cout << "Input file: " << fileInput << endl;
		fscanf(f, "%d\n", &n);

		a = new int[n];

		for (int i = 0; i < n; i++)
		{
			fscanf(f, "%d ", &a[i]);
		}
		fclose(f);
		cout << "Input size: " << n << endl;
	}
	rightInput = 1;
}

void checkAlgorithm1(int*& a, int& n, char algorithm[], const char fileInput[], char outPut[])
{
	bool rightInput = 0;
	cout << "Algorithm: " << nameAlgorithm(algorithm) << endl;
	readFile1(a, n, fileInput, rightInput);
	if (rightInput == 1)
	{
		double timeUse;
		long long countCmp = 0;
		callAlgorithm(algorithm, timeUse, countCmp, a, n);
		checkOutput2(a, n, outPut, timeUse, countCmp);
		writeFile("output.txt", a, n);
	}
		delete[]a;
}