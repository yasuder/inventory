//
// Created by Goitom Hadishe on 5/15/18.
//
#include<string>
#include <sstream>
#include "Movie.h"
#include "BinarySearchTree.h"

using namespace std;

#ifndef CSS343ASS_4_CLASSICS_H
#define CSS343ASS_4_CLASSICS_H

class Classic: public Movie {
private:
	int releaseMonth;
	string majorFirsNa;
	string majorLastNa;

public:
	/** constructor which take stock, title, director, extra, and mtn as parameter **/
	Classic(int stock, string title, string director, string extra, int mtn); //default constructor
	/**distructor to clear up the new Classic **/
	~Classic();	//destructor
         /** get the relese month  **/
	int getReleaseMonth();
	 /**get the first major actor name  **/
	string getmajorFirstName();
	/** get the major last name **/
	string getmajorLastName();
         /**print all the Classic movies **/
	void print();
	 /** oerator to compare if one Classic movie is less than the other dram movie
         *  **/
	bool operator<(Classic & m);
	  /** oerator to compare if one Classic movie is greater than the other dram movie
          *  **/
	bool operator>(Classic & m);
	 /**oerator to compare if two different Classic movies are equal  **/
	bool operator==(Classic & m);
	 /**boolean oerator to compare if two different Classic movies are not equal **/
	bool operator!=(Classic & m);

};

#endif //CSS343ASS_4_CLASSICS_H
