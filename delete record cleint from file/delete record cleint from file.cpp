
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;


struct clientData
{
	string acountNumber;
	string pinCode;
	string name;
	string phone;
	double acountBalance;
	bool isDelete = false;

};

string readAccountNumber(string message) {
	string accountNumber;
	cout << message << endl;
	cin >> accountNumber;
	return accountNumber;
}

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

string convertRcordToStringOneLine(clientData clientData, string delim = "#//#") {
	string text = "";

	text += clientData.acountNumber + delim;
	text += clientData.pinCode + delim;
	text += clientData.name + delim;
	text += clientData.phone + delim;
	text += to_string(clientData.acountBalance);

	return text;
}

void printClientData(clientData sClientData) {
	cout << "the flowing are client detials:- \n";
	cout << "acount Number   : " << sClientData.acountNumber << endl;
	cout << "pin code        : " << sClientData.pinCode << endl;
	cout << "name            : " << sClientData.name << endl;
	cout << "phone           : " << sClientData.phone << endl;
	cout << "acount Balance  : " << sClientData.acountBalance << endl;
}

vector <clientData> loadClientsFromFile(string fileName) {
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

bool findAndMakeMarkToDelete(string accountNumber,vector <clientData> & recordsClient, clientData & RecordClient) {
	for (clientData& client : recordsClient) {
		if (client.acountNumber == accountNumber) {
			client.isDelete = true;
			RecordClient = client;
			return true;
		}
	}
	return false;
}

void saveClientsDataToFiles(string accountNumber, vector <clientData>& recordsClient) {
	fstream MyFile;
	MyFile.open(clientsFileName, ios::out); // create file mode

	if (MyFile.is_open()) {
		for (clientData& client : recordsClient) {
			if (!client.isDelete) {
				MyFile << convertRcordToStringOneLine(client) << endl;
			}
		}
		MyFile.close();
	}
}
void printFile(string fileName) {

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

void DeleteClientFromFile(string accountNumber, vector <clientData>& recordsClient) {
	char answer;
	clientData client;
	if (findAndMakeMarkToDelete(accountNumber, recordsClient, client)) {
		printClientData(client);
		cout << "are you sure want delete client ? ";
		cin >> answer;
		if (toupper(answer) == 'Y') {
			saveClientsDataToFiles(accountNumber, recordsClient);
			recordsClient = loadClientsFromFile(clientsFileName);
			cout << "the deleted client is success " << endl;
		}
	}
	else {
		cout << "the client with account number " << accountNumber << " not found !" << endl;
	}

	cout << "the clients data in file :- " << endl;
	printFile(clientsFileName);
}

//void readFile(string fileName) {
//
//	fstream MyFile;
//
//	MyFile.open(fileName, ios::out | ios::app); // create file mode
//
//	if (MyFile.is_open()) {
//		MyFile << "hallo i am 24 years old " << endl;
//		MyFile << "hallo i am 24 years old " << endl;
//		MyFile << "hallo i am 24 years old " << endl;
//
//		MyFile.close();
//	}
//}

//void fillVectorFromFile(string fileName, vector <string>& data) {
//	fstream myfile;
//	myfile.open(fileName, ios::in);
//
//	if (myfile.is_open()) {
//
//		string line;
//
//		while (getline(myfile, line)) {
//			data.push_back(line);
//		}
//	}
//
//	myfile.close();
//}
//
//void fillFileFromVecotor(string fileName, vector <string>& data) {
//	fstream MyFile;
//
//	MyFile.open(fileName, ios::out); // create file mode
//
//	if (MyFile.is_open()) {
//
//		for (string& line : data) {
//			MyFile << line << endl;
//		}
//
//		MyFile.close();
//	}
//}

int main()
{
	string accountNumber = readAccountNumber("please enter the account number:- ");
	vector <clientData> recordsClient = loadClientsFromFile(clientsFileName);

	DeleteClientFromFile(accountNumber, recordsClient);


	system("pause>0");
}
