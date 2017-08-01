/* Find the longest path in a matrix with given constraints
Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1.

We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.

Example:

Input:  mat[][] = {{1, 2, 9}
                   {5, 3, 8}
                   {4, 6, 7}}
Output: 4

The longest path is 6-7-8-9. 

The idea is simple, we calculate longest path beginning with every cell. Once we have computed longest for all cells, we return maximum of all longest paths. One important observation in this approach is many overlapping subproblems. Therefore this problem can be optimally solved using Dynamic Programming.

Below is Dynamic Programming based implementation that uses a lookup table dp[][] to check if a problem is already solved or not.

*/
#include <iostream>
using namespace std;

int computeLongestPath(int matrix[0][3], int m, int n, int i, int j, int dp[][3]) {
	// Base case
    if (i<0 || i>=n || j<0 || j>=n) {
        return 0;
    }

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	if((j+1 < n) && (matrix[i][j] + 1 == matrix[i][j+1])) {
		return (1 + computeLongestPath(matrix, m, n, i, j+1, dp));
	}
	else if((j-1 >= 0) && (matrix[i][j] + 1 == matrix[i][j-1])) {
		return (1 + computeLongestPath(matrix, m, n, i, j-1, dp));
	}
	else if((i+1 < m) && (matrix[i][j] + 1 == matrix[i+1][j])) {
		return (1 + computeLongestPath(matrix, m, n, i+1, j, dp));
	}
	else if((i-1 >= 0) && (matrix[i][j] + 1 == matrix[i-1][j])) {
		return (1 + computeLongestPath(matrix, m, n, i-1, j, dp));
	}

	return 1;
}

int main() {
	int matrix[3][3] = { {1, 2, 9}, {5, 3, 8}, {4, 6, 7} };

	int dp[3][3] = { {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1} };

	int answer = 1;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {

			dp[i][j] = computeLongestPath(matrix, 3, 3, i, j, dp);

			if(dp[i][j] > answer) {
				answer = dp[i][j];
			}
		}
	}

	cout<<answer;
}