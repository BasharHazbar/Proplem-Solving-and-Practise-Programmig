
#include <iostream>
#include <string>
using namespace std;

enum enOprationType { add = '+', substract = '-', multi = '*', divided = '/' };

int readPositiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;
		cin >> number;
	} while (number < 1);
	return number;
}


int calcOpration(int number_1, int number_2) {
	char opType = ' ';
	cout << "enter the type of opration:- " << endl;
	cin >> opType;
	switch ((enOprationType)opType)
	{
	case enOprationType::add:
		return number_1 + number_2;
	case enOprationType::substract:
		return number_1 - number_2;
	case enOprationType::multi:
		return number_1 * number_2;
	case enOprationType::divided:
		return number_1 / number_2;
	default:
		break;
	}
}

void printNumber(int number){
	cout << "the result is  " << number;
}



int main()
{	
	int number_1 = readPositiveNumber("enter a positive number:- ");
	int number_2 = readPositiveNumber("enter a positive number:- ");

	printNumber(calcOpration(number_1, number_2));
	return 0;
}

