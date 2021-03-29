#include "BinaryTree.h"
#include <queue>
#include <iostream>
#include <stack>
#include <vector>

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

// Performs insertion recursively

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

// Calls deletion of specified node and sets corresponding pointer to null

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

// Performs deletion, recursively deleting all children first

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

// Prints decoded morse string

void MorseBinaryTree::morseToAlpha(const char* repr) {
	queue<char> translation; // queue for printing final string

	// Iterate through morse sting
	while (*repr != '\0') {
		// Print nothing if space
		if (*repr == ' ') {
			repr++;
		}
		// Print space if slash appears
		else if (*repr == '/') {
			repr++;
			translation.push(' ');
		}
		// Print character after search using morse representation
		else
			translation.push(morseSearch(this->root, repr));
	}

	// Print string
	while (!translation.empty()) {
		char c = translation.front();
		std::cout << c;
		translation.pop();
	}
	std::cout << endl;
}

// returns true if ch is in given tree and recursively adds path to the stack path
// performs path search using inorder traversal

bool MorseBinaryTree::pathHelper(Node*& root, stack<char>& path, char ch, char dir) {
	if (root == nullptr)
		return false;

	path.push(dir);

	if (root->data == ch)
		return true;

	if (pathHelper(root->left, path, ch, '*') || pathHelper(root->right, path, ch, '-'))
		return true;
	
	path.pop();
	return false;
}

// Prints encoded version of str in morse,

void MorseBinaryTree::alphaToMorse(const char* str) {
	stack<char> path;  // Stack for path to each char
	queue<char> printQueue;  // Queue to print all chars at the end

	// Loop through string
	while (*str != '\0') {
		// Print a slash in morse for spaces
		if (*str == ' ') {
			printQueue.push('/');
			str++;
		}
		else {
			stack<char> throwAway;
			stack<char> temp;
			if (pathHelper(this->root->left, throwAway, *str, '*')) {
				// Path to character is in the path stack
				pathHelper(this->root->left, path, *str, '*');
				
				// Push morse characters to printQueue in the correct order
				while (!path.empty()) {
					temp.push(path.top());
					path.pop();
				}
				while (!temp.empty()) {
					printQueue.push(temp.top());
					temp.pop();
				}
			}
			else {
				// Path to character is in the path stack
				pathHelper(this->root->right, path, *str, '-');
				
				// Push morse characters to printQueue in the correct order
				while (!path.empty()) {
					temp.push(path.top());
					path.pop();
				}
				while (!temp.empty()) {
					printQueue.push(temp.top());
					temp.pop();
				}
			}
			// Print a space in the morse string between each alpha character
			if (str[1] != ' ')
				printQueue.push(' ');
			str++; 
		}
	}

	// Print morse string
	while (!printQueue.empty()) {
		std::cout << printQueue.front();
		printQueue.pop();
	}

	std::cout << std::endl;
}

// Traverses tree based on morse string then returns the character

char MorseBinaryTree::morseSearch(Node*& root, const char*& repr) {
	// End search if morse sequence is ending
	if (repr[1] == ' ' || repr[1] == '/' || repr[1] == '\0') {
		if (*repr == '*') {
			repr++;
			return root->left->data;
		}
		else {
			repr++;
			return root->right->data;
		}
	}
	// Continue search left or right depending on * or -
	else if (*repr == '*') {
		return morseSearch(root->left, ++repr);
	}
	else {
		return morseSearch(root->right, ++repr);
	}
}