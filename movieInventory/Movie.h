//
// Created by Goitom Hadishe on 5/15/18.
//
#include <string>
#include <vector>
#include <iostream>
#include "Customer.h"
#include "HashTable.h"

using namespace std;

#ifndef CSS343ASS_4_MOVIE_H
#define CSS343ASS_4_MOVIE_H

class Movie {
protected:
	string title;
	string director;
	int year;
	int stock;
	char type;
	int movieTableNum;
	HashTable<string, bool> customerList;

	enum MovieTypes { F, D, C };

public:
	Movie();
	virtual ~Movie();

	bool borrowBy(string customerID);// if possible, borrow this Movie to the customer with given customerID
	bool returnBy(string customerID); // if possible, return this Movie to the inventory from customer with given customerID

	char getType();
	int getStock();
	string getTitle();
	string getDirector();
	int getReleaseYear();

	void addStock(int n);
	int compareMovie(const Movie& m)const;
	vector<string> getRenters();

	virtual void printRental() {};
};

#endif //CSS343ASS_4_MOVIE_H
