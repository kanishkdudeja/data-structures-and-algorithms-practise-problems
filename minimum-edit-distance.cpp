/* Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert, Remove, Replace
All of the above operations are of equal cost.

Examples:

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a 

Solution:

What are the subproblems in this case?

The idea is to process all characters one by one starting from either from left or right sides of both strings.
Let we traverse from right corner, there are two possibilities for every pair of character being traversed.

m: Length of str1 (first string)
n: Length of str2 (second string)

If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.

Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.

Insert: Recur for m and n-1
Remove: Recur for m-1 and n
Replace: Recur for m-1 and n-1

The time complexity of above solution is exponential. In worst case, we may end up doing O(3m) operations. The worst case happens when none of characters of two strings match. Below is a recursive call diagram for worst case.

We can see that many subproblems are solved again and again, for example eD(2,2) is called three times. 

Since same suproblems are called again, this problem has Overlapping Subprolems property. So Edit Distance problem has both properties (see this and this) of a dynamic programming problem.

Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by constructing a temporary array that stores results of subpriblems. 

Time Complexity: O(m x n)
Auxiliary Space: O(m x n) */

#include <iostream>
using namespace std;

// Utility function to find minimum of three numbers
int find_min(int x, int y, int z) {
    return min(min(x, y), z);
}

int minimumEditDistance(string s1, int length1, string s2, int length2) {
	int matrix[length1 + 1][length2 + 1];

	for(int i = 0; i < length1 + 1; i++) {
		for(int j = 0; j < length2 + 1; j++) {
			if(i == 0) {
				matrix[0][j] = j;
			}
			else if(j == 0) {
				matrix[i][0] = i;
			}
			else if(s1[i-1] == s2[j-1]) {
				matrix[i][j] = matrix[i-1][j-1];
			}
			else {
				matrix[i][j] = 1 + find_min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
			}
		}
	}

	return matrix[length1][length2];
}

int main() {
	string s1 = "hello";
	string s2 = "fellow";

	cout<<minimumEditDistance(s1, 5, s2, 6);
}