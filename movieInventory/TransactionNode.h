//
// Created by Goitom Hadishe on 5/16/18.
//

#include <string>
using namespace std;

#ifndef CSS343ASS_4_TRANSACTION_H
#define CSS343ASS_4_TRANSACTION_H


class TransactionNode {
public:
	TransactionNode(char actionType, string movieTitle);
	virtual ~TransactionNode();

	void printTransaction();

private:
	char actionType;
	string movieTitle;
	TransactionNode* prev; // technically points to the NEXT node, but we want to insert newest nodes at the front so it's called prev
};


#endif //CSS343ASS_4_TRANSACTION_H
