#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankCleint.h"
using namespace std;
class clsFindClientScreen : protected clsScreen
{
private:
	static void printClient(clsBankCient client) {
		cout << "Client Card:- \n";
		cout << "-------------------------------------------\n";
		cout << "first name      : " << client.getFisrtName() << endl;
		cout << "last name       : " << client.getlastName() << endl;
		cout << "email	        : " << client.getEmial() << endl;
		cout << "phone	        : " << client.getPhone() << endl;
		cout << "acount Number   : " << client.getAccountNumber() << endl;
		cout << "pin code        : " << client.getPinCode() << endl;
		cout << "acount Balance  : " << client.getAccountBalance() << endl;
		cout << "-------------------------------------------\n";
	}
public:
	static void findClient() {
		if (!checkAccessRight(clsUser::enPermissions::pFindClient)) {
			return;
		}

		drawScreenHeader("Find Client Screen");

		cout << "Please enter an account number:- \n";
		string accountNumber = clsInputValidate::ReadString();

		while (!clsBankCient::isCleintObjectExist(accountNumber))
		{
			cout << "the account is wrong, please enter another account number:- \n";
			accountNumber = clsInputValidate::ReadString();
		}

		clsBankCient cleint = clsBankCient::find(accountNumber);

		if (!cleint.isEmpty()) {
			cout << "\n\nthe client found\n\n";
		}
		else {
			cout << "\n\nthe client found";
		}

		printClient(cleint);
	}
};

