// read client data record.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct clientData
{
	string acountNumber;
	string pinCode;
	string name;
	string phone;
	double acountBalance;

};

const string clientsFileName = "Clients.txt";

string convertRcordToStringOneLine(clientData clientData, string delim = "#//#") {
	string text = "";

	text += clientData.acountNumber + delim;
	text += clientData.pinCode + delim;
	text += clientData.name + delim;
	text += clientData.phone + delim;
	text += to_string(clientData.acountBalance);

	return text;
}

void addClientsToFile(string fileName, string record) {

	fstream MyFile;

	MyFile.open(fileName, ios::out | ios::app); // create file mode

	if (MyFile.is_open()) {
		MyFile << record << endl;
		MyFile.close();
	}
}

void printClientsFile(string fileName) {

	fstream myfile;
	myfile.open(fileName, ios::in);

	if (myfile.is_open()) {

		string line;

		while (getline(myfile, line)) {
			cout << line << endl;
		}
	}

	myfile.close();

}

clientData readNewClient() {
	cout << "add new client:- " << endl;
	clientData clientData;
	cout << "enter acountNumber :- \n";
	getline(cin >> ws, clientData.acountNumber);

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

void addNewClient() {
	addClientsToFile(clientsFileName, convertRcordToStringOneLine(readNewClient()));
}
void addCliens() {
	char addMore = 'Y';
	do
	{
		system("cls");
		addNewClient();
		cout << "clients added uccessfly! \ndo you want adding more ? " << endl;
		cin >> addMore;
	} while (toupper(addMore) == 'Y');
	
}

int main()
{
	addCliens();
	printClientsFile("Clients.txt");
}
