#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
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

short CountNumberInMatrix(int arr[3][3], int record , int rows, int cols)
{
	short CountGivenNumber = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == record)
				CountGivenNumber++;
		}
	}
	return CountGivenNumber;
}



int main()
{
	srand((unsigned)time(NULL));
	
	int record;
	int Matrix1[3][3] = { {9,1,12},{0,9,1},{0,9,9} };

	cout << "\nmatrix is : \n";
	printmatrix(Matrix1, 3, 3);

	cout << "\nEnter the number to count in matrix? ";
	cin >> record; 
	
	cout << "\nNumber " << record << " count in matrix is " << CountNumberInMatrix(Matrix1, record, 3, 3);

	system("pause>0");
}