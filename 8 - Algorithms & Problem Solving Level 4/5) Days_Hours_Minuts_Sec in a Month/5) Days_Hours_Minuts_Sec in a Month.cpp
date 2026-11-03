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

	if (Month == 2)
		return  LeapYear(Year) ? 29 : 28;

	int arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (int i = 0; i < 7; i++)
	{
		if (Month == arr31Days[i])
			return 31;
	}

	return 30;
}
int NumberOfHoursInAMonth(short Year, short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * 24;
}
int NumberOfMinutesInAMonth(short Year, short Month)
{
	return NumberOfHoursInAMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month)
{
	return NumberOfMinutesInAMonth(Year, Month) * 60;
}


int main()
{
	short Year = ReadYears();
	short Month = ReadMonth();

	cout << "Number Of Days    in Month [" << Month << "]: "
		<< NumberOfDaysInAMonth(Year, Month) << endl;

	cout << "Number Of Hours   in Month [" << Month << "]: "
		<< NumberOfHoursInAMonth(Year, Month) << endl;

	cout << "Number Of Minutes in Month [" << Month << "]: "
		<< NumberOfMinutesInAMonth(Year, Month) << endl;

	cout << "Number Of Second  in Month [" << Month << "]: "
		<< NumberOfSecondsInAMonth(Year, Month) << endl;


	return 0;
}
