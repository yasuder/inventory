//
// Created by Goitom Hadishe on 5/16/18.
//

#ifndef CSS343ASS_4_HASHTABLE_H
#define CSS343ASS_4_HASHTABLE_H

template<class KeyType, class ValueType>
class HashTable {
public:
	virtual bool isEmpty() const = 0;
	virtual int getNumberOfEntries() const = 0;
	virtual bool add(const KeyType& searchKey, const ValueType& newValue) = 0;
	virtual bool remove(const KeyType& searchKey) = 0;
	virtual void clear() = 0;
	virtual ValueType getValue(const KeyType& searchKey) const = 0;
	virtual bool contains(const KeyType& searchKey) const = 0;

private:
	int size;

};


#endif //CSS343ASS_4_HASHTABLE_H
