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

struct userData
{
    string userCode;
    string password;
    short permission;
    bool isDelete = false;
};

const string clientsFileName = "Clients.txt";

const string usersFileName = "Users.txt";

userData currentUser;

void crudOprations();
void transactionOprations();
void manageUserOprations();
void printUserInTable(userData recordUser);
void goBackToMenusManageUser();
void loging();

enum choseMenus {
    showClients = 1, addCilents = 2, deleteClinet = 3, UpdateClient = 4, findClient = 5, transaction = 6,

    manageUser = 7, exitOpration = 8
};

enum enPermissions {
    eAll = -1, pShowClients = 1, pAddCilents = 2, pDeleteClinet = 4, pUpdateClient = 8, pFindClient = 16, pTransaction = 32,

    pManageUser = 64, pShowUser = 128, pAddUser = 256, pDeleteUser = 512, pUpdateUser = 1024, pFindUser = 2048
};

enum choseMenusManageUser {
    showUsers = 1, addUser = 2, deleteUser = 3, updateUser = 4, findUser = 5, mainMenuFromUser = 6
};

enum choseMenusTrx {
    deposit = 1, withDraw = 2, totalBalance = 3, mainMenuFromTrx = 4
};

string readAccountNumber(string message) {
    string accountNumber;
    cout << message << endl;
    cin >> accountNumber;
    return accountNumber;
}

short readUserPermission(){
    char answer;
    short permession = 0;
    cout << "\n\ndo you want full access ? ";
    cin >> answer;
    if (tolower(answer) == 'y') {
        return -1;
    }
    cout << "\n\ndo you want to give access show client menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pShowClients;
    }

    cout << "\n\ndo you want access to add client menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pAddCilents;
    }

    cout << "\n\ndo you want access to delete client menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pDeleteClinet;
    }

    cout << "\n\ndo you want access to update client menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pUpdateClient;
    }

    cout << "\n\ndo you want access to find client menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pFindClient;
    }

    cout << "\n\ndo you want access to Transactions menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pTransaction;
    }
    cout << "\n\ndo you want access to  manage user menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pManageUser;
    }

    //====

    cout << "\n\ndo you want to give access show User menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pShowUser;
    }

    cout << "\n\ndo you want access to add User menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pAddUser;
    }

    cout << "\n\ndo you want access to delete User menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pDeleteUser;
    }

    cout << "\n\ndo you want access to update User menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pUpdateUser;
    }

    cout << "\n\ndo you want access to find user menu ? ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        permession += enPermissions::pFindUser;
    }

    return permession;
}

void messagePermission() {
    system("cls");
    cout << "-----------------------------------------------------\n";
    cout << "Acsses Denied,\nyou do not have permission to do this,\ncontact with admin\n";
    cout << "\n-----------------------------------------------------\n";
}
void goBackToMenus() {
    cout << "\n\n\n Press Any key to go back to main menus....";
    system("pause>0");
    crudOprations();
}

string readUserCode(string message) {
    string userCode;
    cout << message << endl;
    cin >> userCode;
    return userCode;
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

userData convertLineUserToRecord(string text, string seperator = "#//#") {
    //cout << text << endl;
    //system("pause>0");
    vector <string> vUsersData = splitString(text, seperator);

    //for (string& recordUser : vUsersData) {
    //    cout << recordUser << endl;
    //}
    //system("pause>0");
    userData sUsersData;
    sUsersData.userCode = vUsersData[0];
    sUsersData.password = vUsersData[1];
    sUsersData.permission = stod(vUsersData[2]);
    return sUsersData;
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

vector <userData> loadUsersFromFile(string fileName) {
    fstream myfile;
    myfile.open(fileName, ios::in);
    vector <userData> recordsUser;
    if (myfile.is_open()) {

        string line;

        while (getline(myfile, line)) {
            recordsUser.push_back(convertLineUserToRecord(line));
        }
    }

    myfile.close();

    //for (userData& recordUser : recordsUser) {
    //    printUserInTable(recordUser);
    //}

    //system("pause>0");
    return recordsUser;
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

bool findUserByUserCode(vector <userData>& recordsUser, string userCode, userData & RecordUser) {
    for (userData& user : recordsUser) {
        if (user.userCode == userCode) {
            RecordUser = user;
            return true;
        }
    }
    return false;
}

bool findUserByUserCodeAndPassword(vector <userData>& recordsUser, string userCode, string password, userData& RecordUser) {
    for (userData & user : recordsUser) {
        if (user.userCode == userCode && user.password == password) {
            RecordUser = user;
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

bool findUserAndMakeMarkToDelete(string userCode, vector <userData>& recordsUser, userData & RecordUser) {
    for (userData & user : recordsUser) {
        if (user.userCode == userCode) {
            user.isDelete = true;
            RecordUser = user;
            return true;
        }
    }
    return false;
}

bool checkAccsessPermissionUser(enPermissions permissions) {
    return ((permissions & currentUser.permission) == permissions);
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

void printTheHeaderOfTheTableUsers(short countUsers) {
    cout << "\t\t\t\t\tUser List (" << countUsers << ") User(s)\n";
    cout << "---------------------------------------------------------------------------------------------------\n\n";
    cout << "| " << left << setw(15) << "User Code";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(20) << "Permission";
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

string convertRcordToStringOneLine(userData userData, string delim = "#//#") {
    string text = "";

    text += userData.userCode + delim;
    text += userData.password + delim;
    text += to_string(userData.permission);

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

void printUserCard(userData sUserData) {
    cout << "the flowing are user detials:- \n";
    cout << "-------------------------------------------\n";
    cout << "user code         : " << sUserData.userCode << endl;
    cout << "password          : " << sUserData.password << endl;
    cout << "permission        : " << sUserData.permission << endl;
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


void printUserInTable(userData recordUser) {
    cout << "| " << left << setw(15) << recordUser.userCode;
    cout << "| " << left << setw(10) << recordUser.password;
    cout << "| " << left << setw(40) << recordUser.permission;
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

userData readNewUser(string userCode, bool isAdding) {

    if (isAdding) {
        cout << "add new user:- " << endl;
    }
    else {
        cout << "update user:- " << endl;
    }
    userData userDate;

    userDate.userCode = userCode;
    cout << "enter password :- \n";
    getline(cin >> ws, userDate.password);

    userDate.permission = readUserPermission();

    return userDate;
}

void saveClientsDataToFiles(vector <clientData>& recordsClient) {
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

void saveUsersDataToFiles(vector <userData>& recordsUser) {
    fstream MyFile;
    MyFile.open(usersFileName, ios::out); // create file mode

    if (MyFile.is_open()) {
        for (userData & user : recordsUser) {
            if (!user.isDelete) {
                MyFile << convertRcordToStringOneLine(user) << endl;
            }
        }
        MyFile.close();
    }
}

void addingDataToFile(string fileName, string record) {

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
            addingDataToFile(clientsFileName, convertRcordToStringOneLine(readNewClient(accountNumber, true)));
            isFind = true;
        }
        else {
            cout << "Client Wiht [" << accountNumber << "] Aready exits, ";
            printClientCard(client);
            accountNumber = readAccountNumber("enter another an account number? ");
        }
    } while (!isFind);
}

void addNewUser(vector <userData> recordsUser) {
    userData user;
    bool isFind = false;
    string userCode = readUserCode("enter an user code? ");
    do {
        if (!findUserByUserCode(recordsUser, userCode, user)) {
            addingDataToFile(usersFileName, convertRcordToStringOneLine(readNewUser(userCode, true)));
            isFind = true;
        }
        else {
            cout << "User Wiht [" << userCode << "] Aready exits, ";
            printUserCard(user);
            userCode = readUserCode("enter another an user code? ");
        }
    } while (!isFind);
}

void printListClients(vector <clientData> recordsClient) {
    if (!checkAccsessPermissionUser(enPermissions::pShowClients)) {
        messagePermission();
        goBackToMenus();
    }
    system("cls");
    printTheHeaderOfTheTableClients(recordsClient.size());
    for (clientData& recordClient : recordsClient) {
        printClientInTable(recordClient);
    }
    cout << "\n---------------------------------------------------------------------------------------------------\n\n";
}

void printListUsers(vector <userData> usersClient) {
    if (!checkAccsessPermissionUser(enPermissions::pShowUser)) {
        messagePermission();
        goBackToMenusManageUser();
    }
    system("cls");
    printTheHeaderOfTheTableUsers(usersClient.size());
    for (userData& recordUser : usersClient) {
        printUserInTable(recordUser);
    }
    cout << "\n---------------------------------------------------------------------------------------------------\n\n";
}

void printListBlances(vector <clientData> recordsClient) {
    system("cls");
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
    if (!checkAccsessPermissionUser(enPermissions::pAddCilents)) {
        messagePermission();
        goBackToMenus();
    }
    char addMore = 'Y';
    do
    {
        system("cls");
        titleOfScrean("Add Menu Screeen");
        /* recordsClient = loadClientsFromFile(clientsFileName);*/
        addNewClient(recordsClient);
        cout << "clients added uccessfly! \ndo you want adding more ? " << endl;
        cin >> addMore;
    } while (toupper(addMore) == 'Y');

}

void addUsers(vector <userData> recordsUser) {
    if (!checkAccsessPermissionUser(enPermissions::pAddUser)) {
        messagePermission();
        goBackToMenusManageUser();
    }
    char addMore = 'Y';
    do
    {
        system("cls");
        titleOfScrean("Add Menu Screeen");
        addNewUser(recordsUser);
        cout << "users added uccessfly! \ndo you want adding more ? " << endl;
        cin >> addMore;
    } while (toupper(addMore) == 'Y');

}

void DeleteClient(vector <clientData>& recordsClient) {
    if (!checkAccsessPermissionUser(enPermissions::pDeleteClinet)) {
        messagePermission();
        goBackToMenus();
    }
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

void DeleteUser(vector <userData>& recordsUser) {
    if (!checkAccsessPermissionUser(enPermissions::pDeleteUser)) {
        messagePermission();
        goBackToMenusManageUser();
    }
    titleOfScrean("Delete Menu Screeen");
    char answer;
    string userCode = readUserCode("enter an user code? ");
    userData user;
    if (findUserAndMakeMarkToDelete(userCode, recordsUser, user)) {
        printUserCard(user);
        cout << "\n\nare you sure want delete user ? ";
        cin >> answer;
        if (toupper(answer) == 'Y') {
            saveUsersDataToFiles(recordsUser);
            cout << "the deleted user is success " << endl;
        }
    }
    else {
        cout << "the user with user code " << userCode << " not found !" << endl;
    }
}

void updateClient(vector <clientData> recordsClient) {
    if (!checkAccsessPermissionUser(enPermissions::pUpdateClient)) {
        messagePermission();
        goBackToMenus();
    }
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

void UpdateUser(vector <userData> recordsUser) {
    if (!checkAccsessPermissionUser(enPermissions::pUpdateUser)) {
        messagePermission();
        goBackToMenusManageUser();
    }
    titleOfScrean("Update Menu Screeen");
    char answer;
    string userCode = readUserCode("enter an user code? ");
    userData user;
    if (findUserByUserCode(recordsUser, userCode, user)) {
        printUserCard(user);
        cout << "\n\nare you sure want update user ? ";
        cin >> answer;
        if (toupper(answer) == 'Y') {
            for (userData & user : recordsUser) {
                if (user.userCode == userCode) {
                    user = readNewUser(userCode, false);
                    break;
                }
            }
            saveUsersDataToFiles(recordsUser);
            cout << "the update user is success " << endl;
        }
    }
    else {
        cout << "the user with user coded " << userCode << " not found !" << endl;
    }
}

void findClientWithPrintByAccountNumber(vector <clientData> recordsClient) {
    if (!checkAccsessPermissionUser(enPermissions::pFindClient)) {
        messagePermission();
        goBackToMenus();
    }
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

void findUserWithPrintByUserCode(vector <userData> recordsUser) {

    if (!checkAccsessPermissionUser(enPermissions::pFindUser)) {
        messagePermission();
        goBackToMenusManageUser();
    }

    titleOfScrean("Find Menu Screeen");
    string userCode = readUserCode("enter an user code? ");
    userData user;
    if (findUserByUserCode(recordsUser, userCode, user)) {
        printUserCard(user);
    }
    else {
        cout << "the user with user code " << userCode << " not found !" << endl;
    }
}

void depositOpration(vector <clientData> recordsClient, string accountNumber, double amount) {
    for (clientData& client : recordsClient) {
        if (client.acountNumber == accountNumber)
        {
            client.acountBalance += amount;
            saveClientsDataToFiles(recordsClient);
            cout << "\n\n Done Successfly!, now the balance is:- " << client.acountBalance << endl;
        }
    }
}

void depositeAndWithdraw(vector <clientData> recordsClient, bool isDepsite) {
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
        depositOpration(recordsClient, accountNumber, amount);
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
    cout << "\t[7] Manage User.\n";
    cout << "\t[8] Logout.\n";
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

void showAllMenusManageUsers() {
    cout << "===============================================\n";
    cout << "\t\tMenu Manage Users Screeen\n";
    cout << "===============================================\n";
    cout << "\t[1] Show Users List.\n";
    cout << "\t[2] Add New Users.\n";
    cout << "\t[3] Delete Users.\n";
    cout << "\t[4] Update Users.\n";
    cout << "\t[5] Find Users.\n";
    cout << "\t[6] Main Menu.\n";
    cout << "===============================================\n";
}




void goBackToMenusTrx() {
    cout << "\n\n\n Press Any key to go back to main menus....";
    system("pause>0");
    system("cls");
    transactionOprations();
}

void goBackToMenusManageUser() {
    cout << "\n\n\n Press Any key to go back to main menus....";
    system("pause>0");
    system("cls");
    manageUserOprations();
}

void crudOprations() {
    system("cls");
    showAllMenus();
    vector <clientData> recordsClient = loadClientsFromFile(clientsFileName);
    cout << "chose what do you want to do ? [1 - 8]? ";
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
    case choseMenus::transaction:
        transactionOprations();
        break;
    case choseMenus::manageUser:
        manageUserOprations();
        break;
    case choseMenus::exitOpration:
        loging();
        break;
    default:
        break;
    }
}

void transactionOprations() {
    if (!checkAccsessPermissionUser(enPermissions::pTransaction)) {
        messagePermission();
        goBackToMenus();
    }
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
    case choseMenusTrx::mainMenuFromTrx:
        crudOprations();
        break;
    default:
        break;
    }
    system("cls");
}

void manageUserOprations() {
    if (!checkAccsessPermissionUser(enPermissions::pManageUser)) {
        messagePermission();
        goBackToMenus();
    }
    system("cls");
    showAllMenusManageUsers();
    vector <userData> recordsUser = loadUsersFromFile(usersFileName);
    cout << "chose what do you want to do ? [1 - 6]? ";
    switch ((choseMenusManageUser)readNumberOprator())
    {
    case choseMenusManageUser::showUsers:
        printListUsers(recordsUser);
        goBackToMenusManageUser();
        break;
    case choseMenusManageUser::addUser:
        addUsers(recordsUser);
        goBackToMenusManageUser();
        break;
    case choseMenusManageUser::deleteUser:
        DeleteUser(recordsUser);
        goBackToMenusManageUser();
        break;
    case choseMenusManageUser::updateUser:
        UpdateUser(recordsUser);
        goBackToMenusManageUser();
        break;
    case choseMenusManageUser::findUser:
        findUserWithPrintByUserCode(recordsUser); 
        goBackToMenusManageUser();
        break;
    case choseMenusManageUser::mainMenuFromUser:
        crudOprations();
        break;
    default:
        break;
    }
    system("cls");
}

bool loadUserInfo(string userCode, string password) {
    vector <userData> recordsUser = loadUsersFromFile(usersFileName);
    if (findUserByUserCodeAndPassword(recordsUser, userCode, password, currentUser)) {
        return true;
    }
    return false;
}

void loging() {
    bool isLogin = false;
    string userCode, password;
    do {

        system("cls");
        titleOfScrean("Login Screeen");

        if (isLogin) {
            cout << "invalid usercode and password\n";
        }

        cout << "enter the user code ? ";
        cin >> userCode;
        cout << "enter the user password ? ";
        cin >> password;

        isLogin = loadUserInfo(userCode, password);

    } while (!isLogin);

    crudOprations();
}

//void printFile(string fileName) {
//    fstream myfile;
//    myfile.open(fileName, ios::in);
//    vector <userData> recordsUser;
//    if (myfile.is_open()) {
//
//        string line;
//
//        while (getline(myfile, line)) {
//            cout << line << endl;
//        }
//    }
//
//    myfile.close();
//
//}
int main()
{

    loging();
    //printFile(usersFileName);

}

