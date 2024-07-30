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

int ReversDigitNumber(int number) {
	int number2 = 0, reminder = 0;
	while (number > 0)
	{
		reminder = number % 10;
		number = number / 10;
		number2 = (number2 * 10) + reminder;
	}
	return number2;
}

void printOrderDigit(int number) {
	while (number > 0)
	{
		int reminder = number % 10;
		number = number / 10;
		cout << reminder << endl;
	}
}




int main()
{
	//cout << printReversDigitNumber(readPositiveNumber("enter a positive number:- "));

	printOrderDigit(ReversDigitNumber(readPositiveNumber("enter a positive number:- ")));

}

