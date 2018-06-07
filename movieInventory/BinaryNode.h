#pragma once

#include "Movie.h"
class BinaryNode {
public:
	/** defalt constructor   **/
	BinaryNode();
	/** constructor which take movie, node pointer left and right as parametr   **/
	BinaryNode(Movie *m, BinaryNode *left, BinaryNode *right);
	 /** destructor   **/
	virtual ~BinaryNode();
         /** cheek if its leaf or not   **/
	bool isLeaf();

	Movie* data;
	BinaryNode* left;
	BinaryNode* right;

private:

};

