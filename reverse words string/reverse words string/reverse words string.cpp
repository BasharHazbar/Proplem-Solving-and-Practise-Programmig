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

string reverseWordsInString(string text, string delim = " ") {
    vector <string> vText = splitString(text, delim);
    string sText;

    vector <string>::iterator iter = vText.end();
    while (iter != vText.begin())
    {
        --iter;
        sText += *iter + " ";
        
    }
    return sText.substr(0, sText.length() - 1);
}

int main() {
    string text = readString("enter a text:- ");
    string delim = " ";
    cout << "enter the delimeter:- " << endl;
    cin >> delim;

    vector <string> vString = splitString(text, delim);
    cout << "tokens:- " << vString.size() << endl;
    for (string& words : vString) {
        cout << words << endl;
    }
   cout << "the reverse:- " <<  reverseWordsInString(text,delim);
}


