#include <iostream>
using namespace std;

void printArray(int* arr, int size) {
	for(int i = 0; i < size; i++) {
		cout<<arr[i]<<"\n";
	}
}

void moveZeroesToEnd(int* arr, int size) {
	int overwriteOffset = 0;
	int countZeros = 0;

	for(int i = 0; i < size; i++) {
		if(arr[i] == 0) {
			countZeros++;
		} else {
			if(i != overwriteOffset) {
				arr[overwriteOffset] = arr[i];
			}

			overwriteOffset++;
		}
	}

	for(int j = overwriteOffset; j < size; j++) {
		arr[j] = 0;
	}
}

int main() {
	int arr[7] = { 3, 0, 4, 5, 0, 7, 9 };

	cout<<"Original array: \n";
	printArray(arr, 7);

	moveZeroesToEnd(arr, 7);

	cout<<"Array after moving zeroes to end: \n";
	printArray(arr, 7);
}