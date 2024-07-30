#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//int RandomNumber(int From, int To) {
//	//Function to generate a random number 
//	int randNum = rand() % (To - From + 1) + From;
//	return randNum;
//}
////
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
bool isPalindromeMatrix(int arr[3][3], short rows, short cols) {
	short countNumber = 0;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols / 2; j++)
		{
			if (arr[i][j] != arr[i][cols - 1 -j]) {
				return false;
			}
		}

	}
	return true;
}






int main()
{
	//srand((unsignrd)time(NULL));

	int matrix1[3][3] = { {1,2,1},{2,5,2},{7,8,7} };
	//	matrix2[3][3] = { {1,2,5},{34,34,56},{5,78,89} };



	cout << "matrix 1 3x3:- \n\n";

	printMatrix(matrix1, 3, 3);

	if (isPalindromeMatrix(matrix1, 3, 3)) {
		cout << "the matrix is palindrome " << endl;
	}
	else{
		cout << "the matrix is not palindrome " << endl;
	}
	//cout << "matrix 2 3x3:- \n\n";

	//fillMatrix(matrix2, 3, 3);
	//printMatrix(matrix2, 3, 3);


	//cout << "the max number is :- " << maxNumberInMatrix(matrix1, 3, 3) << endl;
	//cout << "the min number is :- " << minNumberInMatrix(matrix1, 3, 3) << endl;

}
