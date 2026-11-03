#include <iostream>

using namespace std;

int ReadNumber()
{
	int Num;
	cout << "Enter Number : ";
	cin >> Num;
	return Num;
}

bool LeapYears(int num)
{
	return (num % 100 != 0 && num % 4 == 0) || (num % 400 == 0);
}

int main()
{
	int number = ReadNumber();
	cout << (LeapYears(number) ? "Leap Year" : "Not Leap Years");
	return 0;
}
