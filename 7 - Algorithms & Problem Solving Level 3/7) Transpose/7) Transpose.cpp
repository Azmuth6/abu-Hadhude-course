#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void fillmatrix(int arr[3][3], short raw, short col)
{
	int k = 0;
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			k++;
			arr[i][j] = k;
		}
	}
}

void printmatrix(int arr[3][3], short raw, short col)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
}



//void printmatrixTranspose(int arr[3][3], short raw, short col)
//{
//
//	cout << "Transpose of the matrix is\n";
//
//	for (int i = 0; i < raw; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			cout << setw(3) << arr[j][i] << " ";
//		}
//		cout << endl;
//	}
//}


void TransposeMatrix(int arr[3][3], short raw, short col, int transposed[3][3])
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			transposed[j][i] = arr[i][j];
		}
	}
}

int main()
{
	int arr[3][3];
	int transposed[3][3];

	fillmatrix(arr, 3, 3);

	printmatrix(arr, 3, 3);


	cout << "Transpose of the matrix is:\n";	
	TransposeMatrix(arr, 3, 3, transposed);
	printmatrix(transposed, 3, 3);

	return 0;
}