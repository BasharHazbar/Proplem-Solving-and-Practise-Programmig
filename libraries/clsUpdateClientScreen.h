#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankCleint.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:

	static void ReadCleintInfo(clsBankCient& client) {
		cout << "\nEnter First Name:- ";
		client.setFisrtName(clsInputValidate::ReadString());

		cout << "\nEnter Last Name:- ";
		client.setLastName(clsInputValidate::ReadString());

		cout << "\nEnter Email:- ";
		client.setEmail(clsInputValidate::ReadString());

		cout << "\nEnter Phone:- ";
		client.setPhone(clsInputValidate::ReadString());

		cout << "\nEnter Pin Code:- ";
		client.setPinCode(clsInputValidate::ReadString());

		cout << "\nEnter Account Balance:- ";
		client.setAccountBalance(clsInputValidate::ReadFlNumber());
	}

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
	static void UpdateCleint() {


		if (!checkAccessRight(clsUser::pUpdateClient)) {
			return;
		}

		drawScreenHeader("Update Client Screen");

		cout << "Please enter an account number:- \n";
		string accountNumber = clsInputValidate::ReadString();

		while (!clsBankCient::isCleintObjectExist(accountNumber))
		{
			cout << "the account is wrong, please enter another account number:- \n";
			accountNumber = clsInputValidate::ReadString();
		}
		clsBankCient cleint = clsBankCient::find(accountNumber);

		printClient(cleint);

		cout << "\n\nare you sure want update client ? ";
		char answer;
		cin >> answer;

		if (toupper(answer) == 'Y') {
			ReadCleintInfo(cleint);
			clsBankCient::enSaveResults isSvSucceeded = cleint.save();
			switch (isSvSucceeded)
			{
			case clsBankCient::svfaildSaveEmptyObject:
				cout << "\n\nthe account wrong the client was not saved because it is empty!";
				break;
			case clsBankCient::svSucceeded:
				cout << "\n\naccount update successfly!";
				printClient(cleint);
				break;
			case clsBankCient::svfaildAccountNumberExsits:
				cout << "\n\nthe account aready exsits";
				break;
			default:
				break;
			}
		}
	}
};

