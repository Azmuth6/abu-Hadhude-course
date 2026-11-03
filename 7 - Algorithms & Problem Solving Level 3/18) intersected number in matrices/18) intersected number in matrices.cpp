//void printmatrix1D(vector<int> &arr)
//{
//	for (int& i : arr)
//	{
//		cout << i << "   ";
//	}
//	cout << endl;
//}
//void NumbersInMatrix(int arr[3][3], int arr2[3][3], int rows, int cols, vector <int> &FoundNumbers)
//{
//	int number;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{  
//			number = arr[i][j];
//			if (isNumberInMatrix(arr2, number, rows, cols))
//			{
//				FoundNumbers.push_back(number);
//			}
//		}
//	}
//}


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
			arr[i][j] = Randome(1, 10);
		}
	}
}


bool isNumberInMatrix(int arr[3][3], int record, int rows, int cols)
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




void NumbersInMatrix(int arr[3][3], int arr2[3][3], int rows, int cols)
{
	int number;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			number = arr[i][j];
			if (isNumberInMatrix(arr2, number, rows, cols))
			{
				cout << setw(3) << number << "   ";
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int num;
	int Matrix1[3][3] , Matrix2[3][3] ;
	fillmatrix(Matrix1, 3, 3);
	fillmatrix(Matrix2, 3, 3);


	cout << "\nmatrix 1 is : \n";
	printmatrix2D(Matrix1, 3, 3);

	cout << "\nmatrix 2 is : \n";
	printmatrix2D(Matrix2, 3, 3);


	cout << "\nFound Numbers in both matrices are : \n";
	NumbersInMatrix(Matrix1, Matrix2, 3, 3);




	/*vector<int> FoundNumbers;*/
	/*NumbersInMatrix(Matrix1, Matrix2, 3, 3, FoundNumbers);	
	printmatrix1D(FoundNumbers);*/

	system("pause>0");
}