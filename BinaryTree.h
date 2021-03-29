#pragma once
#include <iostream>

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
	bool search(Node*, char);
	void deleteNode(Node*);
	char morseSearch(Node*&, const char*);
	Node* findNode(Node*&, char);
public:
	MorseBinaryTree();
	~MorseBinaryTree();
	void insertItem(char, const char*);
	void removeItem(char);
	bool findItem(char);
	void printLevelOrder() const;
	char morseToAlpha(const char*);
};

//class BstNode {
//private:
//	int data;
//	BstNode* right;
//	BstNode* left;
//public:
//	BstNode* CreateNode(int data) {
//		BstNode* newNode = new BstNode();
//		newNode->data = data;
//		newNode->left = newNode->right = NULL;
//		return newNode;
//	}
//
//	BstNode* Insert(BstNode* root, int data) {
//		if (root == NULL) {
//			root = CreateNode(data);
//		}
//		else if (data <= root->data) {
//			root->left = Insert(root->left, data);
//		}
//		else {
//			root->right = Insert(root->right, data);
//		}
//		return root;
//	}
//
//	bool Search(BstNode* root, int data) {							//this might have to be changed to out a value but for right now it works with a if statement in main
//		if (root == NULL) { return false; }
//		else if (root->data == data) { return true; }
//		else if (data <= root->data) { return Search(root->left, data); }
//		else { return Search(root->right, data); }
//	}
//
//	BstNode* Delete(BstNode* root, int data) {
//		if (root == NULL) {
//			return root;
//		}
//		else if (data < root->data) {
//			root->left = Delete(root->left, data);
//		}
//		else if (data > root->data) {
//			root->right = Delete(root->right, data);
//		}
//		else {
//			if (root->left == NULL && root->right == NULL) {
//				delete root;
//				root = NULL;
//			}
//			else if (root->left == NULL) {
//				BstNode* temp = root;
//				root = root->right;
//				delete temp;
//			}
//			else if (root->right == NULL) {
//				BstNode* temp = root;
//				root = root->left;
//				delete temp;
//			}
//			else {
//				BstNode* temp = (root->right);   //need to find min value in right tree, so this needs to be changed
//				root->data = temp->data;
//				root->right = Delete(root->right, temp->data);
//			}
//		}
//		return root;
//	}
//};