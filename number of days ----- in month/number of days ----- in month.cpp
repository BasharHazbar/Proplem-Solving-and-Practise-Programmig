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

short readMonth(string message) {
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



short numberOfDaysInMonth(short year, short numberOfMonth) {

    if (numberOfMonth < 1 || numberOfMonth > 12) {
        return 0;
    }
    else if (numberOfMonth == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    
    short arrayNumberOfMonth[7] = { 1,3,5,7,8,10,12 };

    for (short i = 0; i < 7; i++) {
        if (numberOfMonth == arrayNumberOfMonth[i]) {
            return 31;
        }
    }
    return 30;
}

short numberOfHoursInMonth(short year, short numberOfMonth) {
    return numberOfDaysInMonth(year, numberOfMonth) * 24;
}

int numberOfMinutsInMonth(short year, short numberOfMonth) {
    return numberOfHoursInMonth(year,numberOfMonth) * 60;
}

int numberOfSecondsInMonth(short year, short numberOfMonth) {
    return numberOfMinutsInMonth(year,numberOfMonth) * 60;
}

int main()
{
    short year = readYear("enter pleaes the year ? ");
    short month = readYear("enter pleaes the month ? ");

    cout << "number of days    in [" << year << "] is " << numberOfDaysInMonth(year,month) << endl;

    cout << "number of hours   in [" << year << "] is " << numberOfHoursInMonth(year, month) << endl;

    cout << "number of minutes in [" << year << "] is " << numberOfMinutsInMonth(year, month) << endl;

    cout << "number of seconds in [" << year << "] is " << numberOfSecondsInMonth(year, month) << endl;

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
