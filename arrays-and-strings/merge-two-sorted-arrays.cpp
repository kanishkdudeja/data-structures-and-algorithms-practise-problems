#include <iostream>
using namespace std;

void printArray(int* arr, int length) {
	for(int i = 0; i < length; i++) {
		cout<<arr[i]<<"\n";
	}
}

void mergeSortedArrays(int* arr1, int length1, int* arr2, int length2, int* finalArr) {
	int offset1 = 0;
	int offset2 = 0;

	int i = 0;

	while(offset1 < length1 && offset2 < length2) {
		if(arr1[offset1] <= arr2[offset2]) {
			finalArr[i] = arr1[offset1];
			offset1++;
		} else if(arr1[offset1] > arr2[offset2]) {
			finalArr[i] = arr2[offset2];
			offset2++;
		}
		i++;
	}

	while(offset1 < length1) {
		finalArr[i] = arr1[offset1];
		i++;
		offset1++;
	}

	while(offset2 < length2) {
		finalArr[i] = arr2[offset2];
		i++;
		offset2++;
	}
}

int main() {
	int a[5] = {1, 3, 6, 8, 9};

	int b[5] = {2, 3, 4, 7, 10};

	cout<<"First array: "<<"\n";
	printArray(a, 5);
	
	cout<<"Second array: "<<"\n";
	printArray(b, 5);

	int c[10];

	mergeSortedArrays(a, 5, b, 5, c);

	cout<<"Merged sorted array: "<<"\n";
	printArray(c, 10);
}