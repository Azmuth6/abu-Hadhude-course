#include <iostream>
#include <vector>

using namespace std;


int main()
{
	
	vector <int> num{ 10 , 20 , 30 , 40 , 50 };

	cout << "num elements \n";
	for (const int& i : num)
	{
		cout << i << " ";
	}


	cout << "\n\nchange num elements (update vector) \n";
	for (int& i : num)
	{
		i = 20;
		cout << i << " ";
	}

	cout << "\n\nchange num elements (update vector) \n";
	
	num[1] = 100;
	num.at(2) = 500;
	num.at(3) = 820;

	for (const int& i : num)
	{
		cout << i << " ";
	}

	return 0;
}

