/* Problem: Given two strings, find out if the second string is a rotation of the first

Approach: Concatenate first string with itself and check if second string is a concatenation of the 
concatenated string. If yes, then it's a rotation. Otherwise not.

Space Complexity = O(n) since we are saving concatenated length of 2 times first string in memory O(2n)
Time Complexity depends upon time complexity of doing substring check. Other than that,
concatenation would take O(n) time */

#include <iostream>
#include <string>
using namespace std;

bool isRotation(string s1, string s2) {
	if(s1.length() != s2.length()) {
		return false;
	}

	if(s1 == s2) {
		return true;
	}

	string s3 = s1 + s1;

	if(s3.find(s2) != std::string::npos) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	string s1 = "hello";
	string s2 = "lohel";

	cout<<isRotation(s1, s2);
}