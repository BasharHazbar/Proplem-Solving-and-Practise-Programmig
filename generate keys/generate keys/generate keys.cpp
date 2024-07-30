// generate keys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


enum enTypeChar { smallLatter = 1, CapitalLatter = 2, espicialCharater = 3, digitNumber = 4 };

int readPositiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}

enTypeChar readTypeOfChar(string message) {
	int number = 0;
	do {
		cout << message << endl;
		cin >> number;
	} while (number <= 0);
	return (enTypeChar)number;
}

int RandomNumber(int From, int To) {
	//Function to generate a random number 
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}


char getRandomChar(enTypeChar type) {
	switch (type)
	{
	case enTypeChar::smallLatter:
		return char(RandomNumber(97, 122));
		break;
	case enTypeChar::CapitalLatter:
		return char(RandomNumber(65, 90));
		break;
	case enTypeChar::espicialCharater:
		return char(RandomNumber(33, 47));
		break;
	case enTypeChar::digitNumber:
		return char(RandomNumber(48, 57));
		break;
	default:
		break;
	}
}



string generateWord(enTypeChar typeCharOfKey,int lenghtOfWord){
	string word = "";
	for (int i = 1; i <= lenghtOfWord; i++) {
		word = word + getRandomChar(typeCharOfKey);
	}
	return word;
}

string generateKey(enTypeChar typeCharOfKey,int lenghtOfWord) {
	string key = generateWord(typeCharOfKey, lenghtOfWord) + "-" + generateWord(typeCharOfKey, lenghtOfWord)
		+ "-" + generateWord(typeCharOfKey, lenghtOfWord) + "-" + generateWord(typeCharOfKey, lenghtOfWord);
	return key;

}

void generateKeys(int countOfGenerateOfKeys, enTypeChar typeCharOfKey, int lenghtOfWord) {
	for (int i = 1; i <= countOfGenerateOfKeys; i++) {
		cout << "key" << "[" << i << "]: " << generateKey(typeCharOfKey, lenghtOfWord) << endl;
	}
}

int main()
{	
	int lenghtOfWord = readPositiveNumber("enter the length of digit for every word:- ");
	enTypeChar typeCharOfKey = readTypeOfChar("enter 1=SL, 2=CL, 3=EC, 4=DN:- ");
	int countOfGenerateOfKeys = readPositiveNumber("enter cout of keys you want generate:- ");

	generateKeys(countOfGenerateOfKeys, typeCharOfKey, lenghtOfWord);
	return 0;
}
