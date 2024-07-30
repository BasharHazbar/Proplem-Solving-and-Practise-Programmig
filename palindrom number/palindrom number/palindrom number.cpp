// palindrom number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int readPositiveNumber(string message) {
    float number = 0;
    do {
        cout << message << endl;
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

bool checkIsPalindrom(int number) {
	return number == ReversDigitNumber(number);
}

void PrintIsPalindrom(int number) {
	if (checkIsPalindrom(number)) {
		cout << "it is " << number << " palindrom number !";
	}
	else {
		cout << "it is not " << number << " palindrom number !";
	}
}

int main()
{
	//int mainNumber = readPositiveNumber("please enter a positive number:- ");
	//int reversedNumber = ReversDigitNumber(mainNumber);
	//PrintIsPalindrom(mainNumber, reversedNumber);

	PrintIsPalindrom(readPositiveNumber("please enter a positive number:- "));

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
