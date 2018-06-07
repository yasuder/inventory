#include "BinaryNode.h"



BinaryNode::BinaryNode() {
	left = nullptr;
	right = nullptr;
}

BinaryNode::BinaryNode(Movie *m, BinaryNode *left, BinaryNode *right) {
	data = m;
	this->left = left;
	this->right = right;
}

BinaryNode::~BinaryNode() {
	delete data;
	delete left;
	delete right;
}

bool BinaryNode::isLeaf() {
	return left == nullptr && right == nullptr;
}
