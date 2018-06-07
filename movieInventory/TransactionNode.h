//
// Created by Goitom Hadishe on 5/16/18.
//

#include <string>
#include <iostream>
using namespace std;

#ifndef CSS343ASS_4_TRANSACTION_H
#define CSS343ASS_4_TRANSACTION_H


class TransactionNode {
public:
	/** a constructor which take action type and move title as parameter **/
	TransactionNode(char actionType, string movieTitle);
	 /** destructor to clean up un nessary transaction  */v
	virtual ~TransactionNode();
        /**print all the transaction  **/
	void printTransaction();
	/**this will get the action type   **/
	char getActionType();
	 /** this will get the moveie title   **/
	string getMovieTitle();
/**  this is a pointer to the privious node  **/
	TransactionNode* prev; // technically points to the NEXT node, but we want to insert newest nodes at the front so it's called prev


private:
	char actionType;
	string movieTitle;
};


#endif //CSS343ASS_4_TRANSACTION_H
