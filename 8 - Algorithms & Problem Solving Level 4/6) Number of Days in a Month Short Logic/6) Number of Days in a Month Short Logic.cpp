#include <iostream>

using namespace std;

short ReadYears()
{
	short Num;
	cout << "Enter Year : ";
	cin >> Num;
	return Num;
}
short ReadMonth()
{
	short Num;
	cout << "Enter Month : ";
	cin >> Num;
	return Num;
}

bool LeapYear(int num)
{
	return (num % 100 != 0 && num % 4 == 0) || (num % 400 == 0);
}

int NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;

	int NumerOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	return (Month == 2)
		? (LeapYear(Year) ? 29 : 28)
		: NumerOfDays[Month];

}



int main()
{
	short Year = ReadYears();
	short Month = ReadMonth();

	cout << "Number Of Days    in Month [" << Month << "]: "
		<< NumberOfDaysInAMonth(Year, Month) << endl;


	return 0;
}
