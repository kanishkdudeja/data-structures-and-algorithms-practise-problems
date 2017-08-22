/* Smallest Difference: Given two arrays of integers, compute the pair of values (one value in each
array) with the smallest (non-negative) difference. Return the difference.

EXAMPLE
Input: {l, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
Output: 3. That is, the pair (11, 8).

Brute Force

The simple brute force way is to just iterate through all pairs, compute the difference, and compare it 
to the current minimum difference.

int findSmallestDifference(int[] arrayl, int[] array2) {
    if (arrayl.length == 0 I I array2.length == 0) return -1;
    
    int min = Integer.MAX_VALUE;
    for (inti= 0; i < arrayl.length; i++) {
        for (int j = 0; j < array2.length; j++) {
            if (Math.abs(arrayl[i] - array2[j]) < min) {
            min = Math.abs(arrayl[i] - array2[j]);
        }
    }
}

Optimal

A more optimal approach is to sort the arrays. Once the arrays are sorted, we can find the minimum 
differ­ence by iterating through the array.

Consider the following two arrays:

A: {l, 2, 11, 15}
B: {4, 12, 19, 23, 127, 235}

Try the following approach:

1. Suppose a pointer a points to the beginning of A and a pointer b points to the beginning of B. The
current difference between a and b is 3. Store this as the min.

2. How can we (potentially) make this difference smaller? Well, the value at b is bigger than the value
at a, so moving b will only make the difference larger. Therefore, we want to move a.

3. Now a points to 2 and b (still) points to 4. This difference is 2, so we should update min. 
Move a, since it is smaller.

4. Now a points to 11 and b points to 4. Move b.

5. Now a points to 11 and b points to 12. Update min to 1. Move b.

And so on.

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