#pragma once

#include <iostream>
#include "clsDsQueueArr.h"

using namespace std;

template <class T>
class clsDsStackArr : public clsDsQueueArr <T>
{
public:

	void push(T item) {
		clsDsQueueArr <T>::_MyDynamicArr.insertAtBegining(item);
	}

	int size() {
		return clsDsQueueArr <T>::_MyDynamicArr.size();
	}

	T top() {
		return clsDsQueueArr <T>::front();
	}

	T bottom() {
		return clsDsQueueArr <T>::back();
	}

};

