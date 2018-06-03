//
// Created by Goitom Hadishe on 5/15/18.
//
#include<string>
#include <sstream>
#include "Movie.h"

using namespace std;

#ifndef CSS343ASS_4_CLASSICS_H
#define CSS343ASS_4_CLASSICS_H

class Classic: public Movie {
private:
	int releaseMonth;
	string majorFirsNa;
	string majorLastNa;

public:
	Classic(int stock, string title, string director, string extra, int mtn); //default constructor
	~Classic();	//destructor

	int getReleaseMonth();
	string getmajorFirstName();
	string getmajorLastName();

	virtual void print();
	virtual bool operator>(const Movie &m) const;
	virtual bool operator>=(const Movie &m) const;
	virtual bool operator==(const Movie &m) const;
	virtual bool operator!=(const Movie& m)const;
};

#endif //CSS343ASS_4_CLASSICS_H