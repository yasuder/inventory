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
	 /**Default constructor **/
	Customer();

	/**Constructor**/
	Customer(string id, string fn, string ln, int ctn);

	/**Destructor**/
	~Customer();

	//Accessors
	/** get the customer id  **/
	string getCustomerID()const;
	/** get the first name  **/
	string getFirstName()const;
	/** get the last  name  **/
	string getLastName()const;
	/** get the customer table   **/
	int getCustomerTableNum()const;
	/** this will get the list of borrowed movie   **/
	vector<string> getBorrowedMovies() const;
        /** get transaction  **/
	TransactionList getTransactions()const;
        /** this will return true if the movie title is added to the ransaction, and will return false    **/
	bool addTransaction(char actionType, string movieTitle);
	/** this will return true if the movie title is added to the ransaction   **/
	bool borrowMovie(string movieID);
	 /** this will return movie    **/
	bool returnMovie(string movieID);

private:
	string customerID;
	string lastName;
	string firstName;
	int customerTableNum; //index for 2D vector
	TransactionList transactions;
	HashTable<string, bool> movieList;
};
