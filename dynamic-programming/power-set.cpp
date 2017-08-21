/* Power Set
Power Set Power set P(S) of a set S is the set of all subsets of S. For example S = {a, b, c} then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.

If S has n elements in it then P(s) will have 2^n elements


Algorithm:

Input: Set[], set_size
1. Get the size of power set
    powet_set_size = pow(2, set_size)
2  Loop for counter from 0 to pow_set_size
     (a) Loop for i = 0 to set_size
          (i) If ith bit in counter is set
               Print ith element from set for this subset
     (b) Print seperator for subsets i.e., newline 

*/

#include <iostream>
#include <cmath>
using namespace std;

void printAllSubsets(char* set, int size) {
	int powerSetSize = pow(2, size);

	for(int i = 0; i < powerSetSize; i++) {
		for(int j = 0; j < size; j++) {
			/* Check if jth bit in the counter is set
             If set then print jth element from set */
			if(i & (1<<j)) {
				cout<<set[j];
			}
		}
		cout<<"\n";
	}
}

int main() {
	char set[] = {'a', 'b', 'c', 'd'};

	int size = 4;

	printAllSubsets(set, 4);
}