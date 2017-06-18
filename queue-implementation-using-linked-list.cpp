#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Queue {
	Node* front;
	Node* back;

	Node* getNewNode(int data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}

	public:

	Queue() {
		front = NULL;
		back = NULL;
	}

	void enqueue(int data) {
		if(front == NULL) {
			Node* newNode = getNewNode(data);

			front = newNode;
			back = newNode;
		}
		else {
			Node* newNode = getNewNode(data);

			back->next = newNode;
			back = newNode;
		}
	}

	int dequeue() {
		if(front == NULL) {
			return -1;
		}
		else if(front == back) {
			int data = front->data;
			
			Node* tmp = front;

			front = NULL;
			back = NULL;

			free(tmp);

			return data;
		}
		else {
			Node* tmp = front;

			int data = front->data;

			front = front->next;

			free(tmp);

			return data;
		}
	}

	void printQueue() {
		if(front == NULL) {
			cout<<"empty"<<"\n";
		}
		else {
			Node* tmp = front;

			while(tmp != NULL) {
				cout<<tmp->data<<"\n";
				tmp = tmp->next;
			}
		}
	}
};

int main() {
	Queue q = Queue();

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	q.printQueue();

	q.dequeue();
	q.dequeue();

	q.printQueue();
}