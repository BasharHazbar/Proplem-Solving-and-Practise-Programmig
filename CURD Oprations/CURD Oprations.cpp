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

const string clientsFileName = "Clients.txt";

void crudOprations();

enum choseMenus {showClients = 1, addCilents = 2, deleteClinet = 3, UpdateClient = 4, findClient = 5, exitOpration = 6};

string readAccountNumber(string message) {
    string accountNumber;
    cout << message << endl;
    cin >> accountNumber;
    return accountNumber;
}

short readNumberOprator() {
    cout << "chose what do you want to do ? [1 - 6]? ";
    short numberChose;
    cin >> numberChose;
    return numberChose;
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

bool findClientByAccountNumber(vector <clientData> & recordsClient, string accountNumber, clientData& RecordClient) {
    for (clientData& client : recordsClient) {
        if (client.acountNumber == accountNumber) {
            RecordClient = client;
            return true;
        }
    }
    return false;
}

bool findAndMakeMarkToDelete(string accountNumber, vector <clientData> & recordsClient, clientData& RecordClient) {
    for (clientData& client : recordsClient) {
        if (client.acountNumber == accountNumber) {
            client.isDelete = true;
            RecordClient = client;
            return true;
        }
    }
    return false;
}

void titleOfScrean(string message) {
    system("cls");
    cout << "-----------------------------------------------\n";
    cout << "\t\ " << message << "\n";
    cout << "-----------------------------------------------\n";
}

void printTheHeaderOfTheTableClients(short countClients) {
    cout << "\t\t\t\t\tClient List (" << countClients << ") Client(s)\n";
    cout << "---------------------------------------------------------------------------------------------------\n\n";
    cout << "| " << left << setw(15) << "Acount Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n---------------------------------------------------------------------------------------------------\n\n";
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

void printClientCard(clientData sClientData) {
    cout << "the flowing are client detials:- \n";
    cout << "-------------------------------------------\n";
    cout << "acount Number   : " << sClientData.acountNumber << endl;
    cout << "pin code        : " << sClientData.pinCode << endl;
    cout << "name            : " << sClientData.name << endl;
    cout << "phone           : " << sClientData.phone << endl;
    cout << "acount Balance  : " << sClientData.acountBalance << endl;
    cout << "-------------------------------------------\n";
}
void printClientInTable(clientData recordClient) {
    cout << "| " << left << setw(15) << recordClient.acountNumber;
    cout << "| " << left << setw(10) << recordClient.pinCode;
    cout << "| " << left << setw(40) << recordClient.name;
    cout << "| " << left << setw(12) << recordClient.phone;
    cout << "| " << left << setw(12) << recordClient.acountBalance;
    cout << endl;
}

clientData readNewClient(string acountNumber, bool isAdding) {

    if (isAdding) {
        cout << "add new client:- " << endl;
    }
    else {
        cout << "update client:- " << endl;
    }
    clientData clientData;

    clientData.acountNumber = acountNumber;
    cout << "enter pinCode :- \n";
    getline(cin >> ws , clientData.pinCode);

    cout << "enter name :- \n";
    getline(cin, clientData.name);

    cout << "enter phone :- \n";
    getline(cin, clientData.phone);

    cout << "enter acountBalance :- \n";
    cin >> clientData.acountBalance;

    return clientData;
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

void addClientToFile(string fileName, string record) {

    fstream MyFile;

    MyFile.open(fileName, ios::out | ios::app); // create file mode

    if (MyFile.is_open()) {
        MyFile << record << endl;
        MyFile.close();
    }
}

void addNewClient(vector <clientData> recordsClient) {
    clientData client;
    bool isFind = false;
    string accountNumber = readAccountNumber("enter an account number? ");
    do {
        if (!findClientByAccountNumber(recordsClient, accountNumber, client)) {
            addClientToFile(clientsFileName, convertRcordToStringOneLine(readNewClient(accountNumber,true)));
            isFind = true;
        }
        else {
            cout << "Client Wiht [" << accountNumber << "] Aready exits, ";
            printClientCard(client);
            accountNumber = readAccountNumber("enter another an account number? ");
        }
    } while (!isFind);
}

void printListClients(vector <clientData> recordsClient) {
    system("cls");
    printTheHeaderOfTheTableClients(recordsClient.size());
    for (clientData& recordClient : recordsClient) {
        printClientInTable(recordClient);
    }
    cout << "\n---------------------------------------------------------------------------------------------------\n\n";
}

void addClients(vector <clientData> recordsClient) {
    char addMore = 'Y';
    do
    {
        system("cls");
        titleOfScrean("Add Menu Screeen");
        recordsClient = loadClientsFromFile(clientsFileName);
        addNewClient(recordsClient);
        cout << "clients added uccessfly! \ndo you want adding more ? " << endl;
        cin >> addMore;
    } while (toupper(addMore) == 'Y');

}

void DeleteClient(vector <clientData>& recordsClient) {
    titleOfScrean("Delete Menu Screeen");
    char answer;
    string accountNumber = readAccountNumber("enter an account number? ");
    clientData client;
    if (findAndMakeMarkToDelete(accountNumber, recordsClient, client)) {
        printClientCard(client);
        cout << "\n\nare you sure want delete client ? ";
        cin >> answer;
        if (toupper(answer) == 'Y') {
            saveClientsDataToFiles(accountNumber, recordsClient);
            cout << "the deleted client is success " << endl;
        }
    }
    else {
        cout << "the client with account number " << accountNumber << " not found !" << endl;
    }
}

void updateClient(vector <clientData>& recordsClient) {
    titleOfScrean("Update Menu Screeen");
    char answer;
    string accountNumber = readAccountNumber("enter an account number? ");
    clientData client;
    if (findClientByAccountNumber(recordsClient,accountNumber, client)) {
        printClientCard(client);
        cout << "\n\nare you sure want update client ? ";
        cin >> answer;
        if (toupper(answer) == 'Y') {
            recordsClient = loadClientsFromFile(clientsFileName);
            for (clientData& client : recordsClient) {
                if (client.acountNumber == accountNumber) {
                    client = readNewClient(accountNumber,false);
                    break;
                }
            }
            saveClientsDataToFiles(accountNumber, recordsClient);
            cout << "the update client is success " << endl;
        }
    }
    else {
        cout << "the client with account number " << accountNumber << " not found !" << endl;
    }
}

void findClientWithPrintByAccountNumber(vector <clientData> recordsClient) {

    titleOfScrean("Find Menu Screeen");
    string accountNumber = readAccountNumber("enter an account number? ");
    clientData client;
    if (findClientByAccountNumber(recordsClient, accountNumber, client)) {
        printClientCard(client);
    }
    else {
        cout << "the client with account number " << accountNumber << " not found !" << endl;
    }
}

void showAllMenus() {
    cout << "===============================================\n";
    cout << "\t\tMain Menu Screeen\n";
    cout << "===============================================\n";
    cout << "\t[1] Show Clients List.\n";
    cout << "\t[2] Add New Clints.\n";
    cout << "\t[3] Delete Clients.\n";
    cout << "\t[4] Update Clients.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exite.\n";
    cout << "===============================================\n";
}


void goBackToMenus() {
    cout << "\n\n\n Press Any key to go back to main menus....";
    system("pause>0");
    system("cls");
    crudOprations();
}

void exited() {
    system("cls");
    cout << "exited\n\n\n";
}

void crudOprations() {
    showAllMenus();
    vector <clientData> recordsClient = loadClientsFromFile(clientsFileName);
    switch ((choseMenus)readNumberOprator())
    {
    case choseMenus::showClients:
        printListClients(recordsClient);
        goBackToMenus();
        break;
    case choseMenus::addCilents:
        addClients(recordsClient);
        goBackToMenus();
        break;
    case choseMenus::deleteClinet:
        DeleteClient(recordsClient);
        goBackToMenus();
        break;
    case choseMenus::UpdateClient:
        updateClient(recordsClient);
        goBackToMenus();
        break;
    case choseMenus::findClient:
        findClientWithPrintByAccountNumber(recordsClient);
        goBackToMenus();
        break;
    case choseMenus::exitOpration:
        exited();
        break;
    default:
        break;
    }
}



int main()
{


    crudOprations();

}

