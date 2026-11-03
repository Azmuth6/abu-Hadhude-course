
#include <iostream>
#include <iomanip>

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


bool isPalindrome(int arr[3][3], int rows, int cols)
{
	
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols / 2; k++)
		{
			if (arr[i][k] != arr[i][cols - 1 - k])
				return false;

		}
		
	}
	
	return true;
}



int main()
{
	
	int Matrix1[3][3] = { {1, 2, 1},{3, 4, 3 } ,{ 5, 6, 5 } };
	cout << "\nmatrix 1 is : \n";
	printmatrix2D(Matrix1, 3, 3);

	cout << (isPalindrome(Matrix1, 3, 3) ? "true" : "false") << endl;

	system("pause>0");
}