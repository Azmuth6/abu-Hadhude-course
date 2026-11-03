#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	cout << "Value of a: " << a << endl;
	cout << "Address of a: " << &a << endl;

	int* p = &a; // Pointer p holds the address of a
	cout << "Value of p (address of a): " << p << endl;
	cout << "Value pointed to by p: " << *p << endl;
	cout << "Address of p: " << &p << endl;

	return 0;

};