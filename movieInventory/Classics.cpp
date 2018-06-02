//
// Created by Goitom Hadishe on 5/15/18.
//

#include "Classics.h"
Classic::Classic(int stock, string title, string Director,
	string majorFirsNa, string majorLastNa, int releaseMonth, int year) {
	this->stock = stock;
	this->title = title;
	this->director = director;
	this->majorFirsNa = majorFirsNa;
	this->majorLastNa = majorLastNa;
	this->realseMonth = releaseMonth;
	this->year = year;
	this->type = 'C';

}
//destructor
Classic::~Classic() {
	this->majorFirsNa = "";
	this->majorLastNa = "";
	delete  this;

}
int Classic::getReleaseMonth() {
	return  realseMonth;

}
string Classic::getgmajorFirsNa() {
	return majorFirsNa;

}
string Classic::getmajorLastNa() {
	return majorLastNa;

}
//returns information about the classic as formatted output.
// this includes stock counts
virtual void Classic::print() {
	cout << "C" << ", " << stock << ", " << director << ", " << title << " " <<
		majorFirsNa << " " << majorLastNa << " " << realseMonth << " " << year << endl;

}

bool Classic::operator>(const Movie &m) const {

	const Classic& C = static_cast<Classic&>(m);
	return(this->type > C.type && this->year > C.year && this->realseMonth > C.realseMonth &&
		this->majorFirsNa > C.majorFirsNa && this->majorLastNa > C.majorLastNa && this->director > C.director && this->title > C.title);



	//    if(compairMove(m)==0){
	//        const Classic& C = static_cast<Classic&>(m);
	//        string temp1 = this->director;
	//        string temp2 = C.director;
	//        int compair = temp1.compare(temp2);
	//        if(compair<0){
	//            return false;
	//        }
	//        else if(compair > 0){
	//            return true;
	//        }
	//        else if(compair==0){
	//            string tem1 = this->title;
	//            string tem2 = C.title;
	//            int comp = temp1.compare(temp2);
	//            if(comp < 0){
	//                return false;
	//            }
	//            else if(comp > 0){
	//                return true;
	//            }
	//            else if(comp==0){
	//                string temp = this->majorFirsNa;
	//                string tempe1 = C.majorFirsNa;
	//                int compa = temp1.compare(temp2);
	//                if(compa < 0){
	//                    return false;
	//                }
	//                else if(compa > 0){
	//                    return true;
	//                }
	//                else if(compa == 0){
	//                    string tempo1 = this->majorLastNa;
	//                    string tempo2 = C.majorLastNa;
	//                    int compai = temp1.compare(temp2);
	//                    if(compai < 0){
	//                        return false;
	//                    }
	//                    else if(compai > 0){
	//                        return true;
	//                    }
	//                    else if(compai==0){
	//                        if(this->realseMonth < C.realseMonth)
	//                            return false;
	//                        else if(this->realseMonth > C.realseMonth)
	//                            return true;
	//                        else if(this->realseMonth == C.realseMonth)
	//                            if(this->year < C.year)
	//                                return false;
	//                            else if(this->year > this->year)
	//                                return true;
	//                            else
	//                                return false;
	//                    }
	//
	//                }
	//
	//            }
	//        }
	//
	//
	//    }
	//    else if(compairMove(m)>0)
	//        return true;
	//    else
	//        return false;
	//    return false;

}

bool Classic::operator>=(const Movie &m) const {
	const Classic& C = static_cast<Classic&>(m);
	return(this->type >= C.type && this->year >= C.year && this->realseMonth >= C.realseMonth &&
		this->majorFirsNa >= C.majorFirsNa && this->majorLastNa >= C.majorLastNa  && this->director >= C.director && this->title >= C.title);
	//    if(compairMove(m)==0){
	//        const Classic& C = static_cast<Classic&>(m);
	//        string tem = this->title;
	//        string tem1 = C.title;
	//        int compair = tem.compare(tem1);
	//        if(compair < 0){
	//            return false;
	//        }
	//        else{
	//            string temp = this->majorFirsNa;
	//            string temp2 = C.majorFirsNa;
	//            int compaire = temp.compare(temp2);
	//            if(compaire < 0){
	//                return false;
	//            }
	//            else{
	//                string tempo = this->majorLastNa;
	//                string tempo2 = C.majorLastNa;
	//                int compaireing = temp.compare(temp2);
	//                if(compaireing < 0){
	//                    return false;
	//                }
	//                else{
	//                    string tempor = this->director;
	//                    string tempor2 = C.director;
	//                    int compa = tempor.compare(tempor2);
	//                    if(compa < 0){
	//                        return false;
	//                    }
	//                    else{
	//                        if(this->realseMonth < C.realseMonth){
	//                            return false;
	//                        }
	//                        else{
	//                            if(this->year < C.year){
	//                                return false;
	//                            }
	//                            else
	//                                return true;
	//                        }
	//                    }
	//
	//                }
	//
	//
	//
	//            }
	//
	//        }
	//    }
	//    if(compairMove(m) > 0){
	//        return true;
	//    }
	//    return false;

}
bool Classic::operator==(const Movie &m) const {
	const Classic& C = static_cast<Classic&>(m);
	return(this->type == C.type && this->year == C.year && this->realseMonth == C.realseMonth &&
		this->majorFirsNa == C.majorFirsNa && this->majorLastNa == C.majorLastNa  && this->director == C.director && this->title == C.title);

	//    if(compairMove(m)==0){
	//        const Classic& C = static_cast<Classic&>(m);
	//        string tem = this->title;
	//        string tem1 = C.title;
	//        int compair = tem.compare(tem1);
	//        if(compair!=0){
	//            return false;
	//        }
	//        else {
	//            string temp = this->majorFirsNa;
	//            string temp2 = C.majorFirsNa;
	//            int compaire = temp.compare(temp2);
	//            if(compaire != 0){
	//                return false;
	//
	//            }
	//            else{
	//                string tempo = this->majorLastNa;
	//                string tempo2 = C.majorLastNa;
	//                int compaireing = temp.compare(temp2);
	//                if(compaireing != 0){
	//                    return false;
	//                }
	//                else{
	//                    string tempor = this->director;
	//                    string tempor2 = C.director;
	//                    int compa = tempor.compare(tempor2);
	//                    if(compa != 0){
	//                        return false;
	//
	//                    }
	//                    else{
	//                        if(this->realseMonth != C.realseMonth){
	//                            return false;
	//                        }
	//                        else{
	//                            if(this->year!= C.year){
	//                                return false;
	//                            }
	//                            else
	//                                return true;
	//
	//
	//                        }
	//
	//                    }
	//
	//                }
	//
	//            }
	//
	//        }
	//
	//
	//
	//    }
	//    else
	//        return false;

}
bool Classic::operator!=(const Movie& m)const {

	const Classic& C = static_cast<Classic&>(m);
	return (this->type != C.type || this->year != C.year || this->realseMonth != C.realseMonth ||
		this->majorFirsNa != C.majorFirsNa || this->majorLastNa != C.majorLastNa || this->director != C.director || this->title != C.title);

}
