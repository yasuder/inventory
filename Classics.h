//
// Created by Goitom Hadishe on 5/15/18.
//
#include<string>
#include "Movie.h"
using namespace std;
#ifndef CSS343ASS_4_CLASSICS_H
#define CSS343ASS_4_CLASSICS_H


class Classic:public Movie {
private:
    int realseMonth;
    string majorChar;
public:
    Classic(int stock, string title, string Director,
                 string majorFirst, string majorLast, int releaseMonth, int releaseYear);		//default constructor
    ~Classic();	//destructor
    //returns information about the classic as formatted output.
    // this includes stock counts
    int getReleaseMonth();
    string getMajorChar();
    virtual void print();
    virtual bool operator>(const Movie &m) const;
    virtual bool operator>=(const Movie &m) const;
    virtual bool operator==(const Movie &m) const;


};


#endif //CSS343ASS_4_CLASSICS_H
