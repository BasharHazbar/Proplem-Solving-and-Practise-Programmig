// function overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int mySum(int x,int y) {
    return x + y;
}

double mySum(int x, int y, double r, double m) {
    return x + y + r + m;
}


double mySum(int x, int y, double d) {
    return x + y + d;
}


int mySum(int x, int y, int l, int s) {
    return x + y + l + s;
}

int main()
{
    std::cout << "my sum:- " << mySum(1,2) << "\n";
    std::cout << "my sum:- " << mySum(1, 2,4,5) << "\n";
    std::cout << "my sum:- " << mySum(1, 2,3.5,3.5)<< "\n";
    std::cout << "my sum:- " << mySum(1, 2,34.6) << "\n";
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
