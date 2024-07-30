#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//int RandomNumber(int From, int To) {
//	//Function to generate a random number 
//	int randNum = rand() % (To - From + 1) + From;
//	return randNum;
//}
//
//void fillMatrix(int arr[3][3], short rows, short cols) {
//	short number = RandomNumber(1, 10);
//	for (short i = 0; i < rows; i++)
//	{
//		for (short j = 0; j < cols; j++)
//		{
//			arr[i][j] = RandomNumber(1, 50);
//		}
//	}
//}
//string intersectedNumbers(int arr[3][3], int arr2[3][3], int rows, int cols) {
//	string  intersectedNumbers = " ";
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (arr[i][j] == arr2[i][j]) {
//				intersectedNumbers += to_string(arr[i][j]) + "    ";
//			}
//		}
//
//	}
//	return intersectedNumbers;
//}

void printMatrix(int arr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf(" %0*d ",2, arr[i][j]);
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

void printIntersectedNumbers(int arr[3][3], int arr2[3][3], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (isNumberExist(arr, arr2[i][j], 3,3))
			{
				cout << setw(3) << arr2[i][j] << "     ";
			}
		}
	}
}


int main()
{
	//srand((unsignrd)time(NULL));

	int matrix1[3][3] = { {1,2,7},{34,35,56},{5,78,89} },
	matrix2[3][3] = {{1,2,5},{34,34,56},{5,78,89}};

	cout << "matrix 1 3x3:- \n\n";

	//fillMatrix(matrix1, 3, 3);
	printMatrix(matrix1, 3, 3);

	cout << "matrix 2 3x3:- \n\n";

	//fillMatrix(matrix2, 3, 3);
	printMatrix(matrix2, 3, 3);

	printIntersectedNumbers(matrix1, matrix2, 3, 3);

}
