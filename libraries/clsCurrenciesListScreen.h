#pragma once
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsLogInRegister.h"
#include "clsCurrency.h"
using namespace std;
class clsCurrenciesListScreen : protected clsScreen
{ //clsCurrenciesScreen
private:
	static void printTheHeaderOfTheTableCurrencies() {
		cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(35) << "Country Name";
		cout << "| " << left << setw(15) << "Currency Code";
		cout << "| " << left << setw(35) << "Currency Name";
		cout << "| " << left << setw(15) << "Rate (1$)";
		cout << "\n---------------------------------------------------------------------------------------------------------------------\n\n";
	}

	static void printCurrenciesInTable(clsCurrency  currency) {
		cout << "| " << left << setw(35) << currency.getCountryName();
		cout << "| " << left << setw(15) << currency.getCurrencyCode();
		cout << "| " << left << setw(35) << currency.getCurrencyName();
		cout << "| " << left << setw(15) << currency.getRate();
		cout << endl;
	}
public:
	static void showCurrenciesList() {
		vector <clsCurrency> vCurrencies = clsCurrency::getCurrenciesList();
		string titel = "Currencies List Screen";
		string subTitle = "(" + to_string(vCurrencies.size()) + ") Currency (s)";
		drawScreenHeader(titel, subTitle);

		printTheHeaderOfTheTableCurrencies();

		if (vCurrencies.size() <= 0) {
			cout << "\n\n\n\Currencies not available";
		}
		else {
			for (clsCurrency & currency : vCurrencies) {
				printCurrenciesInTable(currency);
			}
			cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
		}


	}
};

