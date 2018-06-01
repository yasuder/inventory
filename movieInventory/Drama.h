//
// Created by Goitom Hadishe on 5/15/18.
//
#include<string>
#include "Movie.h"
using namespace std;
#ifndef CSS343ASS_4_DRAMA_H
#define CSS343ASS_4_DRAMA_H


class Drama :public Movie {
public:
	Drama(int stock, string title, string director, char type, int releaseYear);

	~Drama();

	virtual void print();
	virtual bool operator>(const Movie &m) const;
	virtual bool operator>=(const Movie &m) const;
	virtual bool operator==(const Movie &m) const;
	virtual bool operator!=(const Movie& m)const;
};


#endif //CSS343ASS_4_DRAMA_H
