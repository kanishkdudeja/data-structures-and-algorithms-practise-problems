/* Write a program to detect a loop in the linked list 

Solution: Start traversing each node. Put address of each node into an unordered map (hash table)
As soon as the same address is found, it means there is a loop in the linked list

Time Complexity = O(n)
Space Complexity = O(n) since n elements at max will be stored in the hash table

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
	unordered_map<Node*, bool> umap;

	Node* temp = head;

	if(temp == NULL) {
		return NULL;
	}

	while(temp->next) {
		if(umap.find(temp) != umap.end()) {
			return temp;
		}
		else {
			umap.insert(make_pair(temp, true))	;
		}
		temp = temp->next;
	}

	return NULL;
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