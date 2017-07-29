/* Write a program to detect a loop in the linked list 

Solution: 1. Create two pointers, FastPointer and SlowPointer.
2. Move FastPointer at a rate of 2 steps and SlowPointer at a rate of 1 step.
3. If they don't collide and fast reaches end of list, means that there is no loop.
4. If and when they collide, move SlowPointer to LinkedListHead. Keep FastPointer where it is.
4. Move SlowPointer and FastPointer at a rate of one step. Return the new collision point.

Time Complexity = O(n)
Space Complexity = O(1) since we are only using 2 extra pointers

*/

#include <iostream>
#include <unordered_map>
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

Node* insertNodeAtHead(Node* head, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head;

	return newNode;
}

void printLinkedList(Node* head) {
	Node* tmpNode = head;
	while(tmpNode->next) {
		cout<<tmpNode->data<<"\n";
		tmpNode = tmpNode->next;
	}
	cout<<tmpNode->data<<"\n";
}

Node* detectLoop(Node* head) {
	Node* slow = head;
	Node* fast = head;

	if(fast == NULL) {
		return NULL;
	}

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
		fast = fast->next;

		if(slow == fast) {
			break;
		}
	}

	if(fast == NULL || fast->next == NULL) {
		return NULL;
	}

	slow = head;

	while(slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	return fast;
}

int main() {
	Node* head = NULL;

	head = insertNodeAtHead(head, 1);
	head = insertNodeAtHead(head, 2);
	head = insertNodeAtHead(head, 3);
	head = insertNodeAtHead(head, 4);

	if(detectLoop(head) == NULL) {
		cout<<"Loop not found";
	}
	else {
		cout<<"Loop found";
	}
}