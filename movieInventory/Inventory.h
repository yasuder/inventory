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
#include "RentalTable.h"
#include "TransactionList.h"

using namespace std;

#ifndef CSS343ASS_4_INVENTORY_H
#define CSS343ASS_4_INVENTORY_H


class Inventory {
public:
	Inventory();
	virtual ~Inventory();

	//bool addMovie(char type, int stock, string director, string title, string extra);
	bool addCustomer(string id, string lastName, string firstName);

	//bool borrowMovie(string title, int customerID);
	//bool returnMovie(string title, int customerID);

	//void printInventory();
	void printHistory(string customerID);
	TransactionList getHistory(string customerID);

	void readCustomerFile(string filename);
	void readMovieFile(string filename);
	void readCommandFile(string filename);


private:
	Customer* getCustomerAtIndex(int customerIndex); // from the 2D array
	//Movie* getMovieAtIndex(int movieIndex); // from the 2D array

	//HashTable<string, Movie*> movieList;
	//BinarySearchTree movieTree;
	RentalTable rentals; // 2D vector of bool where true = renting
	HashTable<string, Customer*> customerList;
	vector<string> movieIndex; // index = movieIndex (in 2D array), value = movie title
	vector<int> customerIndex; // index = customerIndex (in 2D array), value = customerID
};


#endif //CSS343ASS_4_INVENTORY_H
