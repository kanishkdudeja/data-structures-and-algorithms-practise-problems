//Complexity = O(n)

#include <iostream>
using namespace std;

bool is_palindrome_permutation(string str1) {
	static int arr[256];

	for(int i = 0; i < str1.length(); i++) {
		int char_code = int(str1[i]);

		arr[char_code] = arr[char_code] + 1;
	}

	bool atMostOneOdd = false;

	for(int j = 0; j < 256; j++) {
		if(arr[j] % 2 == 1) {

			if(atMostOneOdd == true) {
				return false;
			}
			atMostOneOdd = true;
		}	
	}

	return true;
}

int main()
{
  string str1 = "tactcoa";

  cout<<is_palindrome_permutation(str1);
}