#pragma once

#include "TransactionNode.h"

class TransactionList {
public:
	TransactionList();
	virtual ~TransactionList();

	void printHistory();
	bool add(char actionType, string movieTitle);

private:
	TransactionNode * front;

	TransactionNode* clear(TransactionNode *curr);
};

