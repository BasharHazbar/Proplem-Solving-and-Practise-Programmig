// void pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	void * ptr;
	int x = 30;

	ptr = &x;

	cout << "ptr :- " << ptr << endl;
	cout << "*ptr :- " << *(static_cast<int*>(ptr)) << endl;

	float y = 14.30;

	ptr = &y;

	cout << "ptr 2 :- " << ptr << endl;
	cout << "*ptr 2 :- " << *(static_cast<float*>(ptr));




}

