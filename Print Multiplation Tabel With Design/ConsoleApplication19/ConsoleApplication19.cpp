// ConsoleApplication19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


void printTheHeaderOfTheTable() {
    cout << "\t\t\t\tMultiplication tabel from 1 to 100\n\n\t";
    for (int i = 1; i <= 10; i++) {
        cout << "\t" << i;
    }
    cout << "\n---------------------------------------------------------------------------------------------------\n";
}

string seprateCulomn(int i) {
    if (i == 10) {
        return "    |";
    }
    else {
        return "     |";
    }
}

void printFooterOfMultiPliactionTabel() {
    printTheHeaderOfTheTable();
    for (int i = 1; i <= 10; i++) {
        cout << "  " << i << seprateCulomn(i) << "\t";
        for (int j = 1; j <= 10; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}


int main()
{
    printFooterOfMultiPliactionTabel();
    return 0;
}