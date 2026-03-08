#include "sort.h"

                                                        
void selectionSort(vector<int> & a, int n, long long & cmp) {
    int cmp = 0;
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
    int cmp = 0;
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
    long long cmp = 0;
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
