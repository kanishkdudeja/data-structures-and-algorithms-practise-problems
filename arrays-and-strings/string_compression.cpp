//Complexity = O(n)

#include <iostream>
#include <string>

using namespace std;

string convert_int_to_string(int i) {
	return std::to_string(i);
}

int calculate_compressed_string_length(string str) {
	if(str.length() == 0) {
		return 0;
	}

	char last = str[0];
	int count = 0;
	int size = 0;

	for(int i = 1; i < str.length(); i++) {
		if(last == str[i]) {
			count++;
		}
		else {
			size = size + 1 + convert_int_to_string(count).length();
			last=str[i];
			count = 0;
		}
	}

	size = size + 1 + convert_int_to_string(count).length();

	return size;
}

string compress(string str) {
	int final_length = calculate_compressed_string_length(str);

	if(final_length >= str.length()) {
		return str;
	}
	
	char final_str[final_length];

	char last = str[0];
	int count = 1;
	int index = 0;

	for(int i = 1; i < str.length(); i++) {
		if(last == str[i]) {
			count++;
		}
		else {
			string count_as_str = convert_int_to_string(count);

			int length_count = count_as_str.length();

			final_str[index] = last;

			index = index + 1;

			for(int j = 0; j < length_count; j++) {
				final_str[index + j] = count_as_str[j];
			}

			index = index + length_count;
			last = str[i];
			count = 1;
		}
	}

	string count_as_str = convert_int_to_string(count);

	int length_count = count_as_str.length();

	final_str[index] = last;

	index = index + 1;

	for(int j = 0; j < length_count; j++) {
		final_str[index + j] = count_as_str[j];
	}

	return final_str;
}

int main ()
{
  string str = "aaabbcdddde";

  string compressed_str = compress(str);

  cout<<compressed_str;
}