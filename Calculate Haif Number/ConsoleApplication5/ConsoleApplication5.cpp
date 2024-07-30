// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int readNumber() {
    int number;
    cout << "enter the number:- " << endl;
    cin >> number;
    return number;
}

float calcHalfNumber(int number) {
    return (float) number / 2;
}

void printHalfNumber(int number) {
 
    string result = "the half of number " + to_string(number) + " is " + to_string(calcHalfNumber(number));
    cout << result << endl;
}

int main()
{
    printHalfNumber(readNumber());
}

