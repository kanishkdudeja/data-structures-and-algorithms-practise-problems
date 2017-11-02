/*  Count Negative Numbers in a Column-Wise and Row-Wise Sorted Matrix

Find the number of negative numbers in a column-wise / row-wise sorted matrix M[][]. Suppose M has n rows and m columns.

Example:

Input:  M =  [-3, -2, -1,  1]
             [-2,  2,  3,  4]
             [4,   5,  7,  8]
Output : 4
We have 4 negative numbers in this matrix

Naive Solution
Here’s a naive, non-optimal solution.

We start from the top left corner and count the number of negative numbers one by one, from left to right and top to bottom.

With the given example:

[-3, -2, -1,  1]
[-2,  2,  3,  4]
[4,   5,  7,  8]

Evaluation process

[→,  →,  →,  1]
[→,  2,  3,  4]
[4,  5,  7,  8]

In this approach we are traversing through the all the elements and therefore, in the worst case scenario (when all numbers are negative in the matrix), this takes O(n * m) time.

Optimal Solution

Here’s a more efficient solution:

    We start from the top right corner and find the position of the last negative number in the first row.
    Using this information, we find the position of the last negative number in the second row.
    We keep repeating this process until we either run out of negative numbers or we get to the last row.

With the given example:
[-3, -2, -1,  1]
[-2,  2,  3,  4]
[4,   5,  7,  8]

Here's the idea:
[-3, -2,  ↓,  ←] -> Found 3 negative numbers in this row
[ ↓,  ←,  ←,  4] -> Found 1 negative number in this row
[ ←,  5,  7,  8] -> No negative numbers in this row 

With this solution, we can now solve this problem in O(n + m) time.

*/
#include<iostream>
using namespace std;

int countNegativeIntegers(int matrix[][4], int m, int n) {
	int count;
	int i = 0;
	int j = n - 1;

	while (j >= 0 && i < n) {
		if(matrix[i][j] < 0) {
			count = count + j + 1;
			i = i + 1;
		}
		else {
			j = j -1;
		}
	}

	return count;
}

int main() {
  int matrix[3][4] = {-3,-2,-1,1, 
      -2,2,3,4,
      4,5,7,8
  };

  cout<<countNegativeIntegers(matrix, 3, 4);
}