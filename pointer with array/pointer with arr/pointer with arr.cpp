// pointer with arr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int array[] = {1,2,3,4,5,6,7};

    int* pointer = array;

    for (int i = 0; i < 7; i++) { 
        cout << "the reference is:- " << pointer + i << " the value is:- " << *(pointer + i) << endl;
    }
}

