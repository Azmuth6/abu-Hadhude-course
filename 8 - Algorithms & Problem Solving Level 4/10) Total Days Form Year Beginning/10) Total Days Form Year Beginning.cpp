#include <iostream>
#include <iomanip>

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
short ReadDay()
{
	short Num;
	cout << "Enter Day : ";
	cin >> Num;
	return Num;
}

bool LeapYear(int num)
{
	return (num % 100 != 0 && num % 4 == 0) || (num % 400 == 0);
}

int NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	int NumerOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2)
		? (LeapYear(Year) ? 29 : 28)
		: NumerOfDays[Month];

}


int NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
	int TotalOfDays = 0;
	for (int i = 1; i < Month; i++)
	{
		TotalOfDays += NumberOfDaysInAMonth(i, Year);
	}
	TotalOfDays += Day;
	return TotalOfDays;
}


int main()
{
	short Year = ReadYears();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nNumber of Days from the begining of the year is " << NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year) << endl;

	
	return 0;
}

