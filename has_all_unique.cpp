//Complexity = O(n) or 0(1) if we assume that the function can only iterate
//255 times at maximum to find out an answer

#include <iostream>
using namespace std;

bool has_all_unique(string str) {
	int str_length = str.length();

	if(str_length > 255) {
		return 0;
	}

	static int arr[255];

	for(int j = 0; j < str_length; j++) {
		int char_code = int(str[j]);

		if(arr[char_code] == 1) {
			return false;
		}
		else {
			arr[char_code] = 1;
		}
	}

	return true;
}

int main ()
{
  string str1 = "hello";

  cout<<has_all_unique(str1);
}