#include <vector>
using namespace std;

#pragma once
class RentalTable {
public:
	RentalTable();
	virtual ~RentalTable();

	bool addMovie();
	bool addCustomer();
	bool borrowMovie(string title, int customerID); // add a row to the 2D vector
	bool returnMovie(string title, int customerID); // add a column to the 2D vector

	vector<int> customersRentingMovie(string title); // to know who's renting a specified movie
	vector<string> moviesRentedByCustomer(int customerID); // to know what movies a specified customer is renting

	bool isRenting(int customerID, string title);

private:
	vector< vector<bool> > grid; // the actual 2D vector

	vector<int> customerIndex; // index = index in 2D vector for customer
	vector<string> movieIndex; // index = index in 2D vector for movie
};

