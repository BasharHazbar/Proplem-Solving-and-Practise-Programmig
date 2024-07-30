
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

void readArrayWithKeys(string array[], int length,enTypeChar typeCharOfKey, int lenghtOfWord) {
	for (int i = 0; i < length; i++) {
		array[i] = generateKey(typeCharOfKey, lenghtOfWord);
	}

}

void printArray(string array[], int length) {

	for (int i = 0; i < length; i++) {
		cout << "key" << "[" << i + 1 << "]: " << array[i] << endl;
	}
	cout << endl;
}




int main()
{
	const int lenght = readPositiveNumber("enter how many length of array:- ");
	int lenghtOfWord = readPositiveNumber("enter the length of digit for every word:- ");
	enTypeChar typeCharOfKey = readTypeOfChar("enter 1=SL, 2=CL, 3=EC, 4=DN:- ");


	string array[100], array2[100];

	readArrayWithKeys(array, lenght, typeCharOfKey, lenghtOfWord);
	cout << "array1 elements:- " << endl;
	printArray(array, lenght);



	//cout << "the max number is:- " << findMaxNum(array, lenght) << endl;
	//cout << "the min number is:- " << findMinNum(array, lenght) << endl;
	//cout << "the sum numbers is:- " << findSumNums(array, lenght) << endl;
	//cout << "the avrage numbers is:- " << findAvargeNumbers(array, lenght) << endl;

	return 0;
}

