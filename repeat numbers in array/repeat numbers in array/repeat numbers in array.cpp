// repeat numbers in array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

short readPositiveNumber(string message) {
	short number = 0;
	do {
		cout << message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}

void readArray(int array[], int &length) {

	cout << "enter the length of array:- " << endl;
	cin >> length;

	for (int i = 0; i < length; i++) {
		cout << "enter the numner [" << i + 1 << "] :- " << endl;
		cin >> array[i];
	}

}

void PrintArray(int array[], int& length) {

	cout << "the original of array is:- " << endl;

	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

}

int TimesRepeat(int array[], int lenght, int number) {
	int counter = 0;
	for (int i = 0; i < lenght; i++) {
		if (number == array[i]) {
			counter++;
		}
	}
	return counter;
}



int main()
{
	int array[100], lenght;
	readArray(array, lenght);
	PrintArray(array, lenght);
	int number = readPositiveNumber("enter a number to check:- ");

	cout << number << " is repeated " << TimesRepeat(array, lenght, number) << " time(s)";
   
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
