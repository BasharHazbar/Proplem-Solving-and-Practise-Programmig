#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "clsString.h"
using namespace std;

class clsLogInRegister
{
private:
	string dateTime;
	string userName;
	string password;
	int permissions;

	//bool markForDelete = false;

	static clsLogInRegister convertLineToUserObject(string text, string seperator = "#//#") {
		vector <string> vLogInRegister = clsString::Split(text, seperator);
		return clsLogInRegister(vLogInRegister[0], vLogInRegister[1], vLogInRegister[2], stoi(vLogInRegister[3]));
	}

	string convertLoginRegisterObjectToStringLine(clsLogInRegister lognInData, string seperator = "#//#") {
		string text = "";

		text += lognInData.getDateTime() + seperator;
		text += lognInData.getUserName() + seperator;
		text += lognInData.getPassword() + seperator;
		text += to_string(lognInData.getPermissions());
		return text;
	}

	static vector <clsLogInRegister> loadloginRegisterFromFile() {
		fstream myfile;
		myfile.open("LoginRegister.txt", ios::in);
		vector <clsLogInRegister> vLoginRegister;
		if (myfile.is_open()) {

			string line;

			while (getline(myfile, line)) {
				vLoginRegister.push_back(convertLineToUserObject(line));
			}
		}

		myfile.close();

		return vLoginRegister;
	}


	void addLoginDataToFile(string line) {

		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::out | ios::app); // create file mode

		if (MyFile.is_open()) {
			MyFile << line << endl;
			MyFile.close();
		}
	}
	void addNewLoginData() {
		addLoginDataToFile(convertLoginRegisterObjectToStringLine(*this));
	}

public:

	clsLogInRegister(string dateTime,string userName, string password, int permissions)
		
	{
		this->dateTime = dateTime;
		this->userName = userName;
		this->password = password;
		this->permissions = permissions;
		//this->mode = mode;
	};

	string getDateTime() {
		return dateTime;
	}
	void setDateTime(string dateTime) {
		this->dateTime = dateTime;
	}

	string getUserName() {
		return userName;
	}
	void setUserName(string userName) {
		this->userName = userName;
	}

	string getPassword() {
		return password;
	}
	void setPassword(string password) {
		this->password = password;
	}

	short getPermissions() {
		return permissions;
	}
	void setPermissions(short permissions) {
		this->permissions = permissions;
	}

	void sava() {
		addNewLoginData();
	}


	static vector <clsLogInRegister> getLoginRegisterList() {
		return loadloginRegisterFromFile();
	}

};


