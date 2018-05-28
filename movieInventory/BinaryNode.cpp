#include "BinaryNode.h"



BinaryNode::BinaryNode() {
	left = nullptr;
	right = nullptr;
}

BinaryNode::BinaryNode(Movie m, BinaryNode *left, BinaryNode *right) {
	data = m;
	left = nullptr;
	right = nullptr;
}



BinaryNode::~BinaryNode() {
	delete left;
	delete right;
}
