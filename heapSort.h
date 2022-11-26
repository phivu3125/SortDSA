#pragma once
#include "Header.h"

void swap(int& a, int& b);
void countHeapRebuild(int*& a, int k, int n, long long& countCmp);
void heapRebuild(int*& a, int k, int n);
void countHeapConstruct(int*& a, int n, long long& countCmp);
void heapConstruct(int*& a, int n);
void countHeapSort(int*& a, int n, long long& countCmp);
void heapSort(int*& a, int n);