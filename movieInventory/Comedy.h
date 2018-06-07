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
	/** constructor which take stock, itle, director, year, and mtn as parameter **/
	Comedy(int stock, string title, string director, int year, int mtn);
	 /**distructor to clear up the new drama **/
	~Comedy();
        /**print all the dComedy movies **/
	void print();
	 /** oerator to compare if one Comedy movie is greater than the other dram movie
        *  **/
	virtual bool operator>(Comedy &m);
	 /** oerator to compare if one Comedy movie is less than the other dram movie
          *  **/
	virtual bool operator<(Comedy &m);
	/**oerator to compare if two different Comedy movies are equal  **/
	virtual bool operator==(Comedy &m);
	/**boolean oerator to compare if two different Comedy movies are not equal **/
	virtual bool operator!=(Comedy &m);
};

#endif //CSS343ASS_4_COMEDY_H
