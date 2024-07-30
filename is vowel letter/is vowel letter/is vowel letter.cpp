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

//char invertLetterCase(char letter) {
//    return isupper(letter) ? tolower(letter) : toupper(letter);
//}

bool isVowelLetter(string text, char letter) {
    for (short i = 0; i < text.length(); i++) {
        if (text[i] == tolower(letter)) {
            return true;
        }
    }
    return false;
}

bool isVowelLetter(char chr) {
    chr = tolower(chr);
    return((chr == 'a') || (chr == 'e') || (chr == 'i') || (chr == 'o') || (chr == 'u'));
}

int main() {
    string text = "aeiou";
    char letter = readChar("enter a letter:- ");
    if (isVowelLetter(letter)) {
        cout << "yes letter '" << letter << "' is a vowel letter";
    }
    else {
        cout << "yes it is not a vowel letter";
    }
}
    

