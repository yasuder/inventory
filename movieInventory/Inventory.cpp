//
// Created by Goitom Hadishe on 5/16/18.
//

#include "Inventory.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classics.h"

Inventory::Inventory() {
	movieList = HashTable<int, Movie*>();
	movieTree = BinarySearchTree();
	rentals = RentalTable();
	customerList = HashTable<int, Customer*>();
	movieIndex = vector<string>();
	customerIndex = vector<int>();
}

Inventory::~Inventory() {
	movieList.clear();
	movieTree.clear();
	//rentals.clear();
	customerList.clear();
}

bool Inventory::addMovie(char type, int stock, string director, string title, string extra) {
	Movie *m;
	if (type == 'F') {
		m = new Comedy(stock, title, director, std::stoi(extra));
	}
	else if (type == 'D') {
		m = new Drama(stock, title, director, std::stoi(extra));
	}
	else if (type == 'C') {

		m = new Classic(stock, title, director, extra);
	}
	else {
		return false;
	}
	// add to BST
	if (!movieTree.add(m)) {
		return false;
	}
	// add col to rentals 2D vector
		// rentals.add(m);
	// add to movieList
	movieList.add(m);

	// add to movieIndex
	movieIndex.push_back(m->getTitle());
}

bool Inventory::addCustomer(int id, string lastName, string firstName) {
	Customer *temp = new Customer(lastName, firstName);
	customerList.add(temp);

	customerIndex.push_back(temp->getCustomerID());

	// add row to rentals 2D vector
		// rentals.add(temp);
}

bool Inventory::borrowMovie(string title, int customerID) {
	Movie *m = movieList.getValue(title);
	Customer *c = customerList.getValue(customerID);
	if (m != nullptr && m->getStock() > 0 && c != nullptr && !rentals[m->getIndex()][c->getIndex()]) {
		m->borrowBy(customerID);
		return true;
	}
	return false;
}

bool Inventory::returnMovie(string title, int customerID) {
	Movie *m = movieList.getValue(title);
	Customer *c = customerList.getValue(customerID);
	if (m != nullptr && c != nullptr && rentals[m->getIndex()][c->getIndex()]) {
		m->returnBy(customerID);
		return true;
	}
	return false;
}

void Inventory::printInventory() {
	movieTree.print();
}

void Inventory::printHistory(int customerID) {
	Customer *c = customerList.getValue(customerID);
	c->getTransactions().printHistory();
}

TransactionList Inventory::getHistory(int customerID) {
	return customerList.getValue(customerID)->getTransactions();
}

Customer * Inventory::getCustomerAtIndex(int customerIndex) {
	int id = this->customerIndex.at(customerIndex);
	return customerList.getValue(id);
}

Movie * Inventory::getMovieAtIndex(int movieIndex) {
	string title = this->movieIndex.at(movieIndex);
	return movieList.getValue(title); // are we hashing by title or by some movie ID?
}
