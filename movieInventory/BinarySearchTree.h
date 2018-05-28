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

private:
	BinaryNode root;
};


#endif //CSS343ASS_4_BINARYSEARCHTREE_H
