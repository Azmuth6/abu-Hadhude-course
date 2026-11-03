#include <iostream>
using namespace std;


void TheExplanation()
{
	//int x[Rows][Cols];
	int x[3][4] =
	{ {1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};


	for (int i = 0; i < 3; i++)
	{
		cout << "------------------------------\n";
		for (int j = 0; j < 4; j++)
		{
			cout << x[i][j] << "\t";
		}

		cout << endl;
	}

	cout << "------------------------------\n";

	

}
 
void MySolution()
{
	int x[10][10] = {
		{1,2,3,4,5,6,7,8,9,10} ,
		{1,2,3,4,5,6,7,8,9,10} ,
		{1,2,3,4,5,6,7,8,9,10} ,
		{1,2,3,4,5,6,7,8,9,10} ,
		{1,2,3,4,5,6,7,8,9,10} ,
		{1,2,3,4,5,6,7,8,9,10} ,
		{1,2,3,4,5,6,7,8,9,10} ,
		{1,2,3,4,5,6,7,8,9,10} ,
		{1,2,3,4,5,6,7,8,9,10} ,
		{1,2,3,4,5,6,7,8,9,10}
	};

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			printf("%0*d  ", 2, x[i][i] * x[i][j]);
		}

		cout << endl;
	}
	cout << endl;

}



void DrSolution()
{
	int x[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			x[i][j] = (i + 1) * (j + 1);
		}

	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%0*d  ", 2, x[i][j]);
		}
		cout << endl;
	}

	cout << endl;
}



int main()
{
	//TheExplanation();
	//MySolution();

	DrSolution();

	return 0;

}
