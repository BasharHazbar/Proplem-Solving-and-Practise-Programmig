#pragma once
#include <iostream>
#include "clsDbLinkedList.h"

using namespace std;

template <class T>
class clsDsQueueu
{

protected:
	clsDbLinkedList <T> _MyList; 

public:

	void push(T item) {
		_MyList.insertAtEnd(item);
	}

	void pop() {
		_MyList.deleteFirstNode();
	}

	int size() {
		return _MyList.size();
	}

	T front() {
		return _MyList.getItem(0);
	}

	T back() {
		return _MyList.getItem(size() - 1);
	}

	void print() {
		_MyList.PrintList();
	}

	bool isEmpty() {
		_MyList.isEmpty();
	}

	T getItem(int index) {
		return _MyList.getItem(index);
	}

	void reverse() {
		_MyList.reverse();
	}

	void updateItem(int index, T newValue) {
		 _MyList.updateItem(index,newValue);
	}

	void insertAfter(int index, T newValue) {
		 _MyList.insertAfter(index, newValue);
	}

	void insertAtFront(T item) {
		_MyList.insertAtBeginning(item);
	}

	void insertAtBack(T item) {
		_MyList.insertAtEnd(item);
	}

	void clear() {
		_MyList.clear();
	}

};

