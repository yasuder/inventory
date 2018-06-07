//
// Created by Goitom Hadishe on 5/16/18.
//

#ifndef CSS343ASS_4_BINARYSEARCHTREE_H
#define CSS343ASS_4_BINARYSEARCHTREE_H

#include "BinaryNode.h"

class BinarySearchTree {
public:
	 /** default constructor **/
	BinarySearchTree();
	/** destructor to free up un nessary node  **/
	virtual ~BinarySearchTree();
	/** add the movie to the binnary serach tree  **/
	bool add(Movie *m);
	   /** this will check if the the movie is in the tree,
        * if so then it will return true, if its not then it will return false**/
	bool contains(Movie *m);
	Movie* search(string key);
	/** print all the node tp the output  **/
	void clear();
	/** clear all the node from the tree **/
	void print();
        /** root pointer **/
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
