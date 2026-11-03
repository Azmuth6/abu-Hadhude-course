#include <iostream>

using namespace std;

int main()
{

	// declare an int pointer
	int* ptrx;

	// declare a float pointer
	float* ptry;

	// dynamically allocate memory
	ptrx = new int;
	ptry = new float;
	
	// assigning value to the memory
	*ptrx = 22;
	*ptry = 55.223f;

	cout << *ptrx << endl;
	cout << *ptry << endl;

	// deallocate the memory
	delete ptrx;
	delete ptry;

	return 0;
}