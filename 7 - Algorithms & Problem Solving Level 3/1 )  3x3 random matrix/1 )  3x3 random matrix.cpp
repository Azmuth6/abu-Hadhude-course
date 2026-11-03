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

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	ReadMatrixFromRandomNumber(arr, 3, 3);

	cout << "your random matrix 3*3 is : " << endl;

	PrintMatrix(arr, 3, 3);

	return 0;
}