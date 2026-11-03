#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector <int> num{ 1 , 2 ,3,4,5,6 };
	cout << "using .at\n"
		<< "index 0 " << num.at(0)
		<< "\nindex 3 " << num.at(3);

	cout << "\nusing [] \n"
		<< "index 0 " << num[0]
		<< "\nindex 3 " << num[3];
}
