//Complexity = O(n)

#include <iostream>
using namespace std;

bool is_permutation(string str1, string str2) {
	int str1_length = str1.length();
	int str2_length = str2.length();

	if(str1_length != str2_length) {
		return false;
	}

	static int arr[255];

	for(int i = 0; i < str1_length; i++) {
		int char_code = str1[i];

		arr[char_code] = arr[char_code] + 1;
	}

	for(int j = 0; j < str2_length; j++) {
		int char_code = str2[j];

		arr[char_code] = arr[char_code] - 1;
	}

	for(int k = 0; k < 255; k++) {
		if(arr[k] != 0) {
			return false;
		}
	}

	return true;
}

int main ()
{
  string str1 = "elhs";
  string str2 = "hels";

  cout<<is_permutation(str1, str2);
}