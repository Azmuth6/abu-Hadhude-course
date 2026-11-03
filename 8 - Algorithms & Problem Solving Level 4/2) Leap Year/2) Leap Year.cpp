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
	if (num % 400 == 0)
		return true;
	else if (num % 100 == 0)
		return false;
	else if (num % 4 == 0)
		return true;
	else
		return false;

}

int main()
{
	int number = ReadNumber();
	cout << (LeapYears(number) ? "Leap Year" : "Not Leap Years");
	return 0;
}
