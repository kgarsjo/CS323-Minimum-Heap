#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

using namespace std;

/* ------------------------------------------------ //
	Node Struct - Internal Huffmann-Tree Node
// ------------------------------------------------ */
struct Node {
	int value;		// The Huffmann-value of the tree
	char key;		// The Huffman-char key
	Node* left;		// Left child
	Node* right;	// Right child
	
	Node();			// Default Constructor
	Node(char key, int value);			// Key constructor
	bool operator< (Node& operand);		// Comparison overload, <
	bool operator> (Node& operand);		// Comparison overload, >
	bool operator<= (Node& operand);	// Comparison overload, <=
	bool operator>= (Node& operand);	// Comparison overload, >=
	friend ostream &operator<< (ostream& out, Node& oper);
};

#endif