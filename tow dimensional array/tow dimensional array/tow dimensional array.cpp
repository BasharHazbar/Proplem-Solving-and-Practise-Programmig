// tow dimensional array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void fillTowDimensionalArrat(int array[10][10], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            array[i][j] = (i + 1) * (j + 1);
        }
    }
}

void printTowDimensionalArrat(int array[10][10], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
           printf("%0*d ", 2, array[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    int array[10][10], lenght = 10;
    fillTowDimensionalArrat(array, lenght);
    printTowDimensionalArrat(array, lenght);
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
