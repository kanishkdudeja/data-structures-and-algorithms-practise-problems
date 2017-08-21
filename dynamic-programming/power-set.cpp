/* Power Set

Power set P(S) of a set S is the set of all subsets of S. For example S = {a, b, c} then 
P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.

We should first have some reasonable expectations of our time and space complexity.

How many subsets of a set are there? When we generate a subset, each element has the "choice" of either
being in there or not. That is, for the first element, there are two choices: it is either in the set or 
it is not. 

For the second, there are two, etc. So, doing { 2 * 2 * . . . } n times gives us 2" subsets.

Assuming that we're going to be returning a list of subsets, then our best case time is actually the total
number of elements across all of those subsets. There are 2" subsets and each of the n elements will be
contained in half of the subsets (which 2 n - 1 subsets). Therefore, the total number of elements across all of
those subsets is n * 2 n - 1.
We will not be able to beat 0(n2") in space or time complexity.

The subsets of {a 1 , a 2 ,••• , an} are also called the powersetP({a 1 , a 2 , ••• , an}),or justP(n).

Solution #1: Recursion

This problem is a good candidate for the Base Case and Build approach. Imagine that we are trying to find
all subsets of a set like S = {a 1, a 2, • • • , a n }.

We can start with the Base Case.

Base Case: n = 0.

There is just one subset of the empty set: {}.

Case:n = 1.
There are two subsets of the set {aJ: {}, {aJ.

Case:n = 2.
There are four subsets of the set {a 1 , aJ: {} , {aJ, {a), {a 1 , a 2 }.

Case:n = 3.
Now here's where things get interesting. We want to find a way of generating the solution for n
on the prior solutions.

P(2) = {}, {a 1 }, {a 2 }, {a 1 , a 2}
P(3) = {}, {aJ, {a 2 }, {a 3 }, {a 1 , a 2 }, {a 1 , a 3 }, {a 2, a 3}, {a 1 , a 2 , a 3}

The difference between these solutions is that P ( 2) is missing all the subsets containing a 3•
P(3) - P(2) = {a 3 }, {a 1 , a 3 }, {a 2 , a 3 }, {a 1 , a 2 , a 3}

How can we use P ( 2) to create P ( 3)? We can simply clone the subsets in P ( 2) and add a 3 to them:
{} , {a 1}, {a 2}, {a 1, aJ
P(2)
P(2) + a,
= {a 3 }, {a 1 , a 3 }, {a 2 , a), {a 1 , a 2 , a 3 }

When merged together, the lines above make P ( 3).
Case:n > 0
Generating P ( n) for the general case is just a simple generalization of the above steps. We compute
P ( n-1), clone the results, and then add a n to each of these cloned sets.

While there's nothing wrong with the above solution, there's another way to approach it.

Recall that when we're generating a set, we have two choices for each element: (1) the element 
is in the set (the "yes" state) or (2) the element is not in the set (the "no" state). 

This means that each subset is a sequence of yeses I nos-e.g., "yes, yes, no, no, yes, no"
This gives us 2 n possible subsets. How can we iterate through all possible sequences of"yes" /"no" states
for all elements? If each "yes" can be treated as a 1 and each "no" can be treated as a 0, 
then each subset can be represented as a binary string.

Generating all subsets, then, really just comes down to generating all binary numbers (that is, all 
integers). We iterate through all numbers from 0 to 2 n (exclusive) and translate the binary 
representation of the numbers into a set. Easy!

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