#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector <int> num{ 5 , 1 , 4 , 5 , 8 };
	
	try
	{
		cout << num.at(9);
	}
	catch (...)
	{
		cout << "out of bound ";
	}

	return 0;
}

