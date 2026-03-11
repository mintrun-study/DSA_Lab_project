#include "time.h"
using namespace std;

void selectionSort(vector<int> & a, int n) {
    for (int i = 0;  i < n - 1;++i) {
        int cur_min = i;
        for (int j = i + 1; j < n; ++j)
            if (a[cur_min] > a[j])
                cur_min = j;
        swap(a[cur_min], a[i]);
    }
}


void selectionSort_optimize1(vector<int> & a, int n) {
    int r = n;
    for (int i = 0; i < r - 1; ++i) {
        int cur_min = i;
        int cur_max = i;
        for (int j = i + 1; j < r; ++j)
            if ( a[cur_min] > a[j])
                cur_min = j;
            else if ( a[cur_max] < a[j])
                cur_max = j;
        swap(a[cur_min], a[i]);
        if ( cur_max == i) cur_max = cur_min;
        --r;
        swap(a[cur_max], a[r]);
    }
}
void insertionSort(vector<int> & a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while ((k>= 0 && a[k] > key))
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

void binaryinsertionSort(vector<int>& a, int n) {
    for (int i = 1;  i < n; ++i) {
        int key = a[i];
        int first = 0, last = i - 1;
        
        while ( first <= last) {
            int m = (first + last) / 2;
            if (key < a[m]) last = m - 1;
            else            first = m + 1;
        }
        
        for (int j = i - 1;  j >= first; --j)
            a[j + 1] = a[j];
        
        a[first] = key;
    }
}

void shellSort(vector<int>& a, int n) {
    int gap = n/2;
    while ( gap > 0) {
        int i = gap;
        while ( i < n) {
            int temp = a[i];
            int j = i;
            while ( j >= gap &&  a[j-gap] > a[j]) {
                a[j] = a[j-gap];
                j -= gap;
            }
            a[j] = temp;
            i++;
        }
        gap /= 2;
    }
}

void flashSort(vector<int> & a, int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	vector<int> l(m,0);
	for (int i = 1; i < n; i++)
	{
		if ( a[i] < minVal)
			minVal = a[i];
		if ( a[i] > a[max])
			max = i;
	}
	if ( a[max] == minVal)
		return; //sorted array
	double c1 = (double)(m - 1) / (a[max] - minVal);

	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1;  i < m; i++)
		l[i] += l[i - 1];

    swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while ( nmove < n - 1)
	{
		while ( j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if ( k < 0) break;

		while ( j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	insertionSort(a, n);
}

void radixSort(vector<int>& a, int n) {
    int max_val = a[0];
    for (int i = 1;  i < n; ++i)
        if ( a[i] > max_val) max_val = a[i];

    int digits = 0, div;
    do {
        digits++;
        div = max_val / (int)pow(10, digits);
    } while (div > 0);

    vector<vector<int>> tempArr(10, vector<int>(n));
    int tempCount[10];

    for (int i = 0; i < digits; ++i) {
        int exp = (int)pow(10, i);

        for (int j = 0;  j < 10; ++j)
            tempCount[j] = 0;

        for (int j = 0;  j < n; ++j) {
            int idx = (a[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = a[j];
        }

        int idx = 0;
        for (int j = 0;  j < 10; ++j)
            for (int k = 0;  k < tempCount[j]; ++k)
                a[idx++] = tempArr[j][k];
    }
}

void heapRebuild(int start, vector<int>& a, int n) {
    int leftChild = 2*start + 1;
    if ( leftChild >= n) return;
    int largerChild = leftChild;
    int rightChild = 2*start + 2;
    if ( rightChild < n)
        if ( a[rightChild] > a[largerChild]) largerChild = rightChild;

    if ( a[start] < a[largerChild]) {
        swap(a[start], a[largerChild]);
        heapRebuild(largerChild, a, n);
    }
}

void heapSort(vector<int>& a, int n) {
    for (int index = (n-1)/2;  index >= 0; index--)
        heapRebuild(index, a, n);

    swap(a[0], a[n-1]);
    int heapSize = n-1;
    while ( heapSize > 1) {
        heapRebuild(0, a, heapSize);
        heapSize--;
        swap(a[0], a[heapSize]);
    }
}

void merge(vector<int> & arr, int left, int mid, int right){           
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while ( (i < n1 && j < n2)) {
        if ( L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while ( i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while ( j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> & arr, int n){
    if(!arr.empty()){
        mergeSortAlgorithm(arr, 0, n - 1);
    }

}

void mergeSortAlgorithm(vector<int> & arr, int left, int right){
    
    if ( left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSortAlgorithm(arr, left, mid);
    mergeSortAlgorithm(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void bubbleSort(vector<int>& a,int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0;  j < n - i - 1; j++) {
            
            if ( a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
}

void shakerSort(vector<int>& a,int n) {
    int left = 0, right = n - 1;
    while ( left < right) {
        for (int i = left; i < right; i++) {
            if ( a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
        right--;
        for (int i = right;  i > left; i--) {
            if (  a[i - 1] > a[i]) swap(a[i - 1], a[i]);
        }
        left++;
    }
}

void countingSort(vector<int>& a,int n) {
    if ( a.empty()) return;
    int maxVal = *max_element(a.begin(), a.end());
    vector<int> count(maxVal + 1, 0);
    for (int x : a) count[x]++;
    int index = 0;
    for (int i = 0;  i <= maxVal; i++)
        while ( count[i]-- > 0)
            a[index++] = i;
}

void partition(vector<int> &a, int first, int last) {
    int pivot = a[(first + last)/2];
    int i=first, j=last;
    do {
        while ( a[i] < pivot) i++;
        while ( a[j] > pivot) j--;
        if ( i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    } while ( i <= j);
    if ( first < j) partition(a, first, j);
    if ( i < last) partition(a, i, last);
}

void quickSort(vector<int> &a, int n) {
    partition(a, 0, n - 1);
}