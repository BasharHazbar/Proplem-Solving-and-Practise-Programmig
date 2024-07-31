#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankCleint.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;
class clsDeleteUserScreen : protected clsScreen
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
	static void deleteUser() {
		drawScreenHeader("Delete Client Screen");

		cout << "Please enter an User Name:- \n";
		string userName = clsInputValidate::ReadString();

		while (!clsUser::isUserObjectExist(userName))
		{
			cout << "the user is exist, please enter another user name:- \n";
			userName = clsInputValidate::ReadString();
		}

		clsUser user = clsUser::find(userName);

		printUser(user);

		cout << "\n\nare you sure want delete user ? ";
		char answer;
		cin >> answer;
		if (toupper(answer) == 'Y') {
			if (user.Delete()) {
				cout << "the delete user is success " << endl;
				user = clsUser::getEmptyUserObject();
				printUser(user);
			}
			else {
				cout << "the user name is wrong, the delete user is not success " << endl;
			}
		};
	}
};

