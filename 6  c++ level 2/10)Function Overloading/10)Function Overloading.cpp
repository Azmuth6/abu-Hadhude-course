#include<iostream>
using namespace std;

double  Sum (double a, double b)
{ return (a + b); } 

int Sum (int a, int b)
{ return (a + b); }

int Sum (int a, int b, int c)
{ return (a + b + c); }

int Sum (int a, int b, int c, int d)
{ return (a + b + c + d); }

int main() 
{
	cout << Sum (10, 20) << endl;
	cout << Sum (10.1, 20.1) << endl;
	cout << Sum (10, 20, 30) << endl;
	cout << Sum (10, 20, 30, 40) << endl;
	return 0;
}