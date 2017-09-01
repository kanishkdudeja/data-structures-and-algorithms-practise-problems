/* Permutations without Dups: Write a method to compute all permutations of a string of unique characters.

Algorithm:

1. We use a vector to store all permutations of the string.
2. If string is null or of 0 length, we return a vector with "" as element 
3. We keep first character of the string and recursively call getAllPermutations on the remaining string. 
4. When the function returns, we add the first character to all positions in all the strings that we got
in the vector.

Time Complexity is O(n*n!)

*/

#include <iostream>
#include <vector>
using namespace std;

void printPermutations(vector<string> list) {
	vector<string>::iterator it;  // declare an iterator to a vector of strings

	for(it=list.begin(); it < list.end(); it++) {
	    cout<< *it << endl;
	}
}

vector<string> getAllPermutations(string str) {
	vector<string> permutations = vector<string>();
	if(str == "") {
		permutations.push_back("");
		return permutations;
	}
	else {
		int length = str.length();

		char firstChar = str.at(0);
		std::string firstCharAsString(1, firstChar);

		string leftString = str.substr(1, length-1);

		vector<string> subList = getAllPermutations(leftString);

		vector<string>::iterator it;  // declare an iterator to a vector of strings

		for(it=subList.begin(); it < subList.end(); it++) {
		    string word = *it;
		    int wordLength = word.length();

		    for(int i = 0; i <= wordLength; i++) {
		    	string prefix = word.substr(0, i);

		    	string suffix = word.substr(i);

		    	string final = prefix + firstCharAsString + suffix;

		    	permutations.push_back(final);
		    }
		}
	}

	return permutations;
}

int main() {
	string s = "abc";

	vector<string> permutationList = getAllPermutations(s);

	printPermutations(permutationList);
}