#include<iostream>
#include<string>
using namespace std;

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInYear(short year) {
    return isLeapYear(year) ? 366 : 365;
}

struct sDate {
    short day;
    short month;
    short year;
};

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

short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

//string MonthShortName(short MonthNumber) {
//    string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
//    return Months[MonthNumber - 1];
//}

short numberOfDaysFromTheBeginingOfYear(short day, short month, short year) {
    short totalDays = 0;
    for (short i = 1; i <= month - 1; i++) {
        totalDays += NumberOfDaysInAMonth(i, year);
    }
    totalDays += day;
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


sDate addingDaysToDate(sDate date, short numberDaysAdding) {
    //sDate date;
    short reminderDays = numberDaysAdding + numberOfDaysFromTheBeginingOfYear(date.day, date.month, date.year);;
    short monthDays = 0;
    date.month = 1;
    while (true)
    {
        monthDays = NumberOfDaysInAMonth(date.month, date.year);

        if (reminderDays > monthDays) {
            reminderDays -= monthDays;
            date.month++;

            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        }
        else {
            date.day = reminderDays;
            break;
        }
       
    }

    return date;
}

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


short ReadNumberDays() {
    short NumberDays;
    cout << "\nPlease enter a number of days ? ";
    cin >> NumberDays;
    return NumberDays;
}

int main() {

    sDate date = readFullDate();
    short NumberDays = ReadNumberDays();



    //short numberOfDays = numberOfDaysFromTheBeginingOfYear(day, month, year);
    sDate Date = addingDaysToDate(date,NumberDays);

    cout << "\n\nDate after adding  [" << NumberDays << "] is " << Date.day << "/" << Date.month << "/" << Date.year;


    system("pause>0");
    return 0;
}
