// ConsoleApplication8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void readNumber(int& a, int& b) {
	cout << "enter value of 'a' " << endl;
	cin >> a;
	cout << "enter value of 'b' " << endl;
	cin >> b;
}

float getArea(int a, int h) {
	float area = (float) (a * h) / 2;
	return area;
}

void printArea(float area) {
	cout << "the area of rectangle is " << area << endl;
}

int main()
{
	int a = 0, h = 0;
	readNumber(a, h);
	printArea(getArea(a, h));
	

}
