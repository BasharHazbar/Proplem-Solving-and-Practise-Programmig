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
	} 
	while (number <= 0);
	return number;
}

void printReversDigitNumber(int number) {

	while (number > 0)
	{
		int reminder = number % 10;
		number = number / 10;
		cout << reminder;
	}

}


int main()
{
	printReversDigitNumber(readPositiveNumber("enter a positive number:- "));
}

