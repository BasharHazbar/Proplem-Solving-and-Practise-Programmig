#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankCleint.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{

private:
	static void printClient(clsBankCient client) {
		cout << "\nClient Card:- \n";
		cout << "-------------------------------------------\n";
		cout << "first name      : " << client.getFisrtName() << endl;
		cout << "acount Number   : " << client.getAccountNumber() << endl;
		cout << "acount Balance  : " << client.getAccountBalance() << endl;
		cout << "-------------------------------------------\n";
	}

	static string readAccountNumber(string message) {
		cout << message << endl;
		string accountNumber = clsInputValidate::ReadString();

		while (!clsBankCient::isCleintObjectExist(accountNumber))
		{
			cout << "Client Wiht [" << accountNumber << "] not found !";
			accountNumber = clsInputValidate::ReadString();
		}
		return accountNumber;
	}
	
	static float readAmount(clsBankCient sounrceClient) {
		float amount = clsInputValidate::ReadFlNumber();

		while (amount > sounrceClient.getAccountBalance())
		{
			cout << "\n\nthe amount exeeds the availble balance, enter another amount ? ";
			amount = clsInputValidate::ReadFlNumber();
		}

		return amount;
	}

public:

	static void showTransfer() {

		drawScreenHeader("Deposite Transaction Screen");

		string message = "Please enter an account number to transfer From:-";
		clsBankCient sounrceClient = clsBankCient::find(readAccountNumber(message));
		printClient(sounrceClient);


		message = "\n\nPlease enter an account number to transfer To:-";
		clsBankCient destinationClient = clsBankCient::find(readAccountNumber(message));
		printClient(destinationClient);

		cout << "\n\nplease enter the trnsfer amount ?  ";
		float amount = readAmount(sounrceClient);


		cout << "\n\nare you sure want perform this transaction ? ";
		char answer;
		cin >> answer;
		if (toupper(answer) == 'Y') {
			if (sounrceClient.transfer(amount,destinationClient)) {
				cout << "\n\nthe transfer done successfly" << endl;
			}
		}
		else {
			cout << "\n\nthe transaction trasnfer is not perform";
		}
		printClient(sounrceClient);
		printClient(destinationClient);

	}

};

