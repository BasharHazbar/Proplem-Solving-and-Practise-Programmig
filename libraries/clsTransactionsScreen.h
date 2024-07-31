#pragma once
#include <iostream>
#include  "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositeScreene.h"
#include "clsWithdarwScreen.h"
#include "clsTotalBalncesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMneuOptions {
        Deposite = 1, Withdrow = 2, totalBalance = 3, transfer = 4, transferLog = 5, exitOpration = 6
    };

    static void clearSystem() {
        system("cls");
    }

    static void goBackToTrxMenu() {
        cout << "\n\n\nPress Any key to go back to Transactions menus....";
        system("pause>0");
        showTransactionsMenu();
    }

    static short readMainMenuOptions() {
        cout << "\t\t\t\t\tchoose what do you want to do ? [1 - 6] ? ";
        return clsInputValidate::ReadIntNumberBetween(1, 6, "enter number between 1 - 6 ? ");
    }

    static void showDepositeScreen() {
        clearSystem();
        clsDepositeScreene::showDepositeScreen();
    }

    static void showWithdrawScreen() {
        clearSystem();
        clsWithdarwScreen::showWithdrawScreen();
    }

    static void showTotalBalanceScreen() {
        clearSystem();
        clsTotalBalncesScreen::showTotalBalances();
    }

    static void showTransferScreen() {
        clearSystem();
        clsTransferScreen::showTransfer();
    }

    static void showTransfLogerScreen() {
        clearSystem();
        clsTransferLogScreen::showLoginRegisterList();
    }

    static void performTransactionsMenuOptions(enTransactionsMneuOptions transactionsMneuOptions) {
        switch (transactionsMneuOptions)
        {
        case enTransactionsMneuOptions::Deposite:
            showDepositeScreen();
            goBackToTrxMenu();
            break;

        case enTransactionsMneuOptions::Withdrow:
            showWithdrawScreen();
            goBackToTrxMenu();
            break;

        case enTransactionsMneuOptions::totalBalance:
            showTotalBalanceScreen();
            goBackToTrxMenu();
            break;

        case enTransactionsMneuOptions::transfer:
            showTransferScreen();
            goBackToTrxMenu();
            break;

        case enTransactionsMneuOptions::transferLog:
            showTransfLogerScreen();
            goBackToTrxMenu();
            break;
        case enTransactionsMneuOptions::exitOpration:
            clearSystem();
            break;

        default:
            break;
        }
    }
public:

    static void showTransactionsMenu() {

        clearSystem();

        if (!checkAccessRight(clsUser::enPermissions::pTransaction)) {
            return;
        }
        drawScreenHeader("Transactions Screen");
        cout << "\t\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t\Transaction Menu Screeen\n";
        cout << "\t\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t[1] Deposite.\n";
        cout << "\t\t\t\t\t\t[2] Withdrow.\n";
        cout << "\t\t\t\t\t\t[3] Total Balance.\n";
        cout << "\t\t\t\t\t\t[4] Tansfer.\n";
        cout << "\t\t\t\t\t\t[5] Tansfer Log.\n";
        cout << "\t\t\t\t\t\t[6] Main Menu.\n";
        cout << "\t\t\t\t\t===============================================\n";

        performTransactionsMenuOptions((enTransactionsMneuOptions)readMainMenuOptions());
    }

};

