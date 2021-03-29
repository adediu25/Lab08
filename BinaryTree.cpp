#include "BinaryTree.h"
#include <queue>
#include <iostream>

MorseBinaryTree::Node::Node() {
	this->data = '\0';
	this->left = this->right = nullptr;
}

MorseBinaryTree::Node::Node(char ch) {
	this->data = ch;
	this->left = this->right = nullptr;
}

MorseBinaryTree::MorseBinaryTree() {
	this->root = new Node();
}

MorseBinaryTree::~MorseBinaryTree() {
	deleteNode(this->root);
}

// Inserts node based on morse representation

void MorseBinaryTree::insertItem(char ch, const char* repr) {
	Node* newNode = new Node(ch);

	insert(this->root, newNode, repr);
}

// Performs insertion

void MorseBinaryTree::insert(Node*& root, Node*& newNode, const char* repr) {
	if (root == nullptr) {
		root = newNode;
	}
	else if (*repr == '*') {
		insert(root->left, newNode, ++repr);
	}
	else {
		insert(root->right, newNode, ++repr);
	}
}

// Returns a pointer to desired node or nullptr if not found

MorseBinaryTree::Node* MorseBinaryTree::findNode(Node*& root, char ch) {
	Node* foundNode = nullptr;
	
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* currentNode = q.front();
		if (currentNode->data == ch) {
			foundNode = currentNode;
			return foundNode;
		}
		q.pop();

		if (currentNode->left != nullptr)
			q.push(currentNode->left);

		if (currentNode->right != nullptr)
			q.push(currentNode->right);
	}
	return foundNode;
}

// Returns true if item is found in the tree, false otherwise

bool MorseBinaryTree::findItem(char ch) {
	Node* node = findNode(this->root, ch);

	if (node == nullptr)
		return false;
	else
		return true;
}

// Deletes specified node/subtree

void MorseBinaryTree::removeItem(char ch) {
	queue<Node*> q;
	q.push(this->root);

	while (!q.empty()) {
		Node* currentNode = q.front();
		if (currentNode->left == nullptr && currentNode->right == nullptr)
			continue;
		if (currentNode->left->data == ch) {
			currentNode->left = nullptr;
			deleteNode(currentNode->left);
			return;
		}
		if (currentNode->right->data == ch) {
			currentNode->right = nullptr;
			deleteNode(currentNode->right);
			return;
		}
		q.pop();

		if (currentNode->left != nullptr)
			q.push(currentNode->left);

		if (currentNode->right != nullptr)
			q.push(currentNode->right);
	}
}

// Performs deletion

void MorseBinaryTree::deleteNode(Node* nodePtr) {
	if (nodePtr == nullptr)
		return;
	// Delete all children before root
	deleteNode(nodePtr->left);
	deleteNode(nodePtr->right);
	delete nodePtr;
}

// Level order traversal print

void MorseBinaryTree::printLevelOrder() const {
	queue<Node*> q;
	q.push(this->root);

	std::cout << "Level Order Traveral:";
	while (!q.empty()) {
		Node* coutNode = q.front();
		std::cout << coutNode->data << " ";
		q.pop();

		if (coutNode->left != nullptr)
			q.push(coutNode->left);

		if (coutNode->right != nullptr)
			q.push(coutNode->right);
	}
	std::cout << std::endl;
}

char MorseBinaryTree::morseToAlpha(const char* repr) {
	if (*repr == ' ') {
		repr++;
		return '\0';
	}
	else if (*repr == '/') {
		repr++;
		return ' ';
	}
	else
		return morseSearch(this->root, repr);
}

char MorseBinaryTree::morseSearch(Node*& root, const char* repr) {
	if (*repr == '\0' || repr[1] == '/' || repr[1] == ' ') {
		return root->data;
	}
	else if (*repr == '*') {
		return morseSearch(root->left, ++repr);
	}
	else {
		return morseSearch(root->right, ++repr);
	}
}