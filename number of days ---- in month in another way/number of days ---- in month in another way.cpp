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

short numberOfDaysInMonth_2(short year, short numberOfMonth) {

    if (numberOfMonth < 1 || numberOfMonth > 12) {
        return 0;
    }
    int numberOfDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    return numberOfMonth == 2 ? (isLeapYear(year) ? 28 : 29) : numberOfDays[numberOfMonth];
}


short numberOfHoursInMonth(short year, short numberOfMonth) {
    return numberOfDaysInMonth_2(year, numberOfMonth) * 24;
}

int numberOfMinutsInMonth(short year, short numberOfMonth) {
    return numberOfHoursInMonth(year, numberOfMonth) * 60;
}

int numberOfSecondsInMonth(short year, short numberOfMonth) {
    return numberOfMinutsInMonth(year, numberOfMonth) * 60;
}

int main()
{
    short year = readYear("enter pleaes the year ? ");
    short month = readYear("enter pleaes the month ? ");

    cout << "number of days    in [" << year << "] is " << numberOfDaysInMonth(year, month) << endl;

    cout << "number of hours   in [" << year << "] is " << numberOfHoursInMonth(year, month) << endl;

    cout << "number of minutes in [" << year << "] is " << numberOfMinutsInMonth(year, month) << endl;

    cout << "number of seconds in [" << year << "] is " << numberOfSecondsInMonth(year, month) << endl;

    system("pause>0");
}
