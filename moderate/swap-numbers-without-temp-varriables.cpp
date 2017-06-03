#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main() {
	int a = 5;
	int b = 4;

	cout<<"Original numbers are: "<<"\n";
	cout<<"a is: "<<a<<"\n";
	cout<<"b is: "<<b<<"\n";

	swap(&a, &b);

	cout<<"After swapping, numbers are: "<<"\n";
	cout<<"a is: "<<a<<"\n";
	cout<<"b is: "<<b<<"\n";
}