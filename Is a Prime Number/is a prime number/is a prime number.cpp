// is a prime number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

enum enIsPrime { prime = 1, notPrime = 2};

int readPositiveNumber(string message) {
    float number = 0;
    do {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

enIsPrime checkIsPrime(int number) {
    int half = round(number / 2);
    for (int counter = 2; counter <= half; counter++) {
        if (number % counter == 0) {
            return enIsPrime::notPrime;
        }
    }
    return enIsPrime::prime;
}

void printIsPrimeFrom1toN(int number) {
    cout << "the prime number from " << 1 << " to " << number << endl;
    for (int i = 1; i <= number; i++) {

        switch (checkIsPrime(i))
        {
        case enIsPrime::prime:
            cout << i << endl;
        default:
            break;
        }
        //if (checkIsPrime(i) == enIsPrime::prime) {
        //    cout << i << endl;
        //}
    }
}

int main()
{
    //cout << "Hello World!\n";
    printIsPrimeFrom1toN(readPositiveNumber("enter a positive number:- "));

}

