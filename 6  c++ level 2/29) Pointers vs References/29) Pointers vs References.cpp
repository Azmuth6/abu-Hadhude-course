#include <iostream>

using namespace std;

int main()
{
	int v = 5;
	int& x = v; // x is a reference to v

	cout << "Value of v: " << v << endl; // Output: 5
	cout << "Value of x: " << x << endl; // Output: Address of v

	cout << "Address of v: " << &v << endl; // Output: Address of v
	cout << "Address stored in x: " << &x << endl; // Output: Address of v (same as &v)

	int* P = &v; // P is a pointer to v

	cout << "Value of P: " << P << endl; // Output: Address of v
	cout << "Value pointed to by P: " << *P << endl; // Output: 5

	int b = 40;
	P = &b; // P now points to b
	cout << "Value of P after pointing to b: " << P << endl; // Output: Address of b
	cout << "Value pointed to by P after pointing to b: " << *P << endl; // Output: 40


	return 0;
}
