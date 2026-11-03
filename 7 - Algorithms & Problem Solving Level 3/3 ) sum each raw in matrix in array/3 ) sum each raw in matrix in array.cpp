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

int ReadSumOfRows(int arr[3][3], short NumOfRow, short coloms)
{
	int SumOfRowsMat;
	SumOfRowsMat = 0;
		for (int j = 0; j < coloms; j++)
		{
			SumOfRowsMat += arr[NumOfRow][j];
		}
		
		return SumOfRowsMat;
}

void SumMatixRowsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		arrSum[i] = ReadSumOfRows(arr, i, Cols);
	}
}

void PrintSumOfRows(int SumOfRowsMat[3], int Rows)
{
	cout << "\nThe the following are the sum of each row in the matrix:\n";
	for (int i = 0; i < Rows; i++)
	{
		cout << "sum of raw [" << i + 1 << "] is : " << SumOfRowsMat[i] << endl;
	}

}

int main()
{
	srand ((unsigned)time(NULL));
	int arr[3][3];
	int arrSum[3]; 
	
	ReadMatrixFromRandomNumber(arr, 3, 3);
	
	cout << "\nThe following is a 3x3 random matrix:\n";   
	PrintMatrix(arr, 3, 3);  
	
	SumMatixRowsInArry(arr, arrSum, 3, 3);
	
	PrintSumOfRows(arrSum, 3);  
	
	system("pause>0");
}
