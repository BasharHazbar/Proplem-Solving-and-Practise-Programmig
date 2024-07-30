#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsCurrency
{
private:
	enum enMode {emptyMode = 0, updateMode = 1};
	enMode mode;
	string countryName;
	string currencyCode;
	string currencyName;
	float rate;

	static clsCurrency preparedLineToRecordObject(string line, string seperator = "#//#") {
		vector <string> vCurrency = clsString::Split(line,seperator);
		return clsCurrency(enMode::updateMode, vCurrency[0], vCurrency[1], vCurrency[2],stof(vCurrency[3]));
	}

	string preparedRecordObjectToLine(clsCurrency currency, string seperator = "#//#") {
		string line;
		line += currency.getCountryName() + seperator;
		line += currency.getCurrencyCode() + seperator;
		line += currency.getCurrencyName() + seperator;
		line += to_string(currency.getRate()) + seperator;

		return line;
	}

	static vector <clsCurrency> loadCurrenciesFromFile() {
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		vector <clsCurrency> vCurrencies;
		if (myfile.is_open()) {

			string line;

			while (getline(myfile, line)) {
				vCurrencies.push_back(preparedLineToRecordObject(line));
			}
		}

		myfile.close();

		return vCurrencies;
	}

	void saveCurrencyDataToFile(vector <clsCurrency> vCurrencies) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out); // create file mode

		if (MyFile.is_open()) {
			for (clsCurrency & currency : vCurrencies) {
				MyFile << preparedRecordObjectToLine(currency) << endl;
			}
			MyFile.close();
		}
	}

	static clsCurrency getEmptyCurrencyObject() {
		return clsCurrency(enMode::emptyMode, " ", " ", " ", 0);
	}

	void update() {
		vector <clsCurrency> vCurrency = loadCurrenciesFromFile();

		for (clsCurrency& client : vCurrency) {
			if (client.currencyCode == currencyCode) {
				client = *this;
			}
		}

		saveCurrencyDataToFile(vCurrency);
	}


public:

	clsCurrency(enMode mode,string countryName, string currencyCode, string currencyName, float rate) {
		this->mode = mode;
		this->countryName = countryName;
		this->currencyCode = currencyCode;
		this->currencyName = currencyName;
		this->rate = rate;
	}

	string getCountryName() {
		return countryName;
	}

	string getCurrencyCode() {
		return currencyCode;
	}

	string getCurrencyName() {
		return currencyName;
	}

	float getRate() {
		return rate;
	}

	void updateRate(float rate) {
		this->rate = rate;
		update();
	}

	bool isEmpty() {
		return mode == enMode::emptyMode;
	}

	static clsCurrency findByCurrencyCode(string currencyCode) {
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open()) {

			string line;
			currencyCode = clsString::UpperAllString(currencyCode);
			while (getline(myfile, line)) {
				clsCurrency currency = preparedLineToRecordObject(line);
				if (currency.currencyCode == currencyCode) {
					return currency;
				}
			}
		}
		myfile.close();

		return getEmptyCurrencyObject();
	}

	static clsCurrency findByCountryName(string countryName) {
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open()) {

			string line;
			countryName = clsString::UpperFirstLetterOfEachWord(countryName);

			while (getline(myfile, line)) {
				clsCurrency currency = preparedLineToRecordObject(line);
				if (currency.countryName == countryName) {
					return currency;
				}
			}
		}
		myfile.close();
		return getEmptyCurrencyObject();
	}


	static bool isCurrecnyExist(string currecnyCode) {
		clsCurrency cirrency = findByCurrencyCode(currecnyCode);
		return !cirrency.isEmpty();
	}

	float convertToUSD(float amount) {

		return (amount / rate);
	}

	float convertToAnothersCurrency(float amount, clsCurrency currency2) {

		float amountInUSD = convertToUSD(amount);

		if (currency2.getCurrencyCode() == "USD") {
			return amountInUSD;
		}
		return amountInUSD * currency2.getRate();
	}

	static vector <clsCurrency> getCurrenciesList() {
		return loadCurrenciesFromFile();
	}
};

