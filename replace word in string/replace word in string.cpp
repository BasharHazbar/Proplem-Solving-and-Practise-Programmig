// replace word in string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> splitString(string text, string delim) {
    short pos = 0;
    string sWord;
    vector <string> vString;
    while ((pos = text.find(delim)) != std::string::npos) {
        sWord = text.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        text.erase(0, pos + delim.length());
    }
    if (text != "")
    {
        vString.push_back(text);
    }
    return vString;
}

string lowerAll(string text) {
    for (short i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            text[i] = tolower(text[i]);
        }
    }
    return text;
}

string joinString(vector <string> vString, string delim) {
    string text;
    for (string& word : vString) {
        text += word + delim;
    }
    return text.substr(0, text.length() - delim.length());
}

string replacedWord(string text, string mainWord, string replaceWord, bool matches = true, string delim = " ") {
    vector <string> vSplitString = splitString(text,delim);

    for (string & word : vSplitString) {
        if (matches) {
            if (word == mainWord) {
                word = replaceWord;
            }
        }
        else {
            if (lowerAll(word) == lowerAll(mainWord)) {
                word = replaceWord;
            }
        }
    }
    return joinString(vSplitString, delim);
}

int main()
{
    string text = "hallo i am ali , form Indonesia , indonesia is a nice country !";
    string mainWord = "Indonesia";
    string replaceWord = "yemen";

    cout << "replace in matcthes:- \n" << replacedWord(text, mainWord, replaceWord) << "\n\n";

    cout << "replace without matcthes:- \n\n" << replacedWord(text, mainWord, replaceWord, false) << "\n\n";

   
 
    
}
