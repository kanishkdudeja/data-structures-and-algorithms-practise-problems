/* Given two sorted linked lists, write a function to return
a merged sorted list */

/* Time complexity = O(a+b) where a and b are sizes of the two
lists respectively */

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next = nullptr;
};

Node* getNewNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

Node* insertNodeAtHead(Node* head, int data) {
	Node* newNode = getNewNode(data);
	newNode->next = head;

	return newNode;
}

Node* insertNodeAtRear(Node* head, int data) {
	Node* newNode = getNewNode(data);

	if(head == NULL) {
		head = newNode;
	}
	else {
		Node* temp = head;

		while(temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newNode;
	}

	return head;
}

Node* mergeSortedLinkedLists(Node* list1, Node* list2) {
	Node* p1 = list1;
	Node* p2 = list2;

	if(p1 == NULL && p2 == NULL) {
		return p1;
	}

	if(p1 == NULL) {
		return p2;
	}

	if(p2 == NULL) {
		return p1;
	}

	Node* mergedList = NULL;

	while(p1 != NULL && p2 != NULL) {
		if(p1->data <= p2->data) {
			mergedList = insertNodeAtRear(mergedList, p1->data);
			p1 = p1->next;
		}
		else if(p2->data < p1->data) {
			mergedList = insertNodeAtRear(mergedList, p2->data);
			p2 = p2->next;
		}
	}

	if(p1 != NULL) {
		while(p1 != NULL) {
			mergedList = insertNodeAtRear(mergedList, p1->data);
			p1 = p1->next;
		}
	}

	if(p2 != NULL) {
		while(p2 != NULL) {
			mergedList = insertNodeAtRear(mergedList, p2->data);
			p2 = p2->next;
		}
	}

	return mergedList;
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
	Node* list1 = NULL;

	list1 = insertNodeAtRear(list1, 1);
	list1 = insertNodeAtRear(list1, 3);
	list1 = insertNodeAtRear(list1, 5);

	Node* list2 = NULL;

	list2 = insertNodeAtRear(list2, 2);
	list2 = insertNodeAtRear(list2, 4);
	list2 = insertNodeAtRear(list2, 6);
	list2 = insertNodeAtRear(list2, 8);
	list2 = insertNodeAtRear(list2, 9);
	list2 = insertNodeAtRear(list2, 10);

	Node* mergedList = mergeSortedLinkedLists(list1, list2);

	printLinkedList(mergedList);
}