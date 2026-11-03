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

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short d, a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;

	d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] =
	{ "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

string MonthShortName(short MonthNumber)
{
	string arrMonthName[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return arrMonthName[MonthNumber - 1];
}

void PrintMonthCalendar(short Month, short Year)
{
	int NumberOfDays;
	// Index of the day from 0 to 6
	int current = DayOfWeekOrder(1, Month, Year);

	NumberOfDays = NumberOfDaysInAMonth(Month, Year);

	// Print the current month name
	printf("\n  _______________%s_________________\n\n",
		MonthShortName(Month).c_str());

	// Print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Print appropriate spaces
	int i;
	for (i = 0; i < current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);
		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n  ___________________________________\n");
}

void YearCalendar(short Year)
{
	printf("\n  ___________________________________\n\n");
	cout << "               Calendar : " << Year;
	printf("\n  ___________________________________\n");

	for (int i = 1; i <= 12; i++)
	{
		PrintMonthCalendar(i, Year);
	}
}


int main()
{
	short Year = ReadYears();

	YearCalendar(Year);
	return 0;
}

