//
// Created by Goitom Hadishe on 5/16/18.
//

#include "Inventory.h"
#include "Movie.h"
#include <iostream>
#include <fstream>
#include <sstream>

Inventory::Inventory() {
	//movieList = HashTable<string, Movie*>();
	//movieTree = BinarySearchTree();
	rentals = RentalTable();
	customerList = HashTable<string, Customer*>();
	movieIndex = vector<string>();
	customerIndex = vector<int>();
}

Inventory::~Inventory() {
	//movieList.clear();
	//movieTree.clear();
	//rentals.clear();
	customerList.clear();
}

//bool Inventory::addMovie(char type, int stock, string director, string title, string extra) {
//	Movie *m;
//	if (type == 'F') {
//		m = new Comedy(stock, title, director, std::stoi(extra));
//	}
//	else if (type == 'D') {
//		m = new Drama(stock, title, director, std::stoi(extra));
//	}
//	else if (type == 'C') {
//
//		m = new Classic(stock, title, director, extra);
//	}
//	else {
//		return false;
//	}
//	// add to BST
//	if (!movieTree.add(m)) {
//		return false;
//	}
//	// add col to rentals 2D vector
//		// rentals.add(m);
//	// add to movieList
//		// movieList.add(m);
//
//	// add to movieIndex
//	movieIndex.push_back(m->getTitle());
//	return true;
//}

bool Inventory::addCustomer(string id, string lastName, string firstName) {
	int ctn = customerList.getNumberOfEntries();
	Customer *temp = new Customer(id, firstName, lastName, ctn);
	customerList.add(temp->getCustomerID(), temp);

	//customerIndex.push_back(temp->getCustomerID());

	// add row to rentals 2D vector
		// rentals.add(temp);
	return true; // CHANGE THIS
}

//bool Inventory::borrowMovie(string title, int customerID) {
//	Movie *m = movieList.getValue(title);
//	Customer *c = customerList.getValue(customerID);
//	if (m != nullptr && m->getStock() > 0 && c != nullptr && !rentals[m->getIndex()][c->getCustomerTableNum()]) {
//		m->borrowBy(customerID);
//		return true;
//	}
//	return false;
//}

//bool Inventory::returnMovie(string title, int customerID) {
//	Movie *m = movieList.getValue(title);
//	Customer *c = customerList.getValue(customerID);
//	if (m != nullptr && c != nullptr && rentals[m->getIndex()][c->getCustomerTableNum()]) {
//		m->returnBy(customerID);
//		return true;
//	}
//	return false;
//}

//void Inventory::printInventory() {
//	movieTree.print();
//}

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

	//TODO: Remove below lines 
	cout << customerList.getNumberOfEntries() << endl;
	cout << customerList.getValue("2000")->getFirstName() << endl;
	cout << customerList.getValue("1000")->getCustomerTableNum() << endl;

}

void Inventory::readMovieFile(string filename)
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

//Movie * Inventory::getMovieAtIndex(int movieIndex) {
//	string title = this->movieIndex.at(movieIndex);
//	return movieList.getValue(title); // are we hashing by title or by some movie ID?
//}
