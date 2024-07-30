// reversed digit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int readPositiveNumber(string Message) {
	int number = 0;
	do
	{
		cout << Message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}

void printReversNumber(int number) {
	int reminder = 0, number2 = 0;
	while (number > 0)
	{
		reminder = number % 10;
		number = number / 10;
		number2 = number2 * 10 + reminder;
	}
	cout << "the reversed number is:- " << number2;
}


int main()
{
	printReversNumber(readPositiveNumber("enter a positive number:- "));
}

