#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;
int main()
{
	clsDate date(31, 13, 2022);

	cout << date.isValid();
	cout << "\n";
	clsDate date2("1/2/2020");

	cout << date2.isValid();
	//date2.PrintYearCalendar();
	cout << endl;

	date2.printDateDay();

	cout << "\n";

	clsDate date3(255,2022);

	date3.printDateDay();

	cout << "\n";

	date3.PrintMonthCalendar();

	cout << "\n";

	date3.increaseDateByOneDate();

	date3.printDateDay();

	cout << "\n";

	cout << date3.isDate1BeforeDate2(date2);
	cout << "\n";

	cout << date3.calcDifferenceInDaysForTowDates(date2);

	cout << "\n" << date3.numberOfDaysFromTheBeginingOfYear();

	system("pause>0");

	return 0;
}
