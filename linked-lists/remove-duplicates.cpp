//Complexity = O(n) or 0(1) if we assume that the function can only iterate
//255 times at maximum to find out an answer

#include <iostream>
using namespace std;

struct Node {
	int data = 0;
	Node* next = nullptr;
};

void insertNodeAtHead(Node** head, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = *head;

	*head = newNode;
}

void printLinkedList(Node* head) {
	Node* tmpNode = head;
	while(tmpNode->next) {
		cout<<tmpNode->data<<"\n";
		tmpNode = tmpNode->next;
	}
	cout<<tmpNode->data<<"\n";
}

void removeDuplicates(Node** head) {
	static int arr[100];

	Node* tmpNode = *head;
	Node* previousNode = NULL;

	while(tmpNode) {
		int dataOnNode = tmpNode->data;

		if(arr[dataOnNode] == 0) {
			arr[dataOnNode] = 1;

			previousNode = tmpNode;
		}
		else if(arr[dataOnNode] == 1) {
			previousNode->next = tmpNode->next;
		}
		
		tmpNode = tmpNode->next;
	}
}

int main ()
{
	Node* head = new Node;
	head->data = 0;
	head->next = NULL;

	insertNodeAtHead(&head, 0);
	insertNodeAtHead(&head, 1);
	insertNodeAtHead(&head, 2);
	insertNodeAtHead(&head, 3);
	insertNodeAtHead(&head, 4);
	insertNodeAtHead(&head, 2);
	insertNodeAtHead(&head, 3);
	insertNodeAtHead(&head, 4);
	insertNodeAtHead(&head, 5);
	
	cout<<"Original Linked List: "<<"\n";
	printLinkedList(head);

	removeDuplicates(&head);

	cout<<"Linked list after removing duplicates: "<<"\n";
	printLinkedList(head);
}