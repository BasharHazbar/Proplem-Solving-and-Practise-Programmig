#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
	//Function to generate a random number 
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void fillMatrixWithRandomNumber(int arr[3][3], short rows, short cols) {
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
			printf(" %0*d ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

int sumOfMatrix(int arr[3][3], short rows, short cols) {
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}


int main()
{
	//srand((unsignrd)time(NULL));

	int matrix1[3][3];

	cout << "matrix 1 3x3:- \n\n";

	fillMatrixWithRandomNumber(matrix1, 3, 3);
	printMatrix(matrix1, 3, 3);

	cout << "the sum of matrix is:- " << sumOfMatrix(matrix1, 3, 3);


	//cout << "matrix 2 3x3:- \n\n";

	//fillMatrixWithRandomNumber(matrix2, 3, 3);
	//printMatrix(matrix2, 3, 3);

	//cout << "result multiMatrix 3 3x3:- \n\n";

	//multiTowMatrix(matrix1, matrix2, multiMatrix, 3, 3);
	//printMatrix(multiMatrix, 3, 3);


}
