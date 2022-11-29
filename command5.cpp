#include "command5.h"


void checkInputSize5(int*& a, int& n, char inputSize[], char inputOrder[], bool& rightInput)
{
	if (checkNumber(inputSize) == 1)
	{
		rightInput = 1;
		n = stringToNumber(inputSize);
		a = new int[n];
		cout << "Input Size: " << n << endl;
		checkInputOrder2(a, inputOrder, n);
	}
	else
	{
		cout << "Please check input size agrument\n";
		rightInput = 0;
	}
}

void checkAlgorithm5(int*& a, int& n, char algorithm1[], char algorithm2[], char inputSize[], char inputOrder[])
{
	bool rightInput = 0;
	if (strcmp(algorithm1, algorithm2) == 0)
	{
		cout << "Same algorithm please input again\n";
	}
	else
	{
		cout << "Algorithm: ";
		cout << nameAlgorithm(algorithm1) << " | " << nameAlgorithm(algorithm2) << endl;
		checkInputSize5(a, n, inputSize, inputOrder, rightInput);
		writeFile("input.txt", a, n);
		if (rightInput == 1)
		{
			double timeUse1, timeUse2;
			long long countCmp1 = 0;
			long long countCmp2 = 0;
			callAlgorithm(algorithm1, timeUse1, countCmp1, a, n);
			callAlgorithm(algorithm2, timeUse2, countCmp2, a, n);
			checkOutput4(a, n, timeUse1, countCmp1, timeUse2, countCmp2);
		}
	}
}