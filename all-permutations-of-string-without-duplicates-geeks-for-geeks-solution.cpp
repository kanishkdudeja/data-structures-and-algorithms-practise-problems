/*

A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements
of an ordered list S into a one-to-one correspondence with S itself. 

A string of length n has n! permutations.

Below are the permutations of string ABC.
ABC ACB BAC BCA CBA CAB

Here is a solution that is used as a basis in backtracking.

http://www.geeksforgeeks.org/wp-content/uploads/NewPermutation.gif

Algorithm Paradigm: Backtracking
Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a a permutation.

Note : The above solution prints duplicate permutations if there are repeating characters in input string.

*/

#include <iostream>
using namespace std;

/* Function to swap values at two pointers */
void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void printPermutations(char* str, int start, int end) {
	int i;

	if(start == end) {
		cout<<str<<endl;
	}
	else {
		for(i = start; i <= end; i++) {
			swap(str+start, str+i);

			printPermutations(str, start+1, end);

			swap(str+start, str+i); //backtrack
		}
	}
}

int main() {
	char s[3] = {'a', 'b', 'c'};

	printPermutations(s, 0, 2);
}