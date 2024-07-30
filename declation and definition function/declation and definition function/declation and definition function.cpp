// declation and definition function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// function deffinption
void sum(int, int);


int main()
{

    sum(12, 23);
    cout << "Hello World!\n";
}

// function deffinption

void sum(int a, int b) {
    cout << a + b << endl;
}