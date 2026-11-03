#include <iostream>

using namespace std;

int main()
{

	int num;
	cout << "enter number of students ";
	cin >> num;

	float* ptr;
	ptr = new float[num];

	for (int i = 0; i < num; i++)
	{
		cout << "student " << i + 1 << ":";
		cin >> *(ptr + i);

	}

	cout << "\nDisplaying grades of students." << endl;
	 
	for (int i = 0; i < num; i++)
	{
		cout << "student " << i + 1 << ":" << *(ptr + i) << endl ;
	}

	delete[] ptr;

}