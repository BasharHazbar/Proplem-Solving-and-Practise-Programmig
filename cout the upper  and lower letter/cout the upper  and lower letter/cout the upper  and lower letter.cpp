#include <iostream>
#include <string>

using namespace std;

enum enWhatToCoint { capitalLetter = 1, smallLetter = 2, all = 3 };

short countLetters();

string readString(string message) {
    string text;
    cout << message << endl;
    getline(cin, text);
    //cin.ignore();
    return text;
}

short countLetters(string text, enWhatToCoint whatToCount = enWhatToCoint::all) {
    short counter = 0;
    if (whatToCount == enWhatToCoint::all) {
        return text.length();
    }
    for (short i = 0; i < text.length(); i++) {
        if (isupper(text[i]) && whatToCount == enWhatToCoint::capitalLetter) {
            counter++;
        }
        else if (islower(text[i]) && whatToCount == enWhatToCoint::smallLetter) {
            counter++;
        }
    }
    return counter;
}

short coutCapitalLetters(string  text) {
    short counter = 0;
    for (short i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            counter++;
        }
    }
    return counter;
}

short coutSmallLetters(string  text) {
    short counter = 0;
    for (short i = 0; i < text.length(); i++) {
        if (islower(text[i])) {
            counter++;
        }
    }
    return counter;
}



int main()
{
    string text = readString("enter a text:- ");

    cout << "the length is:-" << text.length() << endl;

    cout << "the count capital letter are:- " << coutCapitalLetters(text) << endl;

    cout << "the count capital letter are:- " << coutSmallLetters(text) << endl;

    cout << "\n\nmethod 2\n\n";

    cout << "the length is:-" << countLetters(text) << endl;

    cout << "the count capital letter are:- " << countLetters(text,enWhatToCoint::capitalLetter) << endl;

    cout << "the count capital letter are:- " << countLetters(text, enWhatToCoint::smallLetter) << endl;
    //text = toUpperCase(text);

    //cout << "text in upper case:- \n" << text << endl;

    //text = toLowerCase(text);

    //cout << "text in lower case:- \n" << text << endl;

}

