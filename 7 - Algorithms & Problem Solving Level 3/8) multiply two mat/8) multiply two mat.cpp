#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int Randome(int from, int to)
{
	return (rand() % (to - from + 1)) + from;
}

void fillmatrix(int arr[3][3], short raw, short col)
{
	
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = Randome(1, 10);
		}
	}
}

void printmatrix(int arr[3][3], short raw, short col)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%0*d   ", 2, arr[i][j]) ;
			
		}
		cout << endl;
	}
}


void multiply(int arr1[3][3], int arr2[3][3], int result[3][3], short  rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}




int main()
{
	srand((unsigned)time(NULL));
	int arr1[3][3];
	int arr2[3][3];

	int MatrixMultiply[3][3];

	fillmatrix(arr1, 3, 3);
	fillmatrix(arr2, 3, 3);

	cout << "Matrix 1:\n" << endl;
	printmatrix(arr1, 3, 3);

	cout << "\n\nMatrix 2:\n" << endl;
	printmatrix(arr2, 3, 3);

	multiply(arr1, arr2, MatrixMultiply, 3, 3);
	cout << "\n\nResult of multiplication:\n" << endl;
	printmatrix(MatrixMultiply, 3, 3);

	return 0;
}