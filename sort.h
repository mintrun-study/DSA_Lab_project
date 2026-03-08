#ifndef SORT
#define SORT

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void selectionSort(vector<int> & a, int n, long long & count_comparision);
void selectionSort_optimize1(vector<int> & a, int n, long long & count_comparision);
void insertionSort(vector<int> & a, int n, long long & count_comparision);
void flashSort(vector<int> & a, int n, long long & count_comparision);
void merge(vector<int> & a, int left, int mid, int right, long long & count_comparision);
void mergeSort(vector<int> & a, int n, long long & count_comparision);
void mergeSortAlgorithm(vector<int> & a, int left, int right, long long & count_comparision);

#endif