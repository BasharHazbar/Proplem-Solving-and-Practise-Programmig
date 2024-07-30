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

void AddArrayElement(int Number, int arr[100], int& arrLength) {
	arr[arrLength++] = Number;
}

int RandomNumber(int From, int To) {
	//Function to generate a random number 
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}


//void Swap(int& A, int& B) {
//	int TEMP = 0;
//	TEMP = A;
//	A = B;
//	B = TEMP;
//}

void readArrayWithRandomNumber(int array[], int& length) {
	length = readPositiveNumber();
	for (int i = 0; i < length; i++) {
		array[i] = RandomNumber(1, 100);
	}

}

void copyArrayOddUsingAddArrayElement(int arraySource[], int arrayDistnation[], int lenght1, int& lenght2) {
	for (int i = 0; i < lenght1; i++) {
		if (arraySource[i] % 2 != 0) {
			AddArrayElement(arraySource[i], arrayDistnation, lenght2);
		}
	}
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
	int array[100], array2[100], arrLength1 = 0, arrLength2 = 0;

	readArrayWithRandomNumber(array, arrLength1);


	printArray(array, arrLength1);

	copyArrayOddUsingAddArrayElement(array, array2, arrLength1, arrLength2);



	printArray(array2, arrLength2);

	return 0;
}

