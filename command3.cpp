#include "command3.h"

void writeFile3(int i, int a[], int n)
{
	switch (i)
	{
		case 0:
		{
			writeFile("input_1.txt", a, n);
		}
		case 1:
		{
			writeFile("input_2.txt", a, n);
		}
		case 2:
		{
			writeFile("input_3.txt", a, n);
		}
		case 3:
		{
			writeFile("input_4.txt", a, n);
		}
	}
}
void Output3(int* a, int n, char outPut[], double timeUse, long long countCmp)
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

void outputOrder3(int i)
{
	switch (i)
	{
		case 0:
		{
			cout << endl;
			cout << "Input Order: randomized data\n";
			break;
		}
		case 1:
		{
			cout << endl;
			cout << "Input Order: sorted data\n";
			break;
		}
		case 2:
		{
			cout << endl;
			cout << "Input Order:  reverse sorted data\n";
			break;
		}
		case 3:
		{
			cout << endl;
			cout << "Input Order: nearly sorted data\n";
			break;
		}
	}
}

void checkInputSize3(int*& a, int& n, char inputSize[], bool &rightInput)
{
	if (checkNumber(inputSize) == 1)
	{
		n = stringToNumber(inputSize);
		a = new int[n];
		cout << "Input Size: " << n << endl;
		rightInput = 1;
	}
	else
	{
		cout << "Please check input size agrument\n";
		rightInput = 0;
	}
}

void checkAlgorithm3(int*& a, int& n, char algorithm[], char inputSize[], char outPut[])
{
	bool rightInput = 0;
	cout << "Algorithm: " << nameAlgorithm(algorithm) << endl;
	checkInputSize3(a, n, inputSize, rightInput);
	if (rightInput == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			long long countCmp = 0;
			double timeUse;
			GenerateData(a, n, i);
			writeFile3(i, a, n);
			outputOrder3(i);
			callAlgorithm(algorithm, timeUse, countCmp, a, n);
			Output3(a, n, outPut, timeUse, countCmp);
		}
	}
	delete[]a;
}