#include <iostream>
#include <string>

using namespace std;


string readString(string message) {
    string text;
    cout << message << endl;
    getline(cin, text);
    //cin.ignore();
    return text;
}

//void PrintEachWordInString(string S1) {
//    string delim = " "; // delimiter 
//    cout << "\nYour string wrords are: \n\n";
//    short pos = 0;
//    string sWord;
//    while ((pos = S1.find(delim)) != std::string::npos) {
//        sWord = S1.substr(0, pos);
//        if (sWord != "")
//        {
//            cout << sWord << endl;
//        }
//        S1.erase(0, pos + delim.length());
//    }
//    if (S1 != "")
//    {
//        cout << S1 << endl; // it print last word of the string.
//    }
//}

short countEachWordInString(string text) {
    short counter = 0;
    string delim = " ";
    short pos = 0;
    string sWord;
    while ((pos = text.find(delim)) != std::string::npos) {
        sWord = text.substr(0, pos);
        if (sWord != "")
        {
            counter++;
        }
        text.erase(0, pos + delim.length());
    }
    if (text != "")
    {
        counter++;
    }
    return counter;
}



//void printWordsOfText(string text) {
//    cout << "the words of text are:- " << endl;
//    for (short i = 0; i < text.length(); i++) {
//        cout << text[i];
//        if (text[i] == ' ') {
//            cout << "\n";
//        }
//    }
//}

int main() {
    string text = readString("enter a text:- ");

    cout << "the count of each words in text:- " << countEachWordInString(text);

}


