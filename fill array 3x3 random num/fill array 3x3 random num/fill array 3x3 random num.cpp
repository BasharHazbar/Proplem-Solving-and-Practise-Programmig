

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
			cout << setw(3)<<  arr[i][j] << "         ";
		}
		cout << endl;
	}
}


int main()
{
	int arr[3][3];

	fillMatrixWithRandomNumber(arr, 3,3);
	printMatrixWithRandomNumber(arr, 3,3);
}
