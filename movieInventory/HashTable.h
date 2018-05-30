//
// Created by Goitom Hadishe on 5/16/18.
//

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
	int size;
	double loadFactor; // depends on how your implement the collision handling
	HashEntry<KeyType, ValueType> **arr; // array implementation of map/dictionary

	int getHash(const KeyType &key)
};


#endif //CSS343ASS_4_HASHTABLE_H
