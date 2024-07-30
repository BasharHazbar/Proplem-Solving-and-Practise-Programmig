#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankCleint.h"
#include "clsUser.h"
using namespace std;
class clsFindUserScreen : protected clsScreen
{
private:
	static void printUser(clsUser user) {
		cout << "\nUser Card:- \n";
		cout << "-------------------------------------------\n";
		cout << "first name      : " << user.getFisrtName() << endl;
		cout << "last name       : " << user.getlastName() << endl;
		cout << "email	         : " << user.getEmial() << endl;
		cout << "phone	        : " << user.getPhone() << endl;
		cout << "user Name       : " << user.getUserName() << endl;
		cout << "password        : " << user.getPassword() << endl;
		cout << "permissions     : " << user.getPermissions() << endl;
		cout << "-------------------------------------------\n";
	}
public:
	static void findUser() {
		drawScreenHeader("Find User Screen");

		cout << "Please enter an user name:- \n";
		string userName = clsInputValidate::ReadString();

		while (!clsUser::isUserObjectExist(userName))
		{
			cout << "the user is exist, please enter another user name:- \n";
			userName = clsInputValidate::ReadString();
		}

		clsUser user = clsUser::find(userName);

		if (!user.isEmpty()) {
			cout << "\n\nthe client found\n\n";
		}
		else {
			cout << "\n\nthe client found";
		}

		printUser(user);
	}
};

