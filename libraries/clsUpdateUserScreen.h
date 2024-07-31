#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
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

        //====

  /*      cout << "\n\ndo you want to give access show User menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pShowUser;
        }

        cout << "\n\ndo you want access to add User menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pAddUser;
        }

        cout << "\n\ndo you want access to delete User menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pDeleteUser;
        }

        cout << "\n\ndo you want access to update User menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pUpdateUser;
        }

        cout << "\n\ndo you want access to find user menu ? ";
        cin >> answer;

        if (tolower(answer) == 'y') {
            permession += clsUser::enPermissions::pFindUser;
        }*/

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
	static void UpdateUser() {

		drawScreenHeader("Update User Screen");

		cout << "Please enter an User Name- \n";
		string userName = clsInputValidate::ReadString();

		while (!clsUser::isUserObjectExist(userName))
		{
			cout << "the account is wrong, please enter another account number:- \n";
			userName = clsInputValidate::ReadString();
		}
        clsUser user = clsUser::find(userName);

		printClient(user);

		cout << "\n\nare you sure want update client ? ";
		char answer;
		cin >> answer;

		if (toupper(answer) == 'Y') {
            ReadUserInfo(user);
            clsUser::enSaveResults isSvSucceeded = user.save();
			switch (isSvSucceeded)
			{
			case clsUser::svfaildSaveEmptyObject:
				cout << "\n\nthe user wrong the user was not saved because it is empty!";
				break;
			case clsUser::svSucceeded:
				cout << "\n\nuser update successfly!";
                currentUser = user;
				printClient(user);
				break;
			case clsUser::svfaildAccountNumberExsits:
				cout << "\n\nthe user aready exsits";
				break;
			default:
				break;
			}
		}
	}
};

