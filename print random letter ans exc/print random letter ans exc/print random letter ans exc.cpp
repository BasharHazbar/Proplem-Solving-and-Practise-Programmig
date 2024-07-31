#include<iostream>
#include<cstdlib>
using namespace std;


enum enTypeChar {smallLatter = 1, CapitalLatter = 2, espicialCharater = 3, digitNumber = 4};


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



int main() {   
	srand((unsigned)time(NULL));

	cout << getRandomChar(enTypeChar::smallLatter);
	cout << endl;
	cout << getRandomChar(enTypeChar::CapitalLatter);
	cout << endl;
	cout << getRandomChar(enTypeChar::espicialCharater);
	cout << endl;
	cout << getRandomChar(enTypeChar::digitNumber);
	return 0;
}