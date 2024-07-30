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


void findNumberinArray(int array[], int length, int searchNumber) {
	bool isFound = false;
	int counter = 0;
	for (int i = 0; i < length; i++) {
		counter++;
		if (array[i] == searchNumber) {
			isFound =  true;
			break;
		}
	}
	if (isFound) {
		cout << "number that you are looking for is:- " << searchNumber << endl;

		cout << "the number is found at position:- " << counter << endl;

		cout << "the number is found at order:- " << counter - 1 << endl;
	}
	else {
		cout << "number that you are looking for is:- " << searchNumber << endl;
		cout << "the number is not found :)" << endl;
	}
}
int main()
{
	int array[100], lenght = 0;

	readArrayWithNumber(array, lenght);

	printArray(array, lenght);

	int searchNumber = readPositiveNumber("enter please number that you want search:- ");
	findNumberinArray(array, lenght, searchNumber);

	return 0;
}

