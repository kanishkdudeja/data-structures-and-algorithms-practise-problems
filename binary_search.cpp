/* The below algorithm only works for sorted arrays
	Time complexity - O(log n) */

#include <iostream>
using namespace std;

bool binarySearchRecurse(int* arr, int startIndex, int endIndex, int data) {
	if(startIndex > endIndex) {
		return false;
	}

	int length = endIndex - startIndex + 1;
	int middleIndex = startIndex + (length / 2);

	if(arr[middleIndex] == data) {
		return true;
	}
	else if(arr[middleIndex] < data) {
		return binarySearchRecurse(arr, middleIndex + 1, endIndex, data);
	}
	else if(arr[middleIndex] > data) {
		return binarySearchRecurse(arr, startIndex, middleIndex - 1, data);
	}
}

bool binarySearch(int* arr, int size, int data) {
	int startIndex = 0;
	int endIndex = size - 1;

	return binarySearchRecurse(arr, startIndex, endIndex, data);
}

void printArray(int* arr, int size) {
	for(int i = 0; i < size; i++) {
		cout<<arr[i]<<"\n";
	}
}

int main() {
	int arr[10] = { 1, 3, 5, 6, 7, 10, 11, 12, 14, 16 };

	cout<<"Array: "<<"\n";
	printArray(arr, 10);

	cout<<"Searching for element 3: "<<"\n";
	cout<<binarySearch(arr, 10, 3)<<"\n";

	cout<<"Searching for element 15: "<<"\n";
	cout<<binarySearch(arr, 10, 15)<<"\n";
}