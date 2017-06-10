#include <iostream>
using namespace std;

int maximumContiguousSubArraySum(int* arr, int size) {
	int maxSum = 0;
	int sum = 0;

	for(int i = 0; i < size; i++) {
		sum = sum + arr[i];

		if(maxSum < sum) {
			maxSum = sum;
		}
		else if(sum < 0) {
			sum = 0;
		}
	}
	
	return maxSum;
}

int main() {
	int arr[6] = { 2, -8, 3, -2, 4, -10 };

	int size = 6;

	cout<<maximumContiguousSubArraySum(arr, 6);
}