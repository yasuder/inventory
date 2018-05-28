#include<string>
#include "TransactionList.h";

using namespace std;

#ifndef CSS343ASS_4_CUSTOMER_H
#define CSS343ASS_4_CUSTOMER_H


class Customer {
public:
	Customer(string lastName, string firstName);
	virtual ~Customer();

	int getCustomerID();
	string getLastName();
	string getFirstName();
	TransactionList getTransactions();

private:
	int customerID;
	string lastName;
	string firstName;
	TransactionList history;
	int customerTableNum;	// index for 2D vector
};


#endif //CSS343ASS_4_CUSTOMER_H
