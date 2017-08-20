//Time complexity is O(n) since we traverse array to find spaces
//and then do equal number of swaps.

#include <iostream>
using namespace std;

void reverseCharsInWordsInString(char* str, int length) {
	int wordIndex = 0;
	int oldSwapIndex = 0;
	int newSwapIndex = 0;

	for(int i = 0; i < length; i++) {
		if(str[i] == ' ' || (i == length-1)) {
			if(i == (length - 1)) {
				newSwapIndex = i;	
			}
			else {
				newSwapIndex = i - 1;
			}
			
			oldSwapIndex = wordIndex;

			while(newSwapIndex >= oldSwapIndex) {
				char tmp = str[oldSwapIndex];
				str[oldSwapIndex] = str[newSwapIndex];
				str[newSwapIndex] = tmp;

				oldSwapIndex++;
				newSwapIndex--;
			}

			wordIndex = i + 1;
		}
	}
}

void printString(char* str, int length) {
	for(int i = 0; i < length; i++) {
		cout<<str[i]<<"\n";
	}
}

int main() {
	char str[12] = { 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};

	cout<<"Original string: \n";
	printString(str, 11);

	reverseCharsInWordsInString(str, 11);

	cout<<"String with reversed characters in words: \n";
	printString(str, 11);
}