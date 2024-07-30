// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
enum enPassFail { pass = 1, fail = 2};
float readMark() {
    float mark;
    cout << "enter the number:- " << endl;
    cin >> mark;
    return mark;
}

enPassFail checkMark(float mark) {
    if (mark >= 50)
        return enPassFail::pass;
    else
        return enPassFail::fail;
}

void printResult(float mark) {
    cout << "mark:- " << mark << endl;
    if (checkMark(mark) == enPassFail::pass)
        cout << "you are pass";
    else
        cout << "you are faild";
}

int main()
{
    printResult(readMark());
}
 