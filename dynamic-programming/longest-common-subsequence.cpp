/* LCS Problem Statement: Given two sequences, find the length of longest subsequence present
in both of them. A subsequence is a sequence that appears in the same relative order, but not
necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are 
subsequences of “abcdefg”. 
*/

/* Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4. */

/* Time complexity = O(mn) where M and N are lengths of the 2 subsequences respectively */

#include <iostream>
#include <cstring>
using namespace std;

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

int findLongestCommonSubsequence(char* X, char* Y, int m, int n) {
	int matrix[m+1][n+1];

	int i, j;

	for(i = 0; i <=m ; i++) {
		for(j = 0; j <= n; j++) {
			if(i == 0 || j == 0) {
				matrix[i][j] = 0;
			}
			else if(X[i - 1] == Y[j - 1]) {
				matrix[i][j] = 1 + matrix[i-1][j-1];
			}
			else {
				matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
			}

		}
	}

	return matrix[m][n];
}

int main() {
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = std::strlen(X);
	int n = std::strlen(Y);

	printf("Length of LCS is %d\n", findLongestCommonSubsequence(X, Y, m, n));

	return 0;
}