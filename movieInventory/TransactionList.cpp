#include "TransactionList.h"



TransactionList::TransactionList() {
	front = nullptr;
}


TransactionList::~TransactionList() {
	front = clear(front);
}

void TransactionList::printHistory() {
	TransactionNode *curr = front;
	while (curr != nullptr) {
		curr->printTransaction();
		curr = curr->prev;
	}
}

TransactionNode* TransactionList::clear(TransactionNode *curr) {
	if (curr != nullptr) {
		curr->prev = clear(curr->prev);
	}
	delete curr;
	return nullptr;
}

bool TransactionList::add(char actionType, string movieTitle) {
	TransactionNode *curr = new TransactionNode(actionType, movieTitle);
	curr->prev = front;
	front = curr;
	return true;
}