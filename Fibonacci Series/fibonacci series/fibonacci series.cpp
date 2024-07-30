// fibonacci series.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

short readPositiveNumber (string message) {
    short number;
    do {
        cout << message << endl;
        cin >> number;
    } while (number < 0);
    return number;
}

void printFibonacciSeries(int number) {
    int prev1 = 0, prev2 = 1, febNumber = 0;
    cout << "1     ";
    for (int i = 2; i <= number; i++) {
        febNumber = prev1 + prev2;
        cout << febNumber << "     ";
        prev1 = prev2;
        prev2 = febNumber;
    }
}
int main()
{
    printFibonacciSeries(readPositiveNumber("enter the lenth of series:- "));
}

