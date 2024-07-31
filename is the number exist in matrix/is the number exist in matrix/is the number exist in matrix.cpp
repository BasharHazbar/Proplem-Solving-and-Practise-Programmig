#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
	//Function to generate a random number 
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void fillMatrix(int arr[3][3], short rows, short cols) {
	short number = RandomNumber(1, 10);
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			arr[i][j] = RandomNumber(1,50);
		}
	}
}

void printMatrix(int arr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf(" %d ", arr[i][j]);
		}
		cout << endl;
	}
}

bool isNumberExist(int arr[3][3], int number, int rows, int cols) {
	short countNumber = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == number) {
				return true;
			}
		}

	}
	return false;
}


int main()
{
	//srand((unsignrd)time(NULL));

	int matrix1[3][3], number;

	cout << "matrix 1 3x3:- \n\n";

	fillMatrix(matrix1, 3, 3);
	printMatrix(matrix1, 3, 3);

	cout << "enter a number to check is exist:- " << endl;
	cin >> number;
	if (isNumberExist(matrix1,number, 3, 3))
	{
		cout << "number " << number << " is exist in matrix " << endl;
	}
	else
	{
		cout << "number " << number << " is not exist in matrix " << endl;
	}
}
