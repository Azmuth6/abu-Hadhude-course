#include <iostream>

using namespace std;

void SwapUsingReference(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SwapUsingPointers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 10, y = 20;
	
	cout << "Before SwapUsingReference: x = " << x << ", y = " << y << endl;
	SwapUsingReference(x, y);
	cout << "After SwapUsingReference: x = " << x << ", y = " << y << endl << endl;

	cout << "Before SwapUsingPointers: x = " << x << ", y = " << y << endl;
	SwapUsingPointers(&x, &y);
	cout << "After SwapUsingPointers: x = " << x << ", y = " << y << endl;

	return 0;
}
