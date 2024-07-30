#pragma once

#include <iostream>

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;

public:
	T* originalArray;
	T* tempArray;

	clsDynamicArray(int size = 0) {

		if (size < 0) {
			size = 0;
		}

		this->_Size = size;
		originalArray = new T[size];
	}

	~clsDynamicArray(){

		delete[] originalArray;

	}

	bool setItem(int index, T value) {
		if (index >= _Size || _Size < 0) {
			return false;
		}
		originalArray[index] = value;
		return true;
	}

	int size() {
		return _Size;
	}

	bool isEmpty() {
		return _Size == 0;
	}

	void resize(int newSize) {

		if (newSize < 0) {
			newSize = 0;
		}

		tempArray = new T[newSize];

		for (int i = 0; i < _Size; i++) {

			tempArray[i] = originalArray[i];
		}

		_Size = newSize;

		delete[] originalArray;

		originalArray = tempArray;

	}

	T getItem(int index) {
		if (index >= _Size || index < 0) {
			return NULL;
		}

		return originalArray[index];
	}

	void reverse() {

		tempArray = new T[_Size];

		for (int i = 0; i < _Size; i++) {
			tempArray[i] = originalArray[(_Size - 1 - i)];
		}

		//for (int i = 0; i < _Size; i++) {
		//	cout << tempArray[i] << "  ";
		//}
		
		delete[] originalArray;

		originalArray = tempArray;

	}

	void printList() {
		for (int i = 0; i < _Size; i++) {
			cout << originalArray[i] << "  ";
		}
	}

	bool deleteItemAt(int index) {

		if (index >= _Size || index < 0) {
			return false;
		}

		tempArray = new T[_Size];

		for (int i = 0; i < index; i++) { 
			tempArray[i] = originalArray[i];
		}

		for (int i = index + 1; i < _Size; i++) {
			tempArray[i - 1] = originalArray[i];
		}

		_Size--;

		delete[] originalArray;
		originalArray = tempArray;

		return true;
	}

	void deleteFirstItem() {
		deleteItemAt(0);
	}

	void deleteLastItem() {
		deleteItemAt(_Size - 1);
	}

	int find(T value) {

		for (int i = 0; i < _Size; i++) {
			if (originalArray[i] == value) {
				return i;
			}
		}

		return - 1;
	}

	bool deleteItem(T item) {

		int index = find(item);

		if (index == -1) {
			return false;
		}

		return deleteItemAt(index);;
	}

	bool insertAt(int index, T newValue) { 
		if (index > _Size || index < 0) {
			return false;
		}

		_Size++;

		tempArray = new T[_Size];

		for (int i = 0; i < index; i++) {
			tempArray[i] = originalArray[i];
		}

		tempArray[index] = newValue;

		for (int i = index; i < _Size - 1; i++) {
			tempArray[i + 1] = originalArray[i];
		}

		delete[] originalArray;
		originalArray = tempArray;
		return true;
	}

	bool insertAtBegining(T newValue) {
		return insertAt(0, newValue);
	}

	bool insertAtEnd(T newValue) {
		return insertAt(_Size, newValue);
	}

	bool insertBefor(int index, T newValue) {
		if (index < 1) {
			return insertAt(0, newValue);
		}
		else {
			return insertAt(index - 1, newValue);
		}
	}

	bool insertAfter(int index, T newValue) {
		if (index >= _Size) {
			return insertAt(_Size - 1 , newValue);
		}
		else {
			return insertAt(index + 1, newValue);
		}
	}

	void clear() {
		_Size = 0;
		tempArray = new T[0];
		delete[] originalArray;
		originalArray = tempArray;
	}
};

