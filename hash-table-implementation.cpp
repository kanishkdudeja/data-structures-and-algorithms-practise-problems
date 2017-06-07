#include <iostream>
using namespace std;

struct Node {
	int key;
	int value;
	Node* next = NULL;
};

class HashTable {
	Node* bucketList[10];

	int hash(int key) {
		return (key % 10);
	}

	Node* getNewNode(int key, int value) {
		Node* newNode = new Node();
		newNode->key = key;
		newNode->value = value;
		newNode->next = NULL;

		return newNode;
	}

	public:

	HashTable() {
		for(int i = 0; i < 10; i++) {
			bucketList[i] = NULL;	
		}
	}

	int get(int key) {
		int bucketIndex = hash(key);

		if(bucketList[bucketIndex] == NULL) {
			return 0;
		} else {
			Node* tmp = bucketList[bucketIndex];

			while(true) {
				if(tmp->key == key) {
					return tmp->value;
				}
				else {
					if(tmp->next != NULL) {
						tmp = tmp->next;	
					}
					else {
						break;
					}
				}
			}

			return 0;
		}
	}

	bool set(int key, int value) {
		int bucketIndex = hash(key);

		if(bucketList[bucketIndex] == NULL) {
			bucketList[bucketIndex] = getNewNode(key, value);

			return true;
		} else {
			Node* tmp = bucketList[bucketIndex];

			while(true) {
				if(tmp->key == key) {
					//Key is already set
					return false;
				}
				else {
					if(tmp->next != NULL) {
						tmp = tmp->next;	
					}
					else {
						break;
					}
				}
			}

			tmp->next = getNewNode(key, value);
			return true;
		}
	}
};

int main() {
	HashTable ht = HashTable();
	
	cout<<ht.set(1, 1);
	cout<<ht.set(11, 10);
	cout<<ht.set(23, 2);
	cout<<ht.set(39, 1);

	cout<<ht.get(1);
	cout<<ht.get(11);
	cout<<ht.get(23);
	cout<<ht.get(39);
}