#pragma once
#include "clsScreen.h"
#include "clsBankCleint.h"
#include "clsInputValidate.h"
using namespace std;

class clsWithdarwScreen : protected clsScreen
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

	static void showWithdrawScreen() {
		drawScreenHeader("Withdraw Transaction Screen");

		cout << "Please enter an account number:- \n";
		string accountNumber = clsInputValidate::ReadString();

		while (!clsBankCient::isCleintObjectExist(accountNumber))
		{
			cout << "Client Wiht [" << accountNumber << "] not found ! \nPlease enter again ? ";
			accountNumber = clsInputValidate::ReadString();
		}
		clsBankCient cleint = clsBankCient::find(accountNumber);

		printClient(cleint);

		cout << "\n\nplease enter the withdraw amount ?  ";
		float amount = clsInputValidate::ReadFlNumber();

		cout << "\n\nare you sure want perform this transaction ? ";
		char answer;
		cin >> answer;
		if (toupper(answer) == 'Y') {
			if (cleint.withdraw(amount)) {
				cout << "\n\nthe withdraw transacrion is successfull";
				cout << "\n\nthe new withdraw balance amount is:- " << cleint.getAccountBalance();
			}
			else {
				cout << "\nCannot Withdraw, insufficient balance!";
				cout << "\namount withdraw is :- " << amount;
				cout << "your balance is " << cleint.getAccountBalance();
			}

		}
		else {
			cout << "\n\nthe transaction withdraw is Cancelled";
		}

	}

};



