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
// 
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
//bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
//{
//    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true :
//        (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
//}
//
//int GetDifferenceInDays(sDate date1, sDate date2, bool IncludeEndDay = false) { 
//    int Days = 0;
//    while (IsDate1BeforeDate2(date1, date2))
//    { Days++; date1 = IncreaseDateByOneDay(date1); 
//    }
//    return IncludeEndDay ? ++Days : Days; 
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
//char compareTowDate(sDate date_1, sDate date_2) {
//    char resultCompare = ' '; // B ==> big, S ==> small, E ==> Equal
//    if (date_1.year > date_2.year) {
//        resultCompare = 'B';
//    }
//    else if (date_1.year < date_2.year) {
//        resultCompare = 'S';
//    }
//    if (date_1.year == date_2.year) {
//        if (date_1.month > date_2.month) {
//            resultCompare = 'B';
//        }
//        else if (date_1.month < date_2.month) {
//            resultCompare = 'S';
//        }
//    }
//    if (date_1.year == date_2.year && date_1.month == date_2.month) {
//        if (date_1.day > date_2.day) {
//            resultCompare = 'B';
//        }
//        else if (date_1.day < date_2.day) {
//            resultCompare = 'S';
//        }
//        else {
//            resultCompare = 'E';
//        }
//    }
//
//    return resultCompare;
//}
//sDate increaseDateByOneDate(sDate date) {
//
//    if (isLastDayInMonth(date)) {
//        if (isLastMonthYear(date.month)) {
//            date.day = 1;
//            date.month = 1;
//            date.year++;
//        }
//        else {
//            date.day = 1;
//            date.month++;
//        }
//    }
//    else {
//        date.day++;
//    }
//    return date;
//}
//}
//
//bool isLeapYear(short Year) {
//    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
//}
//
//short NumberOfDaysInYear(short year) {
//    return isLeapYear(year) ? 366 : 365;
//}
//
//short NumberOfDaysInMonth(short Month, short Year) {
//    if (Month < 1 || Month > 12)
//        return 0;
//    int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month];
//}
//
//bool isLastDayInMonth(sDate date) {
//    return date.day == NumberOfDaysInMonth(date.month, date.year);
//}
//
//bool isLastMonthYear(short month) {
//    return month == 12;
//}
//
//short DayOfWeekOrder(short Day, short Month, short Year) {
//    short a, y, m;
//    a = (14 - Month) / 12;
//    y = Year - a;
//    m = Month + (12 * a) - 2;
//    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
//}
//
//short DayOfWeekOrder(sDate date) {
//    return DayOfWeekOrder(date.day, date.month, date.year);
//}
//
//string nameOrderDay(short orderOfDay) {
//    string daysOfWeek[7] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };
//    return daysOfWeek[orderOfDay];
//}
//
//sDate GetDateFromDayInOrderYear(short dayOrderInYear, short year) {
//    sDate date;
//    short reminderDays = dayOrderInYear;
//    short monthDays = 0;
//
//    date.year = year;
//    date.month = 1;
//
//    while (true)
//    {
//        monthDays = NumberOfDaysInMonth(date.month, year);
//
//        if (reminderDays > monthDays) {
//            reminderDays -= monthDays;
//            date.month++;
//        }
//        else {
//            date.day = reminderDays;
//            break;
//        }
//
//    }
//    return date;
//}
//
//short numberOfDaysFromTheBeginingOfYear(sDate date) {
//    short totalDays = 0;
//    for (short i = 1; i <= date.month - 1; i++) {
//        totalDays += NumberOfDaysInMonth(i, date.year);
//    }
//    totalDays += date.day;
//    return totalDays;
//}
//
//sDate decreaseDateByOneDay(sDate date) {
//    if (date.day == 1 && date.month == 1) {
//        date.month = 12;
//        date.year--;
//        date.day = 31;
//
//    }
//    else if (date.day == 1) {
//        date.month--;
//        date.day = NumberOfDaysInMonth(date.month, date.year);
//    }
//    else {
//        date.day--;
//    }
//    return date;
//}
//
//void printDateDay(sDate date, short dayOfWeekOrder) {
//
//    /*   cout << "==>>>>> " << DayOfWeekOrder(date) << endl;*/
//
//    string nameOfDay = nameOrderDay(dayOfWeekOrder);
//
//    cout << "Today is " << nameOfDay << " , " << date.day << "/" << date.month << "/" << date.year;
//}
//
//bool isEndOfWeek(short dayOfWeekOrder) {
//    return dayOfWeekOrder == 6;
//}
//
//bool isWeekEnd(short dayOfWeekOrder) {
//    return (dayOfWeekOrder == 5 || dayOfWeekOrder == 6);
//}
//
//bool isBusinessDay(short dayOfWeekOrder) {
//    //return (dayOfWeekOrder != 5 && dayOfWeekOrder != 6);
//    //return (dayOfWeekOrder <= 5 && dayOfWeekOrder >= 4);
//    return !isWeekEnd(dayOfWeekOrder);
//}
//
//short daysUntillTheEndOfWeek(short dayOfWeekOrder) {
//    return 7 - (dayOfWeekOrder + 1);
//}
//
//short daysUntillTheEndOfMonth(sDate date) {
//    return NumberOfDaysInMonth(date.month, date.year) - date.day;
//}
//
//short daysUntillTheEndOfYear(sDate date) {
//    return NumberOfDaysInYear(date.year) - numberOfDaysFromTheBeginingOfYear(date);
//}
//bool isLeapYear(short Year) {
//    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
//}
//
//short NumberOfDaysInMonth(short Month, short Year) {
//    if (Month < 1 || Month > 12)
//        return 0;
//    int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month];
//}
//
//bool isLastDayInMonth(sDate date) {
//    return date.day == NumberOfDaysInMonth(date.month, date.year);
//}
//
//bool isLastMonthYear(short month) {
//    return month == 12;
//}
//
//sDate increaseDateByOneDate(sDate date) {
//
//    if (isLastDayInMonth(date)) {
//        if (isLastMonthYear(date.month)) {
//            date.day = 1;
//            date.month = 1;
//            date.year++;
//        }
//        else {
//            date.day = 1;
//            date.month++;
//        }
//    }
//    else {
//        date.day++;
//    }
//    return date;
//}
//
//char compareTowDate(sDate date_1, sDate date_2) {
//    char resultCompare = ' '; // B ==> big, S ==> small, E ==> Equal
//    if (date_1.year > date_2.year) {
//        resultCompare = 'B';
//    }
//    else if (date_1.year < date_2.year) {
//        resultCompare = 'S';
//    }
//    if (date_1.year == date_2.year) {
//        if (date_1.month > date_2.month) {
//            resultCompare = 'B';
//        }
//        else if (date_1.month < date_2.month) {
//            resultCompare = 'S';
//        }
//    }
//    if (date_1.year == date_2.year && date_1.month == date_2.month) {
//        if (date_1.day > date_2.day) {
//            resultCompare = 'B';
//        }
//        else if (date_1.day < date_2.day) {
//            resultCompare = 'S';
//        }
//        else {
//            resultCompare = 'E';
//        }
//    }
//    return resultCompare;
//}
//
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
//
//bool isWeekEnd(short dayOfWeekOrder) {
//    return (dayOfWeekOrder == 5 || dayOfWeekOrder == 6);
//}
//
//short DayOfWeekOrder(short Day, short Month, short Year) {
//    short a, y, m;
//    a = (14 - Month) / 12;
//    y = Year - a;
//    m = Month + (12 * a) - 2;
//    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
//}
//
//short DayOfWeekOrder(sDate date) {
//    return DayOfWeekOrder(date.day, date.month, date.year);
//}
//
//short calcDifferenceInDaysForTowDates(sDate date1, sDate date2, bool isIncludeLastDay = false, bool isFindNumberVacation = false) {
//    int days = 0;
//    short sawpFlagValue = 1;
//
//    if (!(compareTowDate(date1, date2) == 'S')) {
//        swapTowDays(date1, date2);
//        sawpFlagValue = -1;
//    }
//
//
//    while (compareTowDate(date1, date2) == 'S')
//    {
//        if (isFindNumberVacation) {
//            if (!isWeekEnd(DayOfWeekOrder(date1))) {
//                days++;
//            }
//            date1 = increaseDateByOneDate(date1);
//        }
//        else {
//            days++;
//            date1 = increaseDateByOneDate(date1);
//        }
//
//    }
//
//    return isIncludeLastDay ? ++days * sawpFlagValue : days * sawpFlagValue;
//}
//
//short calcVacationDyas(sDate dateFrom, sDate dateTo) {
//    short daysCount = 0;
//    while (compareTowDate(dateFrom, dateTo) == 'S')
//    {
//        if (!isWeekEnd(DayOfWeekOrder(dateFrom)))
//            daysCount++;
//        dateFrom = increaseDateByOneDate(dateFrom);
//    }
//    return daysCount;
//}
//
//sDate calcReturnVacationDate(sDate date, short numberVacation) {
//    for (short i = 0; i < numberVacation; i++) {
//        if (isWeekEnd(DayOfWeekOrder(date))) {
//            i--;
//        }
//        date = increaseDateByOneDate(date);
//    }
//    return date;
//}
//
//string nameOrderDay(short orderOfDay) {
//    string daysOfWeek[7] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };
//    return daysOfWeek[orderOfDay];
//}
//
//void printDateDay(sDate date, short dayOfWeekOrder, string meassage) {
//    cout << meassage << nameOrderDay(dayOfWeekOrder) << " , " << date.day << "/" << date.month << "/" << date.year;
//}

struct sDate {
    short day;
    short month;
    short year;
};
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true :
        (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
    return (Date1.year == Date2.year) ?
        ((Date1.month == Date2.month) ?
            ((Date1.day == Date2.day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2) {
    return !IsDate1BeforeDate2(Date1, Date2);
}

enum enCompateDates { before = -1, equal = 0, after = 1 };

enCompateDates compareTowDates(sDate date1, sDate date2) {
    if (IsDate1BeforeDate2(date1, date2)) {
        return enCompateDates::before;
    }
    else if (IsDate1EqualDate2(date1, date2)) {
        return enCompateDates::equal;
    }
    //else if (IsDate1AfterDate2(date1, date2)) {
    //    return 1;
    //}
    return enCompateDates::after;
}


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

short ReadVacationDays() {
    short day;
    cout << "\nplease enter the vacation days? ";
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


    sDate date1 = readFullDate();

    sDate date2 = readFullDate();

    cout << "\n\nthe Compare Result: " << compareTowDates(date1, date2);


    //sDate date_1 = readFullDate();

    //short orderDay = DayOfWeekOrder(date_1.year, date_1.month, date_1.day);

    //cout << "Date             : " << date_1.day << "/" << date_1.month << "/" << date_1.year << endl;
    //cout << "Order day        : " << orderDay << endl;
    //cout << "Day Name         : " << nameOrderDay(orderDay);

    system("pause>0");
    return 0;
}
