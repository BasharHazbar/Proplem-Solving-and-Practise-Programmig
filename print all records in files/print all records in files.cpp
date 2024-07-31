// read client data record.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>S
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

void printTheHeaderOfTheTableClients(short countClients) {
	cout << "\t\t\t\t\tClient List ("<< countClients << ") Client(s)\n";
	cout << "---------------------------------------------------------------------------------------------------\n\n";
	cout << "| " << left << setw(15) << "Acount Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n---------------------------------------------------------------------------------------------------\n\n";
}

vector <string> splitString(string text, string delim = "#//#") {
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

vector <string> takeClientsFromFile(string fileName) {
	fstream myfile;
	myfile.open(fileName, ios::in);
	vector <string> recordsClient;
	if (myfile.is_open()) {

		string line;

		while (getline(myfile, line)) {
			recordsClient.push_back(line);
		}
	}

	myfile.close();

	return recordsClient;
}

clientData inputDataClientsToStruct(vector <string> VrecordClient) {
	clientData stRecordClient;
	stRecordClient.acountNumber = VrecordClient[0];
	stRecordClient.pinCode = VrecordClient[1];
	stRecordClient.name = VrecordClient[2];
	stRecordClient.phone = VrecordClient[3];
	stRecordClient.acountBalance = stod(VrecordClient[4]);
	return stRecordClient;
}

void printClient(clientData recordClient) {
	cout << "| " << left << setw(15) << recordClient.acountNumber;
	cout << "| " << left << setw(10) << recordClient.pinCode;
	cout << "| " << left << setw(40) << recordClient.name;
	cout << "| " << left << setw(12) << recordClient.phone;
	cout << "| " << left << setw(12) << recordClient.acountBalance;
	cout << endl;
}

void printClients() {
	vector <string> recordsClient = takeClientsFromFile(clientsFileName);
	printTheHeaderOfTheTableClients(recordsClient.size());
	for (string & recordClient : recordsClient) {
		printClient(inputDataClientsToStruct(splitString(recordClient)));
	}
	cout << "\n---------------------------------------------------------------------------------------------------\n\n";
}

int main()
{
	addCliens();
	printClients();
}
