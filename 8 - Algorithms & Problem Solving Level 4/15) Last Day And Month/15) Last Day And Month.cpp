#include <iostream>
#include <iomanip>

using namespace std;

short ReadYear()
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

short ReadDaysToAdd()
{
	short Num;
	cout << "How Many Days To Add : ";
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

struct sDate
{
	short Year; short Month; short Day;
};

bool IsLastDayInMonth(sDate Date)
{
	int DayInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	return (Date.Day == DayInMonth);
}

bool IsLastMonthInYear(sDate Date)
{
	return (Date.Month == 12);
}

sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main()
{
	sDate Date;
	Date = ReadFullDate();

	cout << (IsLastDayInMonth(Date) ? "\nYes, Day is Last Day in Month." : "\n\nNo, Day is Not Last Day in Month.");

	cout << (IsLastMonthInYear(Date) ? "\nYes, Month is Last Month in Year." : "\nNo, Month is Not Last Month in Year.");
	
	system("pause>0");
	return 0;
}

