// fill matrix with order number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void fillMatrixWithOrderedNumber(int arr[3][3], short rows, short cols) {
	short counter = 1;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			arr[i][j] = counter++;
		}
	}
}

void convertToTransposedArray(int arr[3][3], int transposedArr[3][3], short rows, short cols) {
	short counter = 1;
	for (short i = 0; i < rows; i++) 
	{
		for (short j = 0; j < cols; j++)
		{
			transposedArr[j][i] = arr[i][j];
		}
		cout << endl;
	}
}

void printMatrix(int arr[3][3], short rows, short cols) {
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
	int array[3][3], transposedArr[3][3];
	fillMatrixWithOrderedNumber(array, 3, 3);
	printMatrix(array, 3, 3);
	convertToTransposedArray(array, transposedArr, 3, 3);
	printMatrix(transposedArr, 3, 3);
	std::cout << "Hello World!\n";
}
