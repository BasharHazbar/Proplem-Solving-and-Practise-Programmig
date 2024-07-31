#pragma once
#include <iostream>
#include  "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteCleintScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrenciesScreen.h"
#include "Global.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMneuOptions {
        showClients = 1, addCilent = 2, deleteClinet = 3, UpdateClient = 4, findClient = 5, transaction = 6,

        manageUser = 7, loginRegister = 8, currencyExchange = 9, exitOpration = 10
    };

    static void clearSystem() {
        system("cls");
    }

    static void goBackToMainMenu() {
        cout << "\n\n\nPress Any key to go back to main menus....";
        system("pause>0");
        showMainMenu();
    }

    static short readMainMenuOptions() {
        cout << "\t\t\t\t\tchoose what do you want to do ? [1 - 10] ? ";
        return clsInputValidate::ReadIntNumberBetween(1,10,"enter number between 1 - 10 ? ");
    }

    static void showAllCleints() {
        clearSystem();
        clsClientListScreen::showClientsList();       
    }

    static void showAddClient() {
        clearSystem();
        clsAddNewClientScreen::AddNewClient();
    }

    static void showUpdateClientMneu() {
        clearSystem();
        clsUpdateClientScreen::UpdateCleint();
    }

    static void showDeleteClinetMneu() {
        clearSystem();
        clsDeleteCleintScreen::deleteClient();
    }

    static void showFindClientMenu() {
        clearSystem();
        clsFindClientScreen::findClient();
 
    }

    static void showTransactionMenu() {
        clearSystem();
        clsTransactionsScreen::showTransactionsMenu();
    }

    static void showManageUserMenu() {
        clearSystem();
        clsManageUsersScreen::showManageUsersMenu();
    }

    static void showLoginRegisterMenu() {
        clearSystem();
        clsLoginRegisterScreen::showLoginRegisterList();
    }

    static void showCurrenciesMenu() {
        clearSystem();
        clsCurrenciesScreen::showCurrenciesMenu();
    }

    static void logout() {
        clearSystem();
        currentUser = clsUser::find("", "");
    }

    static void performMainMenuOption(enMainMneuOptions mainMneuOptions) {
        switch (mainMneuOptions)
        {
        case clsMainScreen::showClients:
            showAllCleints();
            goBackToMainMenu();
            break;
        case clsMainScreen::addCilent:
            showAddClient();
            goBackToMainMenu();
            break;
        case clsMainScreen::deleteClinet:
            showDeleteClinetMneu();
            goBackToMainMenu();
            break;
        case clsMainScreen::UpdateClient:
            showUpdateClientMneu();
            goBackToMainMenu();
            break;
        case clsMainScreen::findClient:
            showFindClientMenu();
            goBackToMainMenu();
            break;
        case clsMainScreen::transaction:
            showTransactionMenu();
            goBackToMainMenu();
            break;
        case clsMainScreen::manageUser:
            showManageUserMenu();
            goBackToMainMenu();
            break;
        case clsMainScreen::loginRegister:
            showLoginRegisterMenu();
            goBackToMainMenu();
            break;
        case clsMainScreen::currencyExchange:
            showCurrenciesMenu();
            goBackToMainMenu();
            break;
        case clsMainScreen::exitOpration:
            logout();
        default:
            break;
        }
    }


public:
	static void showMainMenu() {
        clearSystem();
		drawScreenHeader("Main Menu");
        cout << "\t\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t\tMain Menu Screeen\n";
        cout << "\t\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t[1] Show Clients List.\n";
        cout << "\t\t\t\t\t\t[2] Add New Clints.\n";
        cout << "\t\t\t\t\t\t[3] Delete Clients.\n";
        cout << "\t\t\t\t\t\t[4] Update Clients.\n";
        cout << "\t\t\t\t\t\t[5] Find Client.\n";
        cout << "\t\t\t\t\t\t[6] Transaction.\n";
        cout << "\t\t\t\t\t\t[7] Manage User.\n";
        cout << "\t\t\t\t\t\t[8] Login Register.\n";
        cout << "\t\t\t\t\t\t[9] Currencies Exchange.\n";
        cout << "\t\t\t\t\t\t[10] Logout.\n";
        cout << "\t\t\t\t\t===============================================\n";
        performMainMenuOption((enMainMneuOptions) readMainMenuOptions());
	}
};

