//
// Created by Goitom Hadishe on 5/15/18.
//
#include "Comedy.h"
Comedy::Comedy(int stock, string title, string director, int year) {
	this->type = 'F';
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->year = year;
}

Comedy::~Comedy() {
	delete this;
}

void Comedy::print() {
	cout << "F" << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}

bool Comedy::operator>(const Movie &m) const {
	const Comedy& d = static_cast<const Comedy&>(m);
	return (this->type > d.type && this->title > d.title && this->director > d.director && this->year > d.year);
}

bool Comedy::operator>=(const Movie &m) const {
	const Comedy& d = static_cast<const Comedy&>(m);
	return (this->type >= d.type && this->title >= d.title && this->director >= d.director && this->year >= d.year);
}

bool Comedy::operator==(const Movie &m) const {
	const Comedy& d = static_cast<const Comedy&>(m);
	return (this->type == d.type && this->title == d.title && this->director == d.director && this->year == d.year);
}

bool Comedy::operator!=(const Movie& m)const {
	const Comedy& d = static_cast<const Comedy&>(m);
	return (this->type != d.type || this->title != d.title || this->director != d.director || this->year != d.year);
}
