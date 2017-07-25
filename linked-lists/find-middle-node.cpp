/* Find the middle element in a linked list */

/* Time complexity = O(n) */

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next = nullptr;
};

Node* getNewNode(int data) {
	Node* newNode = new Node();
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

int findMiddleNode(Node* head) {
	if(head == NULL) {
		return -1;
	}

	Node* p1 = head;
	Node* p2 = head;

	while(p2->next != NULL) {
		p1 = p1->next;

		p2 = p2->next;

		if(p2->next != NULL) {
			p2 = p2->next;
		}
	}

	return p1->data;
}

void printLinkedList(Node* head) {
	Node* tmpNode = head;
	while(tmpNode->next) {
		cout<<tmpNode->data<<"\n";
		tmpNode = tmpNode->next;
	}
	cout<<tmpNode->data<<"\n";
}

int main() {
	Node* head = NULL;

	head = insertNodeAtHead(head, 1);
	head = insertNodeAtHead(head, 2);
	head = insertNodeAtHead(head, 3);
	head = insertNodeAtHead(head, 4);

	cout<<findMiddleNode(head);
}