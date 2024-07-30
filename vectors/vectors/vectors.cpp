// vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> vNumbers = { 1,2,3,4,5,6,7,8,9,10 };

    for (int& number : vNumbers) {
        cout << number << " ";
    }

    cout << endl;

    vector <int> vNumbers2;

    vNumbers2.push_back(1);
    vNumbers2.push_back(2);
    vNumbers2.push_back(3);
    vNumbers2.push_back(4);
    vNumbers2.push_back(5);
    vNumbers2.push_back(6);
    vNumbers2.push_back(7);
    vNumbers2.push_back(8);
    vNumbers2.push_back(9);
    vNumbers2.push_back(10);

    for (int& number : vNumbers2) {
        cout << number << " ";
    }
}

