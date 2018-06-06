#pragma once

#include "Movie.h"
class BinaryNode {
public:
	BinaryNode();
	BinaryNode(Movie *m, BinaryNode *left, BinaryNode *right);
	virtual ~BinaryNode();

	bool isLeaf();

	Movie* data;
	BinaryNode* left;
	BinaryNode* right;

private:

};

