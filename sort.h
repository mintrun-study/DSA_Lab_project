#ifndef SORT
#define SORT

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void selectionSort(vector<int> & a, int n, long long & cmp);
void selectionSort_optimize1(vector<int> & a, int n, long long & cmp);
void insertionSort(vector<int> & a, int n, long long & cmp);
void binaryinsertionSort(vector<int>& a, int n, long long& cmp);
void flashSort(vector<int> & a, int n, long long & cmp);
void merge(vector<int> & a, int left, int mid, int right, long long & cmp);
void radixSort(vector<int>& a, int n, long long& cmp);
void mergeSort(vector<int> & a, int n, long long & cmp);
void mergeSortAlgorithm(vector<int> & a, int left, int right, long long & cmp);
void heapRebuild(int start, vector<int>& a, int n, long long& cmp);
void heapSort(vector<int>& a, int n, long long& cmp);
void shellSort(vector<int>& a, int n, long long& cmp);
void bubbleSort(vector<int>& a,int n, long long& cmp);
void shakerSort(vector<int>& a,int n, long long& cmp);
void countingSort(vector<int>& a,int n, long long& cmp);
void partition(vector<int> &a, int first, int last, long long& cmp);
void quickSort(vector<int> &a, int n, long long& cmp);

#endif