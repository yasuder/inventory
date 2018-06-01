//
// Created by Goitom Hadishe on 5/15/18.
//
#include<string>
#include "Movie.h"
using namespace std;
#ifndef CSS343ASS_4_CLASSICS_H
#define CSS343ASS_4_CLASSICS_H


class Classic :public Movie {
private:
	int realseMonth;
	string majorFirsNa;
	string majorLastNa;
public:
	Classic(int stock, string title, string Director,
		string majorFirsNa, string majorLastNa, int releaseMonth, int year);		//default constructor
	~Classic();	//destructor
				//returns information about the classic as formatted output.
				// this includes stock counts
	int getReleaseMonth();
	string getgmajorFirsNa();
	string getmajorLastNa();
	virtual void print();
	virtual bool operator>(const Movie &m) const;
	virtual bool operator>=(const Movie &m) const;
	virtual bool operator==(const Movie &m) const;
	virtual bool operator!=(const Movie& m)const;
};


#endif //CSS343ASS_4_CLASSICS_H
