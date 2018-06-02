//#include "linkedlist.h"
//#include "HashTable.h"
#include "Inventory.h"
#include<string>
#include <iostream> 
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	std::cout << "Hello, World!" << std::endl;
	//cout << "LinkedList Test" << endl;
	//cout << "****************" << endl;
	//LinkedList<string>nameList;
	//nameList.add("Andy");
	//nameList.add("Becky");
	//nameList.add("Chloe");
	//nameList.add("David");
	//nameList.add("Ethan");
	//cout << "Printing nameList(LIFO): " << endl;
	//nameList.print();

	//LinkedList<int>numList;
	//numList.add(111);
	//numList.add(222);
	//numList.add(333);
	//numList.add(444);
	//cout << "Printing numList(LIFO): " << endl;
	//numList.print();
	//cout << endl;

	//cout << "HashTable test" << endl;
	//cout << "****************" << endl;
	//HashTable<string, int> table;
	//cout << "Initial table capacity: " << table.getCapacity() << endl;
	//cout << "Initial table size: " << table.getNumberOfEntries() << endl;
	//table.add("Amy", 1);
	//table.getValue("Amy");
	//table.add("Bob", 2);
	//table.getValue("Bob");
	//table.add("Cam", 3);
	//table.add("D", 4);
	//table.add("X", 5);
	//cout << "Value for Cam: " << table.getValue("Cam") << endl;
	//cout << "Value for D: " << table.getValue("D") << endl;
	//cout << "Value for X: " << table.getValue("X") << endl;
	//cout << "Value for Amy: " << table.getValue("Amy") << endl;
	//cout << "Table size after 5 adds: " << table.getNumberOfEntries() << endl;
	//cout << boolalpha;
	//cout << "Table contains the key 'Amy': " << table.containsKey("Amy") << endl;
	//cout << "Table contains the key 'Jon': " << table.containsKey("Jon") << endl;
	//cout << "Table contains the key 'Cam': " << table.containsKey("Cam") << endl;
	//cout << "Remove Cam success: " << table.remove("Cam") << endl;
	//cout << "Table contains the key 'Cam': " << table.containsKey("Cam") << endl;
	//cout << "Table contains the key 'X': " << table.containsKey("X") << endl;
	//cout << "Value for Cam: " << table.getValue("Cam") << endl;
	//cout << "Value for D: " << table.getValue("D") << endl;
	//cout << "Value for X: " << table.getValue("X") << endl;
	//cout << "Remove D success: " << table.remove("D") << endl;
	//cout << "Value for Cam: " << table.getValue("Cam") << endl;
	//cout << "Value for D: " << table.getValue("D") << endl;
	//cout << "Value for X: " << table.getValue("X") << endl;
	//cout << "Remove X success: " << table.remove("X") << endl;
	//cout << "Table contains the key 'X': " << table.containsKey("X") << endl;
	//cout << "Value for Cam: " << table.getValue("Cam") << endl;
	//cout << "Value for D: " << table.getValue("D") << endl;
	//cout << "Value for X: " << table.getValue("X") << endl;
	//cout << "Table size after a successful remove: " << table.getNumberOfEntries() << endl;
	//cout << "Remove y success: " << table.remove("y") << endl;
	//cout << "Table size after a unsuccessful remove: " << table.getNumberOfEntries() << endl;
	//table.add("Dan", 6);
	//table.add("Ean", 7);
	//table.add("Foo", 8);
	//table.add("Gin", 9);
	//cout << "Table size after 4 more adds: " << table.getNumberOfEntries() << endl;
	//cout << "Table capacity: " << table.getCapacity() << endl;

	//cout << "Clearing table" << endl;
	//cout << "Table size: " << table.getNumberOfEntries() << endl;
	//cout << "Table capacity: " << table.getCapacity() << endl;
	//table.clear();
	//cout << "Table size: " << table.getNumberOfEntries() << endl;
	//cout << "Table capacity: " << table.getCapacity() << endl;

	//readCustomerFile("data4customers.txt");
	Inventory myInventory;
	myInventory.readCustomerFile("data4customers.txt");
	system("pause");
	return 0;
}