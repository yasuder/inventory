//
// Created by Goitom Hadishe on 5/15/18.
//
#include "Movie.h"
#ifndef CSS343ASS_4_COMEDY_H
#define CSS343ASS_4_COMEDY_H


class Comedy: public Movie {
public:
	Comedy(int stock, char movieType, string title, string director, int releaseYear);
	virtual ~Comedy();

private:

};


#endif //CSS343ASS_4_COMEDY_H
