#include <iostream>
#include "BinaryTree.h"

using namespace::std;

int main() {
	//********Task 1 test start********

	/*BstNode* root = NULL;
	root = root->Insert(root, 10);
	root = root->Insert(root, 20);
	root = root->Insert(root, 30);
	root = root->Insert(root, 40);
	root = root->Insert(root, 50);

	root = root->Delete(root, 50);

	int number;
	cout << "Insert a number: ";
	cin >> number;
	if (root->Search(root, number) == true) {
		cout << "Number found \n";
	}
	else {
		cout << "Number not found \n";
	}*/

	//********Task 1 test end********

	MorseBinaryTree morseTree = MorseBinaryTree();

	morseTree.insertItem('E', "*");
	morseTree.insertItem('T', "-");
	morseTree.insertItem('I', "**");
	morseTree.insertItem('A', "*-");
	morseTree.insertItem('N', "-*");
	morseTree.insertItem('M', "--");
	morseTree.insertItem('S', "***");
	morseTree.insertItem('U', "**-");
	morseTree.insertItem('R', "*-*");
	morseTree.insertItem('W', "*--");
	morseTree.insertItem('D', "-**");
	morseTree.insertItem('K', "-*-");
	morseTree.insertItem('G', "--*");
	morseTree.insertItem('O', "---");
	morseTree.insertItem('H', "****");
	morseTree.insertItem('V', "***-");
	morseTree.insertItem('F', "**-*");
	morseTree.insertItem('L', "*-**");
	morseTree.insertItem('P', "*--*");
	morseTree.insertItem('J', "*---");
	morseTree.insertItem('B', "-***");
	morseTree.insertItem('X', "-**-");
	morseTree.insertItem('C', "-*-*");
	morseTree.insertItem('Y', "-*--");
	morseTree.insertItem('Z', "--**");
	morseTree.insertItem('Q', "--*-");

	morseTree.printLevelOrder();

	cout << morseTree.morseToAlpha("-*-*") << endl;

	const char* morse = "*- *--* *--* *-** *";

	while (*morse != '\0')
		cout << morseTree.morseToAlpha(morse);

	return 0;
}
