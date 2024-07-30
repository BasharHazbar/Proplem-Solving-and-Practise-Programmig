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

char readChar(string message) {
    char letter;
    cout << message << endl;
    cin >> letter;
    //cin.ignore();
    return letter;
}

char invertLetterCase(char letter) {
    return isupper(letter) ? tolower(letter) : toupper(letter);
}

short countLetter(string text, char letter, bool machesCase = true) {
    short counter = 0;
    for (short i = 0; i < text.length(); i++) {
        if (machesCase) {
            if (text[i] == letter) {
                counter++;
            }
        }
        else {
            if (tolower(text[i]) == tolower(letter)) {
                counter++;
            }
        }
    }
    return counter;
}

//short countLetterWithIgnoreCase(string text, char letter) {
//    short counter = 0;
//    for (short i = 0; i < text.length(); i++) {
//        if (text[i] == toupper(letter) || text[i] == tolower(letter)) {
//            counter++;
//        }
//    }
//    return counter;
//}



int main()
{
    string text = readString("enter a text :- ");

    char letter = readChar("enter a letter :- ");

    cout << "count of letter '" << letter << "' is:- " << countLetter(text, letter) << endl;

    cout << "count letter '" << letter << "' Or '" << invertLetterCase(letter) << "' is:- " <<
        countLetter(text, letter, false);


}

