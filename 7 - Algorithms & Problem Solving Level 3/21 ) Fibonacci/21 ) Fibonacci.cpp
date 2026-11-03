#include <iostream>

using namespace std;	

void PrintFibonacciUsingLoop(int number)
{
	int  temp1 = 1, temp2 = 0, temp3 = 0;
	cout << "1 ";
	for (int i = 2; i <= number; i++)
	{
		temp3 = temp1 + temp2;
		temp2 = temp1;
		temp1 = temp3;
		cout << temp3 << " ";

	}

}

int main()
{
	int number;
	cout << "Enter the number of Fibonacci numbers to print: ";
	cin >> number;
	
	cout << "Fibonacci series: ";
	PrintFibonacciUsingLoop(number);
	cout << endl;
	return 0;
}