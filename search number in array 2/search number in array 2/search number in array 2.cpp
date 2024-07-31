// store random numbers in array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int readPositiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}

int RandomNumber(int From, int To) {
	//Function to generate a random number 
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void readArrayWithNumber(int array[], int& length) {

	cout << "enter the length of array:- " << endl;
	cin >> length;

	for (int i = 0; i < length; i++) {
		array[i] = RandomNumber(1, 1000);
	}

}

void printArray(int array[], int length) {

	cout << "the elements of array is:- " << endl;

	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

}

int findNumberPositionInArray(int array[], int length, int searchNumber) {
	for (int i = 0; i < length; i++) {
		if (array[i] == searchNumber) {
			return i;
		}
	}
	return -1;
}

bool isNumberFoundinArray(int array[], int length, int searchNumber) {

	return findNumberPositionInArray(array, length, searchNumber) != -1;
}

int main()
{
	int array[100], lenght = 0;

	readArrayWithNumber(array, lenght);

	printArray(array, lenght);

	int searchNumber = readPositiveNumber("enter please number that you want search:- ");

	cout << "the number that you search for is:- " << searchNumber << endl;

	if (!isNumberFoundinArray(array, lenght, searchNumber)) {
		cout << "no, the number is not exsist in array !" << endl;
	}
	else {
		cout << "yes, the number is exsist in array !" << endl;
	}



	return 0;
}

