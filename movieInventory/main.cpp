#include "linkedList.h"
#include "HashTable.h"
#include<string>
#include <iostream> 

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
	cout << "LinkedList Test" << endl;
	LinkedList<string>nameList;
	nameList.add("Andy");
	nameList.add("Becky");
	nameList.add("Chloe");
	nameList.add("David");
	nameList.add("Ethan");
	cout << "Printing nameList(LIFO): " << endl;
	nameList.print();

	LinkedList<int>numList;
	numList.add(111);
	numList.add(222);
	numList.add(333);
	numList.add(444);
	cout << "Printing numList(LIFO): " << endl;
	numList.print();
	cout << endl;

	/*
	cout << "HashTable test" << endl;
	HashTable<string, int> table;
	cout << "initial table size: " << table.getSize() << endl;
	table.put("Amy", 1);
	table.put("Bob", 2);
	table.put("Cam", 3);
	cout << "value for Amy: " << table.get("Amy") << endl;
	cout << "table size after 3 puts: " << table.getSize() << endl;
	cout << boolalpha;
	cout << "table contains the key 'Amy': " << table.containsKey("Amy") << endl;
	cout << "table contains the key 'Jon': " << table.containsKey("Jon") << endl;
	*/

	system("pause");
    return 0;
}