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
	/** movie default constructor **/
	Movie();
	/** movie  ditsructor **/
	virtual ~Movie();
/** boolean method which take customer id as parameter  and borrow the movie
     * to a specfic cutsomer assocated with that id number
     * **/
	bool borrowBy(string customerID);// if possible, borrow this Movie to the customer with given customerID
	 /** a boolean method which take customer id as parameter  and return the movie
     * from the customer  to the inventory
     * **/
	bool returnBy(string customerID); // if possible, return this Movie to the inventory from customer with given customerID
        /** this will return a character for the movie type**/
	char getType();
	/** this will return an integer value of stock **/
	int getStock();
	/** get the movie title **/
	string getTitle();
	/** get the director of the movie **/
	string getDirector();
	/** get the year the movie relesed  **/
	int getReleaseYear();

	void addStock(int n);
	 /** get the movie title **/
	int compareMovie(const Movie& m)const;
	/** this will get the list of renters  **/
	vector<string> getRenters();
      /** display te rental information  **/
	virtual void printRental() {};
};

#endif //CSS343ASS_4_MOVIE_H
