//
// Created by Goitom Hadishe on 5/15/18.
//

#include "Drama.h"
Drama::Drama(int stock, string title, string director, int year) {
	this->stock = stock;
	this->title = title;
	this->director = director;
	this->type = 'D';
	this->year = year;
}

Drama::~Drama() {
	delete this;
}

void Drama::print() {
	cout << "D" << stock << ", " << director << ", " << title << ", " << year << endl;
}

bool Drama::operator>(const Movie &m) const {
	const  Drama& d = static_cast<const Drama&>(m);
	return (this->type > d.type && this->title > d.title && this->director > d.director && this->year > d.year);
}

bool Drama::operator>=(const Movie &m) const {
	const  Drama& d = static_cast<const Drama&>(m);
	return (this->type >= d.type && this->title >= d.title && this->director >= d.director && this->year >= d.year);
}

bool Drama::operator==(const Movie &m) const {
	const  Drama& d = static_cast<const Drama&>(m);
	return (this->type == d.type && this->title == d.title && this->director == d.director && this->year == d.year);
}

bool Drama::operator!=(const Movie& m)const {
	const  Drama& d = static_cast<const Drama&>(m);
	return (this->type != d.type || this->title != d.title || this->director != d.director || this->year != d.year);
}

