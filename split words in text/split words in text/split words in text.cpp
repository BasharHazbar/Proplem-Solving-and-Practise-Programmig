#include <iostream>
#include <string>
#include <vector>

using namespace std;


string readString(string message) {
    string text;
    cout << message << endl;
    getline(cin, text);
    //cin.ignore();
    return text;
}


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


int main() {
    string text = readString("enter a text:- ");

    vector <string> vString = splitString(text,"##");
    cout << "tokens:- " << vString.size() << endl;
    for (string& words : vString) {
        cout << words << endl;
    }
}


