#include "Node.h"

/* ------------------------------------------------ //
Node() - Default Constructor
Time Comp: theta(1)
// ------------------------------------------------ */
Node::Node() {
	value = 0;
	key = 0;
	left = NULL;
	right = NULL;
}


/* ------------------------------------------------ //
Node(...) - Key Constructor, instantiates w/ values

Inputs:	int value - The Huffmann value to copy
		char key - The Huffman key to copy

Time Comp: theta(1)
// ------------------------------------------------ */
Node::Node(char key, int value) {
	this->value = value;
	this->key = key;
	left = NULL;
	right = NULL;
}


/* ------------------------------------------------ //
public bool operator< (...) - Overloads the < op

Inputs:	Node& operand - The obj to compare

Time Comp: theta(1)
// ------------------------------------------------ */
bool Node::operator< (Node& operand) {
	if (value< operand.value) {
		return true;
	}

	if (value == operand.value) {
		if ((int)key < (int)operand.key) {
			return true;
		}
	}
}


/* ------------------------------------------------ //
public bool operator> (...) - Overloads the > op

Inputs:	Node& operand - The obj to compare

Time Comp: theta(1)
// ------------------------------------------------ */
bool Node::operator> (Node& operand) {
	if (value > operand.value) {
		return true;
	}

	if (value == operand.value) {
		if ((int)key > (int)operand.key) {
			return true;
		}
	}
}


/* ------------------------------------------------ //
public bool operator<= (...) - Overloads the <= op

Inputs:	Node& operand - The obj to compare

Time Comp: theta(1)
// ------------------------------------------------ */
bool Node::operator<= (Node& operand) {
	if (value <= operand.value) {
		return true;
	}
}


/* ------------------------------------------------ //
public bool operator>= (...) - Overloads the >= op

Inputs:	Node& operand - The obj to compare

Time Comp: theta(1)
// ------------------------------------------------ */
bool Node::operator>= (Node& operand) {
	if (value >= operand.value) {
		return true;
	}
}


ostream& operator<< (ostream& out, Node& oper) {
	out << '[' << oper.key << '|' << oper.value << ']';
	return out;
}