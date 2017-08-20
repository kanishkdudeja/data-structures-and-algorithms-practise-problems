/* Check if Two stacks are equal using a Queue

We pop all elements from Stack1 and push it into the Queue.
Now we pop each element from Stack2 and Queue, if they are same, then stacks are same.

Otherwise not.

This solution uses the fact that elements in stack will be popped in LIFO order and will be inserted
in queue at FIFO order.

*/

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Stack {
	
	Node* head;

	public:
	
	Stack() {
		head = NULL;
	}

	Node* getNewNode(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = NULL;

		return newNode;
	}

	void push(int data) {
		if(head == NULL) {
			head = getNewNode(data);
		}
		else {
			Node* newNode = getNewNode(data);

			newNode->next = head;
			head = newNode;	
		}
	}

	int pop() {
		if(head == NULL) {
			return -1;
		}
		else {
			int data = head->data;

			if(head->next == NULL) {
				free(head);

				head = NULL;
			}
			else {
				Node* tmp;
				tmp = head;
				head = head->next;

				free(tmp);
			}
			
			return data;
		}
	}

	bool isEmpty() {
		if(head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	int getElementAtTop() {
		if(head == NULL) {
			return -1;
		}
		else {
			return head->data;
		}
	}
};

class Queue {
	Node* front;
	Node* back;
	Stack s1;
	Stack s2;

	Node* getNewNode(int data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}

	public:

	Queue(Stack stack1, Stack stack2) {
		front = NULL;
		back = NULL;

		s1 = stack1;
		s2 = stack2;
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
		else {
			int data = front->data;
			
			Node* tmp = front;

			if(front == back) {
				front = NULL;
				back = NULL;

			}
			else {
				front = front->next;
			}

			free(tmp);

			return data;
		}
	}

	bool checkIfStacksEqual() {
		while(!(s1.isEmpty())) {
			enqueue(s1.pop());
		}

		while(!(s2.isEmpty())) {
			if(s2.pop() != dequeue()) {
				return false;
			}
		}

		return true;
	}
};

int main() {
	Stack s1 = Stack();
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);

	Stack s2 = Stack();
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);

	Queue q = Queue(s1, s2);

	cout<<q.checkIfStacksEqual();
}