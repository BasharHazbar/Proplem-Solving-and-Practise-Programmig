#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankCleint.h"
#include "clsCurrency.h"

using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void printCurrency(clsCurrency currency) {
		cout << "\n\Currency Card:- \n";
		cout << "-------------------------------------------\n";
		cout << "Country Name     : " << currency.getCountryName() << endl;
		cout << "Currency Code    : " << currency.getCurrencyCode() << endl;
		cout << "Currency Name	 : " << currency.getCurrencyName() << endl;
		cout << "Rate (1$)	  : " << currency.getRate() << endl;
		cout << "-------------------------------------------\n";
	}

	static void showResult(clsCurrency currency) {
		if (currency.isEmpty()) {
			cout << "\n\n the currency not found";
		}
		else {
			printCurrency(currency);
		}
	}
public:
	static void findCurrency() {
	
		drawScreenHeader("Find Currency Screen");

		cout << "Find By: [1] Country Name [2] Currency Code ? ";

		short Answer = clsInputValidate::ReadIntNumberBetween(1, 2);
		
		if (Answer == 1) {
			cout << "\n\nPlease Enter the Country Name ? ";
			string countryName = clsInputValidate::ReadString();
			clsCurrency curency = clsCurrency::findByCountryName(countryName);
			showResult(curency);
		}
		else {
			cout << "\n\nPlease Enter the Currency Code ? ";
			string curencyCode = clsInputValidate::ReadString();
			clsCurrency curency = clsCurrency::findByCurrencyCode(curencyCode);
			showResult(curency);
		}
	}
};

