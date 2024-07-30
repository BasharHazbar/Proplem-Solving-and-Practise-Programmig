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

sDate increaseDateByOneDate(sDate date) {

    if (isLastDayInMonth(date)) {
        if (isLastMonthYear(date.month)) {
            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else {
            date.day = 1;
            date.month++;
        }
    }
    else {
        date.day++;
    }
    return date;
}

sDate increaseDateByXDate(short days,sDate date) {
    for (short i = 1; i <= days; i++) {
        date = increaseDateByOneDate(date);
    }
    return date;
}

sDate increaseDateByOneWeek(sDate date) {
    date = increaseDateByXDate(7, date);
    return date ;
}

sDate increaseDateByXWeek(short weeks, sDate date) {
    for (short i = 1; i <= weeks; i++) {
        date = increaseDateByOneWeek(date);
    };
    return date;
}

sDate increaseDateByOneMonth(sDate date) {
    if (date.month == 12) {
        date.month = 1;
        date.year++;
    }
    else {
        date.month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.month,date.year);
    if (date.day > NumberOfDaysInCurrentMonth) {
        date.day = NumberOfDaysInCurrentMonth;
    }
    return date;
}

sDate increaseDateByXMonth(short months,sDate date) {
    for (short i = 1; i <= months; i++) {
        date = increaseDateByOneMonth(date);
    }
    return date;
}

sDate increaseDateByOneYear(sDate date) {
    date.year++;
    return date;
}

sDate increaseDateByXYear(short years, sDate date) {
    for (short i = 1; i <= years; i++) {
        date = increaseDateByOneYear(date);
    }
    return date;
}

sDate increaseDateByXYearFaster(short years, sDate date) {
    date.year += years;
    return date;
}

sDate increaseDateByOneDecade(sDate date) {
    date = increaseDateByXYear(10,date);
    return date;
}

sDate increaseDateByXDecade(short decades,sDate date) {
    date = increaseDateByXYear(10 * decades, date);
    return date;
}

sDate increaseDateByXDecadeFaster(short decades, sDate date) {
    date.year += decades * 10;
    return date;
}

sDate increaseDateByOneCentury(sDate date) {
    date = increaseDateByXDecade(10, date);
    return date;
}

sDate increaseDateByOneMillennium(sDate date) {
    date = increaseDateByXDecade(100, date);
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

    cout << "\nDate After:- ";
    date = increaseDateByOneDate(date);
    cout << "\n\n01 - adding one day is                   : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByXDate(10,date);
    cout << "02 - adding 10 days is                   : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneWeek(date);
    cout << "03 - adding One Week is                  : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByXWeek(10,date);
    cout << "04 - adding 10 Weeks is                  : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneMonth(date);
    cout << "05 - adding One Month is                 : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneYear(date);
    cout << "06 - adding One Year is                  : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByXYear(10,date);
    cout << "07 - adding 10 Year is                   : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByXYearFaster(10, date);
    cout << "09 - adding 10 Year Faster is            : " << date.day << "/" << date.month << "/" << date.year << endl;
    

    date = increaseDateByOneDecade(date);
    cout << "10 - adding One Decade is                : " << date.day << "/" << date.month << "/" << date.year << endl;


    date = increaseDateByXDecade(10,date);
    cout << "11 - adding 10 Decade is                 : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByXDecadeFaster(10, date);
    cout << "12 - adding 10 Decade faster is          : " << date.day << "/" << date.month << "/" << date.year << endl;


    date = increaseDateByOneCentury(date);
    cout << "12 - adding One Century faster is        : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneMillennium(date);
    cout << "13 - adding One Millennium faster is     : " << date.day << "/" << date.month << "/" << date.year << endl;


    system("pause>0");
    return 0;
}
