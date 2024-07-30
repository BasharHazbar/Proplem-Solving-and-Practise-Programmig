#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankCleint.h"
using namespace std;
class clsClientListScreen : protected clsScreen
{
private:
	static void printTheHeaderOfTheTableClients(short countClients) {
		cout << "\n---------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(15) << "Acount Number";
		cout << "| " << left << setw(30) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(30) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n\n---------------------------------------------------------------------------------------------------------------------\n\n";
	}
	static void printClientInTable(clsBankCient client) {
		cout << "| " << left << setw(15) << client.getAccountNumber();
		cout << "| " << left << setw(30) << client.getFullName();
		cout << "| " << left << setw(12) << client.getPhone();
		cout << "| " << left << setw(30) << client.getEmial();
		cout << "| " << left << setw(10) << client.getPhone();
		cout << "| " << left << setw(12) << client.getAccountBalance();
		cout << endl;
	}
public:
	static void showClientsList() {
		vector <clsBankCient> vClients = clsBankCient::getCleintsList();
		string titel = "Client List Screen";
		string subTitle = "(" + to_string(vClients.size()) + ") Cleint(s)";
		drawScreenHeader(titel,subTitle);

		printTheHeaderOfTheTableClients(vClients.size());

		if (vClients.size() <= 0) {
			cout << "\n\n\n\nClients not available";
		}
		else {
			for (clsBankCient& client : vClients) {
				printClientInTable(client);
			}
			cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
		}


	}
};

