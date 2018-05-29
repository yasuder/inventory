#pragma once
#include<iostream>

template<class Type>
struct Node {
	Type data;
	Node<Type>* next;

	//Default constructor 
	Node<Type>() {}

	//Constructor
	Node<Type>(Type d) {
		data = d;
		next = nullptr;
	}
};

template<class Type>
class LinkedList
{
public:
	//Constructor
	LinkedList();

	//Destructor
	~LinkedList();

	//Inserts the specified element at the begining of the list
	void add(const Type & obj);

	//Returns the number of elements in the list
	int getSize() const;

	//Prints all the elements in the list in LIFO order
	void print();

private:
	Node<Type> *head;
	Node<Type> *next = nullptr;
	int size;
};

template<class Type>
inline LinkedList<Type>::LinkedList()
{
	head = nullptr;
	next = nullptr;
	size = 0;
}

template<class Type>
inline LinkedList<Type>::~LinkedList() {}

template<class Type>
inline void LinkedList<Type>::add(const Type & obj)
{
	Node<Type>*newNode = new Node<Type>(obj);
	newNode->next = head;
	head = newNode;
	size++;
}

template<class Type>
inline int LinkedList<Type>::getSize()const
{
	return size;
}

template<class Type>
inline void LinkedList<Type>::print()
{
	if (getSize() == 0) {
		return;
	}
	Node<Type>*temp = new Node<Type>();
	temp = head;
	while (temp != nullptr) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}
