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
			arr[i][j] = 0;
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

//bool isSparceMatrix(int arr[3][3], short rows, short cols) {
//	short countZero = 0; // 4
//	short countAnother = 0; /// 5
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (arr[i][j] == 0) {
//				countZero++;
//			}
//			else {
//				countAnother++;
//			}
//		}
//
//	}
//	return countZero > countAnother;
//}

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

bool isSparceMatrix(int arr[3][3], short rows, short cols) {
	short matrix = rows * cols;

	return (findCountNumberInMatrix(arr, 0, 3, 3) >= matrix / 2);
}

int main()
{
	//srand((unsignrd)time(NULL));

	int matrix1[3][3] = { {0,0,1},{0,0,1},{0,2,1} };

	cout << "matrix 1 3x3:- \n\n";

	//fillMatrix(matrix1, 3, 3);
	printMatrix(matrix1, 3, 3);

	if (isSparceMatrix(matrix1, 3, 3))
	{
		cout << "the matrix is sparce " << endl;
	}
	else
	{
		cout << "the matrix is not sparce " << endl;
	}
}
