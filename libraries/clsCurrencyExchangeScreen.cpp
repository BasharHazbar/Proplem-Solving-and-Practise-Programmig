#pragma once
#include <string>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrencyClaculatorScreen : protected clsScreen
{
private:

	static float readAmount() {
		cout << "\nPlease Enter Amount to exchange ? ";

		return clsInputValidate::ReadFlNumber();
	}


	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{

		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.getCountryName();
		cout << "\nCode          : " << Currency.getCurrencyCode();
		cout << "\nName          : " << Currency.getCurrencyName();
		cout << "\nRate(1$) =    : " << Currency.getRate();
		cout << "\n_____________________________\n\n";

	}

	static clsCurrency getCurrency(string message) {

		cout << message << endl;
		string currencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::isCurrecnyExist(currencyCode))
		{
			cout << "the currency code wrong, please enter another currency code :- \n";
			currencyCode = clsInputValidate::ReadString();
		}

		return clsCurrency::findByCurrencyCode(currencyCode);
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.convertToUSD(Amount);

		cout << Amount << " " << Currency1.getCurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.getCurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrrency2 = Currency1.convertToAnothersCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.getCurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.getCurrencyCode();

	}

public:

	static void showCurrencyCalculator() {

		char isContinue = 'n';

		while (isContinue == 'y' || isContinue == 'Y')
		{
			system("cls");

			drawScreenHeader("Currency Claculator Screen");

			clsCurrency CurrencyFrom = getCurrency("Please enter currency1 Code ? ");
			clsCurrency CurrencyTo = getCurrency("Please enter currency2 Code ? ");


			float Amount = readAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> isContinue;


		}
	}

};

