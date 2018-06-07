//
// Created by Goitom Hadishe on 5/16/18.
//

#include "Inventory.h"
#include "Movie.h"

#include <iostream>
#include <fstream>
#include <sstream>

Inventory::Inventory() {
	movieList = HashTable<string, Movie*>();
	comedyTree = BinarySearchTree();
	classicTree = BinarySearchTree();
	dramaTree = BinarySearchTree();
	customerList = HashTable<string, Customer*>();
}

Inventory::~Inventory() {
	movieList.clear();
	comedyTree.clear();
	classicTree.clear();
	dramaTree.clear();
	customerList.clear();
}

bool Inventory::addMovie(string str) {
	char type = str[0];
	cout << "MOVIE TYPE: " << type << endl;
	stringstream ss(str.substr(3));
	string stock, director, title, extra;

	getline(ss, stock, ',');
	getline(ss, director, ',');
	getline(ss, title, ',');
	getline(ss, extra, ',');

	// trim leading whitespace
	if (director[0] == ' ') director = director.substr(1);
	if (title[0] == ' ') title = title.substr(1);
	if (extra[0] == ' ') extra = extra.substr(1);

	Movie *m;
	int mtn = movieList.getNumberOfEntries();
	switch (type) {
	case 'F':
		//F, 10, Nora Ephron, Sleepless in Seattle, 1993
		m = new Comedy(stoi(stock), title, director, stoi(extra), mtn);
		//movieList.add(title, m);
		return comedyTree.add(m);
	case 'D':
		//D, 10, Barry Levinson, Good Morning Vietnam, 1988
		m = new Drama(stoi(stock), title, director, stoi(extra), mtn);
		//movieList.add(title, m);
		return dramaTree.add(m);
	case 'C':
		//C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
		m = new Classic(stoi(stock), title, director, extra, mtn);
		//movieList.add(title, m);
		return classicTree.add(m);
	default:
		cout << "invalid movie code: " << type << endl;
		return false;
	}
}

bool Inventory::addCustomer(string id, string lastName, string firstName) {
	int ctn = customerList.getNumberOfEntries();
	Customer *temp = new Customer(id, firstName, lastName, ctn);
	customerList.add(temp->getCustomerID(), temp);

	return true; // CHANGE THIS
}

bool Inventory::borrowMovie(string title, string customerID) {
	Movie *m = movieList.getValue(title);
	Customer *c = customerList.getValue(customerID);
	if (m != nullptr && c != nullptr) {
		m->borrowBy(customerID);
		c->borrowMovie(title);
		return true;
	}
	return false;
}

bool Inventory::returnMovie(string title, string customerID) {
	Movie *m = movieList.getValue(title);
	Customer *c = customerList.getValue(customerID);
	if (m != nullptr && c != nullptr) {
		m->returnBy(customerID);
		c->returnMovie(title);
		return true;
	}
	return false;
}

void Inventory::executeCommand(string str)
{
	stringstream ss(str);
	Movie *m;
	Customer *c;
	string action, customerId, mediaType, movieType, director, title, extra, month, year;
	ss >> action;

	if (action == "I") {
		this->printInventory();
	}
	else if (action == "H") {
		string id;
		ss >> id;
		Customer *temp = customerList.getValue(id);
		if (temp != NULL) {
			temp->getTransactions().printHistory();
		}
	}
	else if (action == "B") {
		ss >> customerId >> mediaType >> movieType;
		if (movieType == "F") {
			getline(ss, title, ',');
			getline(ss, year, ',');
			m = movieList.getValue(title);
			cout << "CONTAINS: " << movieList.containsKey(title) << endl;
			cout << "STOCK   : " << m->getStock() << endl;
			if (movieList.containsKey(title) && m->getStock() > 0) {
				if (!borrowMovie(title, customerId)) {
					cout << "Could not perform action BORROW for customer " << 
						customerId << " for item " << title << endl;
				}
			}
		}
		else if (movieType == "D") {
			ss >> director >> title;
			getline(ss, director, ',');
			getline(ss, title, ',');
			m = movieList.getValue(title);
			if (movieList.containsKey(title) && m->getStock() > 0) {
				if (!borrowMovie(title, customerId)) {
					cout << "Could not perform action BORROW for customer " <<
						customerId << " for item " << title << endl;
				}
			}
		}
		else if (movieType == "C") {
			ss >> month >> year;
			getline(ss, extra, ',');
			/*
			m = movieList.getValue(title);
			if (m != NULL && m->getStock() > 0) {
				if (!borrowMovie(title, customerId)) {
					cout << "Could not perform action BORROW for customer " <<
						customerId << " for item " << title << endl;
				}
			}
			*/
		}
	}
	else if (action == "R") {
		ss >> customerId >> mediaType >> movieType;
		if (movieType == "F") {

		}
		else if (movieType == "D") {

		}
		else if (movieType == "C") {

		}
	}
}
	/*
	switch (action) {
	case 'B':
	case 'R':
		//B 8000 D F You've Got Mail, 1998
		getline(ss, customerId, ' ');
		getline(ss, mediaType, ' ');

		if (mediaType != "D") {
			cout << "invalid media code: " << mediaType << endl;
			return;
		}

		getline(ss, movieType, ' ');

		if (movieType == "F") {
			//B 8000 D F You've Got Mail, 1998
			getline(ss, title, ',');
		}
		else if (movieType == "D") {
			//B 1000 D D Barry Levinson, Good Morning Vietnam,
			getline(ss, extra, ',');
			getline(ss, title, ',');

			// trim leading whitespace
			if (title[0] == ' ') title = title.substr(1);
		}
		else if (movieType == "C") {
			//B 4444 D C 2 1971 Malcolm McDowell
			getline(ss, month, ' ');
			getline(ss, extra, ' ');
			getline(ss, director);

			// get the movie from BST
			m = movieList.getValue(title);

			if (m == nullptr) {
				cout << "movie doesn't exist: " << movieType << " " << month << " " << extra << " " << director << endl;
				return;
			}
			title = m->getTitle();
		}
		else {
			cout << "invalid video code: " << movieType << endl;
			return;
		}
		c = customerList.getValue(customerId);
		if (c != nullptr) {
			c->addTransaction(action, title);
			if (type == "B") {
				cout << "borrow " << title << " " << customerId << endl; // TODO: Remove after test
				borrowMovie(title, customerId);
			}
			else {
				cout << "return " << title << " " << customerId << endl; // TODO: Remove after test
				returnMovie(title, customerId);
			}
		}
		else {
			cout << "incorrect customer ID:" << customerId << endl;
		}

		break;
	case 'I':
		printInventory();
		break;
	case 'H':
		getline(ss, customerId, ' ');
		cout << "history " << customerId << endl; // TODO: Remove after test
		customerList.getValue(customerId)->getTransactions().printHistory();
		break;
	default:
		cout << "invalid action code: " << action << endl;
		break;
	}
}
*/

void Inventory::printInventory() {
	cout << "Comedy Movies: " << endl;
	comedyTree.print();
	cout << endl;

	cout << "Drama Movies: " << endl;
	dramaTree.print();
	cout << endl;

	cout << "Classic Movies: " << endl;
	classicTree.print();
	cout << endl;
}

void Inventory::printHistory(string customerID) {
	Customer *c = customerList.getValue(customerID);
	c->getTransactions().printHistory();
}

TransactionList Inventory::getHistory(string customerID) {
	return customerList.getValue(customerID)->getTransactions();
}

void Inventory::readCustomerFile(string filename)
{	
	stringstream ss;
	ifstream infile(filename);
	if (infile.is_open()) {
		string line;
		while (getline(infile, line)) {
			string id, firstname, lastname;
			ss << line;
			ss >> id >> firstname >> lastname;
			addCustomer(id, firstname, lastname);
			ss.clear();
		}
		infile.close();
	}
	else {
		cout << "Error opening file " << endl;
	}
}

void Inventory::readMovieFile(string filename)
{
	stringstream ss;
	ifstream infile(filename);
	if (infile.is_open()) {
		string line;
		while (getline(infile, line)) {
			addMovie(line);
			ss.clear();
		}
		infile.close();
	}
	else {
		cout << "Error opening file " << endl;
	}
}

void Inventory::readCommandFile(string filename)
{
	stringstream ss;
	ifstream infile(filename);
	if (infile.is_open()) {
		string line;
		string type;
		while (getline(infile, line)) {
			stringstream iss(line);
			cout <<  "---" << line << endl;
			executeCommand(line);
		}
		infile.close();
	}
	else {
		cout << "Error opening file " << endl;
	}
}


