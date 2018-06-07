#pragma once

#include "TransactionNode.h"

class TransactionList {
public:
	/** defalt constructor   **/
	TransactionList();
	 /**  destructor to clean up un nesserey tranasaction list   **/
	virtual ~TransactionList();
        /**  print history     **/ 
	void printHistory();
	 /**  add method which take actionType and movie type to to the transactionNode list**/
	bool add(char actionType, string movieTitle);

private:
	TransactionNode * front;

	TransactionNode* clear(TransactionNode *curr);
};

