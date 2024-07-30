#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class clsDate
{
private:
	short day;
	short month;
	short year;

public:
	clsDate() {
		time_t t = time(0);
		tm* now = new tm;
		localtime_s(now, &t);
		
		day = now->tm_mday;
		month = now->tm_mon + 1;
		year = now->tm_year + 1900;
	}
	clsDate(string date) {
		vector <string> splitDate = split(date,"/");
		this->day = stoi(splitDate[0]);
		this->month = stoi(splitDate[1]);
		this->year = stoi(splitDate[2]);
	}
	clsDate(short day, short month, short year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	clsDate(short numberOfdayInYear, short year) {
		*this = GetDateFromDayInOrderYear(numberOfdayInYear,year);

	}

	static short DayOfWeekOrderInDate(clsDate date) {
		short a, y, m;
		a = (14 - date.month) / 12;
		y = date.year - a;
		m = date.month + (12 * a) - 2;
		return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrderInDate() {
		return DayOfWeekOrderInDate(*this);
	}

	static string DayShortName(short DayOfWeekOrder) {
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}
	string DayShortName() {
		return DayShortName(day);
	}

	static string MonthShortName(short MonthNumber) {
		string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return Months[MonthNumber - 1];
	}

	string MonthShortName() {
		return MonthShortName(month);
	}

	static bool isDate1BeforeDate2(clsDate date1, clsDate date2){
    return  (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true :
        (date1.month == date2.month ? date1.day < date2.day : false)) : false);
	}

	bool isDate1BeforeDate2(clsDate date2) {
		return isDate1BeforeDate2(*this, date2);
	}

	static bool isDate1EqualDate2(clsDate date1, clsDate date2) {
		return (date1.year == date2.year) ?
			((date1.month == date2.month) ?
				((date1.day == date2.day) ? true : false) : false) : false;
	}

	bool isDate1EqualDate2(clsDate date) {
		return isDate1EqualDate2(*this, date);
	}

	static bool IsDate1AfterDate2(clsDate date1, clsDate date2) {
		return !isDate1BeforeDate2(date1, date2);
	}

	bool IsDate1AfterDate2(clsDate date1) {
		return !isDate1BeforeDate2(date1);
	}

	static bool isLeapYear(short Year) {
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	bool isLeapYear() {
		return isLeapYear(year);
	}

	static short NumberOfDaysInMonth(short Month, short Year) {
		if (Month < 1 || Month > 12)
			return 0;
		int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month];
	}

	static string nameOrderDay(short orderOfDay) {
		string daysOfWeek[7] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };
		return daysOfWeek[orderOfDay];
	}

	string nameOrderDay() {
		return nameOrderDay();
	}

	short NumberOfDaysInMonth() {
		return NumberOfDaysInMonth(month,year);
	}

	static bool isLastDayInMonth(clsDate date) {
		return date.day == NumberOfDaysInMonth(date.month, date.year);
	}

	static bool isLastMonthYear(short month) {
		return month == 12;
	}

	bool isLastMonthYear() {
		return isLastMonthYear(month);
	}

	static clsDate increaseDateByOneDate(clsDate date) {

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

	void increaseDateByOneDate() {
		*this = increaseDateByOneDate(*this);
	}

	static clsDate decreaseDateByOneDay(clsDate date) {
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

	void decreaseDateByOneDay() {
		*this = decreaseDateByOneDay(*this);
	}

	static short DayOrderInWeek(short Day, short Month, short Year) {
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOrderInWeek() {
		return DayOrderInWeek(day,month,year);
	}

	//static string MonthShortName(short MonthNumber) {
	//	string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	//	return Months[MonthNumber - 1];
	//}

	//string MonthShortName() {
	//	return MonthShortName(month);
	//}

	static void PrintMonthCalendar(short Month, short Year) {
		int NumberOfDays;
		int current = DayOrderInWeek(1, Month, Year);

		NumberOfDays = NumberOfDaysInMonth(Month, Year);

		printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++) {
			printf("%5d", j);
			if (++i == 7) {
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");
	}

	static void PrintYearCalendar(short year) {
		for (short i = 1; i <= 12; i++) {
			PrintMonthCalendar(i,year);
		}
	}

	void PrintYearCalendar() {
		PrintYearCalendar(year);
	}

	void PrintMonthCalendar() {
		PrintMonthCalendar(month, year);
	}

	static short numberOfDaysFromTheBeginingOfYear(clsDate date) {
		short totalDays = 0;
		for (short i = 1; i <= date.month - 1; i++) {
			totalDays += NumberOfDaysInMonth(i, date.year);
		}
		totalDays += date.day;
		return totalDays;
	}

	short numberOfDaysFromTheBeginingOfYear() {
		return numberOfDaysFromTheBeginingOfYear(*this);
	}

	clsDate addingDaysToDate(clsDate date, short numberDaysAdding) {
		//sDate date;
		short reminderDays = numberDaysAdding + numberOfDaysFromTheBeginingOfYear(date);;
		short monthDays = 0;
		date.month = 1;
		while (true)
		{
			monthDays = NumberOfDaysInMonth(date.month, date.year);

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

	void addingDaysToDate(int numberDays) {
		*this = addingDaysToDate(*this,numberDays);
	}

	static bool isValid(clsDate date) {
		short days = NumberOfDaysInMonth(date.month, date.year);
		if (date.day < 1 || date.day > 31) {
			return false;
		}
		if (date.month < 1 || date.month > 12) {
			return false;
		}
		if (date.day > days) {
			return false;
		}

		return true;
	}

	bool isValid() {
		return isValid(*this);
	}

	static void swapTowDays(clsDate& date1, clsDate& date2) {
		clsDate tempDate;

		tempDate.day = date1.day;
		tempDate.month = date1.month;
		tempDate.year = date1.year;

		date1.day = date2.day;
		date1.month = date2.month;
		date1.year = date2.year;

		date2.day = tempDate.day;
		date2.month = tempDate.month;
		date2.year = tempDate.year;
	}

	void swapTowDays(clsDate date) {
		swapTowDays(*this, date);
	}

	enum enCompateDates { before = -1, equal = 0, after = 1 };

	static enCompateDates compareTowDates(clsDate date1, clsDate date2) {
		if (isDate1BeforeDate2(date1, date2)) {
			return enCompateDates::before;
		}
		else if (isDate1EqualDate2(date1, date2)) {
			return enCompateDates::equal;
		}
		//else if (IsDate1AfterDate2(date1, date2)) {
		//    return 1;
		//}
		return enCompateDates::after;
	}

	enCompateDates compareTowDates(clsDate date2) {
		return compareTowDates(*this,date2);
	}

	static short calcDifferenceInDaysForTowDates(clsDate date1, clsDate date2, bool isIncludeLastDay = false) {
		int days = 0;
		short sawpFlagValue = 1;

		if (compareTowDates(date1,date2) == enCompateDates::after) {
			swapTowDays(date1, date2);
			sawpFlagValue = -1;
		}

		while (compareTowDates(date1, date2) == enCompateDates::before)
		{
			days++;
			date1 = increaseDateByOneDate(date1);
		}

		return isIncludeLastDay ? ++days * sawpFlagValue : days * sawpFlagValue;
	}

	short calcDifferenceInDaysForTowDates(clsDate date, bool isIncludeLastDay = false) {
		return calcDifferenceInDaysForTowDates(*this, date, isIncludeLastDay);
	}

	static void printDateDay(clsDate date, short dayOfWeekOrder) {
		string nameOfDay = nameOrderDay(dayOfWeekOrder);

		cout << "Today is " << nameOfDay << " , " << date.day << "/" << date.month << "/" << date.year;
	}

	void printDateDay() {
		printDateDay(*this, DayOfWeekOrderInDate());
	}

	static clsDate GetDateFromDayInOrderYear(short dayOrderInYear, short year) {
		clsDate date;
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

	clsDate GetDateFromDayInOrderYear(short dayOrderInYear) {
		return GetDateFromDayInOrderYear(dayOrderInYear, year);
	}

	vector <string> split(string text, string delim) {
		short pos = 0;
		string sWord;
		vector <string> vString;
		while ((pos = text.find(delim)) != std::string::npos) {
			sWord = text.substr(0, pos);
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			text.erase(0, pos + delim.length());
		}
		if (text != "")
		{
			vString.push_back(text);
		}
		return vString;
	}
};
