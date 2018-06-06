//
// Created by Goitom Hadishe on 5/15/18.
//

#include "Drama.h"
Drama::Drama(int stock, string title, string director, int year, int mtn) {
	this->stock = stock;
	this->title = title;
	this->director = director;
	this->type = 'D';
	this->year = year;
	this->movieTableNum = mtn;
}

Drama::~Drama() {
	delete this;
}

void Drama::print() {
	cout << "D" << stock << ", " << director << ", " << title << ", " << year << endl;
}

bool Drama::operator>(Drama &m) {
	if (director != m.director) {
		return director > m.director;
	}
	else {
		return title > m.title;
	}
}

bool Drama::operator<(Drama &m) {
	return !(this->operator>(m));
}

bool Drama::operator==(Drama &m) {
	return (title == m.title && director == m.director && year == m.year);
}

bool Drama::operator!=(Drama &m) {
	return !(this->operator==(m));
}

