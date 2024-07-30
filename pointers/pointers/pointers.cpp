// pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()

{
    int x = 20;
    int* p = &x;


    cout << "value            = " << x << endl;
    cout << "the address          = " << &x << endl;

    cout << "the value of pointer = " << p << endl;

    cout << "the address of pointer = " << &p << endl;

    std::cout << "Hello World!\n";


    int a = 20;
    int* ap = &a;

    cout << "a:- " << a << endl;
    cout << "ap:- " << *ap << endl;


    cout << "&a:- " << &a << endl;
    cout << "ap:- " << ap << endl;

    *ap = 30;

    cout << "a:- " << a << endl;
    cout << "ap:- " << *ap << endl;

    a = 400;

    cout << "a:- " << a << endl;
    cout << "ap:- " << *ap << endl;

    int c = 90;
    ap = &c;

    cout << "c:- " << c << endl;
    cout << "ap:- " << *ap << endl;




}

