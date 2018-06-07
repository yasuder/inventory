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
	/** constructor which take stock, itle, irector, year, and mtn as parameter **/
	Drama(int stock, string title, string director, int year, int mtn);
	 /**distructor to clear up the new drama **/
	~Drama();
        /**print all the drama movies **/
	virtual void print();
	 /** oerator to compare if one drama movie is greater than the other dram movie
          *  **/
	virtual bool operator>(Drama &m);
	/** oerator to compare if one drama movie is less than the other dram movie
         *  **/
	virtual bool operator<(Drama &m);
	/**oerator to compare if two different Drama movies are equal  **/
	virtual bool operator==(Drama &m);
	/**boolean oerator to compare if two different Drama movies are not equal **/
	virtual bool operator!=(Drama &m);
};

#endif //CSS343ASS_4_DRAMA_H
