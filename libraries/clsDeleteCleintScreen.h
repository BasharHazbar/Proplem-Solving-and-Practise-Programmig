#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankCleint.h"
#include "clsInputValidate.h"
using namespace std;
class clsDeleteCleintScreen : protected clsScreen
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
	static void deleteClient() {

		if (!checkAccessRight(clsUser::enPermissions::pDeleteClinet)) {
			return;
		}

		drawScreenHeader("Delete Client Screen");

		cout << "Please enter an account number:- \n";
		string accountNumber = clsInputValidate::ReadString();

		while (!clsBankCient::isCleintObjectExist(accountNumber))
		{
			cout << "the account is wrong, please enter another account number:- \n";
			accountNumber = clsInputValidate::ReadString();
		}

		clsBankCient cleint = clsBankCient::find(accountNumber);

		printClient(cleint);

		cout << "\n\nare you sure want delete client ? ";
		char answer;
		cin >> answer;
		if (toupper(answer) == 'Y') {
			if (cleint.Delete()) {
				cout << "the delete client is success " << endl;
				cleint = clsBankCient::getEmptyCleintObject();
				printClient(cleint);
			}
			else {
				cout << "the accout is wrong, the delete client is not success " << endl;
			}
		};
	}
};

