// conver char to upper and lower.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

char readLetter(string message) {
	cout << message << endl;
	char letter;
	cin >> letter;
	return letter;
}

//char invertingCharCase(char letter) {
//	if (isupper(letter)) {
//		letter = tolower(letter);
//	}
//	else {
//		letter = toupper(letter);
//	}
//	return letter;
//}

char invertingCharCase(char letter) {
	return isupper(letter) ? tolower(letter) : toupper(letter);
}

int main()
{
	char letter = readLetter("enter a letter:- ");
	letter = invertingCharCase(letter);
	cout << "the char after inverting!! " << endl;
	cout << letter << endl;


   
}

