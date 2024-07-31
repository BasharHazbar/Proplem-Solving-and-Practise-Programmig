#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsUsersListScreen : protected clsScreen
{
private:
	static void printTheHeaderOfTheTableUsers() {
		cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(30) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(30) << "Email";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(15) << "Permission";
		cout << "\n---------------------------------------------------------------------------------------------------------------------\n\n";
	}

	static void printUserInTable(clsUser user) {
		cout << "| " << left << setw(30) << user.getFullName();
		cout << "| " << left << setw(10) << user.getPhone();
		cout << "| " << left << setw(30) << user.getEmial();
		cout << "| " << left << setw(15) << user.getUserName();
		cout << "| " << left << setw(10) << user.getPassword();
		cout << "| " << left << setw(15) << user.getPermissions();
		cout << endl;
	}
public:
	static void showUserList() {
		vector <clsUser> vUsers = clsUser::getUsersList();
		string titel = "Login register List Screen";
		string subTitle = "(" + to_string(vUsers.size()) + ") User (s)";
		drawScreenHeader(titel, subTitle);

		printTheHeaderOfTheTableUsers();

		if (vUsers.size() <= 0) {
			cout << "\n\n\n\nUsers not available";
		}
		else {
			for (clsUser& user : vUsers) {
				printUserInTable(user);
			}
			cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
		}


	}
};

