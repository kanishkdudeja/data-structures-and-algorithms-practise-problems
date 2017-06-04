#include <iostream>
using namespace std;

bool searchRecurse(const char** arr, int startIndex, int endIndex, const char* data) {
	if(startIndex > endIndex) {
		return false;
	}

	int length = endIndex - startIndex + 1;
	int middleIndex = startIndex + (length / 2);

	if(arr[middleIndex] == "") {
		int left = middleIndex - 1;
		int right = middleIndex + 1;

		while(true) {
			if(left >= startIndex and arr[left] != "") {
				middleIndex = left;
				break;
			}
			else if(right <= endIndex and arr[right] != "") {
				middleIndex = right;
				break;
			}
			else if(left < startIndex || right > endIndex) {
				return false;
			}
			left--;
			right++;
		}
	}

	if(arr[middleIndex] == data) {
		return true;
	}
	else if(arr[middleIndex] < data) {
		return searchRecurse(arr, middleIndex + 1, endIndex, data);
	}
	else if(arr[middleIndex] > data) {
		return searchRecurse(arr, startIndex, middleIndex - 1, data);
	}
}

bool search(const char** arr, int size, const char* data) {
	return searchRecurse(arr, 0, size - 1, data);
}

int main() {
	const char *a[12];
	a[0] = "at";
	a[1] = "";
	a[2] = "ball";
	a[3] = "";
	a[4] = "";
	a[5] = "car";
	a[6] = "";
	a[7] = "";
	a[8] = "";
	a[9] = "";
	a[10] = "dad";
	a[11] = "";

	const char* data = "ball";

	bool isFound;
	isFound = search(a, 12, data);

	cout<<isFound;
}