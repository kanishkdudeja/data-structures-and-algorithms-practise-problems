/* Given two numbers represented by two lists, write a function that returns sum list. 
The sum list is list representation of addition of two input numbers.

Example 1

Input:
  First List: 5->6->3  // represents number 365
  Second List: 8->4->2 //  represents number 248
Output
  Resultant list: 3->1->6  // represents number 613
Example 2

Input:
  First List: 7->5->9->4->6  // represents number 64957
  Second List: 8->4 //  represents number 48
Output
  Resultant list: 5->0->0->5->6  // represents number 65005 

Traverse both lists. One by one pick nodes of both lists and add the values. If sum is more than 10,
then make carry as 1 and reduce sum. 

If one list has more elements than the other then consider remaining values of this list as 0. 

Following is the implementation of this approach.

*/

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* getNewNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

Node* addNodeAtHead(Node* head, int data) {
	Node* newNode = getNewNode(data);

	newNode->next = head;
	head = newNode;

	return head;
}

void printList(Node* head) {
	if(head != NULL) {
		cout<<head->data<<"\n";
		printList(head->next);
	}
	else {
		return;
	}
}

Node* addLists(Node* list1, Node* list2, Node* addedList) {
	
	int sum = 0;
	int carry = 0;

	while(list1 != NULL || list2 != NULL) {
		if(list1 != NULL) {
			sum = sum + list1->data;
		}

		if(list2 != NULL) {
			sum = sum + list2->data;
		}

		sum = sum + carry;

		if(sum >= 10) {
			carry = 1;

			sum = sum - 10;
		}
		else {
			carry = 0;
		}

		addedList = addNodeAtHead(addedList, sum);

		if(list1) {
			list1 = list1->next;
		}
		
		if(list2) {
			list2 = list2->next;
		}

		sum = 0;
	}

	if(carry > 0) {
		addedList = addNodeAtHead(addedList, carry);
	}

	return addedList;
}

int main() {
	Node* list1 = NULL;

	list1 = addNodeAtHead(list1, 9);
	list1 = addNodeAtHead(list1, 9);
	list1 = addNodeAtHead(list1, 9);

	Node* list2 = NULL;

	list2 = addNodeAtHead(list2, 9);
	list2 = addNodeAtHead(list2, 9);
	list2 = addNodeAtHead(list2, 9);
	list2 = addNodeAtHead(list2, 9);

	cout<<"First List: "<<"\n";
	printList(list1);

	cout<<"Second List: "<<"\n";
	printList(list2);

	Node* addedList = NULL;

	addedList = addLists(list1, list2, addedList);

	cout<<"Added list: "<<"\n";
	printList(addedList);
}