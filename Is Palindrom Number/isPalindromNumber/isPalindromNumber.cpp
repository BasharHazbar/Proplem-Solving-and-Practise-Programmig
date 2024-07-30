// store random numbers in array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void FillArray(int array[], int& arrLength1) {
	array[arrLength1 = 6];
	array[0] = 10;
	array[1] = 20;
	array[2] = 30;
	array[3] = 30;
	array[4] = 20;
	array[5] = 10;

}

void printArray(int array[], int length) {

	cout << "the elements of array is:- " << endl;

	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

}

bool isPalindromArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		if (array[i] != array[length - i - 1]) {
			return false;
		}
	}
	return true;
}

int main()
{
	int array[100], arrLength1 = 0;

	FillArray(array, arrLength1);

	printArray(array, arrLength1);

	if (isPalindromArray(array, arrLength1)) {
		cout << "yes it is palindrom array ";
	}
	else {
		cout << "no it is not palindrom array ";
	}

	return 0;
}

