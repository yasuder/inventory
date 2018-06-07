//
// Created by Goitom Hadishe on 5/16/18.
//
#include <string>
#include <vector>

#include "BinarySearchTree.h"
#include "Customer.h"
#include "HashTable.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classics.h"
#include "TransactionList.h"

using namespace std;

#ifndef CSS343ASS_4_INVENTORY_H
#define CSS343ASS_4_INVENTORY_H


class Inventory {
public:
	
	 /** defalt constructor  **/
	Inventory();
	/** destructor which cleen up un nessery Inventory  **/
	virtual ~Inventory();
        /** boolean method which take string as parameter and add movie, if add is succesed it will return true
         * if add is not succsefull it will return false **/
	bool addMovie(string str);
       /** boolean  method which take id, first name and lastname as parameter
         * and will return true if add is sucss, and it will return false if add is not sucss **/
	bool addCustomer(string id, string lastName, string firstName);
        /** borrrow method, which boorow the assocate move title to the assocate customer id
         * if succs will return true if not will return false **/
	bool borrowMovie(string title, string customerID);
	 /** return movie  method, which take  movie title and customer id.
          * if the specifec movie is return then it will return true,else will return false;
           * t **/
	bool returnMovie(string title, string customerID);
         /** desplay all the inventory  **/
	void printInventory();
	/** print the history of individual customer  **/
	void printHistory(string customerID);
	  /** get the history of the customer  **/
	TransactionList getHistory(string customerID);
         /** read the txt file for the customer **/
	void readCustomerFile(string filename);
	/** read the movie txt file  **/
	void readMovieFile(string filename);
	/** read the command txt file  **/
	void readCommandFile(string filename);
	  /** read the excute txt file  **/
	void executeCommand(string str);

private:
	HashTable<string, Movie*> movieList;
	BinarySearchTree comedyTree;
	BinarySearchTree dramaTree;
	BinarySearchTree classicTree;
	HashTable<string, Customer*> customerList;
};


#endif //CSS343ASS_4_INVENTORY_H
