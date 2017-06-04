#include <iostream>
using namespace std;

void printArray(int* arr, int length) {
	for(int i = 0; i < length; i++) {
		cout<<arr[i]<<"\n";
	}
}

void sortedMerge(int* arr1, int arr1Length, int* arr2, int arr2Length, int fullLength) {
	int lastIndex1 = arr1Length - 1;
	int lastIndex2 = arr2Length - 1;

	int finalIndex = fullLength - 1;

	while(lastIndex2 >= 0) {
		if((arr1[lastIndex1] > arr2[lastIndex2]) && (lastIndex1 >= 0)) {
			arr1[finalIndex] = arr1[lastIndex1];
			lastIndex1--;
		} else if(arr2[lastIndex2] > arr1[lastIndex1]) {
			arr1[finalIndex] = arr2[lastIndex2];
			lastIndex2--;
		}
		finalIndex--;
	}
}

int main() {
	int arr1[7] = { 2, 5, 7, 9, 0, 0, 0 };
	int arr2[3] = { 1, 3, 6 };

	cout<<"Array A: \n";
	printArray(arr1, 7);

	cout<<"Array B: \n";
	printArray(arr2, 3);

	sortedMerge(arr1, 4, arr2, 3, 7);

	cout<<"Array A after merging \n";
	printArray(arr1, 7);
}