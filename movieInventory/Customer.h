#pragma once
#include <string>
#include "linkedlist.h"
#include "TransactionList.h"
#include "TransactionNode.h"

using namespace std;

class Customer
{
public:
	//Default constructor
	Customer();

	//Constructor
	Customer(string id, string fn, string ln, int ctn);

	//Destructor
	~Customer();

	//Accessors
	string getCustomerID()const;
	string getFirstName()const;
	string getLastName()const;
	int getCustomerTableNum()const;

	TransactionList getTransactions()const;

	bool addTransaction(char actionType, string movieTitle);

private:
	string customerID;
	string lastName;
	string firstName;
	int customerTableNum; //index for 2D vector
	TransactionList transactions;
};