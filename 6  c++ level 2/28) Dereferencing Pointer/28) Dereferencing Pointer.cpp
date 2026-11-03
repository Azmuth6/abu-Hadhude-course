#include <iostream>

using namespace std;

int main()
{
    int a = 10;
	cout << "value of a: " << a << endl;
	cout << "address of a: " << &a << endl << endl;

	int* P;
	P = &a; // P is a pointer to a
	cout << "value of P: " << P << endl;
	cout << "value pointed to by P: " << *P << endl << endl; // dereferencing pointer P

	*P = 20;
	cout << "new value of a: " << a << endl;
	cout << "new value pointed to by P: " << *P << endl; // dereferencing pointer P again

	a = 30;	
	cout << "new value of a: " << a << endl;
	cout << "value pointed to by P: " << *P << endl; // dereferencing pointer P again

	return 0;
}
