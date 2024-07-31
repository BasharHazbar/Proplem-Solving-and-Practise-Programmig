#pragma once
#include "clsScreen.h"
#include "clsBankCleint.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;
class clsTotalBalncesScreen : protected clsScreen
{
private:
    static void printTheHeaderOfTheTableBalance(short countClients) {
        cout << "---------------------------------------------------------------------------------------------------\n\n";
        cout << "| " << left << setw(30) << "Acount Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(30) << "Balance";
        cout << "\n---------------------------------------------------------------------------------------------------\n\n";
    }

    static void printBalanceInTable(clsBankCient client) {
        cout << "| " << left << setw(30) << client.getAccountNumber();
        cout << "| " << left << setw(30) << client.getFisrtName();;
        cout << "| " << left << setw(30) << client.getAccountBalance();
        cout << endl;
    }
	
public:
    static void showTotalBalances() {
         
        vector <clsBankCient> vClient = clsBankCient::getCleintsList();
        string title = "Total Balances Screen";
        string subTitle = "Total Balances for (" + to_string(vClient.size()) + ") Client(s)";
        drawScreenHeader(title,subTitle);

        printTheHeaderOfTheTableBalance(vClient.size());

        double totalBalnaces = 0;
        for (clsBankCient& client : vClient) {

            totalBalnaces += client.getAccountBalance();

            printBalanceInTable(client);
        }
        cout << "\n---------------------------------------------------------------------------------------------------\n\n";
        cout << "\t\t\t\t\Total Balances =  " << totalBalnaces;
        //cout << "\n\t\t\t\t\Total Balances =  " << clsUtil::;
    }
};

