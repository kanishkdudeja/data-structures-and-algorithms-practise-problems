/* Given a string, that contains special character together with alphabets (‘a’ to ‘z’ and ‘A’ to ‘Z’), reverse the string in a way that special characters are not affected.

Examples:

Input:   str = "a,b$c"
Output:  str = "c,b$a"
Note that $ and , are not moved anywhere.  
Only subsequence "abc" is reversed

Input:   str = "Ab,c,de!$"
Output:  str = "ed,c,bA!$" 

Time Complexity = O(n)
Space Complexity = O(1)

*/

#include <iostream>
using namespace std;

bool isAlphabet(char character) {
	return ( (character >= 'A' &&  character <= 'Z') ||
             (character >= 'a' &&  character <= 'z') );	
}

void reverseWithoutSpecialChars(char* str, int length) {
	int start = 0;
	int end = length - 1;

	while(start < end) {
		while(!(isAlphabet(str[start]))) {
			start++;
		}

		while(!(isAlphabet(str[end]))) {
			end--;
		}

		if(start >= end) {
			break;
		}

		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}

int main() {
	char str[] = "hello$$$$$$$$$nishk";
	int length = 19;

	reverseWithoutSpecialChars(str, length);

	cout<<str;
}