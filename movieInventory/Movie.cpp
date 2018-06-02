//
// Created by Goitom Hadishe on 5/15/18.
//

#include "Movie.h"
Movie::Movie() {
	title = "";
	director = "";
	year = 0;
	stock = 0;
}

Movie::Movie(char type, int stock, string director, string title, int year) {
	this->stock = stock;
	this->type = type;
	this->title = title;
	this->director = director;
	this->year = year;

}
Movie::~Movie() {
	this->stock = 0;
	this->director = "";
	this->year = 0;
	delete this;

}
bool Movie::borrowBy(string customerID) {//if possible, borrow this Movie to the customer with given customerID




}
bool Movie::returnBy(string customerID) { // if possible, return this Movie to the inventory from customer with given customerID


}
vector<Customer*> Movie::getRenters() {




}

int  Movie::compairMove(const Movie& m)const {
	if ((int)MovieTypes(this->type) > (int)MovieTypes(m.type)) {
		return 1;
	}
	else if ((int)MovieTypes(this->type) < (int)MovieTypes(m.type)) {
		return -1;
	}
	else {
		return 0;
	}

}

int Movie::getStock() {
	return this->stock;

}
string Movie::getTitle() {
	return this->title;

}
string Movie::getDirector() {
	return this->director;


}
int Movie::getRealseYear() {
	return  year;


}

char Movie::getType() {

	return this->type;

}


