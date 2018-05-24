//
// Created by Goitom Hadishe on 5/15/18.
//
#include <string>
#include <vector>

#include "Customer.h"
using namespace std;
#ifndef CSS343ASS_4_MOVIE_H
#define CSS343ASS_4_MOVIE_H


class Movie {
public:
    Movie();
    Movie(int stock, char movieType, string title, string director, int releaseYear);
    virtual  ~Movie();

    int getStock();
    string getTitle();
    string getDirector();
    int getReleaseYear();
    char getType();
	void print();

	bool borrowBy(int customerID); // if possible, borrow this Movie to the customer with given customerID
	bool returnBy(int customerID); // if possible, return this Movie to the inventory from customer with given customerID

	vector<Customer*> getRenters();

    virtual bool operator>(Movie& m)const;
    virtual bool operator>=(Movie& m)const;
    virtual bool operator==(Movie& m)const;
	virtual bool operator!=(Movie& m)const;

private:
	string title;
	char type;
	string director;
	int releseYear;
	int stock;
};


#endif //CSS343ASS_4_MOVIE_H
