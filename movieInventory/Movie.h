//
// Created by Goitom Hadishe on 5/15/18.
//
#include<string>
#include <vector>
#include "Customer.h"
#include <iostream>
using namespace std;
#define COMMA_SPACE ",   "
#define WHITE_SPACE "  "
#define CURRENT_NUM_TYPES 3
#ifndef CSS343ASS_4_MOVIE_H
#define CSS343ASS_4_MOVIE_H


class Movie {
protected:
	string title;
	string director;
	int year;
	int stock;
	char type;
	enum MovieTypes { F, D, C };

public:
	Movie();
	Movie(char type, int stock, string director, string title, int year);
	~Movie();
	bool borrowBy(string customerID);// if possible, borrow this Movie to the customer with given customerID
	bool returnBy(string customerID); // if possible, return this Movie to the inventory from customer with given customerID


	int getStock();
	string getTitle();
	string getDirector();
	int getRealseYear();
	char getType();
	int compairMove(const Movie& m)const;
	virtual void printRental() {};
	vector<Customer*> getRenters();
	virtual bool operator >(const Movie& m)const { return false; }
	virtual bool operator >=(const Movie& m)const { return false; }
	virtual bool operator ==(const Movie& m)const { return false; }
	virtual bool operator!=(const Movie& m)const { return false; }

};

#endif //CSS343ASS_4_MOVIE_H
