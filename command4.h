#pragma once
#include "Header.h"

void checkOutput4(int* a, int n, double timeUse1, long long countCmp1, double timeUse2, long long countCmp2);
void readFile4(int*& a, int& n, const char fileInput[], bool& rightInput);
char* nameAlgorithm(char algorithm[]);
void callAlgorithm(char algorithm[], double& timeUse, long long& countCmp, int*& a, int n);
void checkAlgorithm4(int*& a, int& n, char algorithm1[], char algorithm2[], const char fileInput[]);