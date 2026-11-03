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


void printMiddleOfRows(int arr[3][3], short  rows, short cols)
{
	int middleOfRow = ceil(rows / 2.0) - 1;
	

		for (int i = 0; i < cols; i++)
		{
			printf("%0*d   ", 2, arr[middleOfRow][i]);
		}
}

void printMiddleOfCols(int arr[3][3], short  rows, short cols)
{
	int middleOfCol = ceil(rows / 2.0) - 1;


	for (int j = 0; j < cols; j++)
	{
		printf("%0*d   ", 2, arr[j][middleOfCol]);
	}
}



int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];

	fillmatrix(arr, 3, 3);

	cout << "Matrix 1:\n" << endl;
	printmatrix(arr, 3, 3);



	cout << "\nMiddle of Rows:\n" << endl;
	printMiddleOfRows(arr, 3, 3);

	cout << "\nMiddle of Columns:\n" << endl;
	printMiddleOfCols(arr, 3, 3);



	return 0;
}