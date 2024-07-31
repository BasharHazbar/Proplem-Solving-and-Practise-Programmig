#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"
using namespace std;

class clsBankCient : public clsPerson
{
	enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2 };
private:
	enMode mode;
	string accountNumber;
	string pinCode;
	float accountBalance;
	bool markForDelete = false;

	static clsBankCient convertLineToCleintObject(string text, string seperator = "#//#") {
		vector <string> vClientData = clsString::Split(text, seperator);
		return clsBankCient(enMode::updateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	string convertClientObjectToStringLine(clsBankCient clientData, string seperator = "#//#") {
		string text = "";

		text += clientData.getFisrtName() + seperator;
		text += clientData.getlastName() + seperator;
		text += clientData.getEmial() + seperator;
		text += clientData.getPhone() + seperator;
		text += clientData.getAccountNumber() + seperator;
		text += clientData.getPinCode() + seperator;
		text += to_string(clientData.getAccountBalance());
		return text;
	}

	static vector <clsBankCient> loadClientsFromFile() {
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		vector <clsBankCient> vClients; 
		if (myfile.is_open()) {

			string line;

			while (getline(myfile, line)) {
				vClients.push_back(convertLineToCleintObject(line));
			}
		}

		myfile.close();

		return vClients;
	}

	void addClientToFile(string client) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app); // create file mode

		if (MyFile.is_open()) {
			MyFile << client << endl;
			MyFile.close();
		}
	}

	void saveUsersDataToFiles(vector <clsBankCient> vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); // create file mode

		if (MyFile.is_open()) {
			for (clsBankCient& client : vClients) {
				if (!client.markForDelete) {
					MyFile << convertClientObjectToStringLine(client) << endl;
				}
				
			}
			MyFile.close();
		}
	}

	void update() {
		vector <clsBankCient> vClients = loadClientsFromFile();

		for (clsBankCient& client : vClients) {
			if (client.accountNumber == accountNumber) {
				client = *this;
			}
		}

		saveUsersDataToFiles(vClients);
	}

	void addNewClient() {
		addClientToFile(convertClientObjectToStringLine(*this));
	}

	string preparedTransferToRecord(float amount, clsBankCient distnationClient ,string seperator = "#//#") {
		string text = "";

		text += clsDate::getSystemDateTimeString() + seperator;
		text += accountNumber + seperator;
		text += distnationClient.getAccountNumber() + seperator;
		text += to_string(amount) + seperator;
		text += to_string(accountBalance) + seperator;
		text += to_string(distnationClient.getAccountBalance()) + seperator;
		text += currentUser.getUserName();

		return text;
	}


	struct stTransferLog;
	static stTransferLog convertLineTransferLogToObject(string line, string seperator = "#//#") {
		vector <string> vTransferLog = clsString::Split(line, seperator);
		stTransferLog transferLogData;
		transferLogData.dateTime = vTransferLog[0];
		transferLogData.accountClientFrom = vTransferLog[1];
		transferLogData.accountClientTo = vTransferLog[2];
		transferLogData.amount = stoi(vTransferLog[3]);
		transferLogData.accountBalanceFrom = stoi(vTransferLog[4]);
		transferLogData.accountBalanceTo = stoi(vTransferLog[5]);
		transferLogData.userName = vTransferLog[6];
		return transferLogData;
	}

	void RegisterTransferLog(float amount, clsBankCient distnationClient) {
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app); // create file mode

		if (MyFile.is_open()) {

			MyFile << preparedTransferToRecord(amount, distnationClient) << endl;

			MyFile.close();
		}
	}

public:
	clsBankCient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, float accountBalance)
		: clsPerson(firstName,lastName,email,phone)
	{
		this->accountNumber = accountNumber;
		this->pinCode = pinCode;
		this->accountBalance = accountBalance;
		this->mode = mode;
	};


	struct stTransferLog
	{
		string dateTime;
		string accountClientFrom;
		string accountClientTo;
		float amount;
		float accountBalanceFrom;
		float accountBalanceTo;
		string userName;

	};

	static clsBankCient getEmptyCleintObject() {
		return clsBankCient(enMode::emptyMode, " ", " ", " ", " ", " ", " ", 0);
	}
	static clsBankCient getEmptyAddNewCleintObject(string accountNumber) {
		return clsBankCient(enMode::addNewMode, " ", " ", " ", " ", accountNumber, " ", 0);
	}

	string getAccountNumber() {
		return accountNumber;
	}
	void setAccountNumber(string accountNumber) {
		this->accountNumber = accountNumber;
	}

	string getPinCode() {
		return pinCode;
	}
	void setPinCode(string pinCode) {
		this->pinCode = pinCode;
	}

	bool getMarkForDelete() {
		return markForDelete;
	}
	void setMarkForDelete(bool markForDelete) {
		this->markForDelete = markForDelete;
	}

	double getAccountBalance() {
		return accountBalance;
	}
	void setAccountBalance(double accountBalance) {
		this->accountBalance = accountBalance;
	}

	string getFullName() {
		return getFisrtName() + " " + getlastName();
	}

	static clsBankCient find(string accountNumber) {
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		//vector <clsBankCleint> recordsClient;
		if (myfile.is_open()) {

			string line;

			while (getline(myfile, line)) {
				clsBankCient cleint = convertLineToCleintObject(line);
				if (cleint.accountNumber == accountNumber) {
					return cleint;
				}
			}
		}

		myfile.close();

		return getEmptyCleintObject();
	}

	static clsBankCient find(string accountNumber, string pinCode) {
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		//vector <clsBankCleint> recordsClient;
		if (myfile.is_open()) {

			string line;

			while (getline(myfile, line)) {
				clsBankCient cleint = convertLineToCleintObject(line);
				if (cleint.accountNumber == accountNumber && cleint.pinCode == pinCode) {
					return cleint;
				}
			}
		}

		myfile.close();

		return getEmptyCleintObject();
	}

	bool isEmpty() {
		return mode == enMode::emptyMode;
	}

	static enum enSaveResults { svfaildSaveEmptyObject = 0,  svSucceeded = 1,svfaildAccountNumberExsits = 2 };


	enSaveResults save() {
		switch (mode)
		{
		case clsBankCient::emptyMode:
			return enSaveResults::svfaildSaveEmptyObject;

		case clsBankCient::updateMode:
			update();
			return enSaveResults::svSucceeded;

		case clsBankCient::addNewMode:
			if (isCleintObjectExist()) {
				return enSaveResults::svfaildAccountNumberExsits;
			}
			else {
				addNewClient();
				mode = enMode::updateMode;
			}
			return enSaveResults::svSucceeded;
		default:
			break;
		}
	}

	static bool isCleintObjectExist(string accountNumber) {
		clsBankCient cleint = find(accountNumber);
		return !cleint.isEmpty();
	}
	bool isCleintObjectExist() {
		return isCleintObjectExist(this->accountNumber);
	}

	bool Delete() {
		vector <clsBankCient> vClients = loadClientsFromFile();
		bool isDelete = false;
		for (clsBankCient& client : vClients) {
			if (client.accountNumber == accountNumber) {
				client.markForDelete = true;
				isDelete = true;
			}
		}
		saveUsersDataToFiles(vClients);
		return isDelete;
	}

	void deposite(float amount) {
		accountBalance += amount;
		save();
	}

	bool withdraw(float amount) {
		if (amount > accountBalance) {
			return false;
		}
		accountBalance -= amount;
		save();
		return true;
	}

	bool transfer(float amount, clsBankCient & distenationClient) {
		if (amount > accountBalance) {
			return false;
		}
		withdraw(amount);
		distenationClient.deposite(amount);
		RegisterTransferLog(amount, distenationClient);
		return true;
	}

	static vector <stTransferLog> getTransferLogList() {
		fstream myfile;
		myfile.open("TransferLog.txt", ios::in);
		vector <stTransferLog> vTransferLog;
		if (myfile.is_open()) {

			string line;

			while (getline(myfile, line)) {
				vTransferLog.push_back(convertLineTransferLogToObject(line));
			}
		}

		myfile.close();

		return vTransferLog;
	}

	static vector <clsBankCient> getCleintsList() {
		return loadClientsFromFile();
	}

};

