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
		root = addHelper(m, root);
		return true;
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

Movie* BinarySearchTree::search(string key) {
	return searchHelper(root, key)->data;
}
BinaryNode* BinarySearchTree::searchHelper(BinaryNode* root, string key) {
	if (root == NULL || root->data->getTitle() == key) {
		return root;
	}

	if (root->data->getTitle() < key) {
		return searchHelper(root->right, key);
	}

	return searchHelper(root->left, key);
}

BinaryNode* BinarySearchTree::addHelper(Movie *m, BinaryNode* node) {
	if (node == NULL) {
		return new BinaryNode(m, nullptr, nullptr);
	}

	if (m < node->data) {
		node->left = addHelper(m, node->left);
	}
	else if (m > node->data) {
		node->right = addHelper(m, node->right);
	}
	return node;
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

void BinarySearchTree::printHelper(BinaryNode *node) {
	if (node == NULL) {
		return;
	}

	printHelper(node->left);

	cout << node->data->getTitle() << endl;

	printHelper(node->right);
}