#include <iostream>

using namespace std;

int main()
{
	void* ptr;
	int a = 10;
	
	ptr = &a; // Assigning address of integer variable to void pointer
	cout << ptr << endl;
	cout << *(static_cast<int*>(ptr)) << endl; // Dereferencing void pointer after casting to int pointer

	float b = 5.5;
	ptr = &b;


	cout << ptr << endl; 
	cout << (static_cast<float*>(ptr)) << endl;
	cout << *(static_cast<float*>(ptr)) << endl;

	int k = 50;
	auto* PointerValue = &k;

	return 0;
}