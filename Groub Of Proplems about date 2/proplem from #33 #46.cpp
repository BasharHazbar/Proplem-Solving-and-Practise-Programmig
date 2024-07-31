#include<iostream>
#include<string>
using namespace std;


//short DayOfWeekOrder(short Day, short Month, short Year) {
//    short a, y, m;
//    a = (14 - Month) / 12;
//    y = Year - a;
//    m = Month + (12 * a) - 2;
//    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
//}
//string DayShortName(short DayOfWeekOrder) {
//    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
//    return arrDayNames[DayOfWeekOrder];
//}
//string MonthShortName(short MonthNumber) {
//    string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
//    return Months[MonthNumber - 1];
//}
//short numberOfDaysFromTheBeginingOfYear(short day, short month, short year) {
//    short totalDays = 0;
//    for (short i = 1; i <= month - 1; i++) {
//        totalDays += NumberOfDaysInAMonth(i, year);
//    }
//    totalDays += day;
//    return totalDays;
//}
//
//
//
//sDate addingDaysToDate(sDate date, short numberDaysAdding) {
//    //sDate date;
//    short reminderDays = numberDaysAdding + numberOfDaysFromTheBeginingOfYear(date.day, date.month, date.year);;
//    short monthDays = 0;
//    date.month = 1;
//    while (true)
//    {
//        monthDays = NumberOfDaysInAMonth(date.month, date.year);
//
//        if (reminderDays > monthDays) {
//            reminderDays -= monthDays;
//            date.month++;
//
//            if (date.month > 12) {
//                date.month = 1;
//                date.year++;
//            }
//        }
//        else {
//            date.day = reminderDays;
//            break;
//        }
//
//    }
//
//    return date;
//}
//void PrintMonthCalendar(short Month, short Year) {
//    int NumberOfDays;
//    int current = DayOfWeekOrder(1, Month, Year);
//    NumberOfDays = NumberOfDaysInAMonth(Month, Year);
//
//    printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
//    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
//
//    int i;
//    for (i = 0; i < current; i++)
//        printf("     ");
//
//    for (int j = 1; j <= NumberOfDays; j++) {
//        printf("%5d", j);
//        if (++i == 7) {
//            i = 0;
//            printf("\n");
//        }
//    }
//
//    printf("\n  _________________________________\n");
//}
//bool isDate1BeforeDate2(sDate date1, sDate date2) {
//    return date1.year > date2.year ? true :
//        date1.month > date2.month ? true :
//        date1.day > date2.day ? true : false;  
//}
//
//bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
//{
//    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true :
//        (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
//}
//short ReadNumberDays() {
//    short NumberDays;
//    cout << "\nPlease enter a number of days ? ";
//    cin >> NumberDays;
//    return NumberDays;
//}
//short numberOfDaysFromTheBeginingOfYear(sDate date) {
//    short totalDays = 0;
//    for (short i = 1; i <= date.month - 1; i++) {
//        totalDays += NumberOfDaysInAMonth(i, date.year);
//    }
//    totalDays += date.day;
//    return totalDays;
//} 
//short NumberOfDaysInYear(short year) {
//    return isLeapYear(year) ? 366 : 365;
//}
//void swapTowDays(sDate& date1, sDate& date2) {
//    sDate tempDate;
//
//    tempDate.day = date1.day;
//    tempDate.month = date1.month;
//    tempDate.year = date1.year;
//
//    date1.day = date2.day;
//    date1.month = date2.month;
//    date1.year = date2.year;
//
//    date2.day = tempDate.day;
//    date2.month = tempDate.month;
//    date2.year = tempDate.year;
//}
//short calcDifferenceInDaysForTowDates(sDate date1, sDate date2, bool isIncludeLastDay = false) {
//    int days = 0;
//    short sawpFlagValue = 1;
//
//    if (!(compareTowDate(date1, date2) == 'S')) {
//        swapTowDays(date1, date2);
//        sawpFlagValue = -1;
//    }
//
//    while (compareTowDate(date1, date2) == 'S')
//    {
//        days++;
//        date1 = increaseDateByOneDate(date1);
//    }
//
//    return isIncludeLastDay ? ++days * sawpFlagValue : days * sawpFlagValue;
//}


struct sDate {
    short day;
    short month;
    short year;
};
char compareTowDate(sDate date_1, sDate date_2) {
    char resultCompare = ' '; // B ==> big, S ==> small, E ==> Equal
    if (date_1.year > date_2.year) {
        resultCompare = 'B';
    }
    else if (date_1.year < date_2.year) {
        resultCompare = 'S';
    }
    if (date_1.year == date_2.year) {
        if (date_1.month > date_2.month) {
            resultCompare = 'B';
        }
        else if (date_1.month < date_2.month) {
            resultCompare = 'S';
        }
    }
    if (date_1.year == date_2.year && date_1.month == date_2.month) {
        if (date_1.day > date_2.day) {
            resultCompare = 'B';
        }
        else if (date_1.day < date_2.day) {
            resultCompare = 'S';
        }
        else {
            resultCompare = 'E';
        }
    }

    return resultCompare;
}

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInYear(short year) {
    return isLeapYear(year) ? 366 : 365;
}

short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;
    int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month];
}

bool isLastDayInMonth(sDate date) {
    return date.day == NumberOfDaysInMonth(date.month, date.year);
}

bool isLastMonthYear(short month) {
    return month == 12;
}

sDate GetDateFromDayInOrderYear(short dayOrderInYear, short year) {
    sDate date;
    short reminderDays = dayOrderInYear;
    short monthDays = 0;

    date.year = year; 
    date.month = 1;

    while (true)
    {
        monthDays = NumberOfDaysInMonth(date.month, year);

        if (reminderDays > monthDays) {
            reminderDays -= monthDays;
            date.month++;
        }
        else {
            date.day = reminderDays;
            break;
        }

    }
    return date;
}

sDate decreaseDateByOneDay(sDate date) {
    if (date.day == 1 && date.month == 1) {
        date.month = 12;
        date.year--;
        date.day = 31;

    }
    else if (date.day == 1) {
        date.month--;
        date.day = NumberOfDaysInMonth(date.month, date.year);
    }
    else {
        date.day--;
    }
    return date;
}

sDate decreaseDateByXDay(short days, sDate date) {
    for (short i = 1; i <= days; i++) {
        date = decreaseDateByOneDay(date);
    }
    return date;

}

sDate decreaseDateByOneWeek(sDate date) {
    date = decreaseDateByXDay(7, date);
    return date;
}

sDate decreaseDateByXWeek(short weeks, sDate date) {
    for (short i = 1; i <= weeks; i++) {
        date = decreaseDateByOneWeek(date);
    };
    return date;
}

sDate decreaseDateByOneMonth(sDate date) {
    if (date.month == 1) {

        date.month = 12;
        date.year--;
    }
    else {
        date.month--;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.month, date.year);
    if (date.day > NumberOfDaysInCurrentMonth) {
        date.day = NumberOfDaysInCurrentMonth;
    }
    return date;
}  

sDate decreaseDateByXMonth(short months, sDate date) {
    for (short i = 1; i <= months; i++) {
        date = decreaseDateByOneMonth(date);
    }
    return date;
}

sDate decreaseDateByOneYear(sDate date) {
    date.year--;
    return date;
}

sDate decreaseDateByXYear(short years, sDate date) {
    for (short i = 1; i <= years; i++) {
        date = decreaseDateByOneYear(date);
    }
    return date;
}

sDate decreaseDateByXYearFaster(short years, sDate date) {
    date.year -= years;
    return date;
}

sDate decreaseDateByOneDecade(sDate date) {
    date = decreaseDateByXYear(10, date);
    return date;
}

sDate decreaseDateByXDecade(short decades, sDate date) {
    date = decreaseDateByXYear(10 * decades, date);
    return date;
}

sDate decreaseDateByXDecadeFaster(short decades, sDate date) {
    date.year -= decades * 10;
    return date;
}

sDate decreaseDateByOneCentury(sDate date) {
    date = decreaseDateByXDecade(10, date);
    return date;
}

sDate decreaseDateByOneMillennium(sDate date) {
    date = decreaseDateByXDecade(100, date);
    return date;
}


//sDate increaseDateByXMonth(sDate date, short x) {
//    date = increaseDateByOneMonth(date,x);
//    return date;
//}

short ReadMonth() {
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}

short ReadDay() {
    short day;
    cout << "\nPlease enter a day? ";
    cin >> day;
    return day;
}

sDate readFullDate() {
    sDate date;
    date.day = ReadDay();
    date.month = ReadMonth();
    date.year = ReadYear();
    return date;
}

sDate getSystemDate() {
    sDate date;

    time_t t = time(0);
    tm* now = new tm;
    localtime_s(now, &t);

    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;

    return date;
}

int main() {

    sDate date = readFullDate();

    cout << "after decrease :- \n";
    date = decreaseDateByOneDay(date);
    cout << "\n\n01 - substracting one day is                   : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByXDay(10,date);
    cout << "02 - substracting 10 day is                   : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneWeek(date);
    cout << "03 - substracting One Week is                  : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByXWeek(10, date);
    cout << "04 - substracting 10 Weeks is                  : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneMonth(date);
    cout << "05 - substracting One Month is                 : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneYear(date);
    cout << "06 - substracting One Year is                  : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByXYear(10, date);
    cout << "07 - substracting 10 Year is                   : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByXYearFaster(10, date);
    cout << "09 - substracting 10 Year Faster is            : " << date.day << "/" << date.month << "/" << date.year << endl;


    date = decreaseDateByOneDecade(date);
    cout << "10 - substracting One Decade is                : " << date.day << "/" << date.month << "/" << date.year << endl;


    date = decreaseDateByXDecade(10, date);
    cout << "11 - substracting 10 Decade is                 : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByXDecadeFaster(10, date);
    cout << "12 - substracting 10 Decade faster is          : " << date.day << "/" << date.month << "/" << date.year << endl;


    date = decreaseDateByOneCentury(date);
    cout << "12 - substracting One Century faster is        : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneMillennium(date);
    cout << "13 - substracting One Millennium faster is     : " << date.day << "/" << date.month << "/" << date.year << endl;


    system("pause>0");
    return 0;
}
