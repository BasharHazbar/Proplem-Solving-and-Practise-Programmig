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
			if (i == j) {
				arr[i][j] = number;
			}
			else {
				arr[i][j] = number;
			}
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


bool isScalarMatrix(int arr[3][3], short rows, short cols) {
	int theFirstDiagonalNumber = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j && arr[i][j] != theFirstDiagonalNumber) {
				return false;
			}
			else if (i != j && arr[i][j] != 0) {
				return false;
			}
		}

	}
	return true;
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

	int matrix1[3][3], matrix2[3][3];

	cout << "matrix 1 3x3:- \n\n";

	fillMatrix(matrix1, 3, 3);
	printMatrix(matrix1, 3, 3);

	//cout << "matrix 2 3x3:- \n\n";

	//fillMatrixWithRandomNumber(matrix2, 3, 3);
	//printMatrix(matrix2, 3, 3);

	if (isScalarMatrix(matrix1, 3, 3))
	{
		cout << "the matrices is scalar " << endl;
	}
	else
	{
		cout << "the matrices is not scalar " << endl;
	}

	//int SumMatrix1 = sumOfMatrix(matrix1, 3, 3);

	//cout << "SumMatrix1:- " << SumMatrix1 << endl;

	//int SumMatrix2 = sumOfMatrix(matrix2, 3, 3);


	//cout << "SumMatrix2:- " << SumMatrix2 << endl;

	//if (SumMatrix1 == SumMatrix2)
	//{
	//	cout << "the matrices is equal " << endl;
	//}
	//else
	//{
	//	cout << "the matrices is not equal " << endl;
	//}
	//cout << "matrix 2 3x3:- \n\n";

	//fillMatrixWithRandomNumber(matrix2, 3, 3);
	//printMatrix(matrix2, 3, 3);

	//cout << "result multiMatrix 3 3x3:- \n\n";

	//multiTowMatrix(matrix1, matrix2, multiMatrix, 3, 3);
	//printMatrix(multiMatrix, 3, 3);


}