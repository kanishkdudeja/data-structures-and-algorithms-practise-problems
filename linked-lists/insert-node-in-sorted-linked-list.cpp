/* Given a sorted linked list, insert a new node in it so that
it still remains sorted */

/* Time Complexity = O(n) since the element may be required to be inserted
at the last position */

#include <iostream>
using namespace std;

struct Node {
	int data = 0;
	Node* next = NULL;
};

Node* insertNodeAtHead(Node* head, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head;

	return newNode;
}

void printLinkedList(Node* head) {
	if(head == NULL) {
		return;
	}

	Node* tmpNode = head;
	while(tmpNode->next) {
		cout<<tmpNode->data<<"\n";
		tmpNode = tmpNode->next;
	}
	cout<<tmpNode->data<<"\n";
}

Node* insertNodeInSortedList(Node* head, int data) {
	Node* prev = NULL;
	Node* temp = head;

	while(temp != NULL && temp->data < data) {
		prev = temp;
		temp = temp->next;	
	}

	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = temp;

	if(prev == NULL) {
		head = newNode;
	}
	else {
		prev->next = newNode;
	}
	
	return head;
}

int main ()
{
	Node* head = NULL;

	head = insertNodeAtHead(head, 10);
	head = insertNodeAtHead(head, 9);
	head = insertNodeAtHead(head, 8);
	head = insertNodeAtHead(head, 6);
	head = insertNodeAtHead(head, 5);
	head = insertNodeAtHead(head, 4);
	head = insertNodeAtHead(head, 3);
	head = insertNodeAtHead(head, 2);
	head = insertNodeAtHead(head, 1);
	
	cout<<"Original Linked List: "<<"\n";
	printLinkedList(head);

	head = insertNodeInSortedList(head, 7);

	cout<<"Linked list after inserting 7: "<<"\n";
	printLinkedList(head);
}