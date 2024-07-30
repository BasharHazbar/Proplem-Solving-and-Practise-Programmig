#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:
	static void drawScreenHeader(string title, string subTitle = " ") {
		cout << "\t\t\t\t\t-----------------------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t  " << title << "\n";
		cout << "\t\t\t\t\t\t\t  " << subTitle << "\n\n";
		cout << "\t\t\t\t\t-----------------------------------------------\n\n\n";
		//clsDate date;
		//cout << "\t\t\t\t\tUser: " << currentUser.getUserName() << endl; 
		//cout << "\t\t\t\t\tDate: "; date.Print();
		//cout << "\n\n";

		cout << "\t\t\t\t\tUser: " << currentUser.getUserName() << endl;
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";

	}

	static bool checkAccessRight(clsUser::enPermissions permission) {
		if (currentUser.checkAccessPermisson(permission)) {
			return true;
		}
		else {
			cout << "\n\t\t\t\t\t-------------------------------------------\n\n";
			cout << "\t\t\t\t\t\tAccess denied!, contact with admin";
			cout << "\n\n\t\t\t\t\t-----------------------------------------\n\n";
			return false;
		}
	}
};

