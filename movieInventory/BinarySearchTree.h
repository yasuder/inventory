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
	Movie* search(string key);
	void clear();
	void print();

	BinaryNode *root;

private:
	int size;

	BinaryNode* clear(BinaryNode *curr);
	BinaryNode* addHelper(Movie *m, BinaryNode* node);
	BinaryNode* searchHelper(BinaryNode* root, string key);
	bool containsHelper(Movie *m, BinaryNode *curr);
	void clearHelper(BinaryNode *curr);
	void printHelper(BinaryNode *curr);

};


#endif //CSS343ASS_4_BINARYSEARCHTREE_H
