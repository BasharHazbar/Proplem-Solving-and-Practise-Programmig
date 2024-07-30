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

int countDigitNumber(int number) {
	int counter = 0, reminder = 0;
	while (number > 0)
	{
		reminder = number % 10;
		number = number / 10;
		counter++;
	}
	return counter;
}

short countDigitFrequency(int number,short digitToChecker) {
	short digitFrequency = 0, reminder = 0;
	while (number > 0)
	{
		reminder = number % 10;
		number = number / 10;
		if (reminder == digitToChecker) {
			digitFrequency++;
		}
	}
	return digitFrequency;
}

void printCountForEveryDigit(int number) {
	int number2 = number, reminder = 1;
	for (int i = 0; i < countDigitNumber(number); i++) {
		reminder = number2 % 10;
		number2 = number2 / 10;
		int number2 = number;
		int digitFrequency = countDigitFrequency(number2, reminder);
		cout << "digit " << reminder << " frequency is " << digitFrequency << " times" << endl;
	}

}

void printCountForEveryDigitLastUpdated(int number) {
	
	for (int i = 0; i < 10; i++) {
		short digitFrequency = countDigitFrequency(number, i);

		if (digitFrequency > 0) {
			cout << "digit " << i << " frequency is " << digitFrequency << " times" << endl;
		}

	}

}


int main()
{/*
	printCountForEveryDigit(readPositiveNumber("enter a positive number to \ncheck how many repeat in the number:- "));*/
	/*printCountForDigit(readPositiveNumber("enter a positive number:- "),readPositiveNumber("enter a reminder number to \n check count of repeats in digits of number:- "));*/

	int number = readPositiveNumber("enter the mian number");
	short digitToChecker = readPositiveNumber("please enter one digit to check:-");
	cout << "digit " << digitToChecker << " frequancy is :- " << countDigitFrequency(number,digitToChecker) << " time (s)";

	cout << "\n===========================================================================\n";
	//printCountForEveryDigit(number);
	printCountForEveryDigitLastUpdated(number);


	return 0;
}


