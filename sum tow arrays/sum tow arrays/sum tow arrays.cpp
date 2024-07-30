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

void readArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		array[i] = RandomNumber(1, 100);
	}

}

//bool checkIsPrime(int number) {
//	int half = round(number / 2);
//	for (int counter = 2; counter <= half; counter++) {
//		if (number % counter == 0) {
//			return false;
//		}
//	}
//	return true;
//}

void printArray(int array[], int length) {

	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

//int findMaxNum(int array[], int length) {
//	int maxNum = array[0];
//	for (int i = 0; i < length; i++) {
//		if (array[i] > maxNum) {
//			maxNum = array[i];
//		}
//	}
//	return maxNum;
//}
//
//
//int findMinNum(int array[], int length) {
//	int minNum = array[0];
//	for (int i = 0; i < length; i++) {
//		if (array[i] < minNum) {
//			minNum = array[i];
//		}
//	}
//	return minNum;
//}
//
//int findSumNums(int array[], int length) {
//	int sumNums = array[0];
//	for (int i = 0; i < length; i++) {
//		sumNums += array[i];
//	}
//	return sumNums;
//}
//
//float findAvargeNumbers(int array[], int length) {
//	//int counter = 0;
//	//for (int i = 0; i < length; i++) {
//	//	counter++;
//	//}
//	return (float)findSumNums(array, length) / length;
//}



//void copyArray(int array[100], int array2[100], int length) {
//
//	for (int i = 0; i < length; i++) {
//		array2[i] = array[i];
//	}
//
//}

void sumArrays(int array1[100], int array2[100], int array3[100], int length) {

	for (int i = 0; i < length; i++) {
		array3[i] = array1[i] + array2[i];
	}

}


//int copyArrayJustPrimeNum(int array[100], int array3[100], int length) {
//	int counter = 0;
//	for (int i = 0; i <= length; i++) {
//		if (checkIsPrime(array[i])) {
//			array3[counter] = array[i];
//			cout << "counter :- " << counter;
//			counter++;
//		}
//	}
//	return length = --counter;
//}




int main()
{
	int array1[100], array2[100], array3[100];
	int  lenght = readPositiveNumber("enter how many length of array:- ");
	readArray(array1, lenght);

	readArray(array2, lenght);

	sumArrays(array1, array2, array3,lenght);

	cout << "array1 elements:- " << endl;
	printArray(array1, lenght);

	cout << "array2 elements:- " << endl;
	printArray(array2, lenght);

	cout << "array3 is sum of elements:- " << endl;
	printArray(array3, lenght);




	//cout << "the max number is:- " << findMaxNum(array, lenght) << endl;
	//cout << "the min number is:- " << findMinNum(array, lenght) << endl;
	//cout << "the sum numbers is:- " << findSumNums(array, lenght) << endl;
	//cout << "the avrage numbers is:- " << findAvargeNumbers(array, lenght) << endl;

	return 0;
}

