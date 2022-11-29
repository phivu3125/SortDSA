#include "command2.h"

void checkOutput2(int*a, int n, char outPut[], double timeUse, long long countCmp)
{
	if (strcmp(outPut, "-time") == 0)// check output
	{
		cout << "-------------------------------\n";
		cout << "Running time(msec): " << timeUse << endl;
	}
	else if (strcmp(outPut, "-comp") == 0)
	{
		cout << "-------------------------------\n";
		cout << "Comparisions: " << countCmp << endl;
	}
	else if (strcmp(outPut, "-both") == 0)
	{
		cout << "-------------------------------\n";
		cout << "Running time(msec): " << timeUse << endl;
		cout << "Comparisions: " << countCmp << endl;
	}
	else
	{
		cout << "Please check output parameters agrument\n";
	}
}

void checkInputOrder2(int* a, char inputOrder[], int n)
{
	if (strcmp(inputOrder, "-rand") == 0)
	{
		GenerateData(a, n, 0);
		cout << "Input Order: randomized data\n";
	}
	else if (strcmp(inputOrder, "-sorted") == 0)
	{
		GenerateData(a, n, 1);
		cout << "Input Order: sorted data\n";
	}
	else if (strcmp(inputOrder, "-rev") == 0)
	{
		GenerateData(a, n, 2);
		cout << "Input Order:  reverse sorted data\n";
	}
	else if (strcmp(inputOrder, "-nsorted") == 0)
	{
		GenerateData(a, n, 3);
		cout << "Input Order: nearly sorted data\n";
	}
	else
	{
		cout << "Please check input order agrument\n";
	}
}

void checkInputSize2(int *&a, int &n, char inputSize[], char inputOrder[], bool &rightInput)
{
	if (checkNumber(inputSize) == 1)
	{
		n = stringToNumber(inputSize);
		a = new int[n];
		cout << "Input Size: " << n << endl;
		checkInputOrder2(a, inputOrder, n);
		rightInput = 1;
	}
	else
	{
		cout << "Please check input size agrument\n";
		rightInput = 0;
	}
}

void checkAlgorithm2(int *&a, int &n, char algorithm[], char inputSize[], char inputOrder[], char outPut[])
{
	bool rightInput = 0;
	cout << "Algorithm: " << nameAlgorithm(algorithm) << endl;
	checkInputSize2(a, n, inputSize, inputOrder, rightInput);
	writeFile("input.txt", a, n);
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