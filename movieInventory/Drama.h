//
// Created by Goitom Hadishe on 5/15/18.
//
#include "Movie.h"
#ifndef CSS343ASS_4_DRAMA_H
#define CSS343ASS_4_DRAMA_H


class Drama: public Movie {
public:
    Drama(int stock, string title, string director, int releaseYear);
    virtual ~Drama();

private:

};


#endif //CSS343ASS_4_DRAMA_H
