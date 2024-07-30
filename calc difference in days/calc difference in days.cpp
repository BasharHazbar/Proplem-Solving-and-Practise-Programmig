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

short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool isLastDayInMonth(sDate date) {
    return date.day == NumberOfDaysInAMonth(date.month, date.year);
}

bool isLastMonthYear(short month) {
    return month == 12;
}

short numberOfDaysFromTheBeginingOfYear(sDate date) {
    short totalDays = 0;
    for (short i = 1; i <= date.month - 1; i++) {
        totalDays += NumberOfDaysInAMonth(i, date.year);
    }
    totalDays += date.day;
    return totalDays;
}

sDate GetDateFromDayInOrderYear(short dayOrderInYear, short year) {
    sDate date;
    short reminderDays = dayOrderInYear;
    short monthDays = 0;

    date.year = year;
    date.month = 1;

    while (true)
    {
        monthDays = NumberOfDaysInAMonth(date.month, year);

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

//short calcDifferenceInDaysForTowDates(sDate date1, sDate date2, bool isIncludeLastDay) {
//    short tempDaysDate1 = 0, tempDaysDate2 = 0, totalDays = 0, resultDifferenceDays = 0;
//
//    if (compareTowDate(date1, date2) == 'S') {
//        if (date1.year == date2.year) {
//            for (short i = date1.month; i < date2.month; i++) {
//                totalDays += NumberOfDaysInAMonth(i, date1.year);
//            }
//            totalDays += date2.day - 1;
//        }
//        else {
//            tempDaysDate1 = numberOfDaysFromTheBeginingOfYear(date1); //1,1,2000,         1,1,2020;
//            tempDaysDate2 = numberOfDaysFromTheBeginingOfYear(date2);
//            date1 = GetDateFromDayInOrderYear(tempDaysDate1, date1.year);
//            while (date1.year < date2.year)
//            {
//                for (short i = 1; i <= 12; i++) {
//                    totalDays += NumberOfDaysInAMonth(i, date1.year);
//                }
//                if (date1.year + 1 == date2.year) {
//                    break;
//                }
//                date1.year++;
//            }
//        }
//
//    }
//    resultDifferenceDays = (totalDays + tempDaysDate2) - tempDaysDate1;
//
//    if (isIncludeLastDay) {
//        return resultDifferenceDays + 1;
//    }
//    else {
//        return resultDifferenceDays;
//    }
//}

sDate increaseOneDate(sDate date) {

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

short calcDifferenceInDaysForTowDates(sDate date1, sDate date2, bool isIncludeLastDay = false) {
    int days = 0;
    while (compareTowDate(date1,date2) == 'S')
    {
        days++;
        date1 = increaseOneDate(date1);
    }
    return isIncludeLastDay ? ++days : days;
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

sDate readFullDate() {
    sDate date;
    date.day = ReadDay();
    date.month = ReadMonth();
    date.year = ReadYear();
    return date;
}


int main() {

    sDate date1 = readFullDate();

    sDate date2 = readFullDate();
    

    cout << "\n\n\nDifference is [" << calcDifferenceInDaysForTowDates(date1,date2) << "] Days (s)";

    cout << "\n\n\nDifference (including end day ) is [" << calcDifferenceInDaysForTowDates(date1, date2,true) << "] Days (s)";




    system("pause>0");
    return 0;
}
