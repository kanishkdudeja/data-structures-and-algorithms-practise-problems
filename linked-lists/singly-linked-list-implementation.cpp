//Complexity = O(n) or 0(1) if we assume that the function can only iterate
//255 times at maximum to find out an answer

#include <iostream>
using namespace std;

struct Node {
	int data = 0;
	Node* next = nullptr;
};

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

int main ()
{
	Node* head = NULL;

	head = insertNodeAtHead(head, 0);
	head = insertNodeAtHead(head, 1);
	head = insertNodeAtHead(head, 2);
	head = insertNodeAtHead(head, 3);
	head = insertNodeAtHead(head, 4);
	head = insertNodeAtHead(head, 2);
	head = insertNodeAtHead(head, 3);
	head = insertNodeAtHead(head, 4);
	head = insertNodeAtHead(head, 5);
	
	cout<<"Original Linked List: "<<"\n";
	printLinkedList(head);
}