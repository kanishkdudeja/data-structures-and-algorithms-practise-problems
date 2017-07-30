/* Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.

Examples:

Input:  n = 3
Output: 4
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step

Input:  n = 4
Output: 7 

The time complexity of above solution is exponential, a close upper bound is O(3n). 
If we draw the complete recursion tree, we can observer that many subproblems are solved again and again. 

For example, when we start from n = 6, we can reach 4 by subtracting one 2 times and by 
subtracting 2 one times. So the subproblem for 4 is called twice.

Since same suproblems are called again, this problem has Overlapping Subproblems property. 

Time complexity of solution = O(n)
Auxiliary Space = O(n)

*/

#include <iostream>
using namespace std;

int countWays(int distance) {
	int countArr[distance+1];

	countArr[0] = 1;
	countArr[1] = 1;
	countArr[2] = 2;

	for(int i = 3; i <= distance; i++) {
		countArr[i] = countArr[i-1] + countArr[i-2] + countArr[i-3];
	}

	return countArr[distance];
}

int main() {
	int distance = 4;

	cout<<countWays(4);
}