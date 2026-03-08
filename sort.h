#ifndef SORT
#define SORT

#include "sort.cpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void selectionSort(int a[], int n);
void selectionSort_optimize1(int a[], int n);
void insertionSort(int a[], int n);
void flashSort(int a[], int n);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

#endif