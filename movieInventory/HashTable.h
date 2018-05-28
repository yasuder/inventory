#pragma once

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

	//Getters
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

private:
	int capacity = 20;
	HashEntry<KeyType, ValueType> **table;
	int numEntries = 0;

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
	int index = getHash(key);
	if (index >= 0 && index < capacity) {
		if (table[index]->getKey() == key) {
			return true;
		}
	}
	return false;
}

template<class KeyType, class ValueType>
inline ValueType HashTable<KeyType, ValueType>::getValue(const KeyType &key) const
{
	int index = getHash(key);
	if (table[index] == NULL || index >= capacity) {
		return NULL;
	}else {
		HashEntry<KeyType, ValueType>* current = table[index];
	
		while (current->next != nullptr) {
			if (current->getKey() == key) {
				return current->getValue();
			}
			current = current->next;
		}
		return current->getValue();
	}
	return NULL;
}

template<class KeyType, class ValueType>
inline bool HashTable<KeyType, ValueType>::remove(const KeyType &key)
{
	int index = getHash(key);
	if (table[index] == NULL) {
		cout << "Invalid key, remove unsuccessful!" << endl;
		return false;
	}
	else {
		HashEntry<KeyType, ValueType>* current = table[index];

		while (current != nullptr) {
			if (current->getKey() == key) {
				delete current;
				numEntries--;
				return true;
			}
			current = current->next;
		}
		cout << "Invalid key, remove unsuccessful !" << endl;
		return false;
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


/*
#ifndef CSS343ASS_4_HASHTABLE_H
#define CSS343ASS_4_HASHTABLE_H

template<typename KeyType, class ValueType>
class HashTable {
public:
	HashTable();
	virtual ~HashTable();
	bool isEmpty() const = 0;
	int getNumberOfEntries() const = 0;
	bool add(const ValueType& newValue) = 0;
	bool remove(const KeyType& searchKey) = 0;
	void clear() = 0;
	ValueType getValue(const KeyType& searchKey) const = 0;
	bool contains(const KeyType& searchKey) const = 0;

private:
	int numEntries;
	double loadFactor; // depends on how your implement the collision handling
	HashEntry<KeyType, ValueType> **arr; // array implementation of map/dictionary

	KeyType hashCalculator(const ValueType& newValue); // hashes the given value to determine index (hash) for table
	bool add(const KeyType& searchKey, const ValueType& newValue) = 0; // searchKey = result of hashCalculator(), newValue is value passed into public add()
};


#endif //CSS343ASS_4_HASHTABLE_H

*/

