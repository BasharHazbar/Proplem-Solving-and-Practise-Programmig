// encrypt and decrypt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string readText(string message) {
    string text;
    cout << message << endl;
    getline(cin, text);
    return text;
}

string encryptText(string text, int ecryptedKey) {
    cout << "encryptText ============================= \n";
    for (int i = 0; i < text.length(); i++) {

        cout << "(int)text[i]:- " << (int)text[i] << endl;
        cout << "((int)text[i] + ecryptedKey):- " << ((int)text[i] + ecryptedKey) << endl;
        text[i] = char((int)text[i] + ecryptedKey);
    }

    return text;
}

string decryptText(string text, int ecryptedKey) {
    cout << "decryptText ============================= \n";
    for (int i = 0; i < text.length(); i++) {
        cout << "(int)text[i]:- " << (int)text[i] << endl;
        cout << "((int)text[i] + ecryptedKey):- " << ((int)text[i] - ecryptedKey) << endl;
        text[i] = char((int)text[i] - ecryptedKey);
    }

    return text;
}

int main()
{
    string text = readText("enter a text to encrypt:- ");
    const short encryptedKey = -99;
    string textBeforEncrypted = encryptText(text,encryptedKey);
    string textAfterEncrypted = decryptText(textBeforEncrypted, encryptedKey);

    cout << "text Befor Encrypted: " << text << endl;
    cout << "text after Encrypted: " << textBeforEncrypted << endl;
    cout << "text after Decrypted: " << textAfterEncrypted << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
