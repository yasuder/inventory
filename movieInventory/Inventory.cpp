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
	movieTree = BinarySearchTree();
	rentals = RentalTable();
	customerList = HashTable<string, Customer*>();
	movieIndex = vector<string>();
	customerIndex = vector<int>();
}

Inventory::~Inventory() {
	movieList.clear();
	movieTree.clear();
	rentals.clear();
	customerList.clear();
}

bool Inventory::addMovie(string str) {
	char type = str[0];
	stringstream ss(str.substr(3));
	string stock, director, title, extra;

	getline(ss, stock, ',');
	getline(ss, director, ',');
	getline(ss, title, ',');
	getline(ss, extra, ',');

	Movie *m;
	switch (type) {
	case 'F':
		//F, 10, Nora Ephron, Sleepless in Seattle, 1993
		m = new Comedy(stoi(stock), title, director, stoi(extra));
		break;
	case 'D':
		//D, 10, Barry Levinson, Good Morning Vietnam, 1988
		m = new Drama(stoi(stock), title, director, stoi(extra));
		break;
	case 'C':
		//C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
		m = new Classic(stoi(stock), title, director, extra);
		break;
	default:
		return false;
	}

		// add to BST
		if (!movieTree.add(m)) {
			return false;
		}
		// add col to rentals 2D vector
			// rentals.add(m);
		// add to movieList
			// movieList.add(m);
	
		// add to movieIndex
		movieIndex.push_back(m->getTitle());
		return true;
}

bool Inventory::addCustomer(string id, string lastName, string firstName) {
	int ctn = customerList.getNumberOfEntries();
	Customer *temp = new Customer(id, firstName, lastName, ctn);
	customerList.add(temp->getCustomerID(), temp);

	//customerIndex.push_back(temp->getCustomerID());

	// add row to rentals 2D vector
		// rentals.add(temp);
	return true; // CHANGE THIS
}

bool Inventory::borrowMovie(string title, string customerID) {
	Movie *m = movieList.getValue(title);
	Customer *c = customerList.getValue(customerID);
	if (m != nullptr && m->getStock() > 0 && c != nullptr && !rentals[m->getIndex()][c->getCustomerTableNum()]) {
		m->borrowBy(customerID);
		return true;
	}
	return false;
}

bool Inventory::returnMovie(string title, string customerID) {
	Movie *m = movieList.getValue(title);
	Customer *c = customerList.getValue(customerID);
	if (m != nullptr && c != nullptr && rentals[m->getIndex()][c->getCustomerTableNum()]) {
		m->returnBy(customerID);
		return true;
	}
	return false;
}

void Inventory::printInventory() {
	movieTree.print();
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
		while (getline(infile, line)) {

			ss.clear();
		}
		infile.close();
	}
	else {
		cout << "Error opening file " << endl;
	}
}

Customer * Inventory::getCustomerAtIndex(int customerIndex) {
	int id = this->customerIndex.at(customerIndex);
	return customerList.getValue(to_string(id));
}

Movie * Inventory::getMovieAtIndex(int movieIndex) {
	string title = this->movieIndex.at(movieIndex);
	return movieList.getValue(title); // are we hashing by title or by some movie ID?
}
