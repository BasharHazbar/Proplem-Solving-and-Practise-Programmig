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

//void printTheFirstLetterOfWords(string text) {
//    cout << "the first letters are:- " << endl;
//    for (short i = 0; i < text.length(); i++) {
//        if (i == 0) {
//            cout << text[0] << "  ";
//        }
//        else {
//            if (text[i] == ' ') {
//                cout << text[++i] << "  ";
//                --i;
//            }
//        }
//
//    }


string upperFirstLetterForEachWord(string  text) {
    bool isFirstLetter = true;
    for (short i = 0; i < text.length(); i++) {
        if (text[i] != ' ' && isFirstLetter) {
            text[i] = tolower(text[i]);
        }
        isFirstLetter = text[i] == ' ' ? true : false;
    }
    return text;
}

int main()
{
    //cout << "the text is:- " << readString("enter the text:- ") << endl;
    string text = readString("enter a text:- ");
    cout << "the text before convert:- \n" << text << endl;

    text = upperFirstLetterForEachWord(text);

    cout << "the text before convert:- \n" << text << endl;



    //cout << "\nthe second way:- " << endl;
    //printTheFirstLetterOfWordsAnotherWay(text);
}

