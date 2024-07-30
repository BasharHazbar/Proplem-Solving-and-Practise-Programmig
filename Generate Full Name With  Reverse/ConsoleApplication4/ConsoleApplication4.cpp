// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct stInfo {
    string firstName;
    string lastName;
};

stInfo readFullName(stInfo &info) {
    cout << "enter your first name:- \n";
    cin >> info.firstName;
    cout << "enter your last name:- \n";
    cin >> info.lastName;

    return info;
}

string generateFullName(stInfo info, bool reversed) {
    string fullName = "";
    if (reversed)
        fullName = info.lastName + " " + info.firstName;
    else
        fullName = info.firstName + " " + info.lastName;

    return fullName;
}

void printFullName(string fullname) {
    cout << "your full name is:- " << fullname;
}


int main()
{
    stInfo info;
    printFullName(generateFullName(readFullName(info), true));
}

