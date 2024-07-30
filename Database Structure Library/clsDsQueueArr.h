#pragma once

#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsDsQueueArr
{
protected:
	clsDynamicArray <T> _MyDynamicArr;
public:

	void push(T item) {
		_MyDynamicArr.insertAtEnd(item);
	}

	void pop() {
		_MyDynamicArr.deleteFirstItem();
	}

	int size() {
		return _MyDynamicArr.size();
	}

	T front() {
		return _MyDynamicArr.getItem(0);
	}

	T back() {
		return _MyDynamicArr.getItem(size() - 1);
	}

	T getItem(int index) {
		return _MyDynamicArr.getItem(index);
	}

	bool updateItem(int index, T value) {
		return _MyDynamicArr.setItem(index,value);
	}

	bool insertAtFront(T value) {
		return _MyDynamicArr.insertAtBegining(value);
	}

	bool insertAtBack(T value) {
		return _MyDynamicArr.insertAtEnd(value);
	}

	bool insertAfter(int index,T item) {
		return _MyDynamicArr.insertAfter(index,item);
	}

	void reverse() {
		 _MyDynamicArr.reverse();
	}

	bool isEmpty() {
		return _MyDynamicArr.isEmpty();
	}

	void print() {
		_MyDynamicArr.printList();
	}


	void clear() {
		_MyDynamicArr.clear();
	}


};

