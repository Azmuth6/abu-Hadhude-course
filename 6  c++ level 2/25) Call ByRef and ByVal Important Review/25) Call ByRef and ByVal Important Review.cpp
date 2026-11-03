#include <iostream>

using namespace std;

void FunCallByValue(int x)
{
	x++;
	cout << "Value of x in FunCallBrValue: " << x << endl;
	cout << "Address of x in FunCallBrValue: " << &x << endl;
}

void FunCallByRef(int &x)
{
	x++;
	cout << "Value of x in FunCallBrRef: " << x << endl;
	cout << "Address of x in FunCallBrRef: " << &x << endl;
}

int main()
{
	int a = 10;
	FunCallByValue(a);
	cout << "Value of a after FunCallByValue: " << a << endl;
	cout << "Address of a: " << &a << "\n\n";

	a = 10;
	FunCallByRef(a);
	cout << "Value of a after FunCallByRef: " << a << endl;
	cout << "Address of a: " << &a << endl;

}
