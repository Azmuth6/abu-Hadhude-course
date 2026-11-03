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

bool typicalMatrix(int arr1[3][3], int arr2[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				return false;
			}
		}
	}

	return true;

}



int main()
{
	srand((unsigned)time(NULL));
	int arr1[3][3];
	int arr2[3][3];

	fillmatrix(arr1, 3, 3);
	fillmatrix(arr2, 3, 3);

	cout << "\nmatrix 1 is : \n";
	printmatrix(arr1, 3, 3);

	cout << "\nmatrix 2 is : \n";
	printmatrix(arr2, 3, 3);

	cout << (typicalMatrix(arr1, arr2, 3, 3) ? "\ntypical\n" : "\nnot typical\n");



	system("pause>0");

}