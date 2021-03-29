#include <iostream>
#include "BinaryTree.h"

using namespace::std;

int main() {
	MorseBinaryTree morseTree = MorseBinaryTree();

	// Add all characters to morse tree
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

	cout << morseTree.findItem('9') << endl;

	morseTree.removeItem('T');
	morseTree.printLevelOrder();



	/*cout << morseTree.morseToAlpha("-*-*") << endl;

	const char* morse = "*- *--* *--* *-** *";

	while (*morse != '\0')
		cout << morseTree.morseToAlpha(morse);*/

	return 0;
}
