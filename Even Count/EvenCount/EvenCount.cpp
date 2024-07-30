// store random numbers in array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

//int readPositiveNumber(string message) {
//	int number = 0;
//	do {
//		cout << message << endl;
//		cin >> number;
//	} while (number <= 0);
//	return number;
//}

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

int EvenCount(int array[], int length) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] % 2 == 0) {
			counter++;
		}
	}
	return counter;
}

//int findNumberPositionInArray(int array[], int length, int searchNumber) {
//	for (int i = 0; i < length; i++) {
//		if (array[i] == searchNumber) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//bool isNumberFoundinArray(int array[], int length, int searchNumber) {
//
//	return findNumberPositionInArray(array, length, searchNumber) != -1;
//}



int main()
{
	int array[100], lenght = 0;

	readArrayWithNumber(array, lenght);

	printArray(array, lenght);

	cout << "count of odd number in array is:- " << EvenCount(array, lenght);

	return 0;
}

