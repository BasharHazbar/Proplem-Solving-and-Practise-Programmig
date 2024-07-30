#pragma once


#include <iostream>
#include "clsDsQueueu.h"

using namespace std;

template <class T>
class clsDbStack : public clsDsQueueu <T>
{


public:

	void push(T item) {
		clsDsQueueu <T>::_MyList.insertAtBeginning(item);
	}

	int size() {
		return clsDsQueueu <T>::_MyList.size();
	}

	T top() {
		return clsDsQueueu <T>::front();
	}

	T bottom() {
		return clsDsQueueu <T>::back();
	}

	void insertAtTop(T newValue) {
		clsDsQueueu <T>::_MyList.insertAtBeginning(newValue);
	}

	void insertAtBottom(T newValue) {
		clsDsQueueu <T>::_MyList.insertAtEnd(newValue);
	}

	//T getItem(int index) {
	//	return _MyList.getItem(index);
	//}

	//void updateItem(int index, T newValue) {
	//	_MyList.updateItem(index,newValue);
	//}

	//void reverse() {
	//	_MyList.reverse();
	//}

	//void insertAfter(int index, T newValue) {
	//	_MyList.insertAfter(index,newValue);
	//}

	//void clear() {
	//	_MyList.clear();
	//}

	//void print() {
	//	_MyList.PrintList();
	//}
};

