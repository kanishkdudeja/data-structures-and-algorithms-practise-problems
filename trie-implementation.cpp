#include <iostream>
#include <cstring>
using namespace std;

#define ALPHABETSIZE 26;

struct TrieNode {
	TrieNode* children[26];
	bool isCompleteWord;
};

int getCharCode(char c) {
	return (int)c - (int)('a');
}

TrieNode* getNewNode() {
	TrieNode* newNode = new TrieNode();

	for(int i = 0; i < 26; i++) {
		newNode->children[i] = NULL;
	}

	newNode->isCompleteWord = false;

	return newNode;
}

class Trie {

	TrieNode* root = NULL;

	public:

	void insertWord(const char* word) {
		TrieNode* temp = root;
		int currentCharOffset = 0;
		int length = std::strlen(word);

		if(root == NULL) {
			root = getNewNode();

			int firstCharCode = getCharCode(word[0]);

			root->children[firstCharCode] = getNewNode();
			
			currentCharOffset = 1;

			temp = root->children[firstCharCode];
		}
		else {
			int i = 0;

			for(i = 0; i < length; i++) {
				int currentCharCode = getCharCode(word[i]);

				if(temp->children[currentCharCode] != NULL) {
					temp = temp->children[currentCharCode];
				}
				else {
					break;
				}
			}

			if(i == (length)) {
				return;
			}
			else {
				currentCharOffset = i;
			}
		}

		for(int j = currentCharOffset; j < length; j++) {
			int currentCode = getCharCode(word[j]);

			temp->children[currentCode] = getNewNode();
			temp = temp->children[currentCode];
		}
	}

	bool searchWord(const char* word) {

		TrieNode* temp = root;
		int length = std::strlen(word);

		if(root == NULL) {
			return false;
		}
		else {
			int i = 0;

			for(i = 0; i < length; i++) {
				int currentCharCode = getCharCode(word[i]);

				if(temp->children[currentCharCode] != NULL) {
					temp = temp->children[currentCharCode];
				}
				else {
					break;
				}
			}

			if(i == (length)) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};

int main() {
	Trie trie = Trie();
	trie.insertWord("hello");
	trie.insertWord("hi");

	cout<<trie.searchWord("hello")<<"\n";
	cout<<trie.searchWord("helli")<<"\n";
	cout<<trie.searchWord("hi")<<"\n";
	cout<<trie.searchWord("hill")<<"\n";
}