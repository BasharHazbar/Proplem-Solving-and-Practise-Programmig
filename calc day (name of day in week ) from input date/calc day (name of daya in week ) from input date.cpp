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

short readDay(string message) {
    cout << message;
    short number;
    cin >> number;
    return number;
}


short calcOrderDay(short year, short month, short day) {
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + 12 * a - 2;
    
    return (day + y + (y / 4) + (y / 100) + (y / 100) + (31 * m / 12)) % 7;
}

string nameOrderDay(short orderOfDay) {
    string daysOfWeek[8] = { "", "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };
    return daysOfWeek[orderOfDay];
}



//bool isLeapYear(int year) {
//
//    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
//}
//
//short numberOfDaysInMonth(short year, short numberOfMonth) {
//
//    if (numberOfMonth < 1 || numberOfMonth > 12) {
//        return 0;
//    }
//    else if (numberOfMonth == 2) {
//        return isLeapYear(year) ? 29 : 28;
//    }
//
//    short arrayNumberOfMonth[7] = { 1,3,5,7,8,10,12 };
//
//    for (short i = 0; i < 7; i++) {
//        if (numberOfMonth == arrayNumberOfMonth[i]) {
//            return 31;
//        }
//    }
//    return 30;
//}
//



int main()
{
    short year = readYear("enter pleaes the year ? ");
    short month = readYear("enter pleaes the month ? ");
    short day = readDay("enter pleaes the day ? ");
    short orderDay = calcOrderDay(year, month, day);

    cout << "Date             : " << day << "/" << month << "/" << year << endl;
    cout << "Order day        : " << orderDay << endl;
    cout << "Day Name         : " << nameOrderDay(orderDay);





    system("pause>0");
}
