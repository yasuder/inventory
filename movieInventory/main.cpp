//#include "linkedlist.h"
//#include "HashTable.h"
#include "Inventory.h"
#include<string>
#include <iostream> 
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	cout << endl;
	cout << "******************" << endl;
	cout << "*LinkedList Tests*" << endl;
	cout << "******************" << endl;
	LinkedList<string>nameList;
	nameList.add("Andy");
	nameList.add("Becky");
	nameList.add("Chloe");
	nameList.add("David");
	nameList.add("Ethan");
	cout << "Printing nameList(LIFO): " << endl;
	cout << "Order should be [Ethan, David, Chloe, Becky, Andy]" << endl;
	nameList.print();
	cout << endl;
	
	LinkedList<int>numList;
	numList.add(111);
	numList.add(222);
	numList.add(333);
	numList.add(444);
	cout << "Printing numList(LIFO): " << endl;
	cout << "Order should be [444, 333, 222, 111]" << endl;
	numList.print();
	cout << endl;

	cout << "*****************" << endl;
	cout << "*HashTable tests*" << endl;
	cout << "*****************" << endl;
	HashTable<string, int> table;
	cout << "Initial table capacity: " << table.getCapacity() << endl;
	cout << "Initial table size: " << table.getNumberOfEntries() << endl;
	table.add("Amy", 1);
	table.getValue("Amy");
	table.add("Bob", 2);
	table.getValue("Bob");
	table.add("Cam", 3);
	table.add("D", 4);
	table.add("X", 5);

	cout << endl;
	cout << "--getValue() checks";
	cout << endl;
	cout << "Value for Cam: " << "Expected: 3		Actual: " << table.getValue("Cam") << endl;
	cout << "Value for D:   " << "Expected: 4		Actual: " << table.getValue("D") << endl;
	cout << "Value for X:   " << "Expected: 5		Actual: " << table.getValue("X") << endl;
	cout << "Value for Amy: " << "Expected: 1		Actual: " <<  table.getValue("Amy") << endl;
	cout << "Table size after 5 adds: " << endl;
	cout << "		Expected: 5		Actual: " << table.getNumberOfEntries() << endl;
	cout << boolalpha;

	cout << endl;
	cout << "--containsKey() checks";
	cout << endl;
	cout << "Table contains the key 'Amy': " << "Expected: true	Actual: " << table.containsKey("Amy") << endl;
	cout << "Table contains the key 'Jon': " << "Expected: false	Actual: " << table.containsKey("Jon") << endl;
	cout << "Table contains the key 'Cam': " << "Expected: true	Actual: " << table.containsKey("Cam") << endl;

	cout << endl;
	cout << "--remove() checks";
	cout << endl;
	cout << "Remove Cam success:		Expected: true	Actual: " << table.remove("Cam") << endl;
	cout << "Table contains the key 'Cam':	Expected: false	Actual: " << table.containsKey("Cam") << endl;
	cout << "Table contains the key 'X':	Expected: true	Actual: " << table.containsKey("X") << endl;
	cout << "Value for Cam:			Expected: -	Actual: " << table.getValue("Cam") << endl;
	cout << "Value for D:			Expected: 4	Actual: " << table.getValue("D") << endl;
	cout << "Value for X:			Expected: 5	Actual: " << table.getValue("X") << endl;
	cout << "Remove D success:		Expected: true	Actual: " << table.remove("D") << endl;
	cout << "Value for D:			Expected: -	Actual: " << table.getValue("D") << endl;
	cout << "Remove X success:		Expected: true	Actual: " << table.remove("X") << endl;
	cout << "Table contains the key 'X':	Expected: false	Actual: " << table.containsKey("X") << endl;
	cout << "Value for X:			Expected: -	Actual: " << table.getValue("X") << endl;
	cout << "Table size after a successful remove:	Expected: 2	Actual: " << table.getNumberOfEntries() << endl;
	cout << "Remove y success:		Expected: false	Actual: " << table.remove("y") << endl;
	cout << "Table size after a unsuccessful remove:	Expected: 2	Actual: " << table.getNumberOfEntries() << endl;

	cout << endl;
	cout << "--add() checks with size";
	cout << endl;
	table.add("Dan", 6);
	table.add("Ean", 7);
	table.add("Foo", 8);
	table.add("Gin", 9);
	cout << "Table size after 4 more adds: " << table.getNumberOfEntries() << endl;
	cout << "Table capacity: " << table.getCapacity() << endl;

	cout << "Clearing table" << endl;
	cout << "Table size: " << table.getNumberOfEntries() << endl;
	cout << "Table capacity: " << table.getCapacity() << endl;
	table.clear();
	cout << "Table size: " << table.getNumberOfEntries() << endl;
	cout << "Table capacity: " << table.getCapacity() << endl;
	cout << endl;
	
	cout << "*************************" << endl;
	cout << "*Text File Reading tests*" << endl;
	cout << "*************************" << endl;
	Inventory myInventory;
	cout << "--Reading from data4movies.txt" << endl;
	cout << "	Expected: 2 errors with Z type movies" << endl;
	cout << "	Actual  :" << endl;
	myInventory.readMovieFile("data4movies.txt");
	cout << endl;

	cout << "--Reading from data4customers.txt" << endl;
	cout << "	Expected: 0 errors" << endl;
	cout << "	Actual  :" << endl;
	myInventory.readCustomerFile("data4customers.txt");
	cout << endl;

	cout << "--Reading from data4commands.txt" << endl;
	cout << "	Expected: 1 error with X type command" << endl;
	cout << "	Actual  :" << endl;
	myInventory.readCommandFile("data4commands.txt");
	cout << endl;

	return 0;
}