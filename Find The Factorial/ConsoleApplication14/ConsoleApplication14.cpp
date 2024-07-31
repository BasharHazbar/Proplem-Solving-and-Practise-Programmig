// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int readTheNumberPositive(string massage) {
    int number = 0;
    do {
        cout << massage << endl;
        cin >> number;
    }
    while(number);
    return number;
}

int findTheFactorial(int number) {
    int factorial = 1;
    for (int counter = 1; counter <= number; counter++) {
        factorial *= counter;
    }
    return factorial;
}

void printFactorial(int number) {
    cout << "the factorial is :- " << number;
}

int main()
{
    printFactorial(findTheFactorial(readTheNumberPositive("enter a positive numbers:- ")));
}
