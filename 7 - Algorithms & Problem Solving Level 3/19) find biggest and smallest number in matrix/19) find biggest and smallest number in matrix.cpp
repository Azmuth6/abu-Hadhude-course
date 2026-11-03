
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;



void printmatrix2D(int arr[3][3], short raw, short col)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(3) << arr[i][j] << "   ";

		}
		cout << endl;
	}
}


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
			arr[i][j] = Randome(1, 100);
		}
	}
}


int BiggestNumberInMatrix(int arr[3][3], int rows, int cols)
{
	int BiggestNumber = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] > BiggestNumber)
			{
				BiggestNumber = arr[i][j];
			}
		}
	}
	return BiggestNumber;
}

int SmallestNumberInMatrix(int arr[3][3], int rows, int cols)
{
	int SmallestNumber = 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] < SmallestNumber)
			{
				SmallestNumber = arr[i][j];
			}
		}
	}
	return SmallestNumber;
}

void PrintBiggestAndSmallest(int arr[3][3], int rows, int cols)
{
	cout << "Biggest Number in Matrix is : " << BiggestNumberInMatrix(arr, rows, cols) << endl;
	cout << "Smallest Number in Matrix is : " << SmallestNumberInMatrix(arr, rows, cols) << endl;
}


int main()
{
	srand((unsigned)time(NULL));
	int Matrix1[3][3];
	fillmatrix(Matrix1, 3, 3);

	cout << "\nmatrix 1 is : \n";
	printmatrix2D(Matrix1, 3, 3);

	PrintBiggestAndSmallest(Matrix1, 3, 3);

	system("pause>0");
}