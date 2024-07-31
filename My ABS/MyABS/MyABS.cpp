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

int ABSValue(int nubmber) {
	if (nubmber >= 0) {
		return nubmber;
	}
	else {
		return nubmber * -1;
	}
}


int main()
{

	int value;
	cout << "enter a number to convert to absloute value:- " << endl;
	cin >> value;

	cout << "my abs value: " << ABSValue(value) << endl;

	cout << "c++ abs value: " << abs(value);



	return 0;
}

