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
			arr[i][j] = Randome(0, 1);
		}
	}
}

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

bool IdentityMatrix(int arr[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j && arr[i][j] != 1)
			{
				return false;
			}
			else if (i != j && arr[i][j] != 0)
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

	//int Matrix1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int Matrix1[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

	int arr[3][3];
	
	//fillmatrix(arr, 3, 3);
	cout << "\nmatrix is : \n";
	printmatrix(Matrix1, 3, 3);

	cout << (IdentityMatrix(Matrix1, 3, 3) ? "\nIDENTITY\n" : "\nNOT IDENTITY\n");


	system("pause>0");

}