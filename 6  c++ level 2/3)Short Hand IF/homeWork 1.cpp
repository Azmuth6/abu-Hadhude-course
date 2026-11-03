
#include <iostream>
using namespace std;

//int main()
//{
//	int num;
//	cout << "enter the number -> ";
//	cin >> num;
//	string result;
//	result = (num > 0) ? "positive" : "negative";
//
//	cout << result;
//	return  0; 
//}


//nested
int main()
{
	int num;
	cout << "Enter the number -> ";
	cin >> num;
	string result;
	result = (num == 0) ? "zero" :( (num > 0) ? "positive" : "negative" );
	cout << result;
	return 0; 
}