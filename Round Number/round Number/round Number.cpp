// round Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


float readNumber() {
    float number = 0;
    cout << "enter a number to round it:- " << endl;
    cin >> number;
    return number;
}

float getFractionPart(float number) {
    return number - (int)number;
}

int getRound(float number) { /// -10.5. 10.3

    int intPart = int(number); //-10
    float fractionPart = getFractionPart(number); // -.5

    if (abs(fractionPart) >= .5) {
        if (number > 0) {
           return  ++intPart; //11
        }
        else {
            return --intPart; //-1-10 = -11
        }
    }
    else {
        return intPart;
    }
}

int main()
{
    float numebr = readNumber();
    cout << "my round is:- " << getRound(numebr) << endl;
    cout << "c++ round is:- " << round(numebr);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
