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

string toUpperCase(string  text) {
    for (short i = 0; i < text.length(); i++) {
        text[i] = toupper(text[i]);
    }
    return text;
}

string toLowerCase(string  text) {
    for (short i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    return text;
}

int main()
{
    string text = readString("enter a text:- ");
    cout << "the text before convert:- \n" << text << endl;

    text = toUpperCase(text);

    cout << "text in upper case:- \n" << text << endl;

    text = toLowerCase(text);

    cout << "text in lower case:- \n" << text << endl;

}

