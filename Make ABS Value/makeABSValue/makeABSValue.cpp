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
		array[i] = RandomNumber(-100, 100);
	}

}

void printArray(int array[], int length) {

	cout << "the elements of array is:- " << endl;

	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

}


int ABSValue(int nubmber) {
	if (nubmber >= 0) {
		return nubmber;
	}
	else {
		return nubmber * -1;
	}
}

void convertToABSValue(int arraySource[], int lengthSourse,int arrayDistenation[], int & lengthDistenation) {
	int counter = 0;
	for (int i = 0; i < lengthSourse; i++) {
		arrayDistenation[lengthDistenation++] = ABSValue(arraySource[i]);
	}
	
}


int main()
{
	int array[100], lenght = 0, array2[100], lenght2 = 0;

	readArrayWithNumber(array, lenght);

	printArray(array, lenght);

	convertToABSValue(array, lenght, array2, lenght2);

	printArray(array2, lenght2);


	return 0;
}

