#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void selectionSort(vector<int> & a, int n);
void selectionSort_optimize1(vector<int> & a, int n);
void insertionSort(vector<int> & a, int n);
void binaryinsertionSort(vector<int>& a, int n);
void flashSort(vector<int> & a, int n);
void merge(vector<int> & a, int left, int mid, int right);
void radixSort(vector<int>& a, int n);
void mergeSort(vector<int> & a, int n);
void mergeSortAlgorithm(vector<int> & a, int left, int right);
void heapRebuild(int start, vector<int>& a, int n);
void heapSort(vector<int>& a, int n);
void shellSort(vector<int>& a, int n);
void bubbleSort(vector<int>& a,int n);
void shakerSort(vector<int>& a,int n);
void countingSort(vector<int>& a,int n);
void partition(vector<int> &a, int first, int last);
void quickSort(vector<int> &a, int n);