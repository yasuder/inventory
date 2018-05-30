//#pragma once
//#include <string>
//#include "linkedList.h"
//#include "TransactionList.h"
//#include "TransactionNode.h"
//
//using namespace std;
//
//class Customer
//{
//public:
//	//Default constructor
//	Customer();
//
//	//Constructor
//	Customer(int id, string fn, string ln, int ctn);
//
//	//Destructor
//	~Customer();
//
//	//Accessors
//	int getCustomerId()const;
//	string getFirstName()const;
//	string getLastName()const;
//	int getCustomerTableNum()const;
//
//	TransactionList getTransactions()const;
//
//	bool addTransaction(char actionType, string movieTitle);
//
//private:
//	int customerId;
//	string lastName;
//	string firstName;
//	int customerTableNum; //index for 2D vector
//	TransactionList transactions;
//};