//
// Created by Goitom Hadishe on 5/16/18.
//

#include "Inventory.h"

Inventory::Inventory() {

}
Inventory::~Inventory() {

}

bool Inventory::addMovie(char type, int stock, string director, string title, string extra) {

}
bool Inventory::addCustomer(int id, string lastName, string firstName) {

}

bool Inventory::borrowMovie(string title, int customerID) {

}
bool Inventory::returnMovie(string title, int customerID) {

}

void Inventory::printInventory() {

}
void Inventory::printHisotry(int customerID) {

}
TransactionList Inventory::getHistory(int customerID) {

}

Customer * Inventory::getCustomerAtIndex(int customerIndex) {

}
Movie * Inventory::getMovieAtIndex(int movieIndex) {

}
