// ConsoleApplication13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

enum enOddOrEven {odd = 1, even = 2, all = 3};

int readRangeNumber() {
    int number = 0;
    cout << "enter the number of range 'N': " << endl;
    cin >> number;
    return number;
}

enOddOrEven checkOddOrEven(int number) {
    if (number % 2 == 0)
        return enOddOrEven::even;
    else
        return enOddOrEven::odd;
}

int checkPrnitAllOrEvenOrOdd() {
  
    cout << "enter '1' : odd, '2' : even, '3' : all " << endl;
    int numType = 0;
    cin >> numType;
    cout << "==============>> " << numType;
    if (enOddOrEven::even == (enOddOrEven)numType) {
        return numType;
    }
    else if (enOddOrEven::odd == (enOddOrEven)numType) {
        return numType;
    }
    else {
        return numType;
    }
}

int sumOddAndEvenAndAllAndPrnit(int numType,int number) {
    cout << "by for loop" << endl;
    int sumEven = 0;
    int sumOdd= 0;
    int sumAll = 0;
    for (int i = 1; i <= number; i++) {
        cout << i;
        if (checkOddOrEven(number) == enOddOrEven::even && (enOddOrEven) numType == enOddOrEven::even) {
            cout << i << endl;
            sumEven += i;
        }
        else if (checkOddOrEven(number) == enOddOrEven::odd && (enOddOrEven) numType == enOddOrEven::odd) {
            cout << i << endl;
            sumOdd += i;
        }
        else if ((enOddOrEven) numType == enOddOrEven::all) {
            sumAll += i;
        }
    }
    
    if ((enOddOrEven) numType == enOddOrEven::even) {
        return sumEven;
    }
    else if ((enOddOrEven) numType == enOddOrEven::even) {
        return sumOdd;
    }
    else {
        return sumAll;
    }
}


int main()
{
   cout << sumOddAndEvenAndAllAndPrnit(checkPrnitAllOrEvenOrOdd(), readRangeNumber());
    cout << "Hello World!\n";
}


