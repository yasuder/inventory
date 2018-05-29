#include "customer.h"

Customer::Customer(){}

Customer::Customer(int id, string fn, string ln, int ctn)
{
	customerId = id;
	firstName = fn;
	lastName = ln;
	customerTableNum = ctn;
	transactions = TransactionList();
}

Customer::~Customer(){}

int Customer::getCustomerId() const
{
	return customerId;
}

string Customer::getFirstName() const
{
	return firstName;
}

string Customer::getLastName() const
{
	return lastName;
}

int Customer::getCustomerTableNum() const
{
	return customerTableNum;
}

TransactionList Customer::getTransactions() const
{
	return transactions;
}

bool Customer::addTransaction(char actionType, string movieTitle) {
	return transactions.add(actionType, movieTitle);
}
