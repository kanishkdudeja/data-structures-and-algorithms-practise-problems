/* The Longest Increasing Subsequence (LIS) problem is to find the length of the 
longest subsequence of a given sequence such that all elements of the subsequence 
are sorted in increasing order. For example, the length of LIS for 
{10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}

Time Complexity = O(n2) where n is the number of elements in the array
Space Complexity = O(n) where n is the number of the elements in the array */

#include <iostream>
using namespace std;

int lis(int* arr, int size) {
	int* lis_arr = (int *)malloc(size*(sizeof(int)));

	for(int l = 0; l < size; l++) {
		lis_arr[l] = 1;
	}

	for(int i = 1; i < size; i++) {
		for(int j = 0; j < i; j++) {
			if((arr[i] > arr[j]) && ((lis_arr[j] + 1) > lis_arr[i])) {
				lis_arr[i] = 1 + lis_arr[j];
			}
		}
	}

	int max = 1;

	for(int k = 0; k < size; k++) {
		if(lis_arr[k] > max) {
			max = lis_arr[k];
		}
	}

	return max;
}

int main() {
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };

	cout<<lis(arr, 9);
}