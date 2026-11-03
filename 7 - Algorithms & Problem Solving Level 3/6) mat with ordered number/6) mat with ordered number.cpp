#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void fillmatrix(int arr[3][3], short raw, short col)
{
	int k = 0;
	for(int i = 0; i < raw; i++)
	{
		for(int j = 0; j < col; j++)
		{
			k++;
			arr[i][j] = k;
		}
	}
}

void printmatrix(int arr[3][3], short raw, short col)
{
	for(int i = 0; i < raw; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	int arr[3][3];

	fillmatrix(arr, 3, 3);

	printmatrix(arr, 3, 3);

	system("pause>0");
}