#pragma once
#include <iostream>
#include  "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h";
#include "clsCurrencyCalcScreen.h"

using namespace std;

class clsCurrenciesScreen : protected clsScreen
{
private:
    enum enCurrenciesMneuOptions {
        currnciesList = 1, findCurrency = 2, updateRate = 3, currencyCalculator = 4, exitOpration = 5
    };

    static void clearSystem() { 
        system("cls");
    }

    static void goBackToCurrenciesMenu() {
        cout << "\n\n\nPress Any key to go back to Currencies menus....";
        system("pause>0");
        showCurrenciesMenu();
    }

    static short readCurrenciesMenuOptions() {
        cout << "\t\t\t\t\tchoose what do you want to do ? [1 - 5] ? ";
        return clsInputValidate::ReadIntNumberBetween(1, 5, "enter number between 1 - 5 ? ");
    }

    static void showCurrenciesListScreen() {
        clearSystem();
        clsCurrenciesListScreen::showCurrenciesList();
    }

    static void showFindCurrencyScreen() {
        clearSystem();
        clsFindCurrencyScreen::findCurrency();
    }

    static void showUpdateCurrencyScreen() {
        clearSystem();
        clsUpdateCurrencyScreen::updateCurrencyRate();
    }

    static void showCurrencyCalculatorScreen() {
        clearSystem();
        clsCurrencyCalcScreen::showCurrencyCalculator();
    } 

    static void performCurrenciesMenuOptions(enCurrenciesMneuOptions transactionsMneuOptions) {
        switch (transactionsMneuOptions)
        {
        case enCurrenciesMneuOptions::currnciesList:
            showCurrenciesListScreen();
            goBackToCurrenciesMenu();
            break;

        case enCurrenciesMneuOptions::findCurrency:
            showFindCurrencyScreen();
            goBackToCurrenciesMenu();
            break;

        case enCurrenciesMneuOptions::updateRate:
            showUpdateCurrencyScreen();
            goBackToCurrenciesMenu();
            break;

        case enCurrenciesMneuOptions::currencyCalculator:
            showCurrencyCalculatorScreen(); 
            cout << "heeey i am here ???????????????????";
            goBackToCurrenciesMenu();
            break;

        case enCurrenciesMneuOptions::exitOpration:
            clearSystem();
            break;

        default:
            break;
        }
    }
public:

    static void showCurrenciesMenu() {

        clearSystem();
        drawScreenHeader("Currencies Screen");
        cout << "\t\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t\Currencies Menu Screeen\n";
        cout << "\t\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t[1] Currencies List.\n";
        cout << "\t\t\t\t\t\t[2] Find Currency.\n";
        cout << "\t\t\t\t\t\t[3] Update Rate.\n";
        cout << "\t\t\t\t\t\t[4] Currency Calculator.\n";
        cout << "\t\t\t\t\t\t[5] Main Menu.\n";
        cout << "\t\t\t\t\t===============================================\n";

        performCurrenciesMenuOptions((enCurrenciesMneuOptions)readCurrenciesMenuOptions());
    }

};


