//
// Created by Goitom Hadishe on 5/15/18.
//
#include<string>
using namespace std;
#ifndef CSS343ASS_4_MOVIE_H
#define CSS343ASS_4_MOVIE_H


class Movie {
private:
    string title;
    char type;
    string director;
    int releseYear;
    int stock;
public:
    Movie();
    Movie(int stock, char movieType, string title, string director, int releaseYear);
    virtual  ~Movie();
    int getStock();
    string getTitle();
    string getDirector();
    int getRealseYear();
    char getType();
    virtual bool operator >(Movie& m)const;
    virtual bool operator >=(Movie& m)const;
    virtual bool operator ==(Movie& m)const;

};


#endif //CSS343ASS_4_MOVIE_H
