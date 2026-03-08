#ifndef SORT
#define SORT

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void selectionSort(vector<int> & a, int n);
void selectionSort_optimize1(vector<int> & a, int n);
void insertionSort(vector<int> & a, int n);
void flashSort(vector<int> & a, int n);
void merge(vector<int> & a, int left, int mid, int right);
void mergeSort(vector<int> & a, int n);
void mergeSortAlgorithm(vector<int> & a, int left, int right);

#endif