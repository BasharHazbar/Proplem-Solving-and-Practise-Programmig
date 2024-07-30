// all word from A to Z.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// trails 

#include <iostream>
#include <string>

using namespace std;

string readPassword(string message) {
    string password = "";
    do {
        cout << message << endl;
        cin >> password;
    } while (password == "");
    return password;
}

bool guessPassword(string mainWord) {
    string word = "";
    short counter = 0;
    for (short i = 65; i <= 90; i++) {
        for (short j = 65; j <= 90; j++) {
            for (short x = 65; x <= 90; x++) {
                word = word + char(i) + char(j) + char(x);
                counter++;
                cout << "trail [" << counter << "]: " << word << endl;
                if (word == mainWord) {
                    //i = j = x = 10000;
                    //break;
                    cout << "the password is " << word << endl;
                    cout << "found after " << counter << " trail(s)";
                    return true;
                }
                word = "";
            }
        }
        cout << "\n-----------------------------------------\n";
    }
    return false;
}

int main()
{
    guessPassword(readPassword("enter a password to check:- "));
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
