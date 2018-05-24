#pragma once

#include "Movie.h"
class BinaryNode {
public:
	BinaryNode();
	virtual ~BinaryNode();

	Movie data;
	BinaryNode* left;
	BinaryNode* right;

private:

};

