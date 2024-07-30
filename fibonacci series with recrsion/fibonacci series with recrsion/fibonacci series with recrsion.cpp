// fibonacci series.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

short readPositiveNumber(string message) {
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

void printFibonacciSeriesByRecursion(int number, int prev1, int prev2) {
    int fibNumber = 0;
    if (number > 0) {
        fibNumber = prev1 + prev2;
        cout << fibNumber << "    ";
        prev1 = prev2;
        prev2 = fibNumber;
        printFibonacciSeriesByRecursion(number - 1,prev1, prev2);
    }

}
int main()
{
    printFibonacciSeriesByRecursion(200, 0, 1);
}

