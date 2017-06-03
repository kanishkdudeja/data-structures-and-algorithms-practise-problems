#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* getNewNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

Node* push(Node* head, int data) {
	if(head == NULL) {
		head = getNewNode(data);
		return head;
	}

	Node* newNode = getNewNode(data);

	newNode->next = head;
	head = newNode;
	return head;
}

Node* pop(Node* head) {
	if(head == NULL) {
		return NULL;
	}
	else {
		Node* tmp;
		tmp = head;
		head = head->next;

		free(tmp);
		return head;
	}
}

bool isEmpty(Node* head) {
	if(head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int getElementAtTop(Node* head) {
	if(head == NULL) {
		return -1;
	}
	else {
		return head->data;
	}
}

int main() {
	Node* head;
	head = NULL;

	head = push(head, 1);
	head = push(head, 2);
	head = push(head, 3);
	head = push(head, 4);

	cout<<getElementAtTop(head)<<"\n";

	head = pop(head);
	head = pop(head);

	cout<<getElementAtTop(head)<<"\n";
}