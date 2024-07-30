#pragma once
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsLogInRegister.h"
using namespace std;
class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void printTheHeaderOfTheTableLoginRegister() {
		cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(30) << "Date/time";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(15) << "Permission";
		cout << "\n---------------------------------------------------------------------------------------------------------------------\n\n";
	}

	static void printLoginRegisterInTable(clsUser::stLoginRegister clsLoginData) {
		cout << "| " << left << setw(30) << clsLoginData.dateTime;
		cout << "| " << left << setw(15) << clsLoginData.userName;
		cout << "| " << left << setw(10) << clsLoginData.password;
		cout << "| " << left << setw(15) << clsLoginData.permissions;
		cout << endl;
	}
public:
	static void showLoginRegisterList() {

		if (!checkAccessRight(clsUser::enPermissions::pLoginRegister)) {
			return;
		}

		vector <clsUser::stLoginRegister> vLoginRegisters = clsUser::getLoginRegisterList();
		string titel = "Login register List Screen";
		string subTitle = "(" + to_string(vLoginRegisters.size()) + ") Login Register (s)";
		drawScreenHeader(titel, subTitle);

		printTheHeaderOfTheTableLoginRegister();

		if (vLoginRegisters.size() <= 0) {
			cout << "\n\n\n\Login Register not available";
		}
		else {
			for (clsUser::stLoginRegister& loginRegister : vLoginRegisters) {
				printLoginRegisterInTable(loginRegister);
			}
			cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
		}


	}
};

