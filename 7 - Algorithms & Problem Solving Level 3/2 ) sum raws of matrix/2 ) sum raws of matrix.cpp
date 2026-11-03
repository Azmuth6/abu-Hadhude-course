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

void ReadMatrixFromRandomNumber(int arr[3][3], short raws, short coloms)  //(int (&arr)[3][3], short raws, short coloms)
{
	for (int i = 0; i < raws; i++)
	{
		for (int j = 0; j < coloms; j++)
		{
			arr[i][j] = ReadRandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short raws, short coloms)
{

	for (int i = 0; i < raws; i++)
	{
		for (int j = 0; j < coloms; j++)
		{
			cout << setw(3) << arr[i][j] << "   ";
		}
		cout << endl;
	}

}

//void ReadSumOfRaws(int arr[3][3], short raws, short coloms, int SumOfRawsMat[3])
//{
//	for (int i = 0; i < raws; i++)
//	{
//		SumOfRawsMat[i] = 0;
//		for (int j = 0; j < coloms; j++)
//		{
//			SumOfRawsMat[i] += arr[i][j];
//		}
//		cout << endl;
//	}
//}
//
//void PrintSumOfRaws(int arr[3][3], int SumOfRawsMat[3])
//{
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "sum of raw [" << i + 1 << "] is : " << SumOfRawsMat[i] << endl;
//	}
//
//}

int ReadSumOfRaws2(int arr[3][3], short rawNumber, short coloms)
{

	int Sum = 0;

	for (int j = 0; j < coloms; j++)
	{
		Sum = arr[rawNumber][j];
	}

	return Sum;
}

void PrintSumOfRaws2(int arr[3][3], short raws, short coloms)
{
	for (int i = 0; i < raws; i++)
	{
		cout << "sum of raw [" << i + 1 << "] is : " << ReadSumOfRaws2(arr, i, coloms) << endl;
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	ReadMatrixFromRandomNumber(arr, 3, 3);

	cout << "your random matrix 3*3 is : " << endl;

	PrintMatrix(arr, 3, 3);

	int SumOfRawsMat[3];

	PrintSumOfRaws2(arr, 3, 3);

	//ReadSumOfRaws(arr, 3, 3, SumOfRawsMat);
	//PrintSumOfRaws(arr, SumOfRawsMat);

	return 0;
}