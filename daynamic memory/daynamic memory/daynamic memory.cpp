// daynamic memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()

{
	int* pntr, number;
	cout << "please enter the length of array:- " << endl;
	cin >> number;

	// please i want (number address in memory)
	pntr = new int[number];
	// fill array
	for (int i = 0; i < number; i++) {
		*(pntr + i) = i + 1;
	}

	// print array
	for (int i = 0; i < number; i++) {
		cout << "value of address " << pntr + i << " is:- " << *(pntr + i) << endl;
	}

	delete[] pntr;
}

