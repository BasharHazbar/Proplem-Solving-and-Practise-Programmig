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




short countLetter(string text, char letter) {
    short counter = 0;
    for (short i = 0; i < text.length(); i++) {
        if (text[i] == letter) {
            counter++;
        }
    }
    return counter;
}


int main()
{
    string text = readString("enter a text :- ");

    char letter = readChar("enter a letter :- ");

    cout << "the count of letter '" << letter << "' is:- " << countLetter(text, letter);

}

