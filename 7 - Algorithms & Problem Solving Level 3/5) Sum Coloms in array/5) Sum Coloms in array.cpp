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


void giveItToArray(int arr[3][3], short rows, short Cols, int Sum[3])
{
	for (int i = 0; i < Cols; i++)
	{
		Sum[i] = SumofColoms(arr, rows, i);
	}
}

void PrintArrayNum(short coloms , int Sum[3])
{
	for (int i = 0; i < coloms; i++)
	{
		cout << "\ncol " << i + 1 << " is : " << Sum[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int Sum[3];
	ReadMatrixFromRandomNumber(arr, 3, 3);

	PrintMatrix(arr, 3, 3);


	giveItToArray(arr, 3, 3, Sum);
	PrintArrayNum(3, Sum);


}