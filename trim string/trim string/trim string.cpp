
#include <iostream>
#include <string>

using namespace std;

string trimLeft(string text) {
    for (short i = 0; i < text.length() - 1; i++) {
        if (text[i] != ' ') {
            return text.substr(i, text.length() - i);
        }
    }
    return "";
}

string trimRight(string text) {
    for (short i = text.length() - 1; i > 0; i--) {
        if (text[i] != ' ') {
            return text.substr(0, i + 1);
        }
    }
    return "";
}

string trim(string text) {
    return trimLeft(trimRight(text));
}

int main()
{
  
    string text = "                bashar abdulwahab        ";
    cout << "trim left  = " << trimLeft(text) << endl;
    cout << "trim right = " << trimRight(text) << endl;
    cout << "trim       = " << trim(text) << endl;
}
