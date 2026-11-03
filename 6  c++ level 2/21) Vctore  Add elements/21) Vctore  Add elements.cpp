#include <iostream>
#include <vector>

using namespace std;


void theExplanation()
{
	vector<int> vNumber;

	vNumber.push_back(10);
	vNumber.push_back(20);
	vNumber.push_back(30);
	vNumber.push_back(40);
	vNumber.push_back(50);

	for (int& NUmber : vNumber)
	{
		cout << NUmber << " ";
	}
}

void ReadNumber(vector <int> &vNumber)
{
	char YesNo ;
	do
	{
		int num;
		cout << "enter number ";
		cin >> num;

		vNumber.push_back(num);

		cout << "do you want to add another number ? (Y/N) ";
		cin >> YesNo;

	} while (YesNo == 'Y' || YesNo == 'y');
		
}

void PrintNumber (vector <int> & vNumber)
{
	cout << "\n\nyour numbers is -> ";

	for (int& NUmber : vNumber)
	{
		cout << NUmber << " ";
	}

}

void HomeWorkSolution()
{
	vector <int> vNumber;
	ReadNumber(vNumber);
	PrintNumber(vNumber);

}


int main()
{
	HomeWorkSolution();

	return 0;
}

