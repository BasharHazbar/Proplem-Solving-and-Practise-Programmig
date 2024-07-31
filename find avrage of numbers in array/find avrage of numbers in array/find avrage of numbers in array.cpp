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

void readArray(int array[], int& length) {

	cout << "enter the length of array:- " << endl;
	cin >> length;

	for (int i = 0; i < length; i++) {
		array[i] = RandomNumber(100, 1000);
	}

}

void printArray(int array[], int length) {

	cout << "the elements of array is:- " << endl;

	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int findMaxNum(int array[], int length) {
	int maxNum = array[0];
	for (int i = 0; i < length; i++) {
		if (array[i] > maxNum) {
			maxNum = array[i];
		}
	}
	return maxNum;
}


int findMinNum(int array[], int length) {
	int minNum = array[0];
	for (int i = 0; i < length; i++) {
		if (array[i] < minNum) {
			minNum = array[i];
		}
	}
	return minNum;
}

int findSumNums(int array[], int length) {
	int sumNums = array[0];
	for (int i = 0; i < length; i++) {
		sumNums += array[i];
	}
	return sumNums;
}

float findAvargeNumbers(int array[], int length) {
	//int counter = 0;
	//for (int i = 0; i < length; i++) {
	//	counter++;
	//}
	return (float)findSumNums(array, length) / length;
}



int main()
{
	int array[100], lenght = 0;
	readArray(array, lenght);
	printArray(array, lenght);

	cout << "the max number is:- " << findMaxNum(array, lenght) << endl;
	cout << "the min number is:- " << findMinNum(array, lenght) << endl;
	cout << "the sum numbers is:- " << findSumNums(array, lenght) << endl;
	cout << "the avrage numbers is:- " << findAvargeNumbers(array, lenght) << endl;

	return 0;
}

