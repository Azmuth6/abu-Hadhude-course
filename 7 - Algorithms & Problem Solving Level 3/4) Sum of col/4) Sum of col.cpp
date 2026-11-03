#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

int ReadRandomNumber(int from, int to)
{
	int random = rand() % (to - from + 1) + from;

	return random;
}

void ReadMatrixFromRandomNumber(int arr[3][3], short rows, short coloms)  //(int (&arr)[3][3], short rows, short coloms)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < coloms; j++)
		{
			arr[i][j] = ReadRandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short rows, short coloms)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < coloms; j++)
		{
			cout << setw(3) << arr[i][j] << "   ";
		}
		cout << endl;
	}

}


int SumofColoms(int arr[3][3], short rows, short numofCol)
{
	int Sum = 0;
	for (int i = 0; i < rows; i++)
	{
		Sum += arr[i][numofCol];
	}

	return Sum;
}

void PrintSum(int arr[3][3], short rows, short coloms)
{
	cout << "\nsum of rows is : \n";
	for (int i = 0; i < coloms; i++)
	{
		cout << "\nSum of col [" << i + 1 << "] is  : " << SumofColoms(arr, rows, i) << endl;
	}


}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	ReadMatrixFromRandomNumber(arr, 3, 3);
	cout << "your mat is : \n";
	PrintMatrix(arr, 3, 3);

	PrintSum(arr, 3, 3);

	return 0;

}