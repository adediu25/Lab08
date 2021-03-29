#pragma once
#include <iostream>
#include <stack>

using namespace::std;

class MorseBinaryTree {
private:
	struct Node {
		char data;
		Node *left, *right;
		Node();
		Node(char ch);
	};
	Node* root;
	void insert(Node*&, Node*&, const char*);
	void deleteNode(Node*);
	char morseSearch(Node*&, const char*&);
	Node* findNode(Node*&, char);
	bool pathHelper(Node*&, stack<char>&, char, char);
public:
	MorseBinaryTree();
	~MorseBinaryTree();
	void insertItem(char, const char*);
	void removeItem(char);
	bool findItem(char);
	void printLevelOrder() const;
	void morseToAlpha(const char*);
	void alphaToMorse(const char*);
};