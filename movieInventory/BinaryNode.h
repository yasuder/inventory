#pragma once

#include "Movie.h"
class BinaryNode {
public:
	BinaryNode();
	BinaryNode(Movie *m, BinaryNode *left, BinaryNode *right);
	virtual ~BinaryNode();

	Movie data;
	BinaryNode* left;
	BinaryNode* right;

private:

};

