//
// Created by Goitom Hadishe on 5/15/18.
//
#include "Movie.h"
using namespace std;
#ifndef CSS343ASS_4_COMEDY_H
#define CSS343ASS_4_COMEDY_H

class Comedy :public Movie {
	friend ostream & operator<<(ostream& out, const Comedy& r);
public:
	Comedy(int stock, string title, string director, int year, int mtn);
	~Comedy();

	void print();
	virtual bool operator>(const Movie &m) const;
	virtual bool operator>=(const Movie &m) const;
	virtual bool operator==(const Movie &m) const;
	virtual bool operator!=(const Movie& m)const;
};

#endif //CSS343ASS_4_COMEDY_H