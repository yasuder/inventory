//
// Created by Goitom Hadishe on 5/15/18.
//

#include "Movie.h"
Movie::Movie() {}

Movie::~Movie() {
	this->stock = 0;
	this->director = "";
	this->year = 0;
	delete this;
}

//bool Movie::borrowBy(string customerID) { //if possible, borrow this Movie to the customer with given customerID
//}
//
//bool Movie::returnBy(string customerID) { // if possible, return this Movie to the inventory from customer with given customerID
//}
//
//vector<Customer*> Movie::getRenters() {
//}

int Movie::compareMovie(const Movie& m)const {
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

int Movie::getReleaseYear() {
	return this->year;
}

char Movie::getType() {
	return this->type;
}
