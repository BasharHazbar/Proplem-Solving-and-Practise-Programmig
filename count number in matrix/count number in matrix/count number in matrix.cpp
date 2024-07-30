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
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void printMatrix(int arr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf(" %0*d ", 2,arr[i][j]);
		}
		cout << endl;
	}
}

short findCountNumberInMatrix(int arr[3][3], int number, int rows, int cols) {
	short countNumber = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == number) {
				countNumber++;
			}
		}

	}
	return countNumber;
}

int main()

{
	//srand((unsignrd)time(NULL));

	int matrix1[3][3], number;

	cout << "matrix 1 3x3:- \n\n";

	fillMatrix(matrix1, 3, 3);
	printMatrix(matrix1, 3, 3);

	cout << "enter a number for count it in matrix:- " << endl;
	cin >> number;

	cout << "number " << number << " count in matrix is " << findCountNumberInMatrix(matrix1, number, 3, 3);

}
