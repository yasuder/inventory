//
// Created by Goitom Hadishe on 5/15/18.
//
#include "Comedy.h"
Comedy::Comedy(int stock, string title, string director, int year, int mtn) {
	this->type = 'F';
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->year = year;
	this->movieTableNum = mtn;
}

Comedy::~Comedy() {
	delete this;
}

void Comedy::print() {
	cout << "F" << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}

bool Comedy::operator>(Comedy &m) {
	if (title != m.title) {
		return title > m.title;
	}
	else {
		return year > m.year;
	}
}

bool Comedy::operator<(Comedy &m) {
	return !(this->operator>(m));
}

bool Comedy::operator==(Comedy &m) {
	return (title == m.title && director == m.director && year == m.year);
}

bool Comedy::operator!=(Comedy &m) {
	return !(this->operator==(m));
}
