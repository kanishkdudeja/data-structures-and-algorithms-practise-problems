#include <iostream>
using namespace std;

void printArray(int* arr, int length) {
	for(int i = 0; i < length; i++) {
		cout<<arr[i]<<"\n";
	}
}

void mergeSortedArrays(int* arr, int low, int high, int mid) {
	int mergedArrayLength = high - low + 1;

	int i, j, k, c[mergedArrayLength];
    
    i = low;
    k = low;
    
    j = mid + 1;
    
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }

    for(i = low; i < k; i++) {
        arr[i] = c[i];
    }
}

void mergeSort(int* arr, int low, int high) {
	if(low < high) {
		int mid = (high + low) / 2;

		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);

		mergeSortedArrays(arr, low, high, mid);
	}
}

int main() {
	int a[10] = {6, 3, 1, 8, 9, 2, 7, 10, 4, 5};

	cout<<"Array before sorting: "<<"\n";
	printArray(a, 10);

	mergeSort(a, 0, 9);

	cout<<"Sorted array after merge sort: "<<"\n";
	printArray(a, 10);
}