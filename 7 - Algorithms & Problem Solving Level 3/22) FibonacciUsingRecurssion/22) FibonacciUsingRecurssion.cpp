#include <iostream>

using namespace std;

void PrintFibonacciUsingRecurssion(short number, int prev1, int prev2)
{
	int Fibonacci = 0;

	if (number > 0)
	{
		Fibonacci = prev1 + prev2;
		prev2 = prev1;
		prev1 = Fibonacci;
		cout << Fibonacci << " ";

		PrintFibonacciUsingRecurssion(number - 1, prev1, prev2);
	}
	
}

int main()
{
	cout << "Fibonacci Series: \n";
	PrintFibonacciUsingRecurssion(10, 0, 1);

	cout << endl;
	return 0;
}

