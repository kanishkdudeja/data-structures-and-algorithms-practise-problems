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

bool findIntersection(Node* firstListHead, Node* secondListHead, Node** intersection) {
	int firstListLength = 0;
	int secondListLength = 0;

	bool doIntersect = false;
	Node* lastOfFirstList;
	Node* lastOfSecondList;

	Node* tmp = firstListHead;
	while(tmp->next) {
		firstListLength++;
		tmp=tmp->next;
		if(tmp->next == NULL) {
			lastOfFirstList = tmp;
		}
	}

	tmp = secondListHead;
	while(tmp->next) {
		secondListLength++;
		tmp=tmp->next;
		if(tmp->next == NULL) {
			lastOfSecondList = tmp;
		}
	}

	if(lastOfFirstList == lastOfSecondList) {
		doIntersect = true;
	}

	if(doIntersect == true) {
		int differenceInLength = 0;

		Node* firstPtr = firstListHead;
		Node* secondPtr = secondListHead;

		if(firstListLength != secondListLength) {
			if(firstListLength > secondListLength) {
				differenceInLength = firstListLength - secondListLength;

				for(int j = 0; j < differenceInLength; j++) {
					firstPtr = firstPtr->next;
				}
			}
			else if(secondListLength > firstListLength) {
				differenceInLength = secondListLength - firstListLength;

				for(int j = 0; j < differenceInLength; j++) {
					secondPtr = secondPtr->next;
				}
			}	
		}

		while(firstPtr != secondPtr) {
			firstPtr = firstPtr->next;
			secondPtr = secondPtr->next;
		}

		*intersection = firstPtr;		

		return true;
	}
	else {
		return false;;
	}
}

int main ()
{
	Node* firstListHead = NULL;

	firstListHead = insertNodeAtHead(firstListHead, 0);
	firstListHead = insertNodeAtHead(firstListHead, 1);
	firstListHead = insertNodeAtHead(firstListHead, 2);
	firstListHead = insertNodeAtHead(firstListHead, 3);
	firstListHead = insertNodeAtHead(firstListHead, 4);
	firstListHead = insertNodeAtHead(firstListHead, 2);
	firstListHead = insertNodeAtHead(firstListHead, 3);
	firstListHead = insertNodeAtHead(firstListHead, 4);
	firstListHead = insertNodeAtHead(firstListHead, 5);

	Node* secondListHead = NULL;

	secondListHead = insertNodeAtHead(secondListHead, 0);
	secondListHead = insertNodeAtHead(secondListHead, 1);
	secondListHead = insertNodeAtHead(secondListHead, 2);
	secondListHead = insertNodeAtHead(secondListHead, 3);
	secondListHead = insertNodeAtHead(secondListHead, 4);
	secondListHead = insertNodeAtHead(secondListHead, 2);
	secondListHead = insertNodeAtHead(secondListHead, 3);
	secondListHead = insertNodeAtHead(secondListHead, 4);
	secondListHead = insertNodeAtHead(secondListHead, 5);

	firstListHead->next = secondListHead;

	Node* intersection;

	if(findIntersection(firstListHead, secondListHead, &intersection)) {
		cout<<"Found intersection: "<<"\n";
		cout<<intersection<<"\n";
	}
	else {
		cout<<"No intersection found."<<"\n";
	}
}