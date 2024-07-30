// store random numbers in array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int readPositiveNumber() {
	int number = 0;
	do {
		cout << "enter the number:- " << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength){ 
	arr[arrLength++] = Number;
}



void insertDynamicNumberToArrayr(int array[], int & arrayLength) {
	bool addMore = true;
	do {
		AddArrayElement(readPositiveNumber(), array, arrayLength);
		cout << "do you want add more numbers ? [1]:yes, [0]:no :- " << endl;
		cin >> addMore;
	} while (addMore);

}

void printArray(int array[], int length) {

	cout << "the elements of array is:- " << endl;

	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

}



int main()
{
	int array[100], arrLength = 0;

	insertDynamicNumberToArrayr(array, arrLength);

	cout << "array length is:- " << arrLength << endl;

	printArray(array, arrLength);

	return 0;
}

