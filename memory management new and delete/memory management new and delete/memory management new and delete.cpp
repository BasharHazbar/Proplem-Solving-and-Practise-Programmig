// memory management new and delete.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int* ptrx;
	float* ptry;

	ptrx = new int;
	ptry = new float;

	*ptrx = 123;
	*ptry = 2323.343f;

	cout << "*ptrx:- " << *ptrx << endl;
	cout << "*ptry:- " << *ptry << endl;

	delete ptrx;
	delete ptry;


}

