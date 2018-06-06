//
// Created by Goitom Hadishe on 5/16/18.
//
#include <string>
#include <vector>

#include "BinarySearchTree.h"
#include "Customer.h"
#include "HashTable.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classics.h"
#include "TransactionList.h"

using namespace std;

#ifndef CSS343ASS_4_INVENTORY_H
#define CSS343ASS_4_INVENTORY_H


class Inventory {
public:
	Inventory();
	virtual ~Inventory();

	bool addMovie(string str);

	bool addCustomer(string id, string lastName, string firstName);

	bool borrowMovie(string title, string customerID);
	bool returnMovie(string title, string customerID);

	void printInventory();
	void printHistory(string customerID);
	TransactionList getHistory(string customerID);

	void readCustomerFile(string filename);
	void readMovieFile(string filename);
	void readCommandFile(string filename);
	void executeCommand(string str);

private:
	HashTable<string, Movie*> movieList;
	BinarySearchTree movieTree;
	HashTable<string, Customer*> customerList;
};


#endif //CSS343ASS_4_INVENTORY_H
