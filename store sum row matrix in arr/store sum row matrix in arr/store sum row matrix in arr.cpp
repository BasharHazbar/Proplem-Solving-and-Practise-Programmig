

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
			arr[i][j] = RandomNumber(1, 100);
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

int sumRow(int arr[3][3], short numberRow, short cols) {
	int sum = 0;
	for (int j = 0; j < cols; j++)
	{
		sum += arr[numberRow][j];
	}
	return sum;
}

void printEachSumOfMatrix(int arr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{

		cout << setw(3) << "sum of row " + i + 1 << "is:- " << sumRow(arr, i, cols) << endl;
	}
}

void storeSumRowsInArray(int arr[3][3], int sumRowsOfMatrix[],int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		sumRowsOfMatrix[i] = sumRow(arr, i, cols);
	}
}

void printArr(int array[3],int row) {
	for (int i = 0; i < row; i++)
	{

		cout << setw(3) << "sum of row " + i + 1 << "is:- " << array[i] << endl;
	}
}


int main()
{
	//srand((unsignrd)time(NULL));

	int arr[3][3],arr2[3];

	fillMatrixWithRandomNumber(arr, 3, 3);
	cout << "the flowing is a matrix 3x3:- \n\n";
	storeSumRowsInArray(arr,arr2, 3, 3);
	printMatrixWithRandomNumber(arr, 3, 3);

	printArr(arr2, 3);

}
