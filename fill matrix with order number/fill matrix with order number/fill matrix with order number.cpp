// fill matrix with order number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void fillMatrixWithRandomNumber(int arr[3][3], short rows, short cols) {
	short counter = 1;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			arr[i][j] = counter++;
		}
	}
}

void printMatrixWithRandomNumber(int arr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << arr[i][j] << "         ";
		}
		cout << endl;
	}
}

int main()
{
	int array[3][3];
	fillMatrixWithRandomNumber(array, 3, 3);
	printMatrixWithRandomNumber(array, 3, 3);
    std::cout << "Hello World!\n";
}
