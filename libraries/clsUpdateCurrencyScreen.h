#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
using namespace std;
class clsUpdateCurrencyScreen : protected clsScreen
{

private:
	static void printCurrency(clsCurrency currency) {
		cout << "\n\nCurrency Card:- \n";
		cout << "-------------------------------------------\n";
		cout << "Country Name     : " << currency.getCountryName() << endl;
		cout << "Currency Code    : " << currency.getCurrencyCode() << endl;
		cout << "Currency Name	 : " << currency.getCurrencyName() << endl;
		cout << "Rate (1$)	  : " << currency.getRate() << endl;
		cout << "-------------------------------------------\n";
	}
	static float readNewRate() {
		cout << "\n\nEnter New Rate ? ";
		return clsInputValidate::ReadFlNumber();
	}
public:
	static void updateCurrencyRate() {

		drawScreenHeader("Update Currency Rate Screen");

		cout << "Please enter an Currency Code ? ";
		string currencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::isCurrecnyExist(currencyCode))
		{
			cout << "the Currency Code is wrong, please enter another Currency Code ? ";
			currencyCode = clsInputValidate::ReadString();
		}
		
		clsCurrency currency = clsCurrency::findByCurrencyCode(currencyCode);

		printCurrency(currency);


		cout << "\n\nAre you sure do you want perform update the rate ? ";
		char answer = 'n';
		cin >> answer;

		if (tolower(answer) == 'y') {

			cout << "\n\n        update rate         ";
			cout << "\n------------------------------\n";

			currency.updateRate(readNewRate());

			cout << "\nthe update rate is succesful";

			printCurrency(currency);
		}

	
	}
};

