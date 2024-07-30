// read client data record.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct clientData
{
	string acountNumber;
	string pinCode;
	string name;
	string phone;
	double acountBalance;

};

//string convertRcordToStringOneLine(clientData clientData, string delim = "#//#") {
//	string text = "";
//
//	text += clientData.acountNumber + delim;
//	text += clientData.pinCode + delim;
//	text += clientData.name + delim;
//	text += clientData.phone + delim;
//	text += to_string(clientData.acountBalance);
//
//	return text;
//}

vector <string> splitString(string text, string delim) {
	short pos = 0;
	string sWord;
	vector <string> vString;
	while ((pos = text.find(delim)) != std::string::npos) {
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		text.erase(0, pos + delim.length());
	}
	if (text != "")
	{
		vString.push_back(text);
	}
	return vString;
}

clientData convertLineToRecord(string text, string seperator = "#//#") {
	vector <string> vClientData = splitString(text, seperator);
	clientData sClientData;
	sClientData.acountNumber = vClientData[0];
	sClientData.pinCode = vClientData[1];
	sClientData.name = vClientData[2];
	sClientData.phone = vClientData[3];
	sClientData.acountBalance = stod(vClientData[4]);
	return sClientData;
}

void printClientData(clientData sClientData) {
	cout << "acount Number   : " << sClientData.acountNumber << endl;
	cout << "pin code        : " << sClientData.pinCode << endl;
	cout << "name            : " << sClientData.name << endl;
	cout << "phone           : " << sClientData.phone << endl;
	cout << "acount Balance  : " << sClientData.acountBalance << endl;
}


int main()
{
	string lineString = "a123#//#11111#//#ali#//#085648187090#//#6223.0000000000";
	cout << lineString << endl;

	printClientData(convertLineToRecord(lineString));


}
