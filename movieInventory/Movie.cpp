//
// Created by Goitom Hadishe on 5/15/18.
//

#include "Movie.h"
Movie::Movie() {}

Movie::~Movie() {
	this->stock = 0;
	this->director = "";
	this->year = 0;
	this->customerList.clear();
}

bool Movie::borrowBy(string customerID) {
	if (!customerList.getValue(customerID) && this->stock > 0) {
		customerList.add(customerID, true);
		this->stock--;
		return true;
	}
	return false;
}

bool Movie::returnBy(string customerID) {
	if (!customerList.getValue(customerID)) {
		customerList.remove(customerID);
		this->stock++;
		return true;
	}
	return false;
}

vector<string> Movie::getRenters() {
	return customerList.getKeys();
}

void Movie::addStock(int n) {
	stock += n;
}


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
