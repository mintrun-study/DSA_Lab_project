#include "sort.h"

                                                        
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int cur_min = i;
        for (int j = i + 1; j < n; ++j)
            if (a[cur_min] > a[j])
                cur_min = j;
        swap(a[cur_min], a[i]);
    }
}


void selectionSortoptimize1(int a[], int n) {
    int r = n;
    for (int i = 0; i < r - 1; ++i) {
        int cur_min = i;
        int cur_max = i;
        for (int j = i + 1; j < r; ++j)
            if (a[cur_min] > a[j])
                cur_min = j;
            else if (a[cur_max] < a[j])
                cur_max = j;
        swap(a[cur_min], a[i]);
        if (cur_max == i) cur_max = cur_min;
        --r;
        swap(a[cur_max], a[r]);
    }
}
void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (k>= 0 && a[k] > key)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

void flashSort(int a[], int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	vector<int> l(m,0);
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return; //sorted array
	double c1 = (double)(m - 1) / (a[max] - minVal);

	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];

    swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;

		while (j != l[k])
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

void merge(int arr[], int left, int mid, int right){           
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
