//
// Created by Goitom Hadishe on 5/16/18.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
	size = 0;
}

BinarySearchTree::~BinarySearchTree() {
	root = clear(root);
}

bool BinarySearchTree::add(Movie *m) {
	return addHelper(m, root);
}

bool BinarySearchTree::contains(Movie *m) {
	return containsHelper(m, root);
}

bool BinarySearchTree::addHelper(Movie *m, BinaryNode *curr) {
	if (curr != nullptr) {
		if (m < curr->data) {
			return addHelper(m, curr->left);
		}
		else if (m > curr->data) {
			return addHelper(m, curr->right);
		}
		else {
			return false;
		}
	}
	curr = new BinaryNode(m, nullptr, nullptr);
	return true;
}

bool BinarySearchTree::containsHelper(Movie *m, BinaryNode *curr) {
	if (curr != nullptr) {
		if (m < curr->data) {
			return containsHelper(m, curr->left);
		}
		else if (m > curr->data) {
			return containsHelper(m, curr->right);
		}
		else {
			return true;
		}
	}
	return false;
}

BinaryNode* BinarySearchTree::clear(BinaryNode *curr) {
	if (curr != nullptr) {
		curr->left = clear(curr->left);
		curr->right = clear(curr->right);
	}
	delete curr;
	return nullptr;
}