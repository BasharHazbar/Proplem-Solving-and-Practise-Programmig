#pragma once
#include "clsScreen.h"
#include "clsBankCleint.h"
#include "clsInputValidate.h"
using namespace std;

class clsDepositeScreene : protected clsScreen
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

	static void showDepositeScreen() {
		drawScreenHeader("Deposite Transaction Screen");

		cout << "Please enter an account number:- \n";
		string accountNumber = clsInputValidate::ReadString();

		while (!clsBankCient::isCleintObjectExist(accountNumber))
		{
			cout << "Client Wiht [" << accountNumber << "] not found !";
			accountNumber = clsInputValidate::ReadString();
		}
		clsBankCient cleint = clsBankCient::find(accountNumber);

		printClient(cleint);

		cout << "\n\nplease enter the deposite amount ?  ";
		float amount = clsInputValidate::ReadFlNumber();

		cout << "\n\nare you sure want perform this transaction ? ";
		char answer;
		cin >> answer;
		if (toupper(answer) == 'Y') {
			cleint.deposite(amount);
			cout << "\n\nthe deposite transacrion is successfull";
			cout << "\n\nthe new balance amount is:- " << cleint.getAccountBalance(); 
		}
		else {
			cout << "\n\nthe transaction deposite is not perform";
		}
		
	}

};

