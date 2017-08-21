/* Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum 
total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1]
which represent values and weights associated with n items respectively. Also given an integer W 
which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the
weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete
item, or don’t pick it (0-1 property).

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.

A simple solution is to consider all subsets of items and calculate the total weight and value of all 
subsets. Consider the only subsets whose total weight is smaller than W. From all such subsets, pick 
the maximum value subset.

1) Optimal Substructure:
To consider all subsets of items, there can be two cases for every item: (1) the item is included in 
the optimal subset, (2) not included in the optimal set.
Therefore, the maximum value that can be obtained from n items is max of following two values.
1) Maximum value obtained by n-1 items and W weight (excluding nth item).
2) Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item 
(including nth item).

If weight of nth item is greater than W, then the nth item cannot be included and case 1 is the only 
possibility.

2) Overlapping Subproblems
Following is recursive implementation that simply follows the recursive structure mentioned above.

A Naive recursive implementation of 0-1 Knapsack problem 
#include<stdio.h>
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   // Base Case
   if (n == 0 || W == 0)
       return 0;
 
   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
 
   // Return the maximum of two cases: 
   // (1) nth item included 
   // (2) not included
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}
 
// Driver program to test above function
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}

It should be noted that the above function computes the same subproblems again and again. See the 
following recursion tree, K(1, 1) is being evaluated twice. Time complexity of this naive recursive 
solution is exponential (2^n).

Since suproblems are evaluated again, this problem has Overlapping Subprolems property. So the 0-1 
Knapsack problem has both properties (see this and this) of a dynamic programming problem. 
Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided 
by constructing a temporary array K[][] in bottom up manner. 

Following is Dynamic Programming based implementation.

*/

#include <iostream>
using namespace std;

int knapsack(int* weights, int* values, int n, int w) {
	int matrix[n+1][w+1];

	int i, j;

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= w; j++) {
			if(i == 0 || j == 0) {
				matrix[i][j] = 0;
			}
			else if(weights[i] > w) {
				matrix[i][j] = matrix[i-1][j];
			}
			else {
				matrix[i][j] = max(matrix[i-1][j], values[i-1] + matrix[i-1][j-weights[i-1]]);
			}
		}
	}

	return matrix[n][w];
}

int main() {
	int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  w = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(wt, val, n, w);
}