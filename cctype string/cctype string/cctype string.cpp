// cctype string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char x;
    char y;

    x = toupper('a');
    y = tolower('A');

    cout << "x = toupper('a'):- " << x << endl;
    cout << "y = toupper('A'):- " << y << endl;

    cout << "is lower('a'):- " << islower('a') << endl;
    cout << "is lower('A'):- " << islower('A') << endl;

    cout << "is upper('a'):- " << isupper('A') << endl;
    cout << "is upper('A'):- " << isupper('a') << endl;

    cout << "is digit('7'):- " << isdigit('7') << endl;
    cout << "is digit('a'):- " << isdigit('a') << endl;

    cout << "is punct('7'):- " << ispunct(';') << endl;
    cout << "is punct('a'):- " << ispunct('a') << endl;

}

