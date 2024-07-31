#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

using namespace std;
class clsAddNewUserScreen : protected clsScreen
{
private:
    static short readUserPermission() {
        char answer;
        short permession = 0;
        cout << "\n\ndo you want full access ? ";
        cin >> answer;
        if (tolower(answer) == 'y') {
            return -1;
        }
        cout << "\n\ndo you want to give access show client menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pShowClients;
        }

        cout << "\n\ndo you want access to add client menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pAddCilents;
        }

        cout << "\n\ndo you want access to delete client menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pDeleteClinet;
        }

        cout << "\n\ndo you want access to update client menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\n\ndo you want access to find client menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pFindClient;
        }

        cout << "\n\ndo you want access to Transactions menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pTransaction;
        }
        cout << "\n\ndo you want access to  manage user menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pManageUser;
        }

		cout << "\n\ndo you want access to login register screen ? ";
		cin >> answer;    

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pLoginRegister;
        }

        return permession;
    }

	static void ReadUserInfo(clsUser& user) {

        user.setUserName(user.getUserName());

		cout << "\nEnter First Name:- ";
		user.setFisrtName(clsInputValidate::ReadString());

		cout << "\nEnter Last Name:- ";
		user.setLastName(clsInputValidate::ReadString());

		cout << "\nEnter Email:- ";
		user.setEmail(clsInputValidate::ReadString());

		cout << "\nEnter Phone:- ";
		user.setPhone(clsInputValidate::ReadString());

		cout << "\nEnter Password:- ";
		user.setPassword(clsInputValidate::ReadString());
		
		cout << "\nEnter Permission:- ";
		user.setPermissions(readUserPermission());
	}

	static void printClient(clsUser user) {
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
	static void addNewUser() {

		drawScreenHeader("Add New User Screen");
		cout << "Please enter an User Name:- \n";
		string userName = clsInputValidate::ReadString();

		while (clsUser::isUserObjectExist(userName))
		{
			cout << "the user is exist, please enter another user name:- \n";
			userName = clsInputValidate::ReadString();
		}

		clsUser newUser = clsUser::getEmptyAddNewUserObject(userName);

	    ReadUserInfo(newUser);

		clsUser::enSaveResults isSvSucceeded;

		isSvSucceeded = newUser.save();

		switch (isSvSucceeded)
		{
		case clsUser::svfaildSaveEmptyObject:
			cout << "\n\nthe user name wrong the user was not saved because it is empty!";
			break;
		case clsUser::svSucceeded:
			cout << "\n\nuser adding successfly!";
			printClient(newUser);
			break;
		case clsUser::svfaildAccountNumberExsits:
			cout << "\n\nthe user aready exsits";
			break;
		default:
			break;
		}
	}
};

