#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankCleint.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:
	static void printTheHeaderOfTheTableLoginRegister() {
		cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(22) << "Date/time";
		cout << "| " << left << setw(15) << "s.Account";
		cout << "| " << left << setw(15) << "d.Account";
		cout << "| " << left << setw(15) << "Amount";
		cout << "| " << left << setw(15) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << "\n---------------------------------------------------------------------------------------------------------------------\n\n";
	}

	static void printLoginRegisterInTable(clsBankCient::stTransferLog transferLogData) {
		cout << "| " << left << setw(22) << transferLogData.dateTime;
		cout << "| " << left << setw(15) << transferLogData.accountClientFrom;
		cout << "| " << left << setw(15) << transferLogData.accountClientTo;
		cout << "| " << left << setw(15) << transferLogData.amount;
		cout << "| " << left << setw(15) << transferLogData.accountBalanceFrom;
		cout << "| " << left << setw(10) << transferLogData.accountBalanceTo;
		cout << "| " << left << setw(10) << transferLogData.userName;
		cout << endl;
	}
public:
	static void showLoginRegisterList() {

		vector <clsBankCient::stTransferLog> vTransferLog = clsBankCient::getTransferLogList();
		string titel = "Transfer Log List Screen";
		string subTitle = "(" + to_string(vTransferLog.size()) + ") Transfer Log (s)";
		drawScreenHeader(titel, subTitle);

		printTheHeaderOfTheTableLoginRegister();

		if (vTransferLog.size() <= 0) {
			cout << "\n\n\n\Login Register not available";
		}
		else {
			for (clsBankCient::stTransferLog & transferLog : vTransferLog) {
				printLoginRegisterInTable(transferLog);
			}
			cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
		}


	}
};

