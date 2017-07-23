/* An array contains 101 numbers between 1 and 100. Write a program
to find the duplicate number. */

/* Time complexity = O(n) */

/* Sum of n natural numbers from 1 to n is (n(n+1))/2 */
/* Sum of n numbers from 0 to n-1 is (n(n-1))/2 */

#include <iostream>
using namespace std;

int findDuplicate(int* arr, int n) {
	int totalSum = (n*(n+1))/2;

	int actualSum = 0;

	for(int i = 0; i < n + 1; i++) {
		actualSum = actualSum + arr[i];
	}

	int duplicateNumber = actualSum - totalSum;

	return duplicateNumber;
}

int main() {
	int arr[11] = { 1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10 };

	cout<<findDuplicate(arr, 10);
}