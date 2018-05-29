#pragma once
#include <string>
#include "linkedList.h"

using namespace std;

class Customer
{
public:
	//Default constructor
	Customer();

	//Constructor
	Customer(int id, string fn, string ln, int ctn);

	//Destructor
	~Customer();

	//Accessors
	int getCustomerId()const;
	string getFirstName()const;
	string getLastName()const;
	int getCustomerTableNum()const;

	//getTransactions()const;

private:
	int customerId;
	string lastName;
	string firstName;
	int customerTableNum; //index for 2D vector
	//LinkedList<>

};




//#include<string>
//#include "TransactionList.h";
//
//using namespace std;
//
//#ifndef CSS343ASS_4_CUSTOMER_H
//#define CSS343ASS_4_CUSTOMER_H
//
//
//class Customer {
//public:
//	Customer(string lastName, string firstName);
//	virtual ~Customer();
//
//	int getCustomerID();
//	string getLastName();
//	string getFirstName();
//	TransactionList getTransactions();
//
//private:
//	int customerID;
//	string lastName;
//	string firstName;
//	TransactionList history;
//	int customerTableNum;	// index for 2D vector
//};
//#endif //CSS343ASS_4_CUSTOMER_H
