#include <iostream>
#include <ctime>
#include <iomanip>
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

short CheckSparseMatrix(int arr[3][3], int rows, int cols)
{
	short CountNumberOfZeros = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == 0)
				CountNumberOfZeros++;
		}
	}
	return CountNumberOfZeros;
}

bool isSparseMatrix(int arr[3][3], int rows, int cols)
{
	short CountNumberOfZeros = CheckSparseMatrix(arr, rows, cols);
	short MatrixSize = (rows * cols);


	return(CountNumberOfZeros >= (MatrixSize / 2));

}

int main()
{
	
	int Matrix1[3][3] = { {0,0,0},{0,9,1},{0,9,9} };

	cout << "\nmatrix is : \n";
	printmatrix(Matrix1, 3, 3);

	cout << (isSparseMatrix(Matrix1, 3, 3) ? "\nSparse Matrix" : "\nNot Sparse Matrix");

	system("pause>0");
}