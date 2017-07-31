/* Implement a Queue (FIFO) using 2 Stacks (LIFO)

Method 1 (By making enQueue operation costly): This method makes sure that oldest entered element is 
always at the top of stack 1, so that deQueue operation just pops from stack1. 
To put the element at top of stack1, stack2 is used.

enQueue(q, x)
  1) While stack1 is not empty, push everything from satck1 to stack2.
  2) Push x to stack1 (assuming size of stacks is unlimited).
  3) Push everything back to stack1.

dnQueue(q)
  1) If stack1 is empty then error
  2) Pop an item from stack1 and return it

Method 2 (By making deQueue operation costly): In this method, in en-queue operation, 
the new element is entered at the top of stack1. In de-queue operation, if stack2 is empty 
then all the elements are moved to stack2 and finally top of stack2 is returned.

enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.

Method 2 is definitely better than method 1.

Method 1 moves all the elements twice in enQueue operation, while method 2 (in deQueue operation)
moves the elements once and moves elements only if stack2 empty.

Space Complexity = O(n) where n is the number of elements in the stack
Time Complexuity = O(n) where n is the number of elements in the stack

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
	Stack s1;
	Stack s2;

	public:

	Queue() {
		s1 = Stack();
		s2 = Stack();
	}

	void enqueue(int data) {
		s1.push(data);
	}

	int dequeue() {
		if(s2.isEmpty()) {
			while(!(s1.isEmpty())) {
				s2.push(s1.pop());
			}
		}

		return s2.pop();
	}

	bool isEmpty() {
		return s1.isEmpty() && s2.isEmpty();
	}
};

int main() {
	Queue q = Queue();

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	cout<<q.dequeue();
	cout<<q.dequeue();
	cout<<q.dequeue();
	cout<<q.dequeue();
}