/* The Longest Increasing Subsequence (LIS) problem is to find the length of the 
longest subsequence of a given sequence such that all elements of the subsequence 
are sorted in increasing order. For example, the length of LIS for 
{10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}

Time Complexity = O(n2) where n is the number of elements in the array
Space Complexity = O(n) where n is the number of the elements in the array 

Optimal Substructure:
Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.
Then, L(i) can be recursively written as:
L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
L(i) = 1, if no such j exists.

To find the LIS for a given array, we need to return max(L(i)) where 0 < i < n.
Thus, we see the LIS problem satisfies the optimal substructure property as the main problem 
can be solved using solutions to subproblems.

Following is a simple recursive implementation of the LIS problem. It follows the recursive structure 
discussed above.

 A Naive C/C++ recursive implementation of LIS problem 
#include<stdio.h>
#include<stdlib.h>
 
/* To make use of recursive calls, this function must return
   two things:
   1) Length of LIS ending with element arr[n-1]. We use
      max_ending_here for this purpose
   2) Overall maximum as the LIS may end with an element
      before arr[n-1] max_ref is used this purpose.
   The value of LIS of full array of size n is stored in
   *max_ref which is our final result 
int _lis( int arr[], int n, int *max_ref)
{
    /* Base case 
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS ending with arr[n-1]
    int res, max_ending_here = 1; 
 
    /* Recursively get all LIS ending with arr[0], arr[1] ...
       arr[n-2]. If   arr[i-1] is smaller than arr[n-1], and
       max ending with arr[n-1] needs to be updated, then
       update it 
    for (int i = 1; i < n; i++)
    {
        res = _lis(arr, i, max_ref);
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall max. And
    // update the overall max if needed
    if (*max_ref < max_ending_here)
       *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis( arr, n, &max );
 
    // returns max
    return max;
}

We can see that there are many subproblems which are solved again and again. So this problem has 
Overlapping Substructure property and recomputation of same subproblems can be avoided by 
either using Memoization or Tabulation. Following is a tabluated implementation for the LIS problem.

*/

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