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

	/*morseTree.printLevelOrder();

	bool containsY = morseTree.findItem('Y');
	bool contains9 = morseTree.findItem('9');

	cout << "Finding Y: ";
	if (containsY)
		cout << "found\n";
	else
		cout << "not found\n";

	cout << "Finding 9: ";
	if (contains9)
		cout << "found\n";
	else
		cout << "not found\n";

	morseTree.removeItem('T');
	morseTree.printLevelOrder();*/
	cout << "Decoding *- *--* *--* *-** */- *-* * *: ";
	morseTree.morseToAlpha("*- *--* *--* *-** */- *-* * *");
	cout << "Encoding C PLUS PLUS: ";
	morseTree.alphaToMorse("C PLUS PLUS");

	return 0;
}
