//Complexity = O(n)

#include <iostream>
using namespace std;

string urlify(string str1, int true_length) {
	int num_spaces = 0;

	string final_str = str1;

	for(int i = 0; i <= true_length - 1; i++) {
		if(isspace(str1[i])) {
			num_spaces = num_spaces + 1;
		}
	}

	int final_end_index = true_length + (2*num_spaces) - 1;

	for(int i = true_length - 1; i >= 0; i--) {
		if(final_end_index > 0) {
			if(!(isspace(str1[i]))) {
				final_str[final_end_index] = str1[i];
				final_end_index = final_end_index - 1;
			}
			else {
				final_str[final_end_index] = '0';
				final_str[final_end_index - 1] = '2';
				final_str[final_end_index - 2] = '%';
				final_end_index = final_end_index - 3;
			}
		}
	}

	return final_str;
}

int main ()
{
  string str1 = "Mr John Smith    ";
  int true_length = 13;

  string urlified_str = urlify(str1, true_length);

  cout<<urlified_str;
}