// ConsoleApplication12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

bool valadateNumberInRange(int number, int From, int To) {
    return (number >= From && number <= To);
}

int readAgaUntilBetween(int From, int To) {
    int age = 0;
    do {
        cout << "enter you age be above of "  << From << " and less " << To << ":- ";
        cin >> age;
    }   while (!valadateNumberInRange(age,From,To));

    return age;
};

void printAge(int age) {
    cout << "your age is:- " << age;
}

int main()
{
    printAge(readAgaUntilBetween(20,100));
}
