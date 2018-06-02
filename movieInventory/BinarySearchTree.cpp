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

void BinarySearchTree::clear() {
	clearHelper(root);
}

void BinarySearchTree::print() {
	printHelper(root);
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

void BinarySearchTree::clearHelper(BinaryNode *curr) {
	if (curr != nullptr) {
		if (curr->isLeaf()) {
			delete curr;
		}
		else {
			clearHelper(curr->left);
			clearHelper(curr->right);
			delete curr;
		}
	}
}

BinaryNode* BinarySearchTree::clear(BinaryNode *curr) {
	if (curr != nullptr) {
		curr->left = clear(curr->left);
		curr->right = clear(curr->right);
	}
	delete curr;
	return nullptr;
}

void BinarySearchTree::printHelper(BinaryNode *curr) {
	if (curr != nullptr) {
		if (curr->left != nullptr) {
			printHelper(curr->left);
			cout << curr->data->getTitle() << endl;
		}
		cout << curr->data->getTitle() << endl;
		if (curr->right != nullptr) {
			printHelper(curr->right);
			cout << curr->data->getTitle() << endl;
		}

	}
}