/* Contiguous Sequence: You are given an array of integers (both positive and negative). Find the
contiguous sequence with the largest sum. Return the sum.

EXAMPLE

Input: 2, -8, 3, -2, 4, -10
Output: 5 ( i. e • , { 3, -2, 4} )

Time complexity = O(n)
Space complexity = O(1) */

#include <iostream>
using namespace std;

int maximumContiguousSubArraySum(int* arr, int size) {
	int maxSum = 0;
	int sum = 0;

	for(int i = 0; i < size; i++) {
		sum = sum + arr[i];

		if(maxSum < sum) {
			maxSum = sum;
		}
		else if(sum < 0) {
			sum = 0;
		}
	}

	return maxSum;
}

int main() {
	int arr[6] = { 2, -8, 3, -2, 4, -10 };

	int size = 6;

	cout<<maximumContiguousSubArraySum(arr, 6);
}