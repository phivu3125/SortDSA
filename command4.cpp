#include "command4.h"

void checkOutput4(int* a, int n, double timeUse1, long long countCmp1, double timeUse2, long long countCmp2)
{
	cout << "-------------------------------\n";
	cout << "Running time(msec): " << timeUse1 << " | " << timeUse2 << endl;
	cout << "Comparisions: " << countCmp1 << " | " << countCmp2 << endl;
}

void readFile4(int*& a, int& n, const char fileInput[], bool& rightInput)
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

char* nameAlgorithm(char algorithm[])
{
	char *s = new char [100];
	if (strcmp(algorithm, "heap-sort") == 0)
	{
		s = strcpy(s, "Heap Sort");
		s[10] = '\0';
	}
	else if (strcmp(algorithm, "merge-sort") == 0)
	{
		s = strcpy(s, "Merge Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "radix-sort") == 0)
	{
		s = strcpy(s, "Radix Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "counting-sort") == 0)
	{
		s = strcpy(s, "Counting Sort");
		s[14] = '\0';
	}
	else if (strcmp(algorithm, "shaker-sort") == 0)
	{
		s = strcpy(s, "Shaker Sort");
		s[12] = '\0';
	}
	else if (strcmp(algorithm, "quick-sort") == 0)
	{
		s = strcpy(s, "Quick Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "shell-sort") == 0)
	{
		s = strcpy(s, "Shell Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "insertion-sort") == 0)
	{
		s = strcpy(s, "Insertion Sort");
		s[15] = '\0';
	}
	else if (strcmp(algorithm, "flash-sort") == 0)
	{
		s = strcpy(s, "Flash Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "selection-sort") == 0)
	{
		s = strcpy(s, "Selection Sort");
		s[15] = '\0';
	}
	else if (strcmp(algorithm, "bubble-sort") == 0)
	{
		s = strcpy(s, "Bubble Sort");
		s[12] = '\0';
	}
	else
	{
		s = strcpy(s, "Wrong algorithm protoptype please check again!!!");
		s[49] = '\0';
	}
	return s;
}

void callAlgorithm(char algorithm[], double &timeUse, long long &countCmp, int*&a, int n)
{
	clock_t start, end;
	if (strcmp(algorithm, "heap-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		heapSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC/1000);
		countHeapSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "merge-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		mergeSort(a, 0 , n - 1);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC/1000);
		countMergeSort(b, 0, n - 1, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "radix-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		radixSort(a, n, log10(getMax(a, n)) + 1);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC/1000);
		countRadixSort(b, n, log10(getMax(a, n)) + 1, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "counting-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		countingSort(a, n, getMin(a, n), getMax(a, n));
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countCountingSort(b, n, countGetMin(b, n, countCmp), countGetMax(b, n, countCmp), countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "shaker-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		shakerSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countShakerSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "quick-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		quickSort(a, 0, n - 1);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countQuickSort(b, 0, n - 1, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "shell-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		shellSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countShellSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "insertion-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		insertionSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countInsertionSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "flash-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		flashSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countFlashSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "selection-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		selectionSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countSelectionSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "bubble-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		bubbleSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countBubbleSort(b, n, countCmp);
		delete[]b;
	}
	else
	{
		cout << "Please check algorithm name agrument\n";
	}
}

void checkAlgorithm4(int*& a, int& n, char algorithm1[], char algorithm2[], const char fileInput[])
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
		readFile4(a, n, fileInput, rightInput);
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