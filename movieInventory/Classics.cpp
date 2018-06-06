//
// Created by Goitom Hadishe on 5/15/18.
//

#include "Classics.h"
Classic::Classic(int stock, string title, string director, string extra, int mtn) {
	this->stock = stock;
	this->title = title;
	this->director = director;
	this->type = 'C';
	this->movieTableNum = mtn;

	string smonth, syear;
	stringstream ss(extra);
	getline(ss, this->majorFirsNa, ' ');
	getline(ss, this->majorLastNa, ' ');
	getline(ss, smonth, ' ');
	getline(ss, syear, ' ');

	this->releaseMonth = stoi(smonth);
	this->year = stoi(syear);
}

//destructor
Classic::~Classic() {
	this->majorFirsNa = "";
	this->majorLastNa = "";
	delete  this;
}

int Classic::getReleaseMonth() {
	return releaseMonth;
}

string Classic::getmajorFirstName() {
	return majorFirsNa;
}

string Classic::getmajorLastName() {
	return majorLastNa;
}

//returns information about the classic as formatted output.
// this includes stock counts
//void Classic::print() {
//	cout << "C" << ", " << stock << ", " << director << ", " << title << " " <<
//		majorFirsNa << " " << majorLastNa << " " << releaseMonth << " " << year << endl;
//}
//
bool Classic::operator<(Classic &m) {
	if (year != m.year) {
		return year < m.year;
	}
	else if (releaseMonth != m.releaseMonth) {
		return getReleaseMonth() < m.getReleaseMonth();
	}
	else if (majorLastNa != m.majorLastNa) {
		return majorLastNa < m.majorLastNa;
	}
	else {
		return majorFirsNa < m.majorFirsNa;
	}
}

bool Classic::operator>(Classic &m) {
	return !(this->operator<(m));
}

bool Classic::operator==(Classic &m) {
	return(year == m.year && releaseMonth == m.releaseMonth &&
		majorFirsNa == m.majorFirsNa && majorLastNa == m.majorLastNa  && director == m.director && title == m.title);
}

bool Classic::operator!=(Classic &m) {
	return !(this->operator==(m));
}
