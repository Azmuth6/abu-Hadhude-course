#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
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
			printf("%0*d   ", 2, arr[i][j]);

		}
		cout << endl;
	}
}



int SumOfMatrixInNum(int arr[3][3], short rows, short cols)
{
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
	int arr[3][3];

	fillmatrix(arr, 3, 3);

	cout << "matrix is : \n";

	printmatrix(arr, 3, 3);

	cout << "\nsum of matrix in number : " << SumOfMatrixInNum(arr, 3, 3) << endl;

	system("pause>0");

}