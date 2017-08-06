/* Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.

Examples

arr[] = {1, 5, 11, 5}
Output: true 
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false 
The array cannot be partitioned into equal sum sets.

Following are the two main steps to solve this problem:
1) Calculate sum of the array. If sum is odd, there can not be two subsets with equal sum, so return false.
2) If sum of array elements is even, calculate sum/2 and find a subset of array with sum equal to sum/2.

The first step is simple. The second step is crucial, it can be solved either using recursion or Dynamic Programming.

The isSubsetSum problem can be divided into two subproblems
…a) Include the last element, recur for n = n-1, sum = sum – set[n-1]
…b) Exclude the last element, recur for n = n-1.
If any of the above the above subproblems return true, then return true.

Following is the recursive formula for isSubsetSum() problem.

isSubsetSum(set, n, sum) = isSubsetSum(set, n-1, sum) || 
                           isSubsetSum(set, n-1, sum-set[n-1])
Base Cases:
isSubsetSum(set, n, sum) = false, if sum > 0 and n == 0
isSubsetSum(set, n, sum) = true, if sum == 0 

Following is naive recursive implementation that simply follows the recursive structure mentioned above.
 
// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
   // Base Cases
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
 
   // If last element is greater than sum, then ignore it
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
 
   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   *//*
   return isSubsetSum(set, n-1, sum) || 
                        isSubsetSum(set, n-1, sum-set[n-1]);
} 

The above solution may try all subsets of given set in worst case. Therefore time complexity of the 
above solution is exponential. The problem is in-fact NP-Complete.
(There is no known polynomial time solution for this problem).

We can solve the problem in Pseudo-polynomial time using Dynamic programming. We create a boolean 2D table 
subset[][] and fill it in bottom up manner. The value of subset[i][j] will be true if there is a subset 
of set[0..j-1] with sum equal to i., otherwise false. Finally, we return subset[sum][n]

*/

#include <iostream>
using namespace std;

bool checkIfSubsetEqualsSum(int* set, int n, int sum) {
	bool matrix[n+1][sum+1];

	for(int i = 0; i <= n; i++) {
		matrix[i][0] = true;
	}

	for(int j = 1; j <= sum; j++) {
		matrix[0][j] = false;
	}

	// uptil every number in the set (uptil position (i - 1) in the set)
	for(int i = 1; i <= n; i++) {

		// for every sum from 1 to sum
		for(int j = 1; j <= sum; j++) {
		
			//evaluate if numbers uptil (i-1) have a subset that can add to sum j
			int currentNumber = set[i-1];

			// if current number (last in current subset) is greater than sum desired
			if(currentNumber > j) {

				// value can be equated as matrix[excluding current number in subset][sum]
				matrix[i][j] = matrix[i-1][j];
			}

			// if current number (last in current subset) <= sum desired
			else if(currentNumber <= j) {

				// either exclude current number or include current number
				matrix[i][j] = matrix[i-1][j] || matrix[i-1][j-currentNumber];
			}
		}
	}

	return matrix[n][sum];
}

int main() {
	int set[5] = { 1, 3, 8, 4, 6 };

	int totalSum = 0;

	for(int i = 0; i < 5; i++) {
		totalSum = totalSum + set[i];
	}

	if(totalSum % 2 == 0) {
		bool isPossible = checkIfSubsetEqualsSum(set, 5, totalSum/2);

		if(isPossible) {
			cout<<"Partition possible Therefore, set can be divided into two subsets with equal sum";
		}
		else {
			cout<<"Partition not possible since total sum is odd. Therefore, set cannot be divided into two subsets with equal sum";
		}
	}
	else {
		cout<<"Partition not possible since total sum is odd. Therefore, set cannot be divided into two subsets with equal sum";
	}
}