//
// Created by Goitom Hadishe on 5/15/18.
//

#include "Drama.h"
Drama::Drama(int stock, string title, string director, char type, int year) {
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

	//    if(compairMove(m)==0){
	//        const  Drama& d = static_cast<const Drama&>(m);
	//        string temp1 = this->title;
	//        string temp2 = d.title;
	//
	//        int compair = temp1.compare(temp2);
	//        if(compair<0){
	//            return false;
	//        }
	//        else if(compair>0){
	//            return true;
	//        }
	//        else if(compair==0){
	//            if(this->year < d.year){
	//                return false;
	//            }
	//            else if(this->year > d.year){
	//                return true;
	//            }
	//            else if(this->year==d.year){
	//                string tem1 = this->director;
	//                string tem2 = d.director;
	//                int comp = tem1.compare(tem2);
	//                if(comp > 0)
	//                    return true;
	//                else
	//                    return false;
	//
	//            }
	//
	//        }
	//
	//    }
	//    else if(compairMove(m)>0){
	//        return true;
	//    }
	//    else{
	//        return false;
	//    }
	//    return false;
	//
	//

}

bool Drama::operator>=(const Movie &m) const {
	const  Drama& d = static_cast<const Drama&>(m);
	return (this->type >= d.type && this->title >= d.title && this->director >= d.director && this->year >= d.year);
	//    if(compairMove(m)==0){
	//        const  Drama& d = static_cast<const Drama&>(m);
	//        string temp1= this->title;
	//        string temp2 = d.title;
	//        int compair = temp1.compare(temp2);
	//        if(compair<0){
	//            return false;
	//        }
	//        else if(compair>0){
	//            return true;
	//        }
	//        else if(compair==0){
	//            if(this->year < d.year)
	//                return false;
	//            else if(this->year > d.year)
	//                return true;
	//            else if(this->year ==d.year){
	//                string tem1 = this->director;
	//                string tem2 = d.director;
	//                int comp = tem1.compare(tem2);
	//                if(comp < 0)
	//                    return false;
	//                else
	//                    return true;
	//            }
	//
	//        }
	//
	//    }
	//    else if(compairMove(m)>0){
	//        return true;
	//    }
	//    else{
	//        return false;
	//    }
	//    return false;
}

bool Drama::operator==(const Movie &m) const {
	const  Drama& d = static_cast<const Drama&>(m);
	return (this->type == d.type && this->title == d.title && this->director == d.director && this->year == d.year);

	//    if(compairMove(m)==0){
	//        const Drama& d = static_cast<const Drama&>(m);
	//        string temp1 =this->title;
	//        string temp2 = m.title;
	//        int compair = temp1.compare(temp2);
	//        if(compair!=0){
	//            return false;
	//        }
	//        else{
	//            string tem1 = this->director;
	//            string tem2 = d.director;
	//            int comp = tem1.compare(tem2);
	//            if(comp!=0){
	//                return false;
	//            }
	//            else{
	//                if(this->year!=d.year){
	//                    return false;
	//                }
	//                else
	//                    return true;
	//            }
	//        }
	//
	//    }
	//    else
	//        return false;
	//
}
bool Drama::operator!=(const Movie& m)const {
	const  Drama& d = static_cast<const Drama&>(m);
	return (this->type != d.type || this->title != d.title || this->director != d.director || this->year != d.year);

	//    if(compairMove(m)==0){
	//        const Drama& d = static_cast<const Drama&>(m);
	//        string temp1 =this->title;
	//        string temp2 = m.title;
	//        int compair = temp1.compare(temp2);
	//        if(compair!=0){
	//            return true;
	//        }
	//        else{
	//            string tem1 = this->director;
	//            string tem2 = d.director;
	//            int comp = tem1.compare(tem2);
	//            if(comp!=0){
	//                return true;
	//            }
	//            else{
	//                if(this->year!=d.year){
	//                    return true;
	//                }
	//                else
	//                    return false;
	//            }
	//
	//
	//        }
	//
	//    }
	//    else
	//        return true;
}

