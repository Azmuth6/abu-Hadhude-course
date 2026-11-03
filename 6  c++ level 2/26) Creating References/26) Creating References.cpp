#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int& x = a; // x is a reference to a

	cout << "Value of a: " << a << endl; // Output: 10
	cout << "Value of x: " << x << endl; // Output: 10
	cout << "Address of a: " << &a << endl; // Output: Address of a
	cout << "Address of x: " << &x << endl << endl; // Output: Address of a (same as &a)

	a = 20; // Changing the value of a
	cout << "Value of a after change: " << a << endl; // Output: 20
	cout << "Value of x after change: " << x << endl << endl; // Output: 20

	x = 30; // Changing the value of x
	cout << "Value of a after x change: " << a << endl; // Output: 30
	cout << "Value of x after x change: " << x << endl; // Output: 30

	
}

