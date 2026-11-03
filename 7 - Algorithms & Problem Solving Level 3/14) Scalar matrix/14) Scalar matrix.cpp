#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

void printmatrix(int arr[3][3], short raw, short col)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << "   ";

		}
		cout << endl;
	}
}

bool ScalarMatrix(int arr[3][3], int rows, int cols)
{
	int DaiagonalValue = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i != j && arr[i][j] != 0)
				return false;
		}
		if ( DaiagonalValue != arr[i][i])
			return false;
	}
	return true;
}



int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {5,0,0},{0,5,0},{0,0,5} }; // SCALAR
	//int Matrix1[3][3] = { {5,0,0},{0,7,0},{0,0,5} }; // NOT SCALAR

	int arr[3][3];

	cout << "\nmatrix is : \n";
	printmatrix(Matrix1, 3, 3);

	cout << (ScalarMatrix(Matrix1, 3, 3) ? "\nSCALAR\n" : "\nNOT SCALAR\n");

	system("pause>0");
}