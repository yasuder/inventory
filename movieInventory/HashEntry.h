#pragma once
template<typename KeyType, class ValueType>
class HashEntry {
public:
	HashEntry();
	virtual ~HashEntry();

	KeyType key;
	ValueType value;
};

