#include<iostream>
#include<string>
#include <vector>
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
//bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
//{
//    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true :
//        (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
//}
//
//bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
//    return (Date1.year == Date2.year) ?
//        ((Date1.month == Date2.month) ?
//            ((Date1.day == Date2.day) ? true : false) : false) : false;
//}
//
//bool IsDate1AfterDate2(sDate Date1, sDate Date2) {
//    return !IsDate1BeforeDate2(Date1, Date2);
//}
//
//enum enCompateDates { before = -1, equal = 0, after = 1 };
//
//enCompateDates compareTowDates(sDate date1, sDate date2) {
//    if (IsDate1BeforeDate2(date1, date2)) {
//        return enCompateDates::before;
//    }
//    else if (IsDate1EqualDate2(date1, date2)) {
//        return enCompateDates::equal;
//    }
//    //else if (IsDate1AfterDate2(date1, date2)) {
//    //    return 1;
//    //}
//    return enCompateDates::after;
//}
//
//
//bool isOverlapPeriods(sPeriod period1, sPeriod period2) {
//    if (compareTowDates(period1.endDate, period2.startDate) == enCompateDates::before
//        || compareTowDates(period2.endDate, period1.startDate) == enCompateDates::before)
//    {
//        return false;
//    }
//    return true;
//}
//short calcDifferenceInDaysForTowDates(sDate date1, sDate date2, bool isIncludeLastDay = false) {
//    int days = 0;
//    short sawpFlagValue = 1;
//
//    //if (compareTowDates(date1,date2) == enCompateDates::after) {
//    //    swapTowDays(date1, date2);
//    //    sawpFlagValue = -1;
//    //}
//
//    while (compareTowDates(date1, date2) == enCompateDates::before)
//    {
//        days++;
//        date1 = increaseDateByOneDate(date1);
//    }
//
//    return isIncludeLastDay ? ++days * sawpFlagValue : days * sawpFlagValue;
//}
//
//short periodLengthInDays(sPeriod period, bool isIncludeLastDay = false) {
//    return calcDifferenceInDaysForTowDates(period.startDate, period.endDate, isIncludeLastDay);
//}
//bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
//{
//    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true :
//        (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
//}
//
//bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
//    return (Date1.year == Date2.year) ?
//        ((Date1.month == Date2.month) ?
//            ((Date1.day == Date2.day) ? true : false) : false) : false;
//}
//
//bool IsDate1AfterDate2(sDate Date1, sDate Date2) {
//    return !IsDate1BeforeDate2(Date1, Date2);
//}
//
//enum enCompateDates { before = -1, equal = 0, after = 1 };
//
//enCompateDates compareTowDates(sDate date1, sDate date2) {
//    if (IsDate1BeforeDate2(date1, date2)) {
//        return enCompateDates::before;
//    }
//    else if (IsDate1EqualDate2(date1, date2)) {
//        return enCompateDates::equal;
//    }
//    //else if (IsDate1AfterDate2(date1, date2)) {
//    //    return 1;
//    //}
//    return enCompateDates::after;
//}//sDate increaseDateByOneDate(sDate date) {
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
//short calcDifferenceInDaysForTowDates(sDate date1, sDate date2, bool isIncludeLastDay = false) {
//    int days = 0;
//    short sawpFlagValue = 1;
//
//    //if (compareTowDates(date1,date2) == enCompateDates::after) {
//    //    swapTowDays(date1, date2);
//    //    sawpFlagValue = -1;
//    //}
//
//    while (compareTowDates(date1, date2) == enCompateDates::before)
//    {
//        days++;
//        date1 = increaseDateByOneDate(date1);
//    }
//
//    return isIncludeLastDay ? ++days * sawpFlagValue : days * sawpFlagValue;
//}
//
//short periodLengthInDays(sPeriod period, bool isIncludeLastDay = false) {
//    return calcDifferenceInDaysForTowDates(period.startDate, period.endDate, isIncludeLastDay);
//}
//
//bool isDateInPeriodMyLogic(sDate date, sPeriod period) {
//
//    while (!(compareTowDates(period.startDate, period.endDate) == enCompateDates::equal))
//    {
//        period.startDate = increaseDateByOneDate(period.startDate);
//
//        if (compareTowDates(period.startDate, date) == enCompateDates::equal) {
//            return true;
//        }
//    }
//    return false;
//}
//
//bool isDateInPeriod(sDate date, sPeriod period) {
//    return !(compareTowDates(date, period.startDate) == enCompateDates::before
//        ||
//        compareTowDates(date, period.endDate) == enCompateDates::after
//        );
//}
//
//short countLenghtOverlapDays(sPeriod period1, sPeriod period2) {
//
//    int period1Length = periodLengthInDays(period1);
//    int period2Length = periodLengthInDays(period2);
//    short countOverlaps = 0;
//
//    if (period1Length > period2Length)
//    {
//        while (IsDate1BeforeDate2(period1.startDate, period1.endDate)) {
//            if (isDateInPeriod(period1.startDate, period2)) {
//                countOverlaps++;
//            }
//            period1.startDate = increaseDateByOneDate(period1.startDate);
//        }
//    }
//    else
//    {
//        while (IsDate1BeforeDate2(period2.startDate, period2.endDate)) {
//            if (isDateInPeriod(period2.startDate, period1)) {
//                countOverlaps++;
//            }
//            period2.startDate = increaseDateByOneDate(period2.startDate);
//        }
//    }
//    return countOverlaps;
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
//bool isValidDate(sDate date) {// 28
//    short days = NumberOfDaysInMonth(date.month, date.year);
//    cout << "days ==> " << days << endl;
//    if (date.day < 1 || date.day > 31) {
//        return false;
//    }
//    if (date.month < 1 || date.month > 12) {
//        return false;
//    }
//    if (date.day > days) {
//        return false;
//    }
//
//    return true;
//}
//vector <string> splitString(string text, string delim) {
//    short pos = 0;
//    string sWord;
//    vector <string> vString;
//    while ((pos = text.find(delim)) != std::string::npos) {
//        sWord = text.substr(0, pos);
//        if (sWord != "")
//        {
//            vString.push_back(sWord);
//        }
//        text.erase(0, pos + delim.length());
//    }
//    if (text != "")
//    {
//        vString.push_back(text);
//    }
//    return vString;
//}
//
//sDate stringToDate(vector <string> date) {
//    sDate dateFromString;
//    dateFromString.day = stoi(date[0]);
//    dateFromString.month = stoi(date[1]);
//    dateFromString.year = stoi(date[2]);
//    return dateFromString;
//}
//
//string dateToStrig(sDate date) {
//    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
//}
struct sDate {
    short day;
    short month;
    short year;
};


vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord;

    // Use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length()); /* erase() until position and move to the next word. */
    }

    if (S1 != "") {
        vString.push_back(S1); // it adds the last word of the string.
    }

    return vString;
}

string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo) {
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos) {
        S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
        pos = S1.find(StringToReplace); // find next
    }
    return S1;
}

string DateToString(sDate Date) {
    return to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
}

sDate StringToDate(string DateString) {
    sDate Date;
    vector<string> vDate;
    vDate = SplitString(DateString, "/");
    Date.day = stoi(vDate[0]);
    Date.month = stoi(vDate[1]);
    Date.year = stoi(vDate[2]);
    return Date;
}

string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy") {
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.year));
    return FormattedDateString;
}

string ReadStringDate(string Message) {
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}


struct sPeriod {
    sDate startDate;
    sDate endDate;
};


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

sPeriod readPeriod() {
    sPeriod period;
    period.startDate = readFullDate();
    period.endDate = readFullDate();
    return period;
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

string readDateStrig(string message) {
    string dateString;
    cout << message;
    getline(cin >> ws, dateString);
    return dateString;
}


int main() {

    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    sDate Date = StringToDate(DateString);

    cout << "\n" << FormateDate(Date) << "\n";
    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");
    return 0;
}
