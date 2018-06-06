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
//bool Classic::operator<(Movie &m) const {
//	//const Classic& C = static_cast<const Classic&>(m);
//	return(this->type > m.getType() && this->year > C.year && this->releaseMonth > C.releaseMonth &&
//		this->majorFirsNa > C.majorFirsNa && this->majorLastNa > C.majorLastNa && this->director > C.director && this->title > C.title);
//}
//
//bool Classic::operator>(const Movie &m) const {
//	const Classic& C = static_cast<const Classic&>(m);
//	return(this->type >= C.type && this->year >= C.year && this->releaseMonth >= C.releaseMonth &&
//		this->majorFirsNa >= C.majorFirsNa && this->majorLastNa >= C.majorLastNa  && this->director >= C.director && this->title >= C.title);
//}
//
//bool Classic::operator==(const Movie &m) const {
//	const Classic& C = static_cast<const Classic&>(m);
//	return(this->type == C.type && this->year == C.year && this->releaseMonth == C.releaseMonth &&
//		this->majorFirsNa == C.majorFirsNa && this->majorLastNa == C.majorLastNa  && this->director == C.director && this->title == C.title);
//}
//
//bool Classic::operator!=(const Movie& m)const {
//	const Classic& C = static_cast<const Classic&>(m);
//	return (this->type != C.type || this->year != C.year || this->releaseMonth != C.releaseMonth ||
//		this->majorFirsNa != C.majorFirsNa || this->majorLastNa != C.majorLastNa || this->director != C.director || this->title != C.title);
//}
