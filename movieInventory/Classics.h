//
// Created by Goitom Hadishe on 5/15/18.
//
#include "Movie.h"
#ifndef CSS343ASS_4_CLASSICS_H
#define CSS343ASS_4_CLASSICS_H


class Classic: public Movie {
public:
    Classic(int stock, string title, string Director, string extra);		//default constructor
    ~Classic();	//destructor
    //returns information about the classic as formatted output.
    // this includes stock counts
    int getReleaseMonth();
    string getMajorChar();

private:
	int realseMonth;
	string majorChar;
};


#endif //CSS343ASS_4_CLASSICS_H
