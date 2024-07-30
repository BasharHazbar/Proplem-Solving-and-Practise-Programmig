// store random numbers in array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

//int readPositiveNumber() {
//	int number = 0;
//	do {
//		cout << "enter the number:- " << endl;
//		cin >> number;
//	} while (number <= 0);
//	return number;
//}


//bool checkIsPrime(int number) {
//	int half = round(number / 2);
//	for (int counter = 2; counter <= half; counter++) {
//		if (number % counter == 0) {
//			return false;
//		}
//	}
//	return true;
//}


//int RandomNumber(int From, int To) {
//	//Function to generate a random number 
//	int randNum = rand() % (To - From + 1) + From;
//	return randNum;
//}
//
//
////void Swap(int& A, int& B) {
////	int TEMP = 0;
////	TEMP = A;
////	A = B;
////	B = TEMP;
////}
//
//void readArrayWithRandomNumber(int array[], int& length) {
//	length = readPositiveNumber();
//	for (int i = 0; i < length; i++) {
//		array[i] = RandomNumber(1, 100);
//	}
//
//}
//
//void copyArrayOddUsingAddArrayElement(int arraySource[], int arrayDistnation[], int lenght1, int& lenght2) {
//	for (int i = 0; i < lenght1; i++) {
//		if (checkIsPrime(arraySource[i])) {
//			AddArrayElement(arraySource[i], arrayDistnation, lenght2);
//		}
//	}
//}


void FillArray(int array[100], int & arrLength1) {
	array[arrLength1 = 10];
	array[0] = 10;
	array[1] = 10;
	array[2] = 10;
	array[3] = 30;
	array[4] = 30;
	array[5] = 30;
	array[6] = 50;
	array[7] = 50;
	array[8] = 60;
	array[9] = 60;
}

int findPositionNumberInArray(int array[], int length, int searchNumber) {
	for (int i = 0; i < length; i++) {
		if (array[i] == searchNumber) {
			return i;
		}
	}
	return -1;
}

bool isNumberFoundinArray(int array[], int length, int searchNumber) {

	return findPositionNumberInArray(array, length, searchNumber) != -1;
}

void AddArrayElement(int Number, int arr[100], int& arrLength) {
	arr[arrLength++] = Number;
}

void printArray(int array[], int length) {

	cout << "the elements of array is:- " << endl;

	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

}

void copyDistincNumberToArray(int array[100], int arrLength1, int array2[100], int& arrLength2) {
	for (int i = 0; i < arrLength1; i++) {
		if (!isNumberFoundinArray(array2, arrLength2, array[i])) {
			AddArrayElement(array[i],array2,arrLength2);
		}
	}
}



int main()
{
	int array[100], array2[100], arrLength1 = 0, arrLength2 = 0;

	FillArray(array, arrLength1);

	printArray(array, arrLength1);
	copyDistincNumberToArray(array, arrLength1, array2, arrLength2);

	printArray(array2, arrLength2);

	return 0;
}

