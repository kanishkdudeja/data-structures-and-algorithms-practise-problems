/* Search in Rotated Array: Given a sorted array of n integers that has been rotated an unknown
number of times, write code to find an element in the array. You may assume that the array was
originally sorted in increasing order.

EXAMPLE

Input : find 5 in {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
Output: 8 (the index of 5 in the array)

*/

/* The below algorithm only works 

/* Time complexity = O(log(n)) */
/* Space complexity = O(1) */

#include <iostream>
using namespace std;

bool searchRotatedCircularArray(int* arr, int size, int x) {
	int low = 0;
	int high = size - 1;

	while(low <= high) {
		int mid = (low + high)/2;

		if(arr[mid] == x) {
			return true;
		}
		else {
			if(arr[mid] <= arr[high]) {
				if(x > arr[mid] && x <= arr[high]) {
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
			} else if(arr[low] <= arr[mid]) {
				if(x >= arr[low] && x < arr[mid]) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
		}
	}

	return false;
}

int main() {
	int arr[12] = { 10, 14, 15, 16, 19, 20, 25, 1, 3, 4, 5, 7 };

	int size = 12;
	int x = 5;

	cout<<searchRotatedCircularArray(arr, 12, 25);
}