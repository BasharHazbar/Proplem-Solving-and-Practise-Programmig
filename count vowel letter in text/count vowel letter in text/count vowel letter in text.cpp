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

//char readChar(string message) {
//    char letter;
//    cout << message << endl;
//    cin >> letter;
//    //cin.ignore();
//    return letter;
//}

bool isVowelLetter(char chr) {
    chr = tolower(chr);
    return((chr == 'a') || (chr == 'e') || (chr == 'i') || (chr == 'o') || (chr == 'u'));
}

short countVowelLetters(string text) {
    short counter = 0;
    for (short i = 0; i < text.length(); i++) {
        if (isVowelLetter(text[i])) {
            counter++;
        }
    }
    return counter;
}

int main() {
    string text = readString("enter a text:- ");
    
    cout << "count vowels letter in text are:- " << countVowelLetters(text);

}


