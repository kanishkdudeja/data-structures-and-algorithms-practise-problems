/* Maximum Subsequence Sum: You are given an array of integers (both positive and negative). Find the
sequence(doesn't need to be contiguous) with the largest sum. Return the sum.

EXAMPLE

Input: 2, -8, 3, -2, 4, -10
Output: 9 ( i. e • , { 2, 3, 4} )

Time complexity = O(n)
Space complexity = O(1) */

#include <iostream>
using namespace std;

int maximumSubSequenceSum(int* arr, int size) {
	int maxSum = 0;

	for(int i = 0; i < size; i++) {
		if(arr[i] > 0) {
			maxSum = maxSum + arr[i];
		}
	}

	return maxSum;
}

int main() {
	int arr[6] = { 2, -8, 3, -2, 4, -10 };

	int size = 6;

	cout<<maximumSubSequenceSum(arr, 6);
}