#pragma once

#include "TransactionNode.h"

class TransactionList {
public:
	TransactionList();
	virtual ~TransactionList();

	void printHistory();

private:
	TransactionNode * front;
};

