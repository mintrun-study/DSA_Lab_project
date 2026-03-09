#include "sort.h"

                                                        
void selectionSort(vector<int> & a, int n, long long & cmp) {
    for (int i = 0; ++cmp && i < n - 1;++i) {
        int cur_min = i;
        for (int j = i + 1; ++cmp && j < n; ++j)
            if (++cmp && a[cur_min] > a[j])
                cur_min = j;
        swap(a[cur_min], a[i]);
    }
}


void selectionSort_optimize1(vector<int> & a, int n, long long & cmp) {
    int r = n;
    for (int i = 0;++cmp && i < r - 1; ++i) {
        int cur_min = i;
        int cur_max = i;
        for (int j = i + 1;++cmp && j < r; ++j)
            if (++cmp && a[cur_min] > a[j])
                cur_min = j;
            else if (++cmp && a[cur_max] < a[j])
                cur_max = j;
        swap(a[cur_min], a[i]);
        if (++cmp && cur_max == i) cur_max = cur_min;
        --r;
        swap(a[cur_max], a[r]);
    }
}
void insertionSort(vector<int> & a, int n, long long & cmp)
{
	for (int i = 1;++cmp && i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (++cmp &&(k>= 0 && a[k] > key))
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

void binaryinsertionSort(vector<int>& a, int n, long long& cmp) {
    for (int i = 1; ++cmp && i < n; ++i) {
        int key = a[i];
        int first = 0, last = i - 1;
        
        while (++cmp && first <= last) {
            int m = (first + last) / 2;
            ++cmp;
            if (key < a[m]) last = m - 1;
            else            first = m + 1;
        }
        
        for (int j = i - 1; ++cmp && j >= first; --j)
            a[j + 1] = a[j];
        
        a[first] = key;
    }
}

void shellSort(vector<int>& a, int n, long long& cmp) {
    int gap = n/2;
    while (++cmp && gap > 0) {
        int i = gap;
        while (++cmp && i < n) {
            int temp = a[i];
            int j = i;
            while (++cmp && j >= gap && ++cmp && a[j-gap] > a[j]) {
                a[j] = a[j-gap];
                j -= gap;
            }
            a[j] = temp;
            i++;
        }
        gap /= 2;
    }
}

void flashSort(vector<int> & a, int n, long long & cmp)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	vector<int> l(m,0);
	for (int i = 1;++cmp && i < n; i++)
	{
		if (++cmp && a[i] < minVal)
			minVal = a[i];
		if (++cmp && a[i] > a[max])
			max = i;
	}
	if (++cmp && a[max] == minVal)
		return; //sorted array
	double c1 = (double)(m - 1) / (a[max] - minVal);

	for (int i = 0;++cmp && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++cmp && i < m; i++)
		l[i] += l[i - 1];

    swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++cmp && nmove < n - 1)
	{
		while (++cmp && j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (++cmp && k < 0) break;

		while (++cmp && j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	insertionSort(a, n, cmp);
}

void radixSort(vector<int>& a, int n, long long& cmp) {
    int max_val = a[0];
    for (int i = 1; ++cmp && i < n; ++i)
        if (++cmp && a[i] > max_val) max_val = a[i];

    int digits = 0, div;
    do {
        digits++;
        div = max_val / (int)pow(10, digits);
    } while (div > 0);

    vector<vector<int>> tempArr(10, vector<int>(n));
    int tempCount[10];

    for (int i = 0; i < digits; ++i) {
        int exp = (int)pow(10, i);

        for (int j = 0; ++cmp && j < 10; ++j)
            tempCount[j] = 0;

        for (int j = 0; ++cmp && j < n; ++j) {
            int idx = (a[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = a[j];
        }

        int idx = 0;
        for (int j = 0; ++cmp && j < 10; ++j)
            for (int k = 0; ++cmp && k < tempCount[j]; ++k)
                a[idx++] = tempArr[j][k];
    }
}

void heapRebuild(int start, vector<int>& a, int n, long long& cmp) {
    int leftChild = 2*start + 1;
    if (++cmp && leftChild >= n) return;
    int largerChild = leftChild;
    int rightChild = 2*start + 2;
    if (++cmp && rightChild < n)
        if (++cmp && a[rightChild] > a[largerChild]) largerChild = rightChild;

    if (++cmp && a[start] < a[largerChild]) {
        swap(a[start], a[largerChild]);
        heapRebuild(largerChild, a, n, cmp);
    }
}

void heapSort(vector<int>& a, int n, long long& cmp) {
    for (int index = (n-1)/2; ++cmp && index >= 0; index--)
        heapRebuild(index, a, n, cmp);

    swap(a[0], a[n-1]);
    int heapSize = n-1;
    while (++cmp && heapSize > 1) {
        heapRebuild(0, a, heapSize, cmp);
        heapSize--;
        swap(a[0], a[heapSize]);
    }
}

void merge(vector<int> & arr, int left, int mid, int right, long long & cmp){           
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0;++cmp && i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0;++cmp && j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (++cmp && (i < n1 && j < n2)) {
        if (++cmp && L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (++cmp && i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (++cmp && j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> & arr, int n, long long & cmp){
    if(!arr.empty()){
        mergeSortAlgorithm(arr, 0, n - 1, cmp);
    }

}

void mergeSortAlgorithm(vector<int> & arr, int left, int right, long long & cmp){
    
    if (++cmp && left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSortAlgorithm(arr, left, mid, cmp);
    mergeSortAlgorithm(arr, mid + 1, right, cmp);
    merge(arr, left, mid, right, cmp);
}

void bubbleSort(vector<int>& a,int n, long long& cmp) {
    for (int i = 0;++cmp && i < n - 1; i++)
        for (int j = 0; ++cmp && j < n - i - 1; j++) {
            
            if (++cmp && a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
}

void shakerSort(vector<int>& a,int n, long long& cmp) {
    int left = 0, right = n - 1;
    while (++cmp && left < right) {
        for (int i = left;++cmp && i < right; i++) {
            cmp++;
            if (++cmp && a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
        right--;
        for (int i = right; ++cmp && i > left; i--) {
            cmp++;
            if ( ++cmp && a[i - 1] > a[i]) swap(a[i - 1], a[i]);
        }
        left++;
    }
}

void countingSort(vector<int>& a,int n, long long& cmp) {
    if (++cmp && a.empty()) return;
    int maxVal = *max_element(a.begin(), a.end());
    vector<int> count(maxVal + 1, 0);
    for (int x : a) count[x]++;
    int index = 0;
    for (int i = 0; ++cmp && i <= maxVal; i++)
        while (++cmp && count[i]-- > 0)
            a[index++] = i;
}

void partition(vector<int> &a, int first, int last, long long& cmp) {
    int pivot = a[(first + last)/2];
    int i=first, j=last;
    do {
        while (++cmp && a[i] < pivot) i++;
        while (++cmp && a[j] > pivot) j--;
        if (++cmp && i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    } while (++cmp && i <= j);
    if (++cmp && first < j) partition(a, first, j, cmp);
    if (++cmp && i < last) partition(a, i, last, cmp);
}

void quickSort(vector<int> &a, int n, long long& cmp) {
    partition(a, 0, n, cmp);
}