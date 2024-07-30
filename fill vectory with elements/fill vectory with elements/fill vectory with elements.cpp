// fill vectory with elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void readNumber(vector  <int> & vNumbers) {
	char isEnter;
	do
	{
		int number;
		cout << "please enter a number:- ";
		cin >> number;
		vNumbers.push_back(number);
		cout << "do you want enter a more number :- [y]yes : [n]no :- ";
		cin >> isEnter;

	} while (isEnter != 'n');
}

void printVectorNumbers(vector <int> & vNumbers) {
	for (int & number : vNumbers) {
		cout << number << " ";
	}
}

int main()
{
	vector <int> vNumbers;
	readNumber(vNumbers);
	printVectorNumbers(vNumbers);

}

