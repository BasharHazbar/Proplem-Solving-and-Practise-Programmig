// static value in class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class MyClass
{ 
	int value = 0;
	static int counter;
public:
	MyClass() {
		counter++;
		value++;
	};

	int getCounter() {
		return counter;
	}
	int getValue() {
		return value;
	}

};


int main()
{
	MyClass sClass;
	cout << sClass.getCounter() << endl;
	cout << sClass.getValue() << endl;

	MyClass sClass1;
	cout << sClass1.getCounter() << endl;
	cout << sClass1.getValue() << endl;

	MyClass sClass2;
	cout << sClass2.getCounter() << endl;
	cout << sClass2.getValue() << endl;

	MyClass sClass3;
	cout << sClass3.getCounter() << endl;
	cout << sClass3.getValue() << endl;

	
}

