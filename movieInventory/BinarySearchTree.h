//
// Created by Goitom Hadishe on 5/16/18.
//

#ifndef CSS343ASS_4_BINARYSEARCHTREE_H
#define CSS343ASS_4_BINARYSEARCHTREE_H

#include "BinaryNode.h"

class BinarySearchTree {
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

	bool add(Movie *m);
	bool contains(Movie *m);

	BinaryNode *root;

private:
	int size;

	BinaryNode* clear(BinaryNode *curr);
	bool addHelper(Movie *m, BinaryNode *curr);
	bool containsHelper(Movie *m, BinaryNode *curr);
};


#endif //CSS343ASS_4_BINARYSEARCHTREE_H
