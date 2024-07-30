// Remove Punctuations From String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string RemovePunctuationsFromString(string text) {
    string text_2 = "";
    for (short i = 0; i < text.length(); i++) {
        if (!ispunct(text[i])) {
            text_2 += text[i];
        }
    }
    return text_2;
}


int main()
{
    string text = "hallo, i am basshar, frome yemen; i love you all !";

    cout << "the original text is:-  \n" << text << "\n\n";

    cout << "text after remove punctuations:-  \n" << RemovePunctuationsFromString(text);

}

