/* Smallest Difference: Given two arrays of integers, compute the pair of values (one value in each
array) with the smallest (non-negative) difference. Return the difference.

EXAMPLE
Input: {l, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
Output: 3. That is, the pair (11, 8).

Time complexity = O(a*log(a) + b*log(b)) since both arrays need to be sorted first.
*/

#include <iostream>
#include <limits>
using namespace std;

int imin = std::numeric_limits<int>::min(); // minimum value
int imax = std::numeric_limits<int>::max();

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

int findSmallestDifference(int* arr1, int size1, int* arr2, int size2) {
	mergeSort(arr1, 0, size1 - 1);
	mergeSort(arr2, 0, size2 - 1);

    int min = imax;
    int i = 0;
    int j = 0;
    int diff;

    while(i < size1 && j < size2) {
        if(arr1[i] >= arr2[j]) {
            diff = arr1[i] - arr2[j];

            if(diff < min) {
                min = diff;
            }

            j++;
        }
        else if(arr1[i] < arr2[j]) {
            diff = arr2[j] - arr1[i];

            if(diff < min) {
                min = diff;
            }

            i++;
        }
    }

    return min;
}

int main() {
	int arr1[5] = { 1, 3, 15, 11, 2 };
	int arr2[5] = { 23, 127, 235, 19, 8 };

	cout<<findSmallestDifference(arr1, 5, arr2, 5);
}