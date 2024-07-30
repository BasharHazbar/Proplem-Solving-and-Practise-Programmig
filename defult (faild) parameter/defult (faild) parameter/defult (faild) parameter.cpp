// defult (faild) parameter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int sum(int x, int y, int c = 0, int b = 0) {
    return (x + y + c + b);
}


int main()
{
    cout << "Hello World!\n";

    cout << "sum:- " << sum(12, 12) << endl;
    cout << "sum:- " << sum(12, 12,12) << endl;
    cout << "sum:- " << sum(12, 12,12,12);
}

