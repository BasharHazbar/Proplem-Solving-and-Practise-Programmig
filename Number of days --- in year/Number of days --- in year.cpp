// is it a leap year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

short readYear(string message) {
    cout << message;
    short number;
    cin >> number;
    return number;
}

//bool isLeapYear(short year) {
//    if (year % 400 == 0) {
//        return true;
//    }
//    if (year % 4 == 0 && year % 100 != 0) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}

bool isLeapYear(int year) {

    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short numberOfDaysInyear(short year) {
    return isLeapYear(year) ? 366 : 365;
}

short numberOfHoursInYear(short year) {
    return numberOfDaysInyear(year) * 24;
}

int numberOfMinutesInYear(short year) {
    return numberOfHoursInDays(year) * 60;
}

int numberOfSecondsInYear(short year) {
    return numberOfMinutesInDays(year) * 60;
}

int main()
{
    short year = readYear("enter pleaes the year ? ");
     
    cout << "number of days    in [" << year << "] is " << numberOfDaysInyear(year) << endl;

    cout << "number of hours   in [" << year << "] is " << numberOfHoursInYear(year) << endl;

    cout << "number of minutes in [" << year << "] is " << numberOfMinutesInYear(year) << endl;

    cout << "number of seconds in [" << year << "] is " << numberOfSecondsInYear(year) << endl;

    system("pause>0");
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
