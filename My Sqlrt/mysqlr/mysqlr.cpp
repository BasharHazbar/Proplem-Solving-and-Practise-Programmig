// round Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


float readNumber() {
    float number = 0;
    cout << "enter a number to Sqrt it:- " << endl;
    cin >> number;
    return number;
}

//float getFractionPart(float number) {
//    return number - (int)number;
//}

float myPow(float number, int n) {
    float power = number;
    for (int i = 0; i <= .5; i++) {
        power *= number;
    }
    return power;
}

float mySqrt(float number) {
    return pow(number, 0.5);
}

int main()
{
    float numebr = readNumber();
    cout << "my Sqrt is:-  " << mySqrt(numebr) << endl;
    cout << "c++ Sqrt is:-  " << sqrt(numebr);
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
