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
void transactionOprations();

enum choseMenus { showClients = 1, addCilents = 2, deleteClinet = 3, UpdateClient = 4, findClient = 5,transaction = 6,

exitOpration = 7 };

enum choseMenusTrx {
    deposit = 1, withDraw = 2, totalBalance = 3, mainMenu = 4
};

string readAccountNumber(string message) {
    string accountNumber;
    cout << message << endl;
    cin >> accountNumber;
    return accountNumber;
}

short readNumberOprator() {
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

bool findClientByAccountNumber(vector <clientData>& recordsClient, string accountNumber, clientData& RecordClient) {
    for (clientData& client : recordsClient) {
        if (client.acountNumber == accountNumber) {
            RecordClient = client;
            return true;
        }
    }
    return false;
}

bool findClientByAccountNumber(vector <clientData>& recordsClient, string accountNumber) {
    for (clientData& client : recordsClient) {
        if (client.acountNumber == accountNumber) {
            return true;
        }
    }
    return false;
}

bool findAndMakeMarkToDelete(string accountNumber, vector <clientData>& recordsClient, clientData& RecordClient) {
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

void printTheHeaderOfTheTableBalance(short countClients) {
    cout << "\t\t\t\t\Balance List (" << countClients << ") Client(s)\n";
    cout << "---------------------------------------------------------------------------------------------------\n\n";
    cout << "| " << left << setw(30) << "Acount Number";
    cout << "| " << left << setw(30) << "Client Name";
    cout << "| " << left << setw(30) << "Balance";
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

void printBalanceInTable(clientData recordClient) {
    cout << "| " << left << setw(30) << recordClient.acountNumber;
    cout << "| " << left << setw(30) << recordClient.name;
    cout << "| " << left << setw(30) << recordClient.acountBalance;
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
    getline(cin >> ws, clientData.pinCode);

    cout << "enter name :- \n";
    getline(cin, clientData.name);

    cout << "enter phone :- \n";
    getline(cin, clientData.phone);

    cout << "enter acountBalance :- \n";
    cin >> clientData.acountBalance;

    return clientData;
}

void saveClientsDataToFiles( vector <clientData>& recordsClient) {
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
            addClientToFile(clientsFileName, convertRcordToStringOneLine(readNewClient(accountNumber, true)));
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

void printListBlances(vector <clientData> recordsClient) {
    double totalBalnace = 0;
    printTheHeaderOfTheTableBalance(recordsClient.size());
    for (clientData& recordClient : recordsClient) {
        totalBalnace += recordClient.acountBalance;
        printBalanceInTable(recordClient);
    }
    cout << "\n---------------------------------------------------------------------------------------------------\n\n";
    cout << "\t\t\t\t\Total Balances =  " << totalBalnace;
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
            saveClientsDataToFiles(recordsClient);
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
    if (findClientByAccountNumber(recordsClient, accountNumber, client)) {
        printClientCard(client);
        cout << "\n\nare you sure want update client ? ";
        cin >> answer;
        if (toupper(answer) == 'Y') {
            for (clientData& client : recordsClient) {
                if (client.acountNumber == accountNumber) {
                    client = readNewClient(accountNumber, false);
                    break;
                }
            }
            saveClientsDataToFiles(recordsClient);
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

void depositOpration(vector <clientData> recordsClient,string accountNumber, double amount) {
    for (clientData& client : recordsClient) {
        if (client.acountNumber == accountNumber)
        {
            client.acountBalance += amount;
            saveClientsDataToFiles(recordsClient);
            cout << "\n\n Done Successfly!, now the balance is:- " << client.acountBalance << endl;
        }
    }
}

void depositeAndWithdraw(vector <clientData> recordsClient, bool isDepsite){
    if (isDepsite) {
        titleOfScrean("Deposit Menu Screeen");
    }
    else {
        titleOfScrean("Witraw hd Menu Screeen");
    }
    string accountNumber = readAccountNumber("enter an account number? ");
    clientData client;
    while (!findClientByAccountNumber(recordsClient, accountNumber, client))
    {
        cout << "Client Wiht [" << accountNumber << "] not found !";
        accountNumber = readAccountNumber("enter another an account number? ");

    }
    printClientCard(client);

    double amount = 0;
    cout << "please enter the amount:- ";
    cin >> amount;
    if (isDepsite) {
      depositOpration(recordsClient,accountNumber,amount);
    }
    else {

        while (amount > client.acountBalance)
        {
            cout << "\n\nthe amount exceeds the balance, please enter another withdraw amount? ";
            cin >> amount;
        }
        depositOpration(recordsClient, accountNumber, amount * -1);
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
    cout << "\t[6] Transaction.\n";
    cout << "\t[7] Exite.\n";
    cout << "===============================================\n";
}

void showAllMenusTrx() {
    cout << "===============================================\n";
    cout << "\t\Transaction Menu Screeen\n";
    cout << "===============================================\n";
    cout << "\t[1] Deposite.\n";
    cout << "\t[2] Withdrow.\n";
    cout << "\t[3] Total Balance.\n";
    cout << "\t[4] Main Menu.\n";
    cout << "===============================================\n";
}

void goBackToMenus() {
    cout << "\n\n\n Press Any key to go back to main menus....";
    system("pause>0");
    crudOprations();
}

void goBackToMenusTrx() {
    cout << "\n\n\n Press Any key to go back to main menus....";
    system("pause>0");
    system("cls");
    transactionOprations();
}

void exited() {
    system("cls");
    cout << "exited\n\n\n";
}

void crudOprations() {
    system("cls");
    showAllMenus();
    vector <clientData> recordsClient = loadClientsFromFile(clientsFileName);
    cout << "chose what do you want to do ? [1 - 7]? ";
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
    case choseMenus::transaction:
        transactionOprations();
        break;
    default:
        break;
    }
}

void transactionOprations() {
    system("cls");
    showAllMenusTrx();
    vector <clientData> recordsClient = loadClientsFromFile(clientsFileName);
    cout << "chose what do you want to do ? [1 - 4]? ";
    switch ((choseMenusTrx)readNumberOprator())
    {
    case choseMenusTrx::deposit:
        depositeAndWithdraw(recordsClient, true);
        goBackToMenusTrx();
        break;
    case choseMenusTrx::withDraw:
        depositeAndWithdraw(recordsClient, false);
        goBackToMenusTrx();
        break;
    case choseMenusTrx::totalBalance:
        printListBlances(recordsClient);
        goBackToMenusTrx();
        break;
    case choseMenusTrx::mainMenu:
        crudOprations();
        break;
    default:
        break;
    }
        system("cls");
}



int main()
{
    crudOprations();
}

