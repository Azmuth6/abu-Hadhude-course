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


bool isNumberInMatrix(int arr[3][3],int record, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == record)
				return true;
		}
	}

	return false;
}

int main()
{
	int num;
	int Matrix1[3][3] = { {0,0,0},{0,9,1},{0,9,9} };

	cout << "\nmatrix is : \n";
	printmatrix(Matrix1, 3, 3);

	cout << "enter Number you want to check if exists : ";
	cin >> num;

	cout << (isNumberInMatrix(Matrix1, num, 3, 3) ? "\nexists" : "\nNot exists");

	system("pause>0");
}