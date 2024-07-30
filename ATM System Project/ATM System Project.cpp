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

clientData curentClient;

void ATMSystemMenus();

void quickWithdrawMenu();

enum choseATMSystemMenus {
    QuickWithdraw = 1, NormalWithdraw = 2, Deposite = 3, CheckBalance = 4, Logout = 5
};

enum choseQuickWithdrawMenus{
     twenty = 1, fifty = 2, oneHandred = 3, towHandred = 4, fourHandred = 5, sixHandred = 6,
     eightHandred = 7, oneThousand = 8, Exite = 9
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

bool findClientByAccountNumberAndPinCode(vector <clientData>& recordsClient, string accountNumber, string pinCode, clientData& RecordClient) {
    for (clientData& client : recordsClient) {
        if (client.acountNumber == accountNumber && client.pinCode == pinCode) {
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

void depositeAndWithdrawAndQuikWithdraw(vector <clientData> recordsClient, bool isDepsite, bool isQuikWithdraw = false, short quikWithdrawValue = 0) {
    if (!isQuikWithdraw) {
        if (isDepsite) {
            titleOfScrean("Deposit Menu Screeen");
        }
        else {
            titleOfScrean("Witraw hd Menu Screeen");
        }
    }
    int amount = 0;
    char answer = 'n';


    if (!isQuikWithdraw && !isDepsite) {
        do
        {
            cout << "\nplease enter amount multiple 5's :- ";
            cin >> amount;

        } while (amount % 5 != 0);
    }
    else {
        amount = quikWithdrawValue;
    }
    if (isDepsite) {
        do {
            cout << "\n\nenter a positive deposite amount ? ";
            cin >> amount;

        } while (amount <= 0);

    }

    cout << "\n\nAre you sure do want perfprm thi transaction ? y/n  ";
    cin >> answer;

    if (tolower(answer) == 'y') {
        if (isDepsite) {
            depositOpration(recordsClient, curentClient.acountNumber, amount);
            curentClient.acountBalance += amount;
        }
        else {

            if (isQuikWithdraw){
                if (amount > curentClient.acountBalance) {
                    cout << "\n\nthe amount exceeds your balance, make another choice. ";
                    cout << "\npress any key....";
                    system("pause>0");
                }
                else {
                    depositOpration(recordsClient, curentClient.acountNumber, amount * -1);
                    curentClient.acountBalance -= amount;
                }
                
            }
            else {
                while (amount > curentClient.acountBalance)
                {
                    cout << "\n\nthe amount exceeds the balance, please enter another withdraw amount? ";
                    cin >> amount;
                }
                depositOpration(recordsClient, curentClient.acountNumber, amount * -1);
                curentClient.acountBalance -= amount;
            }
            
        }
    }
}

bool loadClientInfo(string accountNumber, string pinCode) {
    vector <clientData> recordsClient = loadClientsFromFile(clientsFileName);
    if (findClientByAccountNumberAndPinCode(recordsClient,accountNumber,pinCode,curentClient)) {
        return true;
    }
    return false;
}

void showAllMenusATMSystem() {
    cout << "===============================================\n";
    cout << "\t\tATM Main Menu Screeen\n";
    cout << "===============================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposite.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===============================================\n";
}

void showMenusQuickWithdraw() {
    cout << "===============================================\n";
    cout << "\t\tQuick Withdraw Screeen\n";
    cout << "===============================================\n";
    cout << "\t[1] 20\t\t[2]50\n";
    cout << "\t[3] 100\t\t[4]200\n";
    cout << "\t[5] 400\t\t[6]600\n";
    cout << "\t[7] 800\t\t[8]1000\n";
    cout << "\t[9] Main Menu.\n";
    cout << "===============================================\n";
}

void goBackToMenusTrxATMSystemMenus(){
    cout << "\n\n\n Press Any key to go back to main menus....";
    system("pause>0");
    system("cls");
    ATMSystemMenus();
}

void goBackToMenusQuikWithdrow() {
    cout << "\n\n\n Press Any key to go back to main menus....";
    system("pause>0");
    system("cls");
    quickWithdrawMenu();
}

void loging() {
    bool isFaildLogin = false;
    string accountNumber, pinCode;
    do {

        system("cls");
        titleOfScrean("Login Screeen");

        if (isFaildLogin) {
            cout << "invalid account number and pin code \n";
        }

        cout << "enter the account number ? ";
        cin >> accountNumber;
        cout << "enter the pin code ? ";
        cin >> pinCode;

        isFaildLogin = !loadClientInfo(accountNumber, pinCode);

    } while (isFaildLogin);

    ATMSystemMenus();
}

void checkBalanceClient() {
    system("cls");
    titleOfScrean("Check Balance Screen");
    cout << "your Balance is  " << curentClient.acountBalance << endl;
}

void quickWithdrawMenu() {
    system("cls");
    showMenusQuickWithdraw();
    vector <clientData> recordsClient = loadClientsFromFile(clientsFileName);
    cout << "your Balance is  " << curentClient.acountBalance << endl;
    cout << "chose what do you want to do ? [1 - 9]? ";
    switch ((choseQuickWithdrawMenus)readNumberOprator())
    {
    case choseQuickWithdrawMenus::twenty:
        depositeAndWithdrawAndQuikWithdraw(recordsClient,false,true,20);
        goBackToMenusQuikWithdrow();
        break;
    case choseQuickWithdrawMenus::fifty:
        depositeAndWithdrawAndQuikWithdraw(recordsClient, false, true, 50);
        goBackToMenusQuikWithdrow();
        break;
    case choseQuickWithdrawMenus::oneHandred:
        depositeAndWithdrawAndQuikWithdraw(recordsClient, false, true, 100);
        goBackToMenusQuikWithdrow();
        break;
    case choseQuickWithdrawMenus::towHandred:
        depositeAndWithdrawAndQuikWithdraw(recordsClient, false, true, 200);
        goBackToMenusQuikWithdrow();
        break;
    case choseQuickWithdrawMenus::fourHandred:
        depositeAndWithdrawAndQuikWithdraw(recordsClient, false, true, 400);
        goBackToMenusQuikWithdrow();
        break;
    case choseQuickWithdrawMenus::sixHandred:
        depositeAndWithdrawAndQuikWithdraw(recordsClient, false, true, 600);
        goBackToMenusQuikWithdrow();
        break;
    case choseQuickWithdrawMenus::eightHandred:
        depositeAndWithdrawAndQuikWithdraw(recordsClient, false, true, 800);
        goBackToMenusQuikWithdrow();
        break;
    case choseQuickWithdrawMenus::oneThousand:
        depositeAndWithdrawAndQuikWithdraw(recordsClient, false, true, 1000);
        goBackToMenusQuikWithdrow();
        break;
    case choseQuickWithdrawMenus::Exite:
        ATMSystemMenus();
        break;
    default:
        break;
    }
}

void ATMSystemMenus() {
    system("cls");
    showAllMenusATMSystem();
    vector <clientData> recordsClient = loadClientsFromFile(clientsFileName);
    cout << "chose what do you want to do ? [1 - 5]? ";
    switch ((choseATMSystemMenus)readNumberOprator())
    {
    case choseATMSystemMenus::QuickWithdraw:
        quickWithdrawMenu();
        goBackToMenusTrxATMSystemMenus();
        break;
    case choseATMSystemMenus::NormalWithdraw:
        depositeAndWithdrawAndQuikWithdraw(recordsClient,false);
        goBackToMenusTrxATMSystemMenus();
        break;
    case choseATMSystemMenus::Deposite:
        depositeAndWithdrawAndQuikWithdraw(recordsClient, true);
        goBackToMenusTrxATMSystemMenus();
        break;
    case choseATMSystemMenus::CheckBalance:
        checkBalanceClient();
        goBackToMenusTrxATMSystemMenus();
        break;
    case choseATMSystemMenus::Logout:
        loging();
        break;
    default:
        break;
    }
}

int main()
{
    loging();
}

