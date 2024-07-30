
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
	cout << "the flowing are client detials:- \n";
	cout << "acount Number   : " << sClientData.acountNumber << endl;
	cout << "pin code        : " << sClientData.pinCode << endl;
	cout << "name            : " << sClientData.name << endl;
	cout << "phone           : " << sClientData.phone << endl;
	cout << "acount Balance  : " << sClientData.acountBalance << endl;
}

vector <clientData> takeClientsFromFile(string fileName) {
	fstream myfile;
	myfile.open(fileName, ios::in);
	vector <clientData> recordsClient;
	if (myfile.is_open()) {

		string line;

		while (getline(myfile, line)) {
			recordsClient.push_back(convertLineToRecord(line));
		}
	}

	myfile.close();

	return recordsClient;
}

bool isFindClientByAccountNumber(string accountNumber, clientData & recordClient) {
	vector <clientData> recordsClient = takeClientsFromFile(clientsFileName);
	for (clientData& client : recordsClient) {
		if (client.acountNumber == accountNumber) {
			recordClient = client;
			return true;
		}
	}
	return false;
}

int main()
{
	string accountNumber; clientData recordClient;

	cout << "enter the accountNumber:- " << endl;
	cin >> accountNumber;

	if (isFindClientByAccountNumber(accountNumber, recordClient)) {
		printClientData(recordClient);
	}
	else {
		cout << "the client with account " << accountNumber << " not found!";
	}

}
