/* Given an array that contains both positive and negative integers, find the product of the
maximum product subarray. Expected Time complexity is O(n) and only O(1) extra space can
be used.

EXAMPLE

Input: arr[] = {6, -3, -10, 0, 2}
Output:   180  // The subarray is {6, -3, -10}

Input: arr[] = {-1, -3, -10, 0, 60}
Output:   60  // The subarray is {60}

Input: arr[] = {-2, -3, 0, -2, -40}
Output:   80  // The subarray is {-2, -40}

Time complexity = O(n)
Space complexity = O(1) */

#include <iostream>
using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a > b) ? b: a;
}

int maximumContiguousSubArrayProduct(int* arr, int size) {
	int maxProductSoFar = 1;
		
	// max positive product ending at the current position
	int maxUptilHere = 1;

	// min negative product ending at the current position
	int minUptilHere = 1;

	for(int i = 0; i < size; i++) {
		if(arr[i] > 0) {

			/* If this element is positive, update max_ending_here. 
            Update min_ending_here only if min_ending_here is 
            negative */
			maxUptilHere = maxUptilHere*arr[i];
			minUptilHere = min(minUptilHere*arr[i], 1);
		}
		else if(arr[i] == 0) {
			/* If this element is 0, then the maximum product 
           cannot end here, make both max_ending_here and 
           min_ending_here */
			maxUptilHere = 1;
			minUptilHere = 1;
		}
		/* If element is negative. This is tricky
           max_ending_here can either be 1 or positive. 
           min_ending_here can either be 1 or negative.
           next min_ending_here will always be prev. 
           max_ending_here * arr[i] next max_ending_here
           will be 1 if prev min_ending_here is 1, otherwise 
           next max_ending_here will be prev min_ending_here *
           arr[i] */
		else if(arr[i] < 0) {
			int temp = maxUptilHere;
			maxUptilHere = max(minUptilHere*arr[i] ,1);
			minUptilHere = temp*arr[i];
		}

		if(maxProductSoFar < maxUptilHere) {
			maxProductSoFar = maxUptilHere;
		}
	}

	return maxProductSoFar;
}

int main() {
	int arr[6] = { 2, -8, 3, -2, 4, -10 };

	int size = 6;

	cout<<maximumContiguousSubArrayProduct(arr, 6);
}