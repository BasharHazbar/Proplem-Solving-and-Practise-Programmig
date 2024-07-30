// read client data record.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


struct clientData
{
	string acountNumber;
	string pinCode;
	string name;
	string phone;
	double acountBalance;

};

clientData readClientData() {
	clientData clientData;
	cout << "enter acountNumber :- \n";
	getline(cin, clientData.acountNumber);

	cout << "enter pinCode :- \n";
	getline(cin, clientData.pinCode);

	cout << "enter name :- \n";
	getline(cin, clientData.name);

	cout << "enter phone :- \n";
	getline(cin, clientData.phone);

	cout << "enter acountBalance :- \n";
	cin >> clientData.acountBalance;

	return clientData;
}

string convertRcordToStringOneLine(clientData clientData, string delim = "#//#") {
	string text = "";

	text += clientData.acountNumber + delim;
	text += clientData.pinCode + delim;
	text += clientData.name + delim;
	text += clientData.phone + delim;
	text += to_string(clientData.acountBalance);

	return text;
}

int main()
{
	clientData clientData = readClientData();

	cout << "the convertRcordToStringOneLine = " << convertRcordToStringOneLine(clientData);


}
