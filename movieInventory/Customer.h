#pragma once
#include <string>
#include <vector>
#include "linkedlist.h"
#include "TransactionList.h"
#include "TransactionNode.h"
#include "HashTable.h"

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
	vector<string> getBorrowedMovies() const;

	TransactionList getTransactions()const;

	bool addTransaction(char actionType, string movieTitle);
	bool borrowMovie(string movieID);
	bool returnMovie(string movieID);

private:
	string customerID;
	string lastName;
	string firstName;
	int customerTableNum; //index for 2D vector
	TransactionList transactions;
	HashTable<string, bool> movieList;
};