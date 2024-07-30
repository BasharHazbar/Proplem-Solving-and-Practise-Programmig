// swapping by ref and pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swapByRef(int &a,int &b) {
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int* a, int* b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 1, b = 2;

    cout << a << endl;
    cout << b << endl;

    cout << "========================> 1" << endl;

    swapByRef(a, b);

    cout << a << endl;
    cout << b << endl;


    cout << "========================> 2" << endl;

    swapByPointer(&a, &b);

    cout << a << endl;
    cout << b << endl;

}

