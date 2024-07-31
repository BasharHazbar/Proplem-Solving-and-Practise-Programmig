#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;

class clsUser : public clsPerson
{
	enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2 };
private:
	enMode mode;
	string userName;
	string password;
	int permissions;
	bool markForDelete = false;

	static clsUser convertLineToUserObject(string text, string seperator = "#//#") {
		vector <string> vUserData = clsString::Split(text, seperator);
		return clsUser(enMode::updateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3],
			vUserData[4], DecryptText(vUserData[5]), stoi(vUserData[6]));
	}

	string convertUserObjectToStringLine(clsUser userData, string seperator = "#//#") {
		string text = "";

		text += userData.getFisrtName() + seperator;
		text += userData.getlastName() + seperator;
		text += userData.getEmial() + seperator; 
		text += userData.getPhone() + seperator;
		text += userData.getUserName() + seperator;
		text += EncryptText(userData.getPassword()) + seperator;
		text += to_string(userData.getPermissions());
		return text;
	}



	static vector <clsUser> loadUsersFromFile() {
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		vector <clsUser> vUsers;
		if (myfile.is_open()) {

			string line;

			while (getline(myfile, line)) {
				vUsers.push_back(convertLineToUserObject(line));
			}
		}

		myfile.close();

		return vUsers;
	}

	void addUserToFile(string client) {

		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app); // create file mode

		if (MyFile.is_open()) {
			MyFile << client << endl;
			MyFile.close();
		}
	}

	void saveUsersDataToFiles(vector <clsUser> vUsers) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out); // create file mode

		if (MyFile.is_open()) {
			for (clsUser& user : vUsers) {
				if (!user.markForDelete) {
					MyFile << convertUserObjectToStringLine(user) << endl;
				}

			}
			MyFile.close();
		}
	}

	void update() {
		vector <clsUser> vUsers = loadUsersFromFile();

		for (clsUser& user : vUsers) {
			if (user.userName == userName) {
				user = *this;
			}
		}

		saveUsersDataToFiles(vUsers);
	}

	void addNewUser() {
		addUserToFile(convertUserObjectToStringLine(*this));
	}

	string preparedRecordLoginToLine(string seperator = "#//#") {
		string text = "";

		text += clsDate::getSystemDateTimeString() + seperator;
		text += userName + seperator;
		text += EncryptText(password) + seperator;
		text += to_string(permissions);

		return text;
	}

	struct stLoginRegister;
	static stLoginRegister converLoginRegisterObjectToStringLine(string line, string seperator = "#//#") {
		vector <string> vloginRegister = clsString::Split(line, seperator);
		stLoginRegister loginData;
		loginData.dateTime = vloginRegister[0];
		loginData.userName = vloginRegister[1];
		loginData.password = DecryptText(vloginRegister[2]);
		loginData.permissions = stoi(vloginRegister[3]);
		return loginData;
	}

	//string preparedLineLoginToRecord(vector <string> vLogingData) {
	//	string text = "";

	///*	text += clsDate::getSystemDateTimeString() + seperator;
	//	text += userName + seperator;
	//	text += password + seperator;
	//	text += to_string(permissions);*/
	//	return text;
	//}

	static string EncryptText (string password){
		return clsUtil::EncryptText(password, 18);
	}

	static string DecryptText(string password) {
		return clsUtil::DecryptText(password, 18);
	}

public:
	enum enPermissions {
		eAll = -1, pShowClients = 1, pAddCilents = 2, pDeleteClinet = 4, pUpdateClient = 8, pFindClient = 16, pTransaction = 32,

		pManageUser = 64, pLoginRegister = 128
	};

	struct stLoginRegister
	{
		string dateTime;
		string userName;
		string password;
		int permissions;
	};


	clsUser(enMode mode, string firstName, string lastName, string email,string phone, string userName, string password, int permissions)
		: clsPerson(firstName, lastName, email, phone)
	{
		this->userName = userName;
		this->password = password;
		this->permissions = permissions;
		this->mode = mode;
	};

	static clsUser getEmptyUserObject() {
		return clsUser(enMode::emptyMode, " ", " ", " ", " ", " ", " ", 0);
	}
	static clsUser getEmptyAddNewUserObject(string userName) {
		return clsUser(enMode::addNewMode, " ", " ", " ", " ", userName, " ", 0);
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

	bool getMarkForDelete() {
		return markForDelete;
	}
	void setMarkForDelete(bool markForDelete) {
		this->markForDelete = markForDelete;
	}

	int getPermissions() {
		return permissions;
	}
	void setPermissions(int permissions) {
		this->permissions = permissions;
	}

	string getFullName() {
		return getFisrtName() + " " + getlastName();
	}

	static clsUser find(string userName) {
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		//vector <clsBankCleint> recordsClient;
		if (myfile.is_open()) {

			string line;

			while (getline(myfile, line)) {
				clsUser user = convertLineToUserObject(line);
				if (user.userName == userName) {
					return user;
				}
			}
		}

		myfile.close();

		return getEmptyUserObject();
	}

	static clsUser find(string userName, string password) {
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		//vector <clsBankCleint> recordsClient;
		if (myfile.is_open()) {
			string line;
			//string passwordEecrypt = EncryptText(password);
			//cout << "passwordDecrypt ==> " << passwordEecrypt << endl;
			while (getline(myfile, line)) {
				clsUser user = convertLineToUserObject(line);
				if (user.userName == userName && user.password == password) {
					return user;
				}
			}
		}

		myfile.close();

		return getEmptyUserObject();
	}

	bool isEmpty() {
		return mode == enMode::emptyMode;
	}

	static enum enSaveResults { svfaildSaveEmptyObject = 0, svSucceeded = 1, svfaildAccountNumberExsits = 2 };


	enSaveResults save() {
		switch (mode)
		{
		case clsUser::emptyMode:
			return enSaveResults::svfaildSaveEmptyObject;

		case clsUser::updateMode:
			update();
			return enSaveResults::svSucceeded;

		case clsUser::addNewMode:
			if (isUserObjectExist()) {
				return enSaveResults::svfaildAccountNumberExsits;
			}
			else {
				addNewUser();
				mode = enMode::updateMode;
			}
			return enSaveResults::svSucceeded;
		default:
			break;
		}
	}

	static bool isUserObjectExist(string userName) {
		clsUser user = find(userName);
		return !user.isEmpty();
	}

	bool isUserObjectExist() {
		return isUserObjectExist(userName);
	}

	bool Delete() {
		vector <clsUser> vUsers = loadUsersFromFile();
		bool isDelete = false;
		for (clsUser& user : vUsers) {
			if (user.userName == userName) {
				user.markForDelete = true;
				isDelete = true;
			}
		}
		saveUsersDataToFiles(vUsers);
		return isDelete;
	}

	bool checkAccessPermisson(enPermissions permissions) {
		if (this->permissions == clsUser::eAll) {
			return true;
		}
		else if ((permissions & this->permissions ) == permissions) {
			return true;
		}
		else {
			cout << "not permission";
			return false;
		}
	}

	void loginRgister() {
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app); // create file mode

		if (MyFile.is_open()) {

			MyFile << preparedRecordLoginToLine() << endl;

			MyFile.close();
		}
	}

	static vector <stLoginRegister> getLoginRegisterList() {
		fstream myfile;
		myfile.open("LoginRegister.txt", ios::in);
		vector <stLoginRegister> vLoginRegister;
		if (myfile.is_open()) {

			string line;

			while (getline(myfile, line)) {
				vLoginRegister.push_back(converLoginRegisterObjectToStringLine(line));
			}
		}

		myfile.close();

		return vLoginRegister;
	}

	static vector <clsUser> getUsersList() {
		return loadUsersFromFile();
	}

};


