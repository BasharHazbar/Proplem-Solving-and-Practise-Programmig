// is a prime number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

enum enIsPerfect { perfect = 1, notPerfect = 2 };

int readPositiveNumber(string message) {
    float number = 0;
    do {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

enIsPerfect checkIsPerfcet(int number) {
    int sum = 0;
    for (int counter = 1; counter < number; counter++) {
        if (number % counter == 0) {
            //cout << "the counter == " << counter << endl;
            sum += counter;
       }
    }
    //cout << "the sum = " << sum;
    if (sum == number) {
        return enIsPerfect::perfect;
    }
    return enIsPerfect::notPerfect;
}

void printPerfectNumber(int number) {
    switch (checkIsPerfcet(number))
    {
    case enIsPerfect::perfect:
        cout << number << " is perfect number " << endl;
        break;
    case enIsPerfect::notPerfect:
        cout << number << " is not perfect number " << endl;
        break;
    default:
        break;
    }
}

int main()
{
    //cout << "Hello World!\n";
    printPerfectNumber(readPositiveNumber("enter a positive number to check is positive :- "));

}

