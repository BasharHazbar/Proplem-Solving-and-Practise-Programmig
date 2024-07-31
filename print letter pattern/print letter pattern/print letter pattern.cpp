// printInvertedNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void printInvertedNumber(short number) {
    for (short i = 65 + number - 1; i >= 65; i--) {
        for (short j = i; j >= 65; j--) {
            cout << char(i);
        }
        cout << "\n";
    }
}

void printLetterPattern(short number) { 
 
    for (short i = 65; i <= 65 + number - 1; i++) {
        for (short j = 1; j <= i - 65 + 1; j++) {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    printLetterPattern(readPositiveNumber("enter a positive number:- "));

    return 0;
}
