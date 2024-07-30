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

string replacedWordInString(string text, string mainWord, string replaceToWord) {
    short pos = text.find(mainWord);
    while (pos != std::string::npos)
    {
        text.replace(pos, mainWord.length(), replaceToWord);
        pos = text.find(mainWord);
    }
    return text;
}

int main() {
    string text = readString("enter a text:- ");

    cout << "the main string:- \n" << text << endl;

    string replaceWord = " ", mainWord;
    cout << "enter the mainWord:- " << endl;
    cin >> mainWord;

    cout << "enter the replaceWord:- " << endl;
    cin >> replaceWord;

    cout << "the string replaced into:- " << replacedWordInString(text,mainWord,replaceWord);
    
}


