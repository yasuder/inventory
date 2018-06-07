#pragma once

#include <vector>

using namespace std;

template<class KeyType, class ValueType>
struct HashEntry {
	KeyType key;
	ValueType value;
	HashEntry* next = nullptr;

	//Default constructor 
	HashEntry() {}

	//Constructor
	HashEntry(KeyType k, ValueType v) {
		key = k;
		value = v;
	}

	//Copy constructor
	HashEntry(HashEntry &other) {
		key = other.getKey();
		value = other.getValue();
	}

	//Accessors
	KeyType getKey()const {
		return key;
	}

	ValueType getValue()const {
		return value;
	}
};

template<class KeyType, class ValueType>
class HashTable
{
public:
	//Default constructor
	HashTable();

	//Destructor
	~HashTable();

	//Maps the specified key to the specified value in the HashTable
	void add(const KeyType &key, const ValueType &value);

	//Tests if the specified object is a key in the HashTable
	bool containsKey(const KeyType &key);

	//Returns the value to which the specified key is mapped, or 
	//null if this map contains no mapping for the key
	ValueType getValue(const KeyType &key)const;

	//Removes the key(and its corresponding value) from the HashTable
	bool remove(const KeyType &key);

	//Tests if the HashTable maps no keys to values
	bool isEmpty() const;

	//Returns the number of keys in the HashTable
	int getNumberOfEntries()const;

	//Returns the capacity of the HashTable
	int getCapacity()const;

	//Clears the hashTable so that it contains no keys
	void clear();

	vector<string> getKeys()const;

private:
	int capacity = 1;
	int numEntries = 0;
	double loadFactor = 0.75;
	HashEntry<KeyType, ValueType> **table;

	//Hashing function
	int getHash(const KeyType &key)const;
};

template<class KeyType, class ValueType>
inline HashTable<KeyType, ValueType>::HashTable() {
	table = new HashEntry<KeyType, ValueType> *[capacity];

	for (int i = 0; i < capacity; i++) {
		table[i] = NULL;
	}
}

template<class KeyType, class ValueType>
inline HashTable<KeyType, ValueType>::~HashTable() {}

template<class KeyType, class ValueType>
inline void HashTable<KeyType, ValueType>::add(const KeyType &key, const ValueType &value)
{
	if (numEntries > capacity*loadFactor) {
		//Create bigger table
		HashEntry<KeyType, ValueType> **newTable = new HashEntry<KeyType, ValueType> *[capacity * 2];
		capacity = capacity * 2;

		//Set initial value of array/table to be NULL
		for (int i = 0; i < capacity; i++) {
			newTable[i] = NULL;
		}

		//Rehash
		for (int i = 0; i < capacity / 2; i++) {
			if (table[i] != NULL) {
				HashEntry<KeyType, ValueType>* current = table[i];
				while (current != nullptr) {
					int index = getHash(current->getKey());
					if (newTable[index] == NULL) {
						// Copy only itself, ignore next
						HashEntry<KeyType, ValueType>* entry = new HashEntry<KeyType, ValueType>(*current);
						newTable[index] = entry;
					}
					else {
						HashEntry<KeyType, ValueType>* entry = newTable[index];
						while (entry->next != nullptr) {
							entry = entry->next;
						}
						entry->next = current;
					}
					current = current->next;
				}
			}
		}

		//Assigning new bigger table to old table
		table = newTable;
	}

	int index = getHash(key);
	HashEntry<KeyType, ValueType>* h = new HashEntry<KeyType, ValueType>(key, value);
	if (table[index] == NULL) {
		table[index] = h;
		numEntries++;
	}
	else {
		HashEntry<KeyType, ValueType>* current = table[index];
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = h;
		numEntries++;
	}
}

template<class KeyType, class ValueType>
inline bool HashTable<KeyType, ValueType>::containsKey(const KeyType &key)
{
	return table[getHash(key)];
}

template<class KeyType, class ValueType>
inline ValueType HashTable<KeyType, ValueType>::getValue(const KeyType &key) const
{
	ValueType returnValue;
	int index = getHash(key);
	HashEntry<KeyType, ValueType>* current = table[index];

	while (current != nullptr) {
		if (current->getKey() == key) {
			returnValue = current->getValue();
		}
		current = current->next;
	}

	return returnValue;
}

template<class KeyType, class ValueType>
inline bool HashTable<KeyType, ValueType>::remove(const KeyType &key)
{
	int index = getHash(key);
	HashEntry<KeyType, ValueType>* previous = nullptr;
	HashEntry<KeyType, ValueType>* current = table[index];

	while (current != nullptr && current->getKey() != key) {
		previous = current;
		current = current->next;
	}

	if (current == nullptr) {
		cout << "Key not found!" << endl;
		return false;
	}
	else {
		if (previous == nullptr) {
			table[index] = current->next;
		}
		else {
			previous->next = current->next;
		}
		delete current;
		numEntries--;
		return true;
	}
}

template<class KeyType, class ValueType>
inline bool HashTable<KeyType, ValueType>::isEmpty() const
{
	return getNumberOfEntries() == 0;
}

template<class KeyType, class ValueType>
inline int HashTable<KeyType, ValueType>::getNumberOfEntries() const
{
	return numEntries;
}

template<class KeyType, class ValueType>
inline int HashTable<KeyType, ValueType>::getCapacity() const
{
	return capacity;
}

template<class KeyType, class ValueType>
inline void HashTable<KeyType, ValueType>::clear()
{
	for (int i = 0; i < capacity; i++) {
		HashEntry<KeyType, ValueType>* prev = NULL;
		HashEntry<KeyType, ValueType>* current = table[i];

		while (current != nullptr) {
			prev = current;
			current = current->next;
			remove(prev->getKey());
		}
	}
}

template<class KeyType, class ValueType>
inline vector<string> HashTable<KeyType, ValueType>::getKeys() const
{
	vector<string> keys;

	for (int i = 0; i < capacity; i++) {
		HashEntry<KeyType, ValueType>* current = table[i];

		while (current != nullptr) {
			keys.push_back(current->getKey());
			current = current->next;
		}
	}

	return keys;
}

template<class KeyType, class ValueType>
inline int HashTable<KeyType, ValueType>::getHash(const KeyType &key) const
{
	int hash = 0;
	int length = key.length();

	//Summing up the ascii value of chars to determine index (hash) for table
	for (int i = 0; i < length; i++) {
		hash += (key[i] * (i + 1));
	}
	return hash % capacity;
}